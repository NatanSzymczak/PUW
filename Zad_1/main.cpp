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

using namespace std;

class Pole_prostokata{
public:
    float a, b, pole;

    void czytaj_dane();
    float przetworz_dane();
    void wyswietl_wynik();
};

void Pole_prostokata::czytaj_dane()
{
    cout << "Program oblicza pole prostokąta" << endl;
    cout << "Podaj bok a: ";
    cin  >> a;
    cout << "Podaj bok b: ";
    cin  >> b;
}

float Pole_prostokata::przetworz_dane()
{
    pole = a*b;
}

void Pole_prostokata::wyswietl_wynik()
{
    cout << "Pole prostokąta o boku a = " << endl;
    cout << fixed;
    cout << setprecision(2);
    cout << a << "i o boku b = " << endl;
    cout << " wynosi " << pole << "." <<endl;
}


int main()
{
    Pole_prostokata pole;

    pole.czytaj_dane();
    pole.przetworz_dane();
    pole.wyswietl_wynik();

    getchar(); // getch();
    return 0;
}
