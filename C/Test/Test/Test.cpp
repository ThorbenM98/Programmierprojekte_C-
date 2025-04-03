#include <iostream>
#include <string>

//ersetzt std::cout -> cout
using namespace std;
int date;
int day;
string month;

int main() {
    
    //alternativ auch char[] name
    string month = "April";
    int day = 3;
    int date = 2025;
    cout <<"year: " + to_string(date) + " month: " + month +" day: " + to_string(day);

    return 0;
}


