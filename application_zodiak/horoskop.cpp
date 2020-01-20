#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <cmath>

using namespace std;

class Cechy
{ public:
	string imie;
	int rok_urodzenia;
	int miesiac_urodzenia;
	int dzien_urodzenia;
	string nazwa_dnia_urodzenia;
	string znak_zodiaku;
	char plec;
	string horoskop_link;
	string faza_ksiezyca;
};

Cechy Funboy; //obiekt Funboy opisany przez klase Cechy
Cechy *pFunboy; //deklaracja wskaznika do obiektu

//-------------------------------------------------------------------------------------
bool f_CzyJestYearUrodzenia ( int v_year )
{
int vl_length=0, vl_rok	= v_year;
	SYSTEMTIME st;
	GetSystemTime(&st);
	//cout << "Podany rok to " << v_year<< endl;
	//cout << "Biezacy rok to " << st.wYear<< endl;
	cin.clear();
	cin.sync();
	//sprawdzam z ilu cyfr sklada sie liczba v_year
	do
	{	vl_rok = vl_rok/10;
		vl_length++;
	} while (vl_rok > 0);

	if (v_year		>	st.wYear 		//jesli podany rok jest wiekszy niz biezacy rok
		|| st.wYear-150	>	v_year		//lub jesli biezacy rok - 150 lat jest wiekszy niz podany rok
		|| vl_length	!=	4)			//lub ilosc cyfr w roku jest <> 4 
		{	cout<< "Poda³eœ niew³aœciwy rok urodzenia. Spróbuj jeszcze raz." << endl;
			getch();
			return false;
		}
	else if (v_year == st.wYear )		//jesli podany rok jest rowny biezacemu
		{	cout<< "Jetes za mlody na korzystanie z komputera." << endl;
			getch();
			exit(0);
			return false;
		}
	return true;
}
//-------------------------------------------------------------------------------------
bool f_CzyJestMountUrodzenia ( int v_month )
{	cin.clear();
	cin.sync();
	if (v_month>12 || v_month<1)		//jesli podany miesiac nie istnieje
		{	cout<< "Poda³es niew³asciwy miesiœc urodzenia. Spróbuj jeszcze raz" << endl;
			getch();
			return false;
		}
	return true;
}

//-------------------------------------------------------------------------------------
bool f_CzyJestDayUrodzenia ( int v_day, int v_month, int v_year )
{
	int vl_max_day, i=0;
	int vl_tab_31[7]={1,3,5,7,8,10,12};
	int vl_tab_30[4]={4,6,9,11};
	int vl_tab_28[1]={2};

	cin.clear();
	cin.sync();

	//jesli miesiac to luty
	if (v_month==2 )
	{	//okreslenie czy rok byl przestepny
		if((v_year%4==0 && !(v_year%100==0)) || (v_year%400==0))
			{vl_max_day = 29;}
		else
			{vl_max_day = 28;}

		for( i=0; i < sizeof(vl_tab_28)/sizeof(int); i++)
		{	if( vl_tab_28[i] == v_month && (v_day>0 && v_day<vl_max_day+1))
				return true;
			else
				cout<< "W roku "<<v_year<<" iloœæ dni w lutym wynosi³a: "<<vl_max_day<<endl;
		}
	}
	else
	{	//cout<<"jesli miesiac ma 31 dni"<<endl;
		for( i=0; i < sizeof(vl_tab_31)/sizeof(int); i++)
		{	if( vl_tab_31[i] == v_month && (v_day>0 && v_day<32))
				{	//cout<<"i: "<< i <<" "<<vl_tab_31[i]<<"v_month"<<v_day<<endl;
					return true; }
		}
		//cout<<"jesli miesiac ma 30 dni"<<endl;
		for( i=0; i < sizeof(vl_tab_30)/sizeof(int); i++)
		{	if( vl_tab_30[i] == v_month && (v_day>0 && v_day<31))
			{	//cout<<"i: "<< i <<" "<<vl_tab_30[i]<<"v_month"<<v_day<<endl;
				return true;}
		}
	}
	return false;
}
//---------------------------------------------------------------
void f_ZmienKolor(string value)
{
	if (value == "Niedziela")
	{
		system("Color 0E");
	}
	else if (value == "Poniedzia³ek")
	{
		system("Color 0A");
	}
	else if (value == "Wtorek")
	{
		system("Color 0B");
	}
	else if (value == "Œroda")
	{
		system("Color 0C");
	}
	else if (value == "Czwartek")
	{
		system("Color 03");
	}
	else if (value == "Pi¹tek")
	{
		system("Color 04");
	}
	else
	{
		system("Color 02");
	};
}

//-------------------------------------------------------------------------------------
string f_OdgadnijDzienUrodzin ( int v_day, int v_month, int v_year )
{
	time_t czas;
	struct tm * data;
	const char * dzien_tygodnia[] = { "Niedziela", "Poniedzia³ek","Wtorek", "Œroda", "Czwartek", "Pi¹tek", "Sobota" };

	time( & czas );
	data = localtime( & czas );
	data->tm_year = v_year - 1900;
	data->tm_mon = v_month - 1;
	data->tm_mday = v_day;

	mktime( data );
	f_ZmienKolor(dzien_tygodnia[ data->tm_wday ]);
	return dzien_tygodnia[ data->tm_wday ];
}
//-------------------------------------------------------------------------------------
bool f_CzyPoprawneImie ( string v_name )
{
	int vl_NameLength, i, j, vl_ZnalezionaLiterka=0;
	char tl_ZbiorZnakow[53]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

	vl_NameLength = v_name.length();
	//cout<<"vl_NameLength"<<vl_NameLength<<endl;
	for (i=0; i<vl_NameLength; i++)
	{
		//cout<<"litera : "<< v_name[i] <<endl;
		for (j=0; j<52; j++)
		{
			if (v_name[i] == tl_ZbiorZnakow[j])
			{	//cout<<"literka : "<< tl_ZbiorZnakow[j] <<endl;
				vl_ZnalezionaLiterka++;
				exit;}
		}
	}
	//cout<<"vl_ZnalezionaLiterka: "<<vl_ZnalezionaLiterka<<endl;
	if (v_name.length() == vl_ZnalezionaLiterka)
		{	//getch();
			return true;
		}
	else
		{cout<< "Wpisane imie jest niepoprawne. Spróbuj jeszcze raz.";}
return false;
}
//-------------------------------------------------------------------------------------
string f_ImieInitCap ( string v_name )
{
	string lv_name = v_name;
	lv_name[0] = toupper(lv_name[0]);
	//v_name=lv_name;
return lv_name;
}
//-------------------------------------------------------------------------------------
/*wyznaczanie plci*/
char f_SprawdzPlec (string v_name)
{
	const string v_imiemeskie[] = {"Barnaba", "Bonawentura", "Jarema", "Jona", "Kosma", "Dyzma"};
	const string v_imiezenskie[] = {"Beatrycze", "D¿anan", "Mariam", "Miriam", "Megi", "Noemi", "Rut", "Szarlin"};
	int v_nietypoweimie = 0;
	for (int i = 0; i < 6; i++)
	{
		if (v_name == v_imiemeskie[i])
		{
			return 'M';
			int v_nietypoweimie = 1;
			break;
		}
	};
	for (int i = 0; i < 8; i++)
	{
		if (v_name == v_imiezenskie[i])
		{
			return 'K';
			int v_nietypoweimie = 1;
			break;
		}
	};
	if (v_nietypoweimie == 0)
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
}

string f_PlecSlownie(char v_gender)
{
	if (v_gender == 'K')
	{
		return "Kobieta";
	}
	else
	{
		return "Mê¿czyna";
	}
}
/*wyznaczanie plci*/
/*znak zodiaku*/
string f_Zodiak(int v_day, int v_month)
{
	switch (v_month)
		{
			case 1:
				if (v_day < 20) {return "Kozioro¿ec";}
				else{return "Wodnik";};
				break;
			case 2:
				if (v_day < 19) {return "Wodnik";}
				else{return "Ryby";};
				break;
			case 3:
				if (v_day < 21) {return "Ryby";}
				else{return "Baran";};
				break;
			case 4:
				if (v_day < 20) {return "Baran";}
				else{return "Byk";};
				break;
			case 5:
				if (v_day < 23) {return "Byk";}
				else{return "BliŸniêta";};
				break;
			case 6:
				if (v_day < 22) {return "BliŸniêta";}
				else{return "Rak";};
				break;
			case 7:
				if (v_day < 23) {return "Rak";}
				else{return "Lew";};
				break;
			case 8:
				if (v_day < 24) {return "Lew";}
				else{return "Panna";};
				break;
			case 9:
				if (v_day < 23) {return "Panna";}
				else{return "Waga";};
				break;
			case 10:
				if (v_day < 23) {return "Waga";}
				else{return "Skorpion";};
				break;
			case 11:
				if (v_day < 22) {return "Skorpion";}
				else{return "Strzelec";};
				break;
			case 12:
				if (v_day < 22) {return "Strzelec";}
				else{return "Kozioro¿ec";};
				break;
		};
}
/*znak zodiaku*/
/*link do horoskopu*/
string f_HoroskopLink (string v_zodiac)
{
	string url = "https://www.horoskop360.pl/horoskop-";
	string url_part2 = v_zodiac;
	url_part2[0] = tolower(url_part2[0]);
	return url + url_part2;
}

int f_OtworzLinkHoroskop (string v_zodiac)
{
	string v_url;
	v_url = f_HoroskopLink(v_zodiac);
	ShellExecuteA(NULL, "open", v_url.c_str(), NULL, NULL, SW_SHOWNORMAL);
	return 0;
}
/*link do horoskopu*/
/*wyznaczanie fazy ksiezyca w dniu urodzin*/
double f_FazaKsiezycRang(float value)
{
	int value_1;
	value_1 = 360 * (value / 360 - floor(value / 360));
	if (value_1 < 0)
	{
		value_1 = value_1 + 360;
	};
	return value_1;
}

int f_PrzeksztalcMiesiac (int v_month)
{
	if (v_month < 2)
	{
		return v_month;
	}
	else
	{
		return v_month + 12;
	};
}

int f_PrzeksztalcRok (int v_month, int v_year)
{
	if (v_month < 2)
	{
		return v_year;
	}
	else
	{
		return v_year - 1;
	};
}

float f_FazaKsiezycaPodfunkcja1(int year, int month, int day)
{
	return floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + (2 - floor(year / 100) + floor(floor(year / 100) / 4)) - 1524.5;
}

float f_FazaKsiezycaPodfunkcja2(float value)
{
	return (value - 2451545) / 36525;
}

float f_FazaKsiezycaPodfunkcja3(float value)
{
	return (value + (0.5 / 24) - 2451545) / 36525;
}

float f_FazaKsiezycaPodfunkcja4(float value)
{
	return f_FazaKsiezycRang(297.8502042 + 445267.1115168 * value - (0.00163 * value * value) + value * value * value / 545868 - value * value * value * value / 113065000);
}

float f_FazaKsiezycaPodfunkcja5(float value)
{
	return f_FazaKsiezycRang(357.5291092 + 35999.0502909 * value - 0.0001536 * value * value + value * value * value / 24490000);
}

float f_FazaKsiezycaPodfunkcja6(float value)
{
	return f_FazaKsiezycRang(134.9634114 + 477198.8676313 * value - 0.008997 * value * value + value * value * value / 69699 - value * value * value * value / 14712000);
}

float f_FazaKsiezycaPodfunkcja7(float value1, float value2, float value3)
{
	return 180 - value1 - (6.289 * sin((3.1415926535 / 180) * ((value2)))) + (2.1 * sin((3.1415926535 / 180) * ((value3)))) - (1.274 * sin((3.1415926535 / 180) * (((2 * value1) - value2)))) - (0.658 * sin((3.1415926535 / 180) * ((2 * value1)))) - (0.214 * sin((3.1415926535 / 180) * ((2 * value2)))) - (0.11 * sin((3.1415926535 / 180) * ((value1))));
}

float f_FazaKsiezycaPodfunkcja8(float value)
{
	return (1 + cos((3.1415926535 / 180) * (value))) / 2;
}

float f_FazaKsiezycaPodfunkcja9(float value1, float value2)
{
	if ((value2 - value1) < 0)
	{
		return -1 * value1;
	}
	else
	{
		return value1;
	}
}

float f_FazaKsiezycaPodfunkcja10(float value)
{
	return 100 * value;
}

float f_Fazaksiezyca(int v_year, int v_month, int v_day)
{
	int month, year, day;
	float jdp, tzd, tzd2, elm, elm2, ams, ams2, aml, aml2, asd, asd2, phi1, phi2;
	day = v_day;
	month = f_PrzeksztalcMiesiac(v_month);
	year = f_PrzeksztalcRok(v_month, v_year);
	jdp = f_FazaKsiezycaPodfunkcja1(year, month, day);
	tzd = f_FazaKsiezycaPodfunkcja2(jdp);
	tzd2 = f_FazaKsiezycaPodfunkcja3(jdp);
	elm = f_FazaKsiezycaPodfunkcja4(tzd);
	elm2 = f_FazaKsiezycaPodfunkcja4(tzd2);
	ams = f_FazaKsiezycaPodfunkcja5(tzd);
	ams2 = f_FazaKsiezycaPodfunkcja5(tzd2);
	aml = f_FazaKsiezycaPodfunkcja6(tzd);
	aml2 = f_FazaKsiezycaPodfunkcja6(tzd2);
	asd = f_FazaKsiezycaPodfunkcja7(elm, aml, ams);
	asd2 = f_FazaKsiezycaPodfunkcja7(elm2, aml2, ams2);
	phi1 = f_FazaKsiezycaPodfunkcja8(asd);
	phi2 = f_FazaKsiezycaPodfunkcja8(asd2);
	cout << "Faza ksiezyca: " << f_FazaKsiezycaPodfunkcja10(f_FazaKsiezycaPodfunkcja9(phi1, phi2)) << endl;
	return f_FazaKsiezycaPodfunkcja10(f_FazaKsiezycaPodfunkcja9(phi1, phi2));
}

string f_FazaKsiezycaSlownie(float faza_ksiezyca)
{
	if (faza_ksiezyca >= -5 && faza_ksiezyca <= 5)
	{
		return "Nów";
	}
	else if (faza_ksiezyca > 5 && faza_ksiezyca < 45)
	{
		return "Rosn¹cy sierp";
	}
	else if (faza_ksiezyca >= 45 && faza_ksiezyca <= 55)
	{
		return "Pierwsza kwadra";
	}
	else if (faza_ksiezyca > 55 && faza_ksiezyca < 95)
	{
		return "Rosn¹cy garb";
	}
	else if (faza_ksiezyca >= 95 && faza_ksiezyca <= -95)
	{
		return "Pe³nia";
	}
	else if (faza_ksiezyca > -95 && faza_ksiezyca < -55)
	{
		return "Zanikaj¹cy garb";
	}
	else if (faza_ksiezyca >= -55 && faza_ksiezyca <= -45)
	{
		return "Trzecia kwadra";
	}
	else if (faza_ksiezyca > -45 && faza_ksiezyca < -5)
	{
		return "Zanikaj¹cy sierp";
	}
	else
	{
		return "Nie mozna wyznaczyæ fazy ksiê¿yca";
	};
}
/*wyznaczanie fazy ksiezyca w dniu urodzin*///-------------------------------------------------------------------------------------
void f_PodajDane ()
{
	int v_day, v_month, v_year;
	bool v_czyPoprawneDane = false;
	string v_name, v_dzienUrodzin, v_zodiac;
	char v_gender;

	do
	{ 	cin.clear();
		cin.sync();
		system("cls");
		cout<<"podaj rok urodzenia" <<endl;
		cin>>v_year;
		v_czyPoprawneDane = f_CzyJestYearUrodzenia( v_year );
	} while (v_czyPoprawneDane == false);

	v_czyPoprawneDane = false;
	do
	{ 	cin.clear();
		cin.sync();
		cout<<"podaj miesi¹c urodzenia" <<endl;
		cin>>v_month;
		v_czyPoprawneDane = f_CzyJestMountUrodzenia( v_month );
	} while (v_czyPoprawneDane == false);

	//cout<< "true: "<< true<<endl;
	//cout<< "false:"<< false<<endl;
	//cout << "v_czyYear:  "<<v_czyYear << endl;
	//cout << "v_czyMount: "<<v_czyMount << endl;

	v_czyPoprawneDane = false;
	do
	{	cin.clear();
		cin.sync();
		cout<<"podaj dzieñ urodzenia" <<endl;
		cin>>v_day;
		v_czyPoprawneDane = f_CzyJestDayUrodzenia( v_day, v_month, v_year);
		//cout << "v_czyDay: "<<v_czyDay << endl;
	} while (v_czyPoprawneDane== false);

	v_czyPoprawneDane = true; //po zrobieniu walidacji zmien na false
	do
	{	cin.clear();
		cin.sync();
		cout<<"Podaj imiê" <<endl;
		cin>>v_name;
		v_czyPoprawneDane = f_CzyPoprawneImie( v_name) ;	//wywolanie funkcji do walidacji imienia czy np. user nie wpisal 1234...
	} while (v_czyPoprawneDane== false);
	v_name = f_ImieInitCap(v_name);							//initcap - niezaleznie od tego co user wpisal.
	v_dzienUrodzin = f_OdgadnijDzienUrodzin(v_day, v_month, v_year);
	v_gender = f_SprawdzPlec(v_name);
	v_zodiac = f_Zodiak(v_day, v_month);

	pFunboy = &Funboy;
	pFunboy->imie=v_name;
	pFunboy->rok_urodzenia=v_year;
	pFunboy->miesiac_urodzenia=v_month;
	pFunboy->dzien_urodzenia=v_day;
	pFunboy->nazwa_dnia_urodzenia=v_dzienUrodzin;
	pFunboy->znak_zodiaku=v_zodiac;
	pFunboy->plec=v_gender;
	pFunboy->horoskop_link=f_HoroskopLink(v_zodiac);
	pFunboy->faza_ksiezyca=f_FazaKsiezycaSlownie(f_Fazaksiezyca(pFunboy->rok_urodzenia, pFunboy->miesiac_urodzenia, pFunboy->dzien_urodzenia));

	cin.clear();
	cin.sync();
	system("cls");
	
	cout << "Czeœæ "<< pFunboy->imie <<". "<<endl;
	cout << "Data Twoich narodzin to: " <<pFunboy->dzien_urodzenia<<"/"<<pFunboy->miesiac_urodzenia<<"/"<<pFunboy->rok_urodzenia<<endl;
	cout << "Dzieñ Twoich urodzin to: " << pFunboy->nazwa_dnia_urodzenia <<endl;
	cout << "Twoja p³eæ to: " <<f_PlecSlownie(pFunboy->plec) << endl;
	cout << "Twój znak zodiaku to: " << pFunboy->znak_zodiaku << endl;
	cout << "W dniu Twoich urodzin by³a nastêpuj¹ca faza ksiê¿yca: " << pFunboy->faza_ksiezyca << endl; 
	cout << "Link do Twojego horoskopu: " << f_HoroskopLink(v_zodiac) << endl;
	cout << "Kliknij dowolny przycisk, ¿eby otworzyæ horoskop w przegl¹darce." << endl;
	getch();
	f_OtworzLinkHoroskop(v_zodiac);

	cout << "Press any key to continue... " <<endl;
	getch();
}

//-------------------------------------------------------------------------------------
void f_Zapisz_do_pliku ()
{
	fstream plik;
	pFunboy = &Funboy;
	plik.open( "zodiak.txt", ios::out | ios::app );
		plik<<pFunboy->imie<<';';
		plik<<pFunboy->rok_urodzenia<<';';
		plik<<pFunboy->miesiac_urodzenia<<';';
		plik<<pFunboy->dzien_urodzenia<<';';
		plik<<pFunboy->nazwa_dnia_urodzenia<<';';
		plik<<pFunboy->znak_zodiaku<<';';
		plik<<pFunboy->plec<<';';
		plik<<pFunboy->faza_ksiezyca<<';';
		plik<<pFunboy->horoskop_link<<endl;
		plik.flush();
	plik.close();
}
//-------------------------------------------------------------------------------------
void f_OdczytPelnejBazy()
{
	fstream plik;
	plik.open("zodiak.txt", ios::in);
	plik.clear();
	plik.seekg (0, ios::beg);
	cout << "Poni¿ej znajduje sie wypis z pe³nej bazy danych." << endl;
	cout << "W kolumnie po œrednikach znajduje siê: imiê, rok, miesi¹c i dzieñ urodzenia, nazwa dnia tygodnia z daty urodzenia, znak zodiaku, p³eæ, faza ksiê¿yca oraz link do horoskopu"<<endl;
	string linia;
	while (getline(plik, linia))
		{
			cout<< linia << endl;
		};
	plik.flush();
	plik.close();
	cout << endl << "Naciœnij dowolny przycisk, ¿eby wróciæ do menu"<< endl;
	getch();
}

int main()
{	//srand(time ( 0 ) );
	setlocale(LC_CTYPE, "Polish");
	Cechy *pFunboy; //deklaracja wskaznika do obiektu
	char v_znak;
	pFunboy = &Funboy;

	do
	{
		cin.clear();
		cin.sync();
		system("cls");
		cout <<"Program Horoskop."<< endl;
		cout <<" "<< endl;
		cout <<"Program stworzony na zaliczenie æwiczeñ z Podstaw Programowania."			<< endl;
		cout <<"Funkcjonalnoœci programu:"													<< endl;
		cout <<"1. Podanie imienia i daty urodzenia"										<< endl;
		cout <<"2. Okreœlenie dnia tygodnia na podstawie daty urodzenia"					<< endl;
		cout <<"3. Zmiana koloru czcionki w zaleznoœci od dnia tygodnia z daty urodzenia"	<< endl;
		cout <<"4. Stworzenie/otwarcie bazy danych"											<< endl;
		cout <<"5. Okreœlenie p³ci na podstawie imienia"									<< endl;
		cout <<"6. Wyznaczenie wieku u¿ytkownika"											<< endl;
		cout <<"7. Rozpoznanie znaku zodiaku"												<< endl;
		cout <<"8. Zwrócenie horoskopu"														<< endl;
		cout <<"9. Wyznaczenie fazy ksiê¿yca w dniu urodzin"								<< endl;
		cout <<"10.Import danych do g³ównej bazy danych"									<< endl;
		cout <<"11.Funkcja zwracajaca pe³n¹ zawartoœæ bazy danych"							<< endl;
		cout <<"12.Agregaty na bazie danych"												<< endl<< endl;
		cout <<"Aby rozpocz¹æ korzystanie z programu wciœnij 1, aby zakoñczyæ dzia³anie programu wciœnij W."<< endl << endl;
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
		cout << "1. Okreœlenie dnia tygodnia z daty urodzenia	"	<< endl;
		cout << "   Okreœlenie p³ci na podstawie imienia		"	<< endl;
		cout << "   Wyznaczenie wieku u¿ytkownika				"	<< endl;
		cout << "   Rozpoznanie znaku zodiaku					"	<< endl;
		cout << "   Wyswietl horoskop							"	<< endl;
		cout << "   Wyznaczenie fazy ksiê¿yca w dniu urodzin	"	<< endl;
		cout << "2. Wyswietl historiê							"	<< endl;
		cout << "3. Dodaj dane z pliku							"	<< endl;
		cout << "4. Poka¿ agregaty								"	<< endl;
		cout << "W. Wyjœcie z programu							"	<< endl;
		cout<<"Wybieram : ";

		v_znak = getchar();
		switch (v_znak)
		{
			case '1':
				f_PodajDane();
				f_Zapisz_do_pliku();

				cin.clear();
				cin.sync();
				system("cls");
				//
					cout<<pFunboy->imie<< endl;
					cout<<pFunboy->rok_urodzenia<< endl;
					cout<<pFunboy->miesiac_urodzenia<< endl;
					cout<<pFunboy->dzien_urodzenia<< endl;
					cout<<pFunboy->nazwa_dnia_urodzenia<< endl;
					cout<<pFunboy->znak_zodiaku<< endl;
					cout<<pFunboy->plec<< endl;
					cout<<pFunboy->horoskop_link<< endl;
				//
				getch();
				break;
			case '2':
				f_OdczytPelnejBazy();
				break;
			case '3':
				//Dodaj dane z pliku
				break;
			case '4':
				//Wyswietl agregaty
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

