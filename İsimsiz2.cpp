#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

class Yigin{
public:
	Yigin(){
		sonraki = NULL;
	}
	char k;
	Yigin *sonraki;
};


Yigin *Push(Yigin *yigin, char k){
	Yigin *yeni = new Yigin();
	yeni->k = k;
	yeni->sonraki = yigin;
	return yeni;
}

Yigin *Pop(Yigin *yigin){
	Yigin *gecici = yigin->sonraki;
	free(yigin);
	return gecici;
}


class Veri{
public:
	Veri()
	{
		sol = NULL;
		sag = NULL;
	}
	string ad;
	int yil;
	int kilo;
	Veri* sol;
	Veri* sag;
	int h;
	Yigin *yigin;
};
Veri *kok=NULL;

int Yukseklik(Veri *dugum){
	if(dugum == NULL) return 0;
	return dugum->h;
}

int Max(int s1,int s2){
	return (s1>s2)?s1:s2;
}
//					y				x
//			x								y
//				z						z

Veri *SagCevrim(Veri *y){
	Veri *x = y->sol;
	Veri *z = x->sag;
	
	x->sag = y;
	y->sol = z;
	
	if(x->yigin->k != 'Y'){
		x->yigin = Push(x->yigin,'Y');
	}
	if(y->yigin->k != 'A'){
		y->yigin = Push(y->yigin,'A');
	}
	
	y->h = Max(Yukseklik(y->sol),Yukseklik(y->sag)) +1 ;
	x->h = Max(Yukseklik(x->sol),Yukseklik(x->sag)) +1 ;
	
	return x;
}

//		x	L				x						y
//			y	A			y		x
//				z	M				z				z

Veri *SolCevrim(Veri *x){
	
	Veri *y = x->sag;
	Veri *z = y->sol;
	
	y->sol = x;
	x->sag = z;
	
	if(y->yigin->k != 'Y'){
		y->yigin = Push(y->yigin,'Y');
	}
	if(x->yigin->k != 'A'){
		x->yigin = Push(x->yigin,'A');
	}
	
	y->h = Max(Yukseklik(y->sol),Yukseklik(y->sag)) +1 ;
	x->h = Max(Yukseklik(x->sol),Yukseklik(x->sag)) +1 ;
	
	return y;
}

int Balans(Veri *dugum){
	if(dugum == NULL) return 0;
	return Yukseklik(dugum->sol) - Yukseklik(dugum->sag);
}

int Yas(int yil){
	return 2020-yil;
}

Veri *Yeni(string adi,int yili,int kilosu){
	Veri *yeni = new Veri();
	yeni->ad = adi;
	yeni->yil = yili;
	yeni->kilo = kilosu;
	return yeni;
}
void f(Veri *dugum)
{
	if(dugum!=NULL){
		if(dugum->sol != NULL) f(dugum->sol);
		if(dugum->sag != NULL) f(dugum->sag);
		dugum->yigin = Push(dugum->yigin,'D');
	}
}

Veri *Ekle(Veri *dugum,Veri *yeni){
	if(dugum == NULL) return yeni;
	if(Yas(yeni->yil)<Yas(dugum->yil)){
		dugum->sol = Ekle(dugum->sol,yeni);
		f(dugum->sag);
	}
	if(Yas(yeni->yil)>Yas(dugum->yil)){
		dugum->sag = Ekle(dugum->sag,yeni);
		f(dugum->sol);
	}
	else return dugum;
	dugum->h = Max(Yukseklik(dugum->sol),Yukseklik(dugum->sag)) + 1;
	int balans = Balans(dugum);
	if(balans > 1 && Yas(yeni->yil) < Yas(dugum->sol->yil)){
		return SagCevrim(dugum);
	}
	if(balans < -1 && Yas(yeni->yil) > Yas(dugum->sag->yil)){
		return SolCevrim(dugum);
	}
	if(balans > 1 && Yas(yeni->yil) > Yas(dugum->sol->yil)){
		dugum->sol = SolCevrim(dugum->sol);
		return SagCevrim(dugum);
	}
	if(balans < -1 && Yas(yeni->yil) < Yas(dugum->sag->yil)){
		dugum->sag = SagCevrim(dugum->sag);
		return SolCevrim(dugum);
	}
	dugum->yigin = Push(dugum->yigin,'D');
	return dugum;
}

void Yazdir(Veri *dugum){
	cout<<dugum->ad<<", "<<dugum->yil<<", "<<dugum->kilo<<"     ";
	cout<<"Yigin: ";
	while(dugum->yigin != NULL){
		cout<<dugum->yigin->k<<" ";
		dugum->yigin = Pop(dugum->yigin);
	}
	cout<<"\n";
}

//							50
//					40				60
//				25		45		55		65
void Postorder(Veri *dugum){
	if(dugum!=NULL){
		if(dugum->sol != NULL) Postorder(dugum->sol);
		if(dugum->sag != NULL) Postorder(dugum->sag);
		Yazdir(dugum);
	}
}


void DosyaOku(){
	fstream dosya("Kisiler.txt",ios::in);
    if(dosya.is_open()){
		do{
			string satir;
			getline(dosya,satir);
			char array[satir.length()+1];
			strcpy(array,satir.c_str());
			Veri *yeni = new Veri();
			yeni->ad = strtok(array,"#");
			yeni->yil = atoi(strtok(NULL,"#"));
			yeni->kilo = atoi(strtok(NULL,"#"));
			yeni->h = 1;
			yeni->yigin = Push(yeni->yigin,'O');
			kok = Ekle(kok,yeni);
		}while(!dosya.eof());
		dosya.close();
		
	}
	else cout << "Dosya acilamadi";
}

int main(){
	DosyaOku();	
	Postorder(kok);
}











