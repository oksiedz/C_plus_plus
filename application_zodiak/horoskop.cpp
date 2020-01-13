#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h> 
#include <sstream>

using namespace std;	

//-------------------------------------------------------------------------------------
bool f_CzyJestYearUrodzenia ( int v_year  )
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
		{ 	cout<< "Podales niewlasciwy rok urodzenia. Sprobuj jeszcze raz" << endl;
			cout << "Podany rok to: " << v_year<< endl;
			cout << "dlugosc liczby:" <<vl_length<< endl;
			getch();
			return false;
		}
	else if (v_year == st.wYear ) //jesli podany rok jest rowny biezacemu
		{ 	cout<< "Jetes za mlody na korzystanie z komputera." << endl;
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
int vl_length = 0;	
string vl_tab_31="01,03,05,07,08,10,12";
string vl_tab_30="04,06,09,11";
string vl_tab_28="02";
string vl_day;
stringstream vl_ss;
	cin.clear();
	cin.sync();	
		
	//zamiana int-a na string
	vl_ss << v_day;
    vl_day=vl_ss.str();
	vl_length=vl_day.length();

	if (vl_length<2 || vl_length>2)
		{ 	cout<< "Podales niewlasciwa wartosc. Sprobuj jeszcze raz" << endl;
			getch();
			return false;
		}
	// jesli miesiac ma 31 dni
	size_t znalezionaPozycja = vl_tab_31.find( v_mount );
	if( znalezionaPozycja != std::string::npos && (v_day>0 && v_day<32))
	        return true;
    else 
    		return false;
	// jesli miesiac ma 30 dni    
	znalezionaPozycja = vl_tab_30.find( v_mount );
	if( znalezionaPozycja != std::string::npos && (v_day>0 && v_day<31))
	        return true;
    else 
    		return false;
	// jesli miesiac to luty    		
	znalezionaPozycja = vl_tab_28.find( v_mount );
	if( znalezionaPozycja != std::string::npos && (v_day>0 && v_day<31))
	        return true;
    else 
    		return false;
				
	znalezionaPozycja = vl_tab_31.find( v_day );
	if( znalezionaPozycja != std::string::npos )
	         return true;
    else if (size_t znalezionaPozycja = vl_tab_30.find( v_day ))
			return true;
    else if (size_t znalezionaPozycja = vl_tab_28.find( v_day ))
		    return true;

	return true;
}

//-------------------------------------------------------------------------------------
int f_OkreslenieDniaTygodnia ()
{
	int v_day, v_mount, v_year;
	bool v_czyYear = false, v_czyMount = false,v_czyDay = false;
	do
	{ 	cin.clear();
		cin.sync();			
		system("cls");
		cout<<"podaj rok urodzenia" <<endl;
		cin>>v_year;
		v_czyYear = f_CzyJestYearUrodzenia( v_year ) ;		
	} while (v_czyYear == false);
	
	do
	{ 	cin.clear();
		cin.sync();			
		cout<<"podaj miesiac urodzenia" <<endl;
		cin>>v_mount;
		v_czyMount = f_CzyJestMountUrodzenia( v_mount ) ;			
	} while (v_czyMount == false);
	
	do
	{ 	cin.clear();
		cin.sync();			
		cout<<"podaj dzien urodzenia" <<endl;
		cin>>v_day;
		v_czyDay = f_CzyJestDayUrodzenia( v_day, v_mount, v_year) ;	
	} while (v_czyDay== false);
}

int main()
{

	//srand(time ( 0 ) );
	char v_znak;
    do 
	{	
		cin.clear();
		cin.sync();			
		system("cls");
		cout <<"Program Horoskop."															<< endl;
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
		cout <<"12.Aggregaty na bazie danych"												<< endl;
		cout <<" "<< endl;
		cout <<" "<< endl;
		cout <<"Aby rozpoczac korzystanie z programu wcisnij 1, aby zakonczyc dzialanie programu wcisnij W."<< endl;
		cout <<" "<< endl;
		cout <<" "<< endl;
		cout<<"Dokonaj wyboru : ";
	    
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
		cout << "1. okreslenie dnia tygodnia z daty urodzenia	"	<< endl;
		cout << "2. okreslenia plci na podstawie imienia		"	<< endl;
		cout << "3. Wyznaczenie wieku uzytkownika				"	<< endl;
		cout << "4. rozpoznanie znaku zodiaku					"	<< endl;
		cout << "5. wyswietl horoskop							"	<< endl;
		cout << "6. Wyznaczenie fazy ksiezyca w dniu urodzin	"	<< endl;
		cout << "7. wyswietl historie							"	<< endl;
		cout << "8. dodaj dane z pliku							"	<< endl;
		cout << "9. poka¿ agregaty								"	<< endl;
		cout << "W. wyjscie z programu							" << endl;
		cout<<"Wybieram : ";
	    
	    v_znak = getchar();
	    switch (v_znak)
	    {
	       	case '1':
	            f_OkreslenieDniaTygodnia();
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
















