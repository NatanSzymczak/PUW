/***************************************************************
 * Name:      Zad_4 (6.4)
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

const int n = 6;
int liczby[n];

class Sortowanie{
public:
    void czytaj_dane();
    float przetworz_dane();
    void wyswietl_wynik();
};

void Sortowanie::czytaj_dane()
{
    int i;

    liczby[0] =  574;
    liczby[1] =  303;
    liczby[2] = -134;
    liczby[3] =  125;
    liczby[4] =   80;
    liczby[5] =  236;

    cout << "Liczby nieposortowane: " << endl;
    for (i = 0; i < n; i++)
    {
      cout << liczby[i] << " ";
    }
    cout << endl;
}

float Sortowanie::przetworz_dane()
{
    int i, j, x;

    for ( i = 1; i <= n-1; i++ )
    {
      for ( j = n-1; j >= i; j--)
      {
        if (liczby[j-1] > liczby[j])
        {
          x = liczby[j-1];
          liczby[j-1] = liczby[j];
          liczby[j] = x;
        }
      }
    }
}

void Sortowanie::wyswietl_wynik()
{
    int i;

    cout << endl;
    cout << "Liczny posortowane: " << endl;

    for ( i = 0; i < n; i++)
    {
      cout << liczby[i] << " ";
    }
    cout << endl;
}


int main()
{
    Sortowanie obj;

    obj.czytaj_dane();
    obj.przetworz_dane();
    obj.wyswietl_wynik();

    getchar(); // getch();
    return 0;
}
