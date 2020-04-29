#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include "SWektor.hh"
#include "SMacierz.hh"

#include <iostream>

/*
 * Szablon klasy modelujacej pojecie ukladu rownan liniowych, 
 * ktorego glownymi cechami sa macierz jego wspolczynnikow, 
 * wektor niewiadomych (rozwiazan) badz napis mowiacy o 
 * braku rozwiazan lub ich nieskonczonej ilosci oraz
 * wektor wyrazow wolnych.
 */ 
template <typename typ, int rozmiar>
class SUkladRownanLiniowych {
  
  SMacierz <typ, rozmiar> wspolczynniki;    // Macierz współczynników układu
  SWektor <typ, rozmiar> Wniewiadome;   // Wektor niewiadomych (rozwiązań) układu
  std::string Nniewiadome;    // Napis mówiący o tym, że układ jest sprzeczny bądź sprzeczny lub nieoznaczony
  SWektor <typ, rozmiar> wyrazy_wolne;    // Wektor wyrazów wolnych układu

  public:
  
  void set_wspolczynniki (SMacierz <typ, rozmiar> Mac) {    // Umozliwia wczytanie macierzy wspolczynnikow
    wspolczynniki = Mac;} 

  void set_wyrazy_wolne (SWektor <typ, rozmiar> Wek) {    // Umozliwia wczytanie wektora wyrazow wolnych
    wyrazy_wolne = Wek;}  

  SMacierz <typ, rozmiar> get_wspolczynniki () const {    // Umozliwia czytanie macierzy wspolczynnikow
    return wspolczynniki;}   

  SWektor <typ, rozmiar> get_Wniewiadome () const {   // Umozliwia czytanie wektora niewiadomych (rozwiazan)
    return Wniewiadome;}

  std::string get_Nniewiadome () const {  // Umozliwia czytanie napisu mowiacego o braku rozwiazan lub
    return Nniewiadome;}                  // ich nieskonczonej ilosci

  SWektor <typ, rozmiar> get_wyrazy_wolne () const {    // Umozliwia czytanie wektora wyrazow wolnych
    return wyrazy_wolne;}

  int rozwiaz ();   // Rozwiazuje uklad rownan liniowych
};

/*
 * Rozwiazuje uklad rownan liniowych.
 */ 
template <typename typ, int rozmiar>
int SUkladRownanLiniowych<typ, rozmiar>::rozwiaz () {
    typ wyznacznik_glownej, wyznacznik_po_podmianie, rozwiazanie;
    unsigned int i;
    SMacierz <typ, rozmiar> pomM;
    SWektor <typ, rozmiar> pomW1, pomW2;
    wyznacznik_glownej = wspolczynniki.oblicz_wyznacznik();
    for (i = 0; i < rozmiar; ++i) {
        pomM = wspolczynniki;
        pomM = pomM.podmien_kolumne(i, wyrazy_wolne);
        wyznacznik_po_podmianie = pomM.oblicz_wyznacznik();
        if (wyznacznik_glownej != 0) {
            rozwiazanie = wyznacznik_po_podmianie / wyznacznik_glownej;
            pomW1[i] = rozwiazanie;
            Wniewiadome = pomW1;
        } else {
            pomW2[i] = wyznacznik_po_podmianie;
        }
    }
    if (wyznacznik_glownej != 0) {
       return 0;
    } else {
        for (i = 0; i < rozmiar; ++i) {
            if (pomW2[i] != 0) {
                Nniewiadome = "Układ jest sprzeczny.";
                return 1;
            } else {
                Nniewiadome = "Układ jest sprzeczny lub ma nieskończenie wiele rozwiązań.";
            }
        }
        return 1;
    }
    return -1;
}

/*
 * Wczytuje uklad rownan ze strumienia wejsciowego.
 */
template <typename typ, int rozmiar>
std::istream & operator >> (std::istream & Str, SUkladRownanLiniowych <typ, rozmiar> & UklRow)
{
    SMacierz <typ, rozmiar> pomM;
    SWektor <typ, rozmiar> pomW;

    Str >> pomM;
    Str >> pomW;

    UklRow.set_wspolczynniki(pomM);
    UklRow.set_wyrazy_wolne(pomW);

    return Str;
}

/*
 * Zapisuje uklad rownan na strumieniu wyjsciowym.
 */ 
template <typename typ, int rozmiar>
std::ostream & operator << (std::ostream & Str, const SUkladRownanLiniowych <typ, rozmiar> & UklRow)
{
    unsigned int i;
    SMacierz <typ, rozmiar> pomM;
    SWektor <typ, rozmiar> pomW;
    double pomd;

    pomM = UklRow.get_wspolczynniki();
    pomM = pomM.transponuj();
    pomW = UklRow.get_wyrazy_wolne();
    pomd = ROZMIAR / 2 + 1 / 2;
    
    for (i = 0; i < rozmiar; ++i)
    {
        Str << "| " << pomM[i] << "|" << " " << "| x_" << i+1 << " |";
        if (i == pomd)
        {
            Str << " = " << "| " << pomW[i] << " |" << std::endl;
        } else {
            Str << "   " << "| " << pomW[i] << " |" << std::endl;
        }
    }

    return Str;
}

#endif