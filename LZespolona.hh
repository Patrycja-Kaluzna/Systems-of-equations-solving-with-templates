#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZespolona oraz zapowiedzi
 *  przeciazen operatorow dzialajacych na tej strukturze, a 
 *  takze innych funkcji z nia zwiazanych.
 */

/*!
 * Modeluje pojecie liczby zespolonej.
 */
struct LZespolona {

  double re;    /*! Pole repezentuje czesc rzeczywista. */
  double im;    /*! Pole repezentuje czesc urojona. */

  void operator = (double Lic);   // Reazlizuje podstawiaie częśći rzeczywistej (za częśc urojoną podstawia zero)

  LZespolona operator += (LZespolona LZ);   // Realizuje dodanie dwóch liczb zespolonych i podstawienie wyniku 
                                            // w miejcu pierwszej z nich
  LZespolona operator * (double lic) const;   // Realizuje mnożenie liczby zespolonej przez liczbę typu double
  
};

/*
 * Realizuje dodawanie.
 */
LZespolona  operator + (LZespolona, LZespolona);

/*
 * Realizuje odejmowanie.
 */
LZespolona operator - (LZespolona, LZespolona);

/*
 * Realizuje mnozenie.
 */
LZespolona operator * (LZespolona, LZespolona);

/*
 * Oblicza sprzezenie.
 */
LZespolona Sprzezenie (LZespolona);        

/*
 * Oblicza modul podniesiony do kwadratu.
 */
double Modul2 (LZespolona);

/*
 * Relizuje dzielenie liczby zespolonej przez liczbe typu double. 
 */ 
LZespolona operator / (LZespolona, double);

/*
 * Realizuje dzielenie liczb zesoplonych.
 */
LZespolona operator / (LZespolona, LZespolona);

/*
 * Wczytuje liczbe zespolona.
 */ 
LZespolona WczytajLZ ();

/*
 * Wyswietla liczbe zespolona.
 */
void Wyswietl (LZespolona);

/*
 * Wczytuje liczbe zespolona.
 */
istream & operator >> (istream &, LZespolona &);

/*
 * Wyswietla liczbe zespolona.
 */
ostream & operator << (ostream &, LZespolona);

/*
 * Porownuje ze soba dwie liczby zespolone
 */ 
bool operator == (LZespolona, LZespolona);

/*
 * Realizuje dzielenie modulo liczb zespolonych.
 */
LZespolona operator % (LZespolona, LZespolona);

#endif