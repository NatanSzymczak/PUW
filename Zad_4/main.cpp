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
#include <cmath>

using namespace std;

const int n = 30; //ilosc elementow w tablicy
int liczby[n];

class Sortowanie{
public:
    void czytaj_dane();
    void babelkowe();
    void quicksort(int [],int,int);
    void przetworz_dane();
    void wyswietl_wynik();
};

void Sortowanie::czytaj_dane()
{
    int i;


    cout << "Liczby nieposortowane: " << endl;
    for (i = 0; i < n; i++)
    {
        liczby[i] =  rand() %1000;
        cout << liczby[i] << " ";
    }
    cout << endl;
}

void Sortowanie::babelkowe()
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

    cout << endl << "Sortowanie Babelkowe" << endl;

}

void Sortowanie::quicksort( int liczby[], int left, int right )
{
    int i = left;
    int j = right;
    int x = liczby[( left + right ) / 2 ];

    do
    {
        while( liczby[ i ] < x )
             i++;

        while( liczby[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( liczby[ i ], liczby[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) quicksort( liczby, left, j );

    if( right > i ) quicksort( liczby, i, right );

    if(i==1)
        cout << endl << "Sortowanie Szybkie" << endl;

}

void Sortowanie::przetworz_dane()
{
    char wybor = ' ';

    cout << "Dokonaj wyboru rodzaju algorytmu sortowania: " << endl;
    cout << "Babelkowe 1" << endl;
    cout << "quicksort 2" << endl;
    cout << "Twoj wybor: ";
    cin  >> wybor;

    switch (wybor)
    {
        case '1':
            babelkowe();
        break;

        case '2':
            quicksort(liczby,0,n);
        break;

        default:
            babelkowe();
        break;

    }

    cout << "-----------------------------------------------" << endl;
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

void czekaj_na_klawisz()
{
    cout << "Nacisnij enter by zakonczyc: ";
    cin.ignore();
    cin.get();
}

int main()
{
    Sortowanie obj;

    obj.czytaj_dane();
    obj.przetworz_dane();
    obj.wyswietl_wynik();

    czekaj_na_klawisz();

    return 0;
}
