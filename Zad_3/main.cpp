/***************************************************************
 * Name:      Zad_3 (6.3) _Przerobione_Ver1
 * File:      main.cpp
 * Purpose:   Code for school
 * Author:    Damian Michalak-Szmacińśki ()
 * Created:   2018-11-28
 * Copyright: Damian Michalak-Szmaciński ()
 * License: MIT License
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <curses.h>//conio for windows//linux install lib:/rpm ncurses-devel ncurses/deb: libncurses5-dev libncursesw5-dev/

using namespace std;

const int rozmiar = 10;

class Matrix{
public:
    void czytaj_dane(int macierz[rozmiar][rozmiar], int rozmiar);
    void przetworz_dane(int macierz[rozmiar][rozmiar], int rozmiar);
    void suma_nizej_przek(int tablica[rozmiar][rozmiar], int rozmiar);
    void suma_wyzej_przek(int tablica[rozmiar][rozmiar], int rozmiar);
    void suma_elementow(int tablica[rozmiar][rozmiar], int rozmiar);
    void wyswietl_wynik(int macierz[rozmiar][rozmiar], int rozmiar);
};

void Matrix::czytaj_dane(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i,j,t =1;

    //randomize(); //Orginalnie prawdopodobnie dla windows
    for (i = 0; i < rozmiar; i++)
    {
        for (j = 0; j < rozmiar; j++)
        {

            if (i == j) tablica[i][j] = rand() %10; //warunek dla przekontnej
            else tablica[i][j] = rand() %10; //pozostale // rand() %10 == random(10)

            for (t=1; t < rozmiar; t++) // pętla i warunka dla poniżej przkatnej
                if (i-t == j) tablica[i][j] = rand() %10;

            for (t=1; t < rozmiar; t++) // pętla i warunka dla powyrzej przkatnej
                if (i+t == j) tablica[i][j] = rand() %10;

        }

    }

}

void Matrix::suma_nizej_przek(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i, j, t, suma = 0;

    for (i = 0; i < rozmiar; i++)
        for (j = 0; j < rozmiar; j++)
            for (t=1; t < rozmiar; t++)
            {
                if (i == j)     suma = suma;
                if (i-t == j && i != j)   suma = suma+tablica[i][j];
            }

        cout << "Suma elementow nizej przekatnej wynosi: " << suma << endl;

}

void Matrix::suma_wyzej_przek(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i, j, t, suma = 0;

    for (i = 0; i < rozmiar; i++)
        for (j = 0; j < rozmiar; j++)
            for (t=1; t < rozmiar; t++)
                if (i+t == j && i !=j)
                  suma = suma+tablica[i][j];

        cout << "Suma elementow wyzej przekatnej wynosi: " << suma << endl;

}

void Matrix::suma_elementow(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i, j, t, suma = 0;

    for (i = 0; i < rozmiar; i++)
        for (j = 0; j < rozmiar; j++)
                  suma = suma+tablica[i][j];

        cout << "Suma wszystkich elementow wynosi: " << suma << endl;

}

void Matrix::przetworz_dane(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i, suma = 0;

    for (i = 0; i < rozmiar; i++)
    {
        suma = suma+tablica[i][i];
    }

    cout << "Suma elementow na przekatnej wynosi " << suma << endl;
}

void Matrix::wyswietl_wynik(int tablica[rozmiar][rozmiar], int rozmiar)
{
    int i,j;

    cout << endl;
    cout << "Zawartosc tablicy:" << endl;
    cout << endl;

    for (i = 0; i < rozmiar; i++)
    {
        for (j = 0; j < rozmiar; j++)
        {
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int tablica[rozmiar][rozmiar];
    Matrix obj;

    obj.czytaj_dane(tablica,rozmiar);
    obj.przetworz_dane(tablica,rozmiar);
    obj.wyswietl_wynik(tablica,rozmiar);

    cout << endl;

    obj.suma_nizej_przek(tablica,rozmiar);
    obj.suma_wyzej_przek(tablica,rozmiar);
    obj.suma_elementow(tablica,rozmiar);


    getchar(); // getch();
    return 0;
}
