#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"

#include <iostream>

using namespace std;

int main ()
{
    cout << "TEST KLASY WEKTOR <double, " << ROZMIAR << ">:" << endl;

    SWektor <double, ROZMIAR> Wekd, Wynikd;
    double Lic, dWynik;
    
    cout << "Test wczytywania i wyświetlania wektora:" << endl;

    cout << "Podaj współrzędne: ";
    cin >> Wekd;
    cout << "Wek = " << Wekd << endl;

    cout << "Test dodawania i odejmowania wektorów:" << endl;

    Wynikd = Wekd + Wekd;
    cout << "Wek + Wek = " << Wynikd << endl;
    Wynikd = Wekd - Wekd;
    cout << "Wek - Wek = " << Wynikd << endl;
    
    cout << "Test iloczynu skalarnego:" << endl;

    dWynik = Wekd * Wekd;
    cout << "Wek * Wek = " << dWynik << endl;
    
    cout << "Test mnożenia i dzielenia wektora przez liczbę:" << endl;

    cout << "Podaj liczbę: ";
    cin >> Lic;
    cout << "Lic = " << Lic << endl;
    Wynikd = Wekd * Lic;
    cout << "Wek * Lic = " << Wynikd << endl;
    Wynikd = Wekd / Lic;
    cout << "Wek / Lic = " << Wynikd << endl;
    
    cout << "Test iloczynu wektorowego:" << endl;

    if (ROZMIAR == 3)
    {
        Wynikd = Wekd.iloczyn_wektorowy(Wekd);
        cout << "Wek x Wek = " << Wynikd << endl;
    } else {
        cout << "Rozmiar jest różny od 3 - niespełniona definicja iloczynu wektorowego" << endl;
    }

    cout << "TEST KLASY WEKTOR <LZespolona, " << ROZMIAR << ">:" << endl;

    SWektor <LZespolona, ROZMIAR> WekLZ, WynikLZ;
    LZespolona LZWynik;
    
    cout << "Test wczytywania i wyświetlania wektora:" << endl;

    cout << "Podaj współrzędne: ";
    cin >> WekLZ;
    cout << "Wek = " << WekLZ << endl;

    cout << "Test dodawania i odejmowania wektorów:" << endl;

    WynikLZ = WekLZ + WekLZ;
    cout << "Wek + Wek = " << WynikLZ << endl;
    WynikLZ = WekLZ - WekLZ;
    cout << "Wek - Wek = " << WynikLZ << endl;
    
    cout << "Test iloczynu skalarnego:" << endl;

    LZWynik = WekLZ * WekLZ;
    cout << "Wek * Wek = " << LZWynik << endl;
    
    cout << "Test mnożenia i dzielenia wektora przez liczbę:" << endl;

    cout << "Podaj liczbę: ";
    cin >> Lic;
    cout << "Lic = " << Lic << endl;
    WynikLZ = WekLZ * Lic;
    cout << "Wek * Lic = " << WynikLZ << endl;
    WynikLZ = WekLZ / Lic;
    cout << "Wek / Lic = " << WynikLZ << endl;
    
    cout << "Test iloczynu wektorowego:" << endl;

    if (ROZMIAR == 3)
    {
        WynikLZ = WekLZ.iloczyn_wektorowy(WekLZ);
        cout << "Wek x Wek = " << WynikLZ << endl;
    } else {
        cout << "Rozmiar jest różny od 3 - niespełniona definiacja iloczynu wektorowego" << endl;
    }
}