//UYGULAMA ÝLE ÝLGÝLÝ GENEL AÇIKLAMALAR :
//HÝLAL ZEHRA AYDIN 
//190707078
//Bilgisayar Mühendsiliði 
//BM 104 : Nesneye Yönelik Programlama
//Bahar 2020 Dönemi 
//Programlama projesi 1 (Bir) 
//Dersi veren öðretim üyesinin adý : GÜLÞAH TUMUKLU 
#include<iostream> // cout kullanýmý için kütüphane.
#include<clocale> //setlocale kullanýmý için kütüphane .
#include<time.h> //rand sayý atabilmek içi gerekli bir kütüpane
#include<stdlib.h> //17.satýr bu kütüphane ile çalýþmaktadýr.
using namespace std; //standart kütüphane	
int g = 0,
   Satir ; //global deðiþken tanýmlandý.

	int Tabloyu_belirle(int satir,int sutun,char oyunMat[6][5]){ // gereken parametreler alýndý.
	srand(time(NULL)); //rand sayi atmak için gereklidir.
	int deger; //rand sütun sayýsýný tutmak için deðer adýnda deðiþken tanýmlandý.
	for(satir=1;satir<=6;satir++) // satýr sayisi döngüye sokuldu.
	{
		deger = 1 + rand()%5; //rand sütun sayisi deger deðiþkenine atandý.(seçilen sütun da bomba bulunacak.) 
		for(sutun=1;sutun<=6;sutun++)//sütun sayýsý döngüye sokuldu.
		{
				oyunMat[satir][sutun] = 'T'; // Tablodakki for döngüdündeki sýrasýna göre, 	
		}                                    // Tüm sütun elemanlarý T (Temiz seçildi.)
			oyunMat[satir][deger] = 'X'; //deger deðiþkenine atýlan rondom sütun sayisi X (Bomba) seçildi. 
		}
	}
	int tabloyu_degistir(int i,int j, char oyunMat[6][5]){ //parametreler alýndý,tablo oyuncu hamlesine göre düzenleniyor. 
		if (oyunMat[i][j] == 'T'){ //secilen sütun T (Temiz) ise                            
			oyunMat[i][j] = 'O'; //kullanýcýnýn seçtiði sütun O olarak deðiþtirildi.(iþaretlendi.)
			if(i == 6){ //Son satýra gelmeyi baþardýysa ,
				cout<<"\n Tebrikler Kazandýnýz!"<<endl; // oyuncu kazanmýþtýr.
				cout<<"**************************************"<<endl;//süsleme
				for(int b=1;b<=6;b++){ //satýr 
				for(int c=1;c<=5;c++){ //sütün 
					cout<< oyunMat[b][c] << " "; // ekrana bastýrýldý.
				}
				cout << endl; //satýr atlamasý yapýldý.
			}
			g = 1; //sayac while(75.satýr) döngüsünden çýkmak için güncellendi.
			Satir = Satir + 1; //while(75.satýr) döngüsünden çýkmak için gerekli.
			}
		}
		else if (oyunMat[i][j] == 'X'){ //Oyuncu mayýna bastýysa,
			oyunMat[i][j] = 'P'; // mayýn patlar !!!( satýr P (patladý) olarak deðiþtirildi). 
		cout<<"Mayin Patladi. Uzgunum Maalesef Kaybettiniz!"<<endl;//oyun kaybedildi.
		cout<<"----------------------------------------"<<endl;// süsleme
			g = 1; // while(75.satýr) dan  çýkmak için gerekli
			for(int b=1;b<=6;b++){ //satir
				for(int c=1;c<=5;c++){ //sütun
					cout<< oyunMat[b][c]<<" "; //kullanýcýnýn hamlesiyle deðiþtirilen tablo ekrana basýldý.
				}
				cout << endl;//satýr atlandý.
			}
			Satir = 7;//while döngüsünden çýkmak için kullanýldý 
		}	
	}
int main() //ana fonksiyon 
{
	setlocale(LC_ALL,"Turkish"); // Türkçe karakter çýktýsý için. 
	char karar = 'e';//while döngüsünü çalýþtýrmak için ilk deðer atandý.
	char oyunMat[6][5];//Oyun Matrisi tanýmlandý.
	int sayi; //Oyuncunun gireceði sayý deðiþkeni tanýmlandý.
	while(karar=='e' || karar =='E')//Oyunun sürekliliði için sonsuz döngüye girildi.
	{		
	Tabloyu_belirle(6,5,oyunMat);//Tabloyu_belirle adlý fonksiyon çaðýrýldý , parametre gönderildi. 
		int Satir = 1; // Satýr sayacý tanýmlandý,deðerini artýrabilmek için ilk deðer atandý.
		g = 0;//while döngüsünden çýkabilmek için sayaç oluþturdum.Deðer atamasýný while döngüsüne girmesi için 0 yaptým. 
		do{ // her zaman döngüye 1 kere de olsa girsin diye do while döngüsü oluþturdum.
			cout<<"1 ile 5 arasinda bir sayi giriniz : "; // kullanýcýdan sayý girmesi istendi.
			cin>>sayi;//kullanýcýdan sayý alýndý.
			if(sayi>5 || sayi<1)//sayi 1 ile 5 arasýnda deðil ise 
				{
					cout<<"Hatali giriþ yaptiniz lütfen tekrar deneyin!!!"<<endl; //kullanýcýya uyarý mesajý ekrana bastýrýldý.
				}
		}while(sayi>5 || sayi<1); //sayý 1 ile 5 arasýnda olmayana kadar döngü devam eder.
		tabloyu_degistir(Satir,sayi,oyunMat);//paremetreler göderildi.Foksiyon çaðrýldý.
		while((sayi >= 1) && (sayi <=5) && (Satir<6) && (g == 0) && (karar = ( 'E' || 'e' )))//koþullar saðlanmayana kadar döngü devam eder.
		{
			Satir = Satir + 1; // satir sayacý artýrýldý.
			cout<<Satir<<". satira gectiniz."<<endl; //gecilen satýrýn sayýsý oyuncuya belirtildi.
			do{ //her zaman döngüye 1 kere de olsa girsin diye do while döngüsü oluþturdum.
				cout<<"1 ile 5 arasinda bir sayi giriniz : ";//oyuncudan sayi istendi.
				cin>>sayi;//sayi oyuncudan alýndý.
				if(sayi>5 || sayi<1)//sayi 1 ile 5 arasýnda deðil ise 
				{  
					cout<<"Hatali giriþ yaptiniz lütfen tekrar deneyin!!!"<<endl;// kullanýcýya uyarý mesajý ekrana bastýrýldý.
				}
			}while(sayi>5 || sayi<1); //sayý 1 ile 5 arasýnda olmayana kadar döngü devam eder.
			tabloyu_degistir(Satir,sayi,oyunMat);//paremetreler gönderildi fonksiyon çaðrýldý.	
		} 
		tabloyu_degistir(Satir,sayi,oyunMat);//fonksiyon son satýr elemaný içinde çaðrýldý,parametreler gönderildi.
		cout<<"Yeniden oynamak ister misiniz? (Evet için e/E, Hayýr için h/H giriniz) :";//Oyuncuya yeniden oynama isteði soruldu.
		cin>>karar; //oyuncunun kararý alýndý.
		if ((karar == 'h') || (karar== 'H') && (karar !='e') && (karar != 'E')||(karar =='/0') ){//karar hayýr ise
			break; // döngüden çýk oyunu bitir iþlemi saðlandý.
		}
	}
	cout<<"-------OYUN BÝTTÝ!-------";//oyun bitti mesajý bastýrýldý.
	return 0; // program sona erdi.
}



