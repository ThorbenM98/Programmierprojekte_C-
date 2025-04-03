#include <iostream>
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
#define leer cout << "\n";


int main() {
    bool monatsausgabe(const string & month, const string jahresMonat[]);
    bool tagesausgabe(int day);
    void fehlermeldung();

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
