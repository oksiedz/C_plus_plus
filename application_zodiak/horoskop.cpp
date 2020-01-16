#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h> 

using namespace std;

//-------------------------------------------------------------------------------------
bool f_CzyJestYearUrodzenia ( int v_year )
{
int vl_length=0, vl_rok	= v_year;
	SYSTEMTIME st;
	GetSystemTime(&st);
	cout << "Podany rok to " << v_year<< endl;
	cout << "Biezacy rok to " << st.wYear<< endl;
	cin.clear();
	cin.sync();
	//sprawdzam z ilu cyfr sklada sie liczba v_year
	do
	{	vl_rok = vl_rok/10;
		vl_length++;
	} while (vl_rok > 0);

	if (   v_year		>	st.wYear 	//jesli podany rok jest wiekszy niz biezacy rok
		|| st.wYear-100	>	v_year 		//lub jesli biezacy rok - 100 lat jest wiekszy niz podany rok
		|| vl_length	!=	4)   		//lub ilosc cyfr w roku jest <> 4 
		{	cout<< "Podales niewlasciwy rok urodzenia. Sprobuj jeszcze raz" << endl;
			cout << "Podany rok to: " << v_year<< endl;
			cout << "dlugosc liczby:" <<vl_length<< endl;
			getch();
			return false;
		}
	else if (v_year == st.wYear ) //jesli podany rok jest rowny biezacemu
		{	cout<< "Jetes za mlody na korzystanie z komputera." << endl;
			//cout << "Podany rok to " << v_year<< endl;
			//cout << "Biezacy rok to " << st.wYear<< endl;
			getch();
			exit(0);
			return false;
		}
	return true;
}
//-------------------------------------------------------------------------------------
bool f_CzyJestMountUrodzenia ( int v_mount  )
{	cin.clear();
	cin.sync();
	if (v_mount>12 || v_mount<1) //jesli podany miesiac nie istnieje
		{ 	cout<< "Podales niewlasciwy miesiac urodzenia. Sprobuj jeszcze raz" << endl;
			getch();
			return false;
		}
	return true;
}

//-------------------------------------------------------------------------------------
bool f_CzyJestDayUrodzenia ( int v_day, int v_mount, int v_year )
{	
	int vl_max_day, i;	
	int vl_tab_31[7]={1,3,5,7,8,10,12};
	int vl_tab_30[4]={4,6,9,11};
	int vl_tab_28[1]={2};

	cin.clear();
	cin.sync();	

	cout<<"dni: 	"	<<v_day		<<endl;
	cout<<"miesiac: "	<<v_mount	<<endl;
	cout<<"rok: 	"	<<v_year	<<endl;
	

	//jesli miesiac to luty
	if (v_mount=2 )	
	{	//okreslenie czy rok byl przestepny
		if((v_year%4==0 && !(v_year%100==0)) || (v_year%400==0))
			{            vl_max_day = 29;        }
		else
			{vl_max_day = 28;
			 cout<< "ilosc dni w lutym: "<<vl_max_day<<endl;		}

		for( i=0; i < sizeof(vl_tab_28)/sizeof(int); i++)
		if( vl_tab_28[i] == v_mount && (v_day>0 && v_day<vl_max_day+1))
		        return true;
	}	
	else
		// jesli miesiac ma 31 dni
		for( i=0; i < sizeof(vl_tab_31)/sizeof(int); i++)
		if( vl_tab_28[i] == v_mount && (v_day>0 && v_day<31+1))
		        return true;
	    else 
		{//jesli miesiac ma 30 dni
			for( i=0; i < sizeof(vl_tab_30)/sizeof(int); i++)
			if( vl_tab_28[i] == v_mount && (v_day>0 && v_day<30+1))
			        return true;
		}
	return false;
}
//-------------------------------------------------------------------------------------
string f_OdgadnijDzienUrodzin ( int v_day, int v_mount, int v_year )
{
    time_t czas;
    struct tm * data;
	const char * dzien_tygodnia[] = { "Niedziela", "Poniedzialek","Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota" };

    time( & czas );
    data = localtime( & czas );
    data->tm_year = v_year - 1900;
    data->tm_mon = v_mount - 1;
    data->tm_mday = v_day;
   
    mktime( data );
    return dzien_tygodnia[ data->tm_wday ];
}

int f_OtworzPlecPlik()
{
	fstream imie_plec;
	imie_plec.open("imie_plec.txt", ios::in | ios::out | ios::app);
	int liczba_wierszy = 1;
	string linia_do_licznika;
	if (getline(imie_plec,linia_do_licznika))
		{
			while(!imie_plec.eof())
				{
					getline(imie_plec, linia_do_licznika);
					liczba_wierszy++;	
				}	
		}
	else
		{
			liczba_wierszy = 0;
		}
	imie_plec.close();
	imie_plec.open("imie_plec.txt", ios::in | ios::out);
	imie_plec.clear();
	imie_plec.seekg (0, ios::beg);
	return liczba_wierszy;
}

int f_ZamkniPlecPlik()
{
	fstream imie_plec;
	imie_plec.close();
	return 0;
}

char f_SprawdzPlec (string v_name)
{
	if (v_name[v_name.length() - 1] == 'a')
		{
			return 'K';
		}
	else
		{
			return 'M';
		};
}

char f_PotwierdzPlec (string v_name)
{
	int v_potwierdz;
	f_OtworzPlecPlik();
	if(f_OtworzPlecPlik() != 0)
		{
			string imie_petla;
			char plec_petla;
			string linia_petla;
			while (getline(imie_plec,linia_petla))
				{
					isstringstream petla1(linia_petla);
					if (!(petla1 >> imie_petla >> plec_petla)) {break;}
					if (v_name == imie_petla)
						{
							v_plec=plec_petla;
						}
				};
			
			 
			 f_PotwierdzPlec(v_name);		
		}
	
	return f_SprawdzPlec(v_name);
	
}

char f_OkreslPlec (string v_name)
{
	return f_PotwierdzPlec(v_name);
}

//-------------------------------------------------------------------------------------
int f_PodajDane ()
{
	int v_day, v_mount, v_year;
	bool v_czyPoprawneDane = false;
	string v_imie, v_dzienUrodzin;
	char v_plec;
	
	do
	{ 	cin.clear();
		cin.sync();
		system("cls");
		cout<<"podaj rok urodzenia" <<endl;
		cin>>v_year;
		v_czyPoprawneDane = f_CzyJestYearUrodzenia( v_year ) ;
	} while (v_czyPoprawneDane == false);

	v_czyPoprawneDane = false;
	do
	{ 	cin.clear();
		cin.sync();
		cout<<"podaj miesiac urodzenia" <<endl;
		cin>>v_mount;
		v_czyPoprawneDane = f_CzyJestMountUrodzenia( v_mount ) ;
	} while (v_czyPoprawneDane == false);
	
	//cout<< "true: "<< true<<endl;
	//cout<< "false:"<< false<<endl;
	//cout << "v_czyYear:  "<<v_czyYear << endl;
	//cout << "v_czyMount: "<<v_czyMount << endl;	
	
	v_czyPoprawneDane = false;
	do
	{ 	cin.clear();
		cin.sync();
		cout<<"podaj dzien urodzenia" <<endl;
		cin>>v_day;
		v_czyPoprawneDane = f_CzyJestDayUrodzenia( v_day, v_mount, v_year) ;	
		//cout << "v_czyDay: "<<v_czyDay << endl;
	} while (v_czyPoprawneDane== false);
	
	v_czyPoprawneDane = true; //po zrobieniu walidacji zmien na false
	do
	{ 	cin.clear();
		cin.sync();
		cout<<"Podaj imie" <<endl;
		cin>>v_imie;
		//v_czyPoprawneDane = f_Czyimie( v_imie) ;	//tu powinno byc wywolanie funkcji do walidacji imienia czy np. user nie wpisal 1234... pamietaj ze jest cos takiego jak zakres ... (w przypadku skracania linkow bylo to uzywane.)
		//dodalbym jeszcze initcap-a niezaleznie od tego co user wpisal.
	} while (v_czyPoprawneDane== false);

	v_dzienUrodzin = f_OdgadnijDzienUrodzin(v_day, v_mount, v_year);
    v_plec = f_OkreslPlec(v_imie);
	cout << "Czesc "<< v_imie <<". "<<endl;
	cout << "Data Twoich narodzin to: " <<v_day<<"/"<<v_mount<<"/"<<v_year<<endl;
	cout << "Dzien twoich urodzin to: " << v_dzienUrodzin <<endl;
    cout << "Twoja plec to: ";
	if(v_plec == 'K'){cout << "Kobieta";} else {cout << "Mezczyzna";};
	cout << endl;
    getch();
}

int main()
{	//srand(time ( 0 ) );
	char v_znak;
	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout <<"Program Horoskop."<< endl;
		cout <<" "<< endl;
		cout <<"Program stworzony na zaliczenie cwiczen z Podstaw Programowania."			<< endl;
		cout <<"Funkcjonalnosci programu:"													<< endl;
		cout <<"1. Podanie imienia i daty urodzenia"										<< endl;
		cout <<"2. Okreslenie dnia tygodnia na podstawie daty urodzenia"					<< endl;
		cout <<"3. Zmiana koloru czcionki w zaleznosci od dnia tygodnia z daty urodzenia"	<< endl;
		cout <<"4. Stworzenie/otwarcie bazy danych"											<< endl;
		cout <<"5. Okreslenie plci na podstawie imienia"									<< endl;
		cout <<"6. Wyznaczenie wieku uzytkownika"											<< endl;
		cout <<"7. Rozpoznanie znaku zodiaku"												<< endl;
		cout <<"8. Zwrocenie horoskopu"														<< endl;
		cout <<"9. Wyznaczenie fazy ksiezyca w dniu urodzin"								<< endl;
		cout <<"10.Import danych do glownej bazy danych"									<< endl;
		cout <<"11.Funkcja zwracajaca pelna zawartosc bazy danych"							<< endl;
		cout <<"12.Agregaty na bazie danych"												<< endl<< endl;
		cout <<"Aby rozpoczac korzystanie z programu wcisnij 1, aby zakonczyc dzialanie programu wcisnij W."<< endl << endl;
		cout<<"Dokonaj wyboru :";

		v_znak = getchar();
		if (v_znak=='W')
		{
			exit(0);
		}
	
	} while (v_znak!='1');

	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout <<"********************* MENU *********************"	<< endl;
		cout << "1. Okreslenie dnia tygodnia z daty urodzenia	"	<< endl;
		cout << "   Okreslenia plci na podstawie imienia		"	<< endl;
		cout << "   Wyznaczenie wieku uzytkownika				"	<< endl;
		cout << "   Rozpoznanie znaku zodiaku					"	<< endl;
		cout << "   Wyswietl horoskop							"	<< endl;
		cout << "   Wyznaczenie fazy ksiezyca w dniu urodzin	"	<< endl;
		cout << "2. Wyswietl historie							"	<< endl;
		cout << "3. Dodaj dane z pliku							"	<< endl;
		cout << "4. Pokaz agregaty								"	<< endl;
		cout << "W. Wyjscie z programu							" << endl;
		cout<<"Wybieram : ";

		v_znak = getchar();
		switch (v_znak)
		{
			case '1':
				f_PodajDane();
				break;
			case '2':
				//f_znajdz_url();
				break;
			case '3':
				//f_wyswietl_historie();
				break;
			case 'W':
				exit(0);
				break;
			default:
				cout << "Nie ma takiej opcji w menu."<< flush;
				Sleep(750);
				break;
		}
	} while (v_znak!='W');

	return 0;

}