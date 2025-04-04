#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

//ersetzt std::cout -> cout
using namespace std;
int umwandlung;
//alternativ auch char[] name
string month;
string day;
string date;
string jahresMonat[12] = { "Januar","Februar","März","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember" };
string eingabe;
#define leer cout << "\n";


int main()
{
    bool monatsausgabe(const string & month, const string jahresMonat[]);
    bool tagesausgabe(int day);
    void fehlermeldung();
    void dateiErstellen();

    do {
        cout << "***Datumsausgabe***";
        leer;
        cout << "Bitte geben Sie das Jahr ein: ";
        getline(cin, date);
        leer;
        cout << "Bitte geben Sie den Monat ein: ";
        getline(cin, month);
            //Funktion wird direkt in der If Abfrage aufgerufen und gleichzeitig auf true oder false ggeprüft!
            if (!monatsausgabe(month, jahresMonat))
            {  
                fehlermeldung();
                return 0;
	        }
        leer;
        cout << "Bitte geben Sie den Tag ein: ";
        getline(cin, day);
        int intday=stoi(day);
            if (!tagesausgabe(intday))
            {
                fehlermeldung(); 
                return 0;
            }
        cout << " year: " + date + " month: " + month + " day: " + day;
        leer;
        //eingabe wird als txt.file gespeichert.
        dateiErstellen();
        cout <<"Sollen weitere Eingaben erfolgen? (j/n) \n";
        getline(cin, eingabe);  
            if (eingabe == "j")
            {
                continue;
            }
            if (eingabe == "n" || eingabe != "j")
            {
                break;
            }
    } while (eingabe =="j");
    return 0;
}



bool monatsausgabe(const string& month,const string jahresMonat[])
{
   
    for (int i = 0; i <= 11; i++)                                                                                                                                                                                   // string& = Referenz auf einen String, der nicht kopiert wird.
	{                                                                                                                                                                                                               // const string = Referenz auf einen konstanten String, der nicht verändert werden kann.
        if (month == jahresMonat[i])                                                                                                                                                                                // i <= 11 = 12 Monate
        {   
            return true;
		}
        else if (i == 11 && month != jahresMonat[i])                              
        {
            
			return false;
		}
       
    }
    return false;
}
bool tagesausgabe(int day)
{
    if (day > 31 || day < 1)
    {
        return false;
	}
    else
    {
		return true;
	}
}
void fehlermeldung()
{
    cout << "\a";
    cout << "Fehlerhafte Eingabe!";
    return;
}
void dateiErstellen()
{
    // Ausgabe in eine Datei
    //Du brauchst ostream_iterator hier nicht, weil du nur einen String schreiben willst – kein Array von Strings.
    // output_file << ... ist in C++ der Standardweg, um Dateien mit einfachem Text zu füllen.
    //ios:app sorgt dafür, dass neue Inhalte hinten an die Datei angehängt werden.
    ofstream output_file("output.txt",ios::app);

    if (!output_file) {
        cout << "Fehler beim Erstellen der Datei!" << endl;
        return;
    }

    output_file << "Datum: " << day << ". " << month << " " << date << endl;

    output_file.close(); // Gute Praxis
    return;
    }
