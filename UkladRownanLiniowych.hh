#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Macierz.hh"
#include "Wektor.hh"

#include <iostream>

/*
 * Modeluje pojecie ukladu rownan liniowych, ktorego glownymi cechami
 * sa macierz jego wspolczynnikow, wektor niewiadomych (rozwiazan) badz
 * napis mowiacy o braku rozwiazan lub ich nieskonczonej ilosci oraz
 * wektor wyrazow wolnych.
 */
class UkladRownanLiniowych {
  
  Macierz wspolczynniki;    // Macierz współczynników układu
  Wektor Wniewiadome;   // Wektor niewiadomych (rozwiązań) układu
  std::string Nniewiadome;    // Napis mówiący o tym, że układ jest sprzeczny bądź sprzeczny lub nieoznaczony
  Wektor wyrazy_wolne;    // Wektor wyrazów wolnych układu

  public:
  
  void set_wspolczynniki (Macierz Mac) {    // Umozliwia wczytanie macierzy wspolczynnikow
    wspolczynniki = Mac;} 

  void set_wyrazy_wolne (Wektor Wek) {    // Umozliwia wczytanie wektora wyrazow wolnych
    wyrazy_wolne = Wek;}  

  Macierz get_wspolczynniki () const {    // Umozliwia czytanie macierzy wspolczynnikow
    return wspolczynniki;}   

  Wektor get_Wniewiadome () const {   // Umozliwia czytanie wektora niewiadomych (rozwiazan)
    return Wniewiadome;}

  std::string get_Nniewiadome () const {  // Umozliwia czytanie napisu mowiacego o braku rozwiazan lub
    return Nniewiadome;}                  // ich nieskonczonej ilosci

  Wektor get_wyrazy_wolne () const {    // Umozliwia czytanie wektora wyrazow wolnych
    return wyrazy_wolne;}

  int rozwiaz ();   // Rozwiazuje uklad rownan liniowych
};

/*
 * Wczytuje uklad rownan ze strumienia wejsciowego.
 */
std::istream & operator >> (std::istream & Str, UkladRownanLiniowych & UklRow);

/*
 * Zapisuje uklad rownan na strumieniu wyjsciowym.
 */ 
std::ostream & operator << (std::ostream & Str, const UkladRownanLiniowych & UklRow);

#endif