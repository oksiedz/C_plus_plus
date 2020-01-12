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
bool f_CzyJestData ( string t_data )
{
char szukanyZnak = '/';
int licznikZnaku1 =0, licznikZnaku2 =0, licznik=0, pozycjaZnaku1 =2, pozycjaZnaku2=5, pozycja =0 ;
string t_day, t_month, t_year;
int v_day, v_month, v_year;
char * napis;

	if (t_data.length()<10)
		{ 	cout<< "Podales zbyt krotka date. Sprobuj jeszcze raz" << endl;
			getch();
			return false;
		}
	else if (t_data.length()>10)
		{ 	cout<< "Podales zbyt dluga date. Sprobuj jeszcze raz" << endl;
			getch();
			return false;
		}		
	
	for (pozycja =0; pozycja<t_data.length(); ++pozycja)
	{ 	if (t_data[pozycja]=='/')
			{	licznik++;
				if (licznik == 1)
					{licznikZnaku1 =pozycja;
					}
				if (licznik == 2)
					{licznikZnaku2 =pozycja;
					}
			}
	}	
	t_day 	= t_data.substr(0,licznikZnaku1);
	t_month = t_data.substr(licznikZnaku1+1,licznikZnaku2-licznikZnaku1-1);
	t_year 	= t_data.substr(licznikZnaku2+1);
	cout << t_day<<endl;
	cout << t_month<<endl;
	cout << t_year<<endl;
	//napis = std::atoi(t_day);
	//v_day = std::atoi(napis);
	
	
	if( licznik != 2 )
	{	cout<< "Nie podales wlasciwego formatu daty" << endl;
		getch();
		return false;
	}


}

int f_OkreslenieDniaTygodnia ()
{
	string t_data;
	bool v_czyData = false;
	do
	{ 	system("cls");
		cin.clear();
		cout<<"podaj date urodzenia w formacie dd/mm/yyyy: \n";
		cin>>t_data;
		v_czyData = f_CzyJestData( t_data ) ;
	} while (v_czyData == false );
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
		cout <<"*************** MENU ***************"			<< endl;
		cout << "1. okreœlenie dnia tygodnia z daty urodzenia	"	<< endl;
		cout << "2. okreœlenia p³ci na podstawie imienia		"	<< endl;
		cout << "3. Wyznaczenie wieku u¿ytkownika				"	<< endl;
		cout << "4. rozpoznanie znaku zodiaku					"	<< endl;
		cout << "5. wyœwietl horoskop							"	<< endl;
		cout << "6. Wyznaczenie fazy ksiê¿yca w dniu urodzin	"	<< endl;
		cout << "7. wyswietl historie							"	<< endl;
		cout << "8. dodaj dane z pliku							"	<< endl;
		cout << "9. poka¿ agregaty								"	<< endl;
		cout << "W. wyjscie z programu" 				<< endl;
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

















