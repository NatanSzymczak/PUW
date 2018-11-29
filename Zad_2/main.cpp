/***************************************************************
 * Name:      Zad_1 (6.1)
 * File:      main.cpp
 * Purpose:   Code for school
 * Author:    Damian Michalak-Szmacińśki ()
 * Created:   2018-11-28
 * Copyright: Damian Michalak-Szmaciński ()
 * License: MIT License
 **************************************************************/

#include <iostream>
#include <iomanip>
#include <curses.h>//conio for windows//linux install lib:/rpm ncurses-devel ncurses/deb: libncurses5-dev libncursesw5-dev/
#include <math.h> // dla sqrt() w linux napewno niewiem jak w windows

using namespace std;

class Trojmian{
public:
    float a, b,c , delta, x1, x2;
    char liczba_pierwiastkow;

    void czytaj_dane();
    float przetworz_dane();
    void wyswietl_wynik();
};

void Trojmian::czytaj_dane()
{
    cout << "Program oblicza pierwiastki rownania kwadratowego" << endl;
    cout << "dla dowolnych wspolczynnikow a. b. c." << endl;
    cout << "Podaj a: ";
    cin  >> a;

    if (a == 0)
    {
        cout << "Niedozwolona wartosc wpolczynika. Nacisnij dowolny klawisz" << endl;
        getchar();
        exit(1);
    }
    else
    {
        cout << "Podaj b: ";
        cin  >> b;
        cout << "Podaj c: ";
        cin  >> c;
    }
}

float Trojmian::przetworz_dane()
{
    delta = b*b-(4*a*c);

    if (delta < 0)  liczba_pierwiastkow = '0';
    if (delta > 0)  liczba_pierwiastkow = '2';
    if (delta == 0) liczba_pierwiastkow = '1';

    switch(liczba_pierwiastkow)
    {
    case '1':
        x1 = -b/(2*a);
        break;
    case '2':
        x1 = (-b-sqrt(delta))/(2*a);
        break;
    }
}

void Trojmian::wyswietl_wynik()
{
    cout << "Dla wprowadzonych liczb:" << endl;
    cout << "a = " << a << "." << endl;
    cout << "b = " << b << "." << endl;
    cout << "c = " << c << "." << endl;

    switch(liczba_pierwiastkow)
    {
        case '0':
            cout << "brak pierwiastkow rzeczywistych." << endl;
        break;

        case '1':
            cout << "trojmian ma jeden pierwiastek podwojny x1 = " << x1 << endl;
        break;

        case '2':
            cout << "trojmian ma dwa pierwiastki:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        break;
    }
}


int main()
{
    Trojmian obj;

    cout << fixed << setprecision(2);

    obj.czytaj_dane();
    obj.przetworz_dane();
    obj.wyswietl_wynik();

    getchar(); // getch();
    return 0;
}
