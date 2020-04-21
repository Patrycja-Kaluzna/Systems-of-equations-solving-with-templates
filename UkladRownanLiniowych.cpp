#include "UkladRownanLiniowych.hh"

/*
 * Metoda wczytuje układ równan liniowych 
 * (dokładniej macierz współczynników i 
 * wektor wyrazów wolnych) podany na 
 * strumieniu wejściowym.
 * 
 * Argumenty:
 *      Str - strumień wejściowy,
 *      UklRow - układ równań, który
 *               zostanie wczytany.
 * 
 * Warunki wstępne:
 * - Pierwszy argument musi być przekazany
 *   przez referencję.
 * - Drugi argument też musi być przekazany
 *   przez referencję.
 * - Dane podane na strumieniu wejściowym
 *   muszą być liczbami.
 * 
 * Zwraca:
 *      Strumień wejściowy.
 */ 
std::istream & operator >> (std::istream & Str, UkladRownanLiniowych & UklRow)
{
    Macierz pomM;
    Wektor pomW;

    Str >> pomM;
    Str >> pomW;

    UklRow.set_wspolczynniki(pomM);
    UklRow.set_wyrazy_wolne(pomW);

    return Str;
}



/*
 * Metoda zapisuje układ równań liniowych 
 * (dokładniej macierz współczynników, wektor 
 * wyrazów wolnych i wektor niewiadomych w postaci
 * x_1, x_2, x_3 itd.) na strumieniu wyjściowym.
 * 
 * Argumenty:
 *      Str - strumień wyjściowy,
 *      UklRow - układ równań, który zostanie
 *               zapisany.
 * 
 * Warunki wstępne:
 *      - Pierwszy argument musi być przekazany
 *        przez referencję.
 *      - Drugi argument też musi być przekazany
 *        przez referencję.
 * 
 * Zwraca:
 *      Strumień wyjściowy.
 */ 
std::ostream & operator << (std::ostream & Str, const UkladRownanLiniowych & UklRow)
{
    unsigned int i;
    Macierz pomM;
    Wektor pomW;
    double pomd;

    pomM = UklRow.get_wspolczynniki();
    pomM = pomM.transponuj();
    pomW = UklRow.get_wyrazy_wolne();
    pomd = ROZMIAR / 2 + 1 / 2;
    
    for (i = 0; i < ROZMIAR; i++)
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



/*
 * Metoda rozwiązuje układ równań liniowych
 * z wykorzystaniem wzorów Cramera i zapisuje
 * rozwiązanie w odpowiednim polu obiektu klasy
 * UkladRownanLiniowych.
 * 
 * Zwraca:
 *      Liczbe całkowitą mówiącą jakiego typu
 *      jest rozwiązanie układu, tzn. czy jest
 *      on oznaczony - zwraca 0, sprzeczny - 
 *      zwraca 1, czy sprzeczny lub
 *      nieoznaczony - też zwraca 1.
 */
int UkladRownanLiniowych::rozwiaz () {
    double wyznacznik_glownej, wyznacznik_po_podmianie, rozwiazanie;
    unsigned int i;
    Macierz pomM;
    Wektor pomW1, pomW2;
    wyznacznik_glownej = wspolczynniki.oblicz_wyznacznik();
    for (i = 0; i < ROZMIAR; i++) {
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
        for (i = 0; i < ROZMIAR; i++) {
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