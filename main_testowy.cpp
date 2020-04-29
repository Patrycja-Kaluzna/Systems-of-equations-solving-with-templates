#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"
#include "rozmiar.h"
#include "LZespolona.hh"

#include <iostream>

using namespace std;

int main ()
{
    cout << "TEST SZABLONU KLASY SUKLADROWNANLINIOWYCH <double, " << ROZMIAR << ">:" << endl;
    SUkladRownanLiniowych <double, ROZMIAR> URLd;
    int r, i;

    cout << "Test wczytywania i wyświetlania ukladu rownan liniowych:" << endl;
    cin >> URLd;
    cout << URLd << endl;

    cout << "Test rozwiązywania ukladu rownan liniowych z " << ROZMIAR << " niewiadomymi:" << endl;
    r = URLd.rozwiaz();
    if (r == 0)
    {
        cout << "Wektor rozwiązania:" << endl << "x = ( ";
        for (i = 0; i < ROZMIAR; ++i)
        {
            cout << "x_" << i << " ";
        }
        cout << ") = ( " << URLd.get_Wniewiadome() << " )" << endl;
    } else {
        cout << "Rozwiązanie:" << endl << URLd.get_Nniewiadome() << endl;
    }


    cout << "TEST SZABLONU KLASY SUKLADROWNANLINIOWYCH <LZespolona, " << ROZMIAR << ">:" << endl;
    SUkladRownanLiniowych <LZespolona, ROZMIAR> URLLZ;

    cout << "Test wczytywania i wyświetlania ukladu rownan liniowych:" << endl;
    cin >> URLLZ;
    cout << URLLZ << endl;

    cout << "Test rozwiązywania ukladu rownan liniowych z " << ROZMIAR << " niewiadomymi:" << endl;
    r = URLLZ.rozwiaz();
    if (r == 0)
    {
        cout << "Wektor rozwiązania:" << endl << "x = ( ";
        for (i = 0; i < ROZMIAR; ++i)
        {
            cout << "x_" << i << " ";
        }
        cout << ") = ( " << URLLZ.get_Wniewiadome() << " )" << endl;
    } else {
        cout << "Rozwiązanie:" << endl << URLLZ.get_Nniewiadome() << endl;
    }
}