#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);

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
    cout << stopnie << " stopni Farenheita to ";
    return wynik;
}
float FtoK(float stopnie) { 
    stopnie = PobierzF();
    float wynik = (stopnie + 459.67) * (5.0/9.0);
    cout << stopnie << " stopni Farenheita to ";
    return wynik;
}
float CtoF(float stopnie) { 
    stopnie = PobierzC();
    float wynik = stopnie * 9.0 / 5.0 + 32.0;
    cout << stopnie << " stopni Celsjusza to ";
    return wynik;
}
float CtoK(float stopnie) { 
    stopnie = PobierzC();
    float wynik = stopnie + 273.15;
    cout << stopnie << " stopni Celsjusza to ";
    return wynik;
}
float KtoC(float stopnie) { 
    stopnie = PobierzK();
    float wynik = stopnie - 273.15;
    cout << stopnie << " stopni Kelvina to ";
    return wynik;
}
float KtoF(float stopnie) {
    stopnie = PobierzK();
    float wynik = stopnie * 9.0/5.0 - 459.67;
    cout << stopnie << " stopni Kelvina to ";
    return wynik;
}

void menu() {
    cout << " 1- przelicz Fahr-> Celsius\n";
    cout << " 2- przelicz Fahr-> Kelwin\n";
    cout << " 3- przelicz Celsius-> Fahr\n";
    cout << " 4- przelicz Celsius-> Kelwin\n";
    cout << " 5- przelicz Kelwin-> Celsius\n";
    cout << " 6- przelicz Kelwin-> Fahr\n";
    cout << " 7- zakoncz dzialanie programu\n";
}
int main() {
    while (true) {
        int wybor;

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
