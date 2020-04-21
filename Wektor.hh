#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"

#include <iostream>
#include <cmath>

/*
 * Modeluje pojecie wektora, ktorego
 * glowna cecha sa jego wspolrzedne.
 */ 
class Wektor {

  double wspolrzedne [ROZMIAR];   // Wspolrzedne wektora

  public:

  double operator [] (const unsigned int indeks) const {    // Umozliwia czytanie wspolrzednych wektora
    return wspolrzedne[indeks];}   

  double & operator [] (const unsigned int indeks) {    // Umozliwia wczytywanie wspolrzednych wektora
    return wspolrzedne[indeks];}                                        

  Wektor operator + (const Wektor Wek) const;   // Realizuje dodawanie wektorow

  Wektor operator - (const Wektor Wek) const;   // Realizuje odejmowanie wektorow

  double operator * (const Wektor Wek) const;   // Realizuje mnozenie (iloczyn skalarny) wektorow

  Wektor operator * (const double lic) const;   // Realizuje mnozenie wektora przez liczbe

  Wektor operator / (const double lic) const;   // Realizuje dzielenie wektora przez liczbe

  Wektor iloczyn_wektorowy (const Wektor Wek) const;    // Relizuje mnozenie (iloczyn wektorowy) wektorow

  double dlugosc_wektora () const;    // Oblicza dlugosc wektora
};

/*
 * Wczytuje wspolrzedne wektora ze strumienia wejsciowego.
 */ 
std::istream & operator >> (std::istream & Str, Wektor & Wek);

/*
 * Zapisuje wspolrzedne wektora na strumieniu wyjsciowym.
 */
std::ostream & operator << (std::ostream & Str, const Wektor & Wek);

#endif