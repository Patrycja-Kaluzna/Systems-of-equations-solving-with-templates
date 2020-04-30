#include "rozmiar.h"
#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"

#include <iomanip>

int main () 
{   
    char pom;
    int a, i;
    std::cin >> pom;
    switch (pom) 
    {
        case 'r':
            {
            SUkladRownanLiniowych <double, ROZMIAR> URLr;
            SWektor <double, ROZMIAR> bladr;
            std::cin >> URLr;
            std::cout << "Układ równań liniowych o współczynnikach rzeczywistych:" << endl << URLr << endl;
            a = URLr.rozwiaz();
            if (a == 0)
            {
                std::cout << "Wektor rozwiązania:" << endl << "x = ( ";
                for (i = 0; i < ROZMIAR; ++i)
                {
                    std::cout << "x_" << i << " ";
                }
                std::cout << ") = ( " << fixed << setprecision(2) << URLr.get_Wniewiadome() << ")" << endl << endl;
                bladr = (URLr.get_wspolczynniki() * URLr.get_Wniewiadome()) - URLr.get_wyrazy_wolne();
                std::cout << "Wektor błędu:" << endl << "E = Ax - b = ( " << scientific << setprecision(1) << bladr << ")" << endl << endl;
                std::cout << "Długość wektora błędu:" << endl << "|| E || = " << bladr.dlugosc_wektora() << endl;
            } else {
                std::cout << "Rozwiązanie:" << endl << URLr.get_Nniewiadome() << endl;
                std::cout << "Nie można wyznaczyć wektora błędu i jego długości." << endl;
            }
            break;
            }
        case 'z':
            {
            SUkladRownanLiniowych <LZespolona, ROZMIAR> URLLZ;
            SWektor <LZespolona, ROZMIAR> bladLZ;
            std::cin >> URLLZ;
            std::cout << "Układ równań liniowych o współczynnikach zespolonych:" << endl << URLLZ << endl;
            a = URLLZ.rozwiaz();
            if (a == 0)
            {
                std::cout << "Wektor rozwiązania:" << endl << "x = ( ";
                for (i = 0; i < ROZMIAR; ++i)
                {
                    std::cout << "x_" << i << " ";
                }
                std::cout << ") = (" << fixed << setprecision(2) << URLLZ.get_Wniewiadome() << ")" << endl << endl;
                bladLZ = (URLLZ.get_wspolczynniki() * URLLZ.get_Wniewiadome()) - URLLZ.get_wyrazy_wolne();
                std::cout << "Wektor błędu:" << endl << "E = Ax - b = (" << scientific << setprecision(1) << bladLZ << ")" << endl << endl;
                std::cout << "Długość wektora błędu:" << endl << "|| E || = " << bladLZ.dlugosc_wektora() << endl;
            } else {
                std::cout << "Rozwiązanie:" << endl << URLLZ.get_Nniewiadome() << endl;
                std::cout << "Nie można wyznaczyć wektora błędu i jego długości." << endl;
            }
            break;
            }
        default:
            {
            cerr << "Błąd: niepoprawna opcja. Poprawne opcje: r (liczby rzeczywiste), z (liczby zespolone)." << endl;
            break;
            }
    }
}