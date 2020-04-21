#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"

#include <iostream>

/*
 * Modeluje pojecie macierzy, ktorej
 * glowna cecha sa jej kolumny.
 */
class Macierz {
  
  Wektor kolumny [ROZMIAR];   // Kolumny macierzy
 
  public: 

  double operator () (unsigned int indeksK, unsigned int indeksW) const {   // Umozliwia czytanie elementow macierzy
    return kolumny[indeksK][indeksW];}

  double & operator () (unsigned int indeksK, unsigned int indeksW) {   // Umozliwia wczytywanie elementow macierzy
    return kolumny[indeksK][indeksW];}

  Wektor operator [] (unsigned int indeks) const {    // Umozliwia czytanie kolumn macierzy
    return kolumny[indeks];}

  Wektor & operator [] (unsigned int indeks) {    // Umozliwia wczytywanie kolumn macierzy
    return kolumny[indeks];}

  Macierz elementy2 () const;   // Realizuje podnoszenie do kwadratu kazdego z elementow macierzy

  void zamien_kolumny (unsigned int indeks1, unsigned int indeks2);    // Realizuje zamiane ze soba kolumn macierzy

  double oblicz_wyznacznik () const;   // Oblicza wyznacznik macierzy metoda eliminacji Gaussa

  Macierz podmien_kolumne (unsigned int indeks, Wektor Wek) const;  // Realizuje podmiane kolumny macierzy z wektorem

  Macierz transponuj () const;    // Realizuje transpozycje macierzy

  Wektor operator * (Wektor Wek) const;   // Realizuje mnozenie macierzy z wektorem
};

/*
 * Zapisuje kolumny macierzy na strumieniu wyjsciowym. 
 */
std::ostream & operator << (std::ostream & Str, const Macierz & Mac);

/*
 * Wczytuje kolumny macierzy ze strumienia wejsciowego.
 */ 
std::istream & operator >> (std::istream & Str, Macierz & Mac);

#endif