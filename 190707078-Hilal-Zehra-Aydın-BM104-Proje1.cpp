//UYGULAMA �LE �LG�L� GENEL A�IKLAMALAR :
//H�LAL ZEHRA AYDIN 
//190707078
//Bilgisayar M�hendsili�i 
//BM 104 : Nesneye Y�nelik Programlama
//Bahar 2020 D�nemi 
//Programlama projesi 1 (Bir) 
//Dersi veren ��retim �yesinin ad� : G�L�AH TUMUKLU 
#include<iostream> // cout kullan�m� i�in k�t�phane.
#include<clocale> //setlocale kullan�m� i�in k�t�phane .
#include<time.h> //rand say� atabilmek i�i gerekli bir k�t�pane
#include<stdlib.h> //17.sat�r bu k�t�phane ile �al��maktad�r.
using namespace std; //standart k�t�phane	
int g = 0,
   Satir ; //global de�i�ken tan�mland�.

	int Tabloyu_belirle(int satir,int sutun,char oyunMat[6][5]){ // gereken parametreler al�nd�.
	srand(time(NULL)); //rand sayi atmak i�in gereklidir.
	int deger; //rand s�tun say�s�n� tutmak i�in de�er ad�nda de�i�ken tan�mland�.
	for(satir=1;satir<=6;satir++) // sat�r sayisi d�ng�ye sokuldu.
	{
		deger = 1 + rand()%5; //rand s�tun sayisi deger de�i�kenine atand�.(se�ilen s�tun da bomba bulunacak.) 
		for(sutun=1;sutun<=6;sutun++)//s�tun say�s� d�ng�ye sokuldu.
		{
				oyunMat[satir][sutun] = 'T'; // Tablodakki for d�ng�d�ndeki s�ras�na g�re, 	
		}                                    // T�m s�tun elemanlar� T (Temiz se�ildi.)
			oyunMat[satir][deger] = 'X'; //deger de�i�kenine at�lan rondom s�tun sayisi X (Bomba) se�ildi. 
		}
	}
	int tabloyu_degistir(int i,int j, char oyunMat[6][5]){ //parametreler al�nd�,tablo oyuncu hamlesine g�re d�zenleniyor. 
		if (oyunMat[i][j] == 'T'){ //secilen s�tun T (Temiz) ise                            
			oyunMat[i][j] = 'O'; //kullan�c�n�n se�ti�i s�tun O olarak de�i�tirildi.(i�aretlendi.)
			if(i == 6){ //Son sat�ra gelmeyi ba�ard�ysa ,
				cout<<"\n Tebrikler Kazand�n�z!"<<endl; // oyuncu kazanm��t�r.
				cout<<"**************************************"<<endl;//s�sleme
				for(int b=1;b<=6;b++){ //sat�r 
				for(int c=1;c<=5;c++){ //s�t�n 
					cout<< oyunMat[b][c] << " "; // ekrana bast�r�ld�.
				}
				cout << endl; //sat�r atlamas� yap�ld�.
			}
			g = 1; //sayac while(75.sat�r) d�ng�s�nden ��kmak i�in g�ncellendi.
			Satir = Satir + 1; //while(75.sat�r) d�ng�s�nden ��kmak i�in gerekli.
			}
		}
		else if (oyunMat[i][j] == 'X'){ //Oyuncu may�na bast�ysa,
			oyunMat[i][j] = 'P'; // may�n patlar !!!( sat�r P (patlad�) olarak de�i�tirildi). 
		cout<<"Mayin Patladi. Uzgunum Maalesef Kaybettiniz!"<<endl;//oyun kaybedildi.
		cout<<"----------------------------------------"<<endl;// s�sleme
			g = 1; // while(75.sat�r) dan  ��kmak i�in gerekli
			for(int b=1;b<=6;b++){ //satir
				for(int c=1;c<=5;c++){ //s�tun
					cout<< oyunMat[b][c]<<" "; //kullan�c�n�n hamlesiyle de�i�tirilen tablo ekrana bas�ld�.
				}
				cout << endl;//sat�r atland�.
			}
			Satir = 7;//while d�ng�s�nden ��kmak i�in kullan�ld� 
		}	
	}
int main() //ana fonksiyon 
{
	setlocale(LC_ALL,"Turkish"); // T�rk�e karakter ��kt�s� i�in. 
	char karar = 'e';//while d�ng�s�n� �al��t�rmak i�in ilk de�er atand�.
	char oyunMat[6][5];//Oyun Matrisi tan�mland�.
	int sayi; //Oyuncunun girece�i say� de�i�keni tan�mland�.
	while(karar=='e' || karar =='E')//Oyunun s�reklili�i i�in sonsuz d�ng�ye girildi.
	{		
	Tabloyu_belirle(6,5,oyunMat);//Tabloyu_belirle adl� fonksiyon �a��r�ld� , parametre g�nderildi. 
		int Satir = 1; // Sat�r sayac� tan�mland�,de�erini art�rabilmek i�in ilk de�er atand�.
		g = 0;//while d�ng�s�nden ��kabilmek i�in saya� olu�turdum.De�er atamas�n� while d�ng�s�ne girmesi i�in 0 yapt�m. 
		do{ // her zaman d�ng�ye 1 kere de olsa girsin diye do while d�ng�s� olu�turdum.
			cout<<"1 ile 5 arasinda bir sayi giriniz : "; // kullan�c�dan say� girmesi istendi.
			cin>>sayi;//kullan�c�dan say� al�nd�.
			if(sayi>5 || sayi<1)//sayi 1 ile 5 aras�nda de�il ise 
				{
					cout<<"Hatali giri� yaptiniz l�tfen tekrar deneyin!!!"<<endl; //kullan�c�ya uyar� mesaj� ekrana bast�r�ld�.
				}
		}while(sayi>5 || sayi<1); //say� 1 ile 5 aras�nda olmayana kadar d�ng� devam eder.
		tabloyu_degistir(Satir,sayi,oyunMat);//paremetreler g�derildi.Foksiyon �a�r�ld�.
		while((sayi >= 1) && (sayi <=5) && (Satir<6) && (g == 0) && (karar = ( 'E' || 'e' )))//ko�ullar sa�lanmayana kadar d�ng� devam eder.
		{
			Satir = Satir + 1; // satir sayac� art�r�ld�.
			cout<<Satir<<". satira gectiniz."<<endl; //gecilen sat�r�n say�s� oyuncuya belirtildi.
			do{ //her zaman d�ng�ye 1 kere de olsa girsin diye do while d�ng�s� olu�turdum.
				cout<<"1 ile 5 arasinda bir sayi giriniz : ";//oyuncudan sayi istendi.
				cin>>sayi;//sayi oyuncudan al�nd�.
				if(sayi>5 || sayi<1)//sayi 1 ile 5 aras�nda de�il ise 
				{  
					cout<<"Hatali giri� yaptiniz l�tfen tekrar deneyin!!!"<<endl;// kullan�c�ya uyar� mesaj� ekrana bast�r�ld�.
				}
			}while(sayi>5 || sayi<1); //say� 1 ile 5 aras�nda olmayana kadar d�ng� devam eder.
			tabloyu_degistir(Satir,sayi,oyunMat);//paremetreler g�nderildi fonksiyon �a�r�ld�.	
		} 
		tabloyu_degistir(Satir,sayi,oyunMat);//fonksiyon son sat�r eleman� i�inde �a�r�ld�,parametreler g�nderildi.
		cout<<"Yeniden oynamak ister misiniz? (Evet i�in e/E, Hay�r i�in h/H giriniz) :";//Oyuncuya yeniden oynama iste�i soruldu.
		cin>>karar; //oyuncunun karar� al�nd�.
		if ((karar == 'h') || (karar== 'H') && (karar !='e') && (karar != 'E')||(karar =='/0') ){//karar hay�r ise
			break; // d�ng�den ��k oyunu bitir i�lemi sa�land�.
		}
	}
	cout<<"-------OYUN B�TT�!-------";//oyun bitti mesaj� bast�r�ld�.
	return 0; // program sona erdi.
}



