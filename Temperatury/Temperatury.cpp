#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
#include <windows.h>
using namespace std;

int DataCounter = 0;
double pamiec[100] = { 0 };
char temp[100];

int check(float temp, char stopnie) {
    if (temp < 0 && stopnie == 'K') {
        cout << "Nie ma takiej temperatury.\n";
        cin.ignore();
        cout << "\n\nNacisnij ENTER, aby kontynuowac.";
        if (cin.get() == '\n') {
            system("cls");
        }
        return -999.0;
    }
    else if (temp < -273.15 && stopnie == 'C') {
        cout << "Nie ma takiej temperatury.\n";
        cin.ignore();
        cout << "\n\nNacisnij ENTER, aby kontynuowac.";
        if (cin.get() == '\n') {
            system("cls");
        }
        return -999.0;
    }
    else if (temp < -459.67 && stopnie == 'F') {
        cout << "Nie ma takiej temperatury.\n";
        cin.ignore();
        cout << "\n\nNacisnij ENTER, aby kontynuowac.";
        if (cin.get() == '\n') {
            system("cls");
        }
        //nie działa ale nie mam już pomysłów po 2 godzinach jak to naprawić, I am sick and tired..
        return -999.0;
    }
    else {
        return NULL;
    }
}

float PobierzF() {
    float F;
    cout << "Podaj stopnie Farenheita: ";
    cin >> F;
    cout << check(F, 'F');
    return F;
}
float PobierzC() {
    float C;
    cout << "Podaj stopnie Celsjusza: ";
    cin >> C;
    cout << check(C, 'C');
    return C;
}
float PobierzK() {
    float K;
    cout << "Podaj stopnie Kelvina: ";
    cin >> K;
    cout << check(K, 'K');
    return K;
}


float FtoC(float stopnie) { 
    stopnie = PobierzF();
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);

    //wpisywanie do tablic
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'F';
    temp[DataCounter + 1] = 'C';

    DataCounter += 2;

    cout << stopnie << " stopni Farenheita to ";
    return wynik;
}
float FtoK(float stopnie) { 
    stopnie = PobierzF();
    float wynik = (stopnie + 459.67) * (5.0/9.0);
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'F';
    temp[DataCounter + 1] = 'K';

    DataCounter += 2;

    cout << stopnie << " stopni Farenheita to ";
    return wynik;
}
float CtoF(float stopnie) { 
    stopnie = PobierzC();
    float wynik = stopnie * 9.0 / 5.0 + 32.0;
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'C';
    temp[DataCounter + 1] = 'F';

    DataCounter += 2;

    cout << stopnie << " stopni Celsjusza to ";
    return wynik;
}
float CtoK(float stopnie) { 
    stopnie = PobierzC();
    float wynik = stopnie + 273.15;
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'C';
    temp[DataCounter + 1] = 'K';

    DataCounter += 2;

    cout << stopnie << " stopni Celsjusza to ";
    return wynik;
}
float KtoC(float stopnie) { 
    stopnie = PobierzK();
    float wynik = stopnie - 273.15;
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'K';
    temp[DataCounter + 1] = 'C';

    DataCounter += 2;

    cout << stopnie << " stopni Kelvina to ";
    return wynik;
}
float KtoF(float stopnie) {
    stopnie = PobierzK();
    float wynik = stopnie * 9.0/5.0 - 459.67;
    pamiec[DataCounter] = stopnie;
    pamiec[DataCounter + 1] = wynik;
    
    temp[DataCounter] = 'K';
    temp[DataCounter + 1] = 'F';

    DataCounter += 2;

    cout << stopnie << " stopni Kelvina to ";
    return wynik;
}

void menu() {
    cout << "1. przelicz Fahr-> Celsius\n";
    cout << "2. przelicz Fahr-> Kelwin\n";
    cout << "3. przelicz Celsius-> Fahr\n";
    cout << "4. przelicz Celsius-> Kelwin\n";
    cout << "5. przelicz Kelwin-> Celsius\n";
    cout << "6. przelicz Kelwin-> Fahr\n";
    cout << "7. pokaz historie\n";
    cout << "8. zakoncz dzialanie programu\n";
}
int main() {
    while (true) {
        int wybor;
        int licznik = 0;
        menu();
        cin >> wybor;

        switch (wybor) {
        case 1:
            cout << FtoC(0) << " stopni Celsjusza.";
            break;
        case 2:
            cout << FtoK(0) << " stopni Kelvina.";
            break;
        case 3:
            cout << CtoF(0) << " stopni Farenheita.";
            break;
        case 4:
            cout << CtoK(0) << " stopni Kelvina.";
            break;
        case 5:
            cout << KtoC(0) << " stopni Celsjusza.";
            break;
        case 6:
            cout << KtoF(0) << " stopni Farenheita.";
            break;
        case 7:
            for (int i = 0; i < (DataCounter / 2); i++) {
                cout << i + 1 << ". " << pamiec[licznik] << temp[licznik] << " = " << pamiec[licznik + 1] << temp[licznik + 1] << endl;
                licznik += 2;
            }
            break;
        default:
            return 0;
        }
        cin.ignore();
        cout << "\n\nNacisnij ENTER, aby kontynuowac.";
        if (cin.get() == '\n') {
            system("cls");
        }
    }

    return 0;
}
