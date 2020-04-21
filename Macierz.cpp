#include "Macierz.hh"

/*
 * Metoda zapisuje kolumny macierzy
 * na strumienu wyjsciowym.
 * 
 * Argumenty:
 *      Str - strumien wyjsciowy,
 *      Mac - macierz, ktorej kolumny
 *            zostana zapisane.
 * 
 * Warunki wstepne:
 *      - Pierwszy argument musi byc przekazany
 *        przez referencje.
 *      - Drugi argument tez musi byc przekazany
 *        przez referencje.   
 *
 * Zwraca:
 *      Strumien wyjsciowy. 
 */
std::ostream & operator << (std::ostream & Str, const Macierz & Mac)
{
    unsigned int i;

    for (i = 0; i < ROZMIAR; i++)
    {
        Str << Mac[i] << std::endl;
    }

    return Str;
}



/*
 * Metoda wczytuje kolumny macierzy
 * podane na strumienu wejsciowym.
 * 
 * Argumenty:
 *      Str - strumien wejsciowy,
 *      Mac - macierz, ktorej kolumny
 *            zostana wczytane.
 * 
 * Warunki wstepne:
 *      - Pierwszy argument musi byc przekazany
 *        przez referencje.
 *      - Drugi argument tez musi byc przekazany
 *        przez referencje.
 *      - Dane podane na strumieniu wejsciowym
 *        musza byc liczbami.
 *
 * Zwraca:
 *      Strumien wejsciowy. 
 */ 
std::istream & operator >> (std::istream & Str, Macierz & Mac)
{
    unsigned int i;
    Wektor pom;

    for (i = 0; i < ROZMIAR; i++)
    {
        Str >> pom;
        Mac[i] = pom;
    }

    return Str;
}



/*
 * Metoda realizuje podnoszenie do
 * kwadratu kazdego z elementow 
 * macierzy.
 * 
 * Zwraca:
 *      Macierz, ktorej kazdy z
 *      elementow zostal 
 *      podniesiony do
 *      kwadratu.
 */ 
Macierz Macierz::elementy2 () const
{
   Wektor pomWek1, pomWek2;
   unsigned int i, j;
   Macierz pomMac;
   double pomdbl;

   for (i = 0; i < ROZMIAR; i++)
   {
        pomWek1 = kolumny[i];
        for (j = 0; j < ROZMIAR; j++)
        {
            pomdbl = pomWek1[j] * pomWek1[j];
            pomWek2[j] = pomdbl;
        }
        pomMac[i] = pomWek2;
   }

   return pomMac;
}



/*
 * Metoda realizuje zamiane ze soba
 * kolumn macierzy.
 * 
 * Argumenty:
 *      indeks1 - indeks jednej z 
 *                kolumn macierzy,
 *      indeks2 - indeks innej z
 *                kolumn macierzy, 
 *                z ktora ma byc 
 *                zamieniona kolumna
 *                o indeksie indeks1.
 */ 
void Macierz::zamien_kolumny (unsigned int indeks1, unsigned int indeks2)
{
    Wektor pomW;

    pomW = kolumny[indeks1];
    kolumny[indeks1] = kolumny[indeks2];
    kolumny[indeks2] = pomW;
}



/*
 * Metoda oblicza wyznacznik macierzy
 * metoda eliminacji Gaussa.
 * 
 * Warunek wstępny:
 *      - Macierz nie moze byc osobliwa.
 *        (w przeciwnym przypadku wyswietla
 *         sie stosowny komunikat o bledzie)       
 * 
 * Zwraca:
 *      Liczbe bedaca rowna co do wartosci
 *      wyznacznikowi macierzy.
 */ 
double Macierz::oblicz_wyznacznik () const {
    unsigned int i, j, k, l, m;
    double wyznacznik, mnoznik;
    Macierz pomM;
    m = 0;
    wyznacznik = 1;
    pomM = *this;
    for (i = 0; i < (ROZMIAR - 1); i++) {
        if (pomM(i,i) == 0) {
            for (l = i + 1; l < ROZMIAR; l++) {
                while (pomM(i,i) == 0) {
                    if (pomM(l,i) != 0) {
                        pomM.zamien_kolumny(i,l);
                        m++; 
                    }    
                }
            }
            if (pomM(i,i) == 0) {
                std::cout << "Blad: macierz osobliwa" << std::endl;
                return wyznacznik;
            }    
        }
        for (j = i + 1; j < ROZMIAR; j++) {
            mnoznik = -1 * pomM(j,i) / pomM(i,i);
            for (k = i; k < ROZMIAR; k++) {
                pomM(j,k) += (mnoznik * pomM(i,k));                
            }   
        }    
    }
    for (i = 0; i < ROZMIAR; i++) {
        wyznacznik = wyznacznik * pomM(i,i);
    }
    if (m % 2 == 0) {
        return wyznacznik;
    } else {
        wyznacznik = -1 * wyznacznik;
        return wyznacznik;
    }
}



/*
 * Metoda realizuje podmiane kolumny
 * macierzy z wektorem przekazanym 
 * przez argument.
 * 
 * Argumenty:
 *      indeks - indeks kolumny macierzy,
 *               ktora zostanie podmieniona,
 *      Wek - wektor, ktory zostanie podstawiony
 *            w miejsce kolumny o indeksie indeks.
 * 
 * Zwraca:
 *      Macierz, ktorej kolumna o indeksie indeks
 *      zostala podmienona z wektorem przekazanym 
 *      przez argument.
 */ 
Macierz Macierz::podmien_kolumne (unsigned int indeks, Wektor Wek) const
{
    Macierz pomM;

    pomM = *this;
    pomM[indeks] = Wek;

    return pomM;
}



/*
 * Metoda realizuje transpozycje macierzy.
 * 
 * Zwraca:
 *      Macierz transponowaną. 
 */ 
Macierz Macierz::transponuj () const
{
    unsigned int i, j;
    Macierz pomM;

    for (i = 0; i < ROZMIAR; i++)
    {
        for (j = 0; j < ROZMIAR; j++)
        {
            pomM(j,i) = kolumny[i][j];
        }
    }

    return pomM;
}



/*
 * Metoda realizuje mnozenie macierzy 
 * z wektorem.
 * 
 * Argument:
 *      Wek - wektor, przez ktory
 *            zostanie pomnozona
 *            macierz.
 * 
 * Warunek wstepny:
 *      - Macierz musi byc w postaci 
 *        transponowanej, poniewaz 
 *        metoda ta dokonuje też 
 *        transpozycji wiec wynik 
 *        moglby byc zaklamany.
 * 
 * Zwraca:
 *      Wektor bedacy iloczynem czynnikow.
 */ 
Wektor Macierz::operator * (Wektor Wek) const
{
    unsigned int i, j;
    Macierz pomM;
    Wektor pomW;

    pomM = *this;
    pomM = pomM.transponuj();
    for (i = 0; i < ROZMIAR; i++)
    {
        pomW[i] = 0;
        for (j = 0; j < ROZMIAR; j++)
        {
            pomW[i] += pomM[i][j] * Wek[j];
        }
    }

    return pomW;
}