/***************************************************************
 * Name:      Zad_1 (6.2)
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
    float a, b,c , delta, x1, x2, wartX, wartFunc;
    char liczba_pierwiastkow, wybor;

    void czytaj_dane();
    void przetworz_dane();
    void wyz_pierwiastki();
    void wyz_delte();
    void wyz_wartosc();
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

    cout << setprecision(1) << "Twoja funkcja: " << "f(x)= ";
    cout <<  a << "x^2 + ";
    cout << b << "x + " << c << endl;
}

void Trojmian::wyz_delte()
{
    delta = b*b-(4*a*c);
}

void Trojmian::wyz_wartosc()
{
    cout << "Podaj wartosc x: ";
    cin  >> wartX;

    wartFunc = a*pow(wartX,2)+(b*wartX)+c;
}

void Trojmian::wyz_pierwiastki()
{
    wyz_delte();

    if (delta <  0)  liczba_pierwiastkow = '0';
    if (delta >  0)  liczba_pierwiastkow = '2';
    if (delta == 0) liczba_pierwiastkow = '1';

    switch(liczba_pierwiastkow)
    {
    case '1':
        x1 = -b/(2*a);
        break;
    case '2':
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);
        break;
    }
}

void Trojmian::przetworz_dane()
{
    cout << "Wybierz co chcesz dokonać:" << endl;
    cout << "---------------------" << endl;
    cout << "Wyznacz Pierwiastki 1" << endl;
    cout << "Wyznacz Pierwiastki 2" << endl;
    cout << "Wyznacz Pierwiastki 3" << endl;
    cout << "---------------------" << endl;
    cout << "Twoj wybór (domyślnie 1):";
    cin  >> wybor;

    switch (wybor)
    {
        case '1':
            wyz_pierwiastki();
        break;

        case '2':
            wyz_delte();
        break;

        case '3':
            wyz_wartosc();
        break;

        default:
            wyz_pierwiastki();
        break;
    }
}

void Trojmian::wyswietl_wynik()
{
    cout << "Dla wprowadzonych liczb:" << endl;
    cout << "a = " << a << "." << endl;
    cout << "b = " << b << "." << endl;
    cout << "c = " << c << "." << endl;

    switch(wybor)
    {
        case '1':
            if (liczba_pierwiastkow == '0') cout << "brak pierwiastkow rzeczywistych." << endl;
            if (liczba_pierwiastkow == '1') cout << "trojmian ma jeden pierwiastek podwojny x1 = " << x1 << endl;
            if (liczba_pierwiastkow == '2')
            {
                cout << "trojmian ma dwa pierwiastki:" << endl;
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
        break;

        case '2':
            cout << "Delta wynosi: " << delta;
        break;

        case '3':
            cout << "Wartośc funkcji dla F(" << wartX << ") = " << wartFunc;
        break;

        default:
            if (liczba_pierwiastkow == '0') cout << "brak pierwiastkow rzeczywistych." << endl;
            if (liczba_pierwiastkow == '1') cout << "trojmian ma jeden pierwiastek podwojny x1 = " << x1 << endl;
            if (liczba_pierwiastkow == '2')
            {
                cout << "trojmian ma dwa pierwiastki:" << endl;
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
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
