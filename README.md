# VeriYapıları DosyaIslemleri

Ödev İçeriği Yazacağınız program C++ konsol uygulaması olup çalıştırıldığında Kisiler.txt isimli dosyayı okuyacaktır. 
Bu dosyada her satırda bir kişi verilmiştir. 
Kişi bilgileri # karakteri ile ayrılmıştır
. Kişi bilgileri aşağıdaki  gibi olacaktır. İsim#doğumyılı#kilo 
Ahmet#1980#72 

Kişi için bir sınıf tasarlanmalıdır. Bu kişiler AVL ağacına eklenecektir. Eklenme kuralı yaşa göre  hesaplanacaktır. Örneğin yukarıdaki kişi için yaş 2020-1980=40 yaşındadır. Eğer yaş aynı veya küçük gelirse düğümün soluna aksi halde düğümün sağına eklenecektir. Yine AVL ağacının her düğümünde  bir yığıt bulunacaktır. Bu yığıt bulunduğu düğümün hareketlerini tutacaktır. Örneğin düğüm seviye  olarak aşağı inerse yığıta A harfi atanacaktır. Seviye olarak yukarı çıkarsa Y harfi yığıta atılacaktır. Değişiklik yoksa D harfi yığıta atılacaktır. Yeni oluşan düğümde yığıta O harfi atanmalıdır. Aşağıda  örnek anlaşılma adına incelenmelidir. Çift çevrimlerde yığıta atılacak hareket sayısı bir olacaktır. Yani  bir düğüm iki seviye yukarı çıksa bile yığıta sadece bir Y harfi atanacaktır.  Leyla#1992#60 Ahmet#1980#72 Mehmet#1974#82 Mehtap#1987#74 Murtaza#1982#85
