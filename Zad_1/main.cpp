/***************************************************************
 * Name:      Zad_1 (6.1) _Przerobione_Ver1
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

class Pole_czworokata{
public:
    float a, b, h, pole;

    virtual void czytaj_dane()=0;
    virtual float przetworz_dane()=0;
    virtual void wyswietl_wynik()=0;
};

class Kwadrat : public Pole_czworokata{

    void czytaj_dane()
    {
        cout << "Program oblicza pole kwadratu" << endl;
        cout << "Podaj bok a: ";
        cin  >> a;
    }

    float przetworz_dane()
    {
        pole = a*a;
    }

    void wyswietl_wynik()
    {
        cout << fixed;
        cout << setprecision(2);
        cout << "------------------------------" << endl;
        cout << "Pole kwadratu o boku a = " << a << endl;
        cout << "Wynosi " << pole << "." <<endl;
    }

};

class Prostokat : public Pole_czworokata{

    void czytaj_dane()
    {
        cout << "Program oblicza pole prostokąta" << endl;
        cout << "Podaj bok a: ";
        cin  >> a;
        cout << "Podaj bok b: ";
        cin  >> b;
    }

    float przetworz_dane()
    {
        pole = a*b;
    }

    void wyswietl_wynik()
    {
        cout << fixed;
        cout << setprecision(2);
        cout << "------------------------------" << endl;
        cout << "Pole kwadratu o boku a = " << a << endl;
        cout << "i o boku b = " << b << endl;
        cout << "Wynosi " << pole << "." <<endl;
    }

};

class Trapez : public Pole_czworokata{

    void czytaj_dane()
    {
        cout << "Program oblicza pole trapezu" << endl;
        cout << "Podaj podstawe a: ";
        cin  >> a;
        cout << "Podaj podstawe b: ";
        cin  >> b;
        cout << "Podaj wyskosc h: ";
        cin  >> h;
    }

    float przetworz_dane()
    {
        pole = (a+b)*h*0.5; // Srpawdzic poprawnosc wzoru
    }

    void wyswietl_wynik()
    {
        cout << fixed;
        cout << setprecision(2);
        cout << "------------------------------" << endl;
        cout << "Pole Trapezu o podstawie a = " << endl;
        cout << a << "i o postawie b = " << b << endl;
        cout << a << "oraz o wyskosci h = " << h << endl;
        cout << "Wynosi " << pole << "." <<endl;
    }

};

void oblicz_pole_dla_czworokata()
{
    char wybor = ' ';

    cout << "Wybierz dla jakiej figury chcesz obliczyc pole:" << endl;
    cout << "Kwadrat    1" << endl;
    cout << "Prostokat  2" << endl;
    cout << "Trapez     3" << endl;
    cout << "Twoj wybor (domyslnie kwadrat): ";
    cin  >> wybor;

    Kwadrat             kwadrat;
    Prostokat           prostokat;
    Trapez              trapez;
    Pole_czworokata    *wsk_pole = 0;

    switch (wybor)
    {
        case '1':
            wsk_pole = &kwadrat;
        break;

        case '2':
            wsk_pole = &prostokat;
        break;

        case '3':
            wsk_pole = &trapez;
        break;

        default:
            cout << "Niedokonano wlasciwego wyboru obliczam domyslnie" << endl;
            wsk_pole = &kwadrat;
        break;
    }

    wsk_pole->czytaj_dane();
    wsk_pole->przetworz_dane();
    wsk_pole->wyswietl_wynik();

}

void czekaj_na_klawisz()
{
    cout << "Nacisnij enter by zakonczyc: ";
    cin.ignore();
    cin.get();
}

int main()
{
    oblicz_pole_dla_czworokata();

    czekaj_na_klawisz(); // getch();
    return 0;
}
