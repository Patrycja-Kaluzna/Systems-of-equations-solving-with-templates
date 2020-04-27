#include "SWektor.hh"
#include "SMacierz.hh"
#include "rozmiar.h"
#include "LZespolona.hh"

#include <iostream>

using namespace std;

int main ()
{
    cout << "TEST SZABLONU KLASY SMACIERZ <double, " << ROZMIAR << ">:" << endl;
    SMacierz <double, ROZMIAR> Macd, Wynikd;
    
    cout << "Test wczytywania i wyświetlania macierzy:" << endl;
    cout << "Podaj kolumny: ";
    cin >> Macd;
    cout << "Mac:" << endl << Macd;

    cout << "Test podnoszenia do kwadratu kazdego z elementow miacierzy:" << endl;
    Wynikd = Macd.elementy2();
    cout << "Mac^2:" << endl << Wynikd;

    cout << "Test zamiany kolumn o zadanych indeksach:" << endl;
    int ind1, ind2;
    cout << "Podaj indeks 1. kolumny: ";
    cin >> ind1;
    cout << "Podaj indeks 2. kolumny: ";
    cin >> ind2;
    Macd.zamien_kolumny(ind1, ind2);
    cout << "Macierz po zamianie kolumn:" << endl << Macd;

    cout << "Test podmiany kolumny macierzy z wektorem:" << endl;
    SWektor <double, ROZMIAR> Wekd;
    cout << "Podaj wspolrzedne wektora Wek: ";
    cin >> Wekd;
    cout << "Podaj wspolrzedne kolumny do podmiany: ";
    cin >> ind1;
    Wynikd = Macd.podmien_kolumne(ind1, Wekd);
    cout << "Macierz po podmianie:" << endl << Wynikd;

    cout << "Test transpozycji macierzy:" << endl;
    Wynikd = Wynikd.transponuj();
    cout << "Mac^T:" << endl << Wynikd;

    cout << "Test mnozenia macierzy z wektorem:" << endl;
    Wekd = Wynikd * Wekd;
    cout << "Mac * Wek = " << Wekd << endl;

    cout << "Test obliczania wyznacznika macierzy metoda eliminacji Gaussa:" << endl;
    double pomd;
    pomd = Wynikd.oblicz_wyznacznik();
    cout << "Det Mac = " << pomd << endl;


    cout << "TEST SZABLONU KLASY SMACIERZ <LZespolona, " << ROZMIAR << ">:" << endl;
    SMacierz <LZespolona, ROZMIAR> MacLZ, WynikLZ;

    cout << "Test wczytywania i wyświetlania macierzy:" << endl;
    cout << "Podaj kolumny: ";
    cin >> MacLZ;
    cout << "Mac:" << endl << MacLZ;

    cout << "Test podnoszenia do kwadratu kazdego z elementow miacierzy:" << endl;
    WynikLZ = MacLZ.elementy2();
    cout << "Mac^2:" << endl << WynikLZ;

    cout << "Test zamiany kolumn o zadanych indeksach:" << endl;
    int ind1, ind2;
    cout << "Podaj indeks 1. kolumny: ";
    cin >> ind1;
    cout << "Podaj indeks 2. kolumny: ";
    cin >> ind2;
    MacLZ.zamien_kolumny(ind1, ind2);
    cout << "Macierz po zamianie kolumn:" << endl << MacLZ;

    cout << "Test podmiany kolumny macierzy z wektorem:" << endl;
    SWektor <LZespolona, ROZMIAR> WekLZ;
    cout << "Podaj wspolrzedne wektora Wek: ";
    cin >> WekLZ;
    cout << "Podaj wspolrzedne kolumny do podmiany: ";
    cin >> ind1;
    WynikLZ = MacLZ.podmien_kolumne(ind1, WekLZ);
    cout << "Macierz po podmianie:" << endl << WynikLZ;

    cout << "Test transpozycji macierzy:" << endl;
    WynikLZ = WynikLZ.transponuj();
    cout << "Mac^T:" << endl << WynikLZ;

    cout << "Test mnozenia macierzy z wektorem:" << endl;
    WekLZ = WynikLZ * WekLZ;
    cout << "Mac * Wek = " << WekLZ << endl;

    cout << "Test obliczania wyznacznika macierzy metoda eliminacji Gaussa:" << endl;
    LZespolona pomLZ;
    pomLZ = WynikLZ.oblicz_wyznacznik();
    cout << "Det Mac = " << pomLZ << endl;
}