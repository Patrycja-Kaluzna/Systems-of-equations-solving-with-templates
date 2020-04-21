#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main() 
{   
    UkladRownanLiniowych URL;
    Wektor blad;
    int a;

    cin >> URL;
    cout << "Układ rownań liniowych:" << endl << URL << endl;
    a = URL.rozwiaz();
    if (a == 0)
    {
        cout << "Wektor rozwiązania:" << endl << "x = ( x_1, x_2, x_3 ) = ";
        cout << "( " << URL.get_Wniewiadome() << ")" << endl << endl;
        blad = (URL.get_wspolczynniki() * URL.get_Wniewiadome()) - URL.get_wyrazy_wolne();
        cout << "Wektor błędu:" << endl << "E = Ax - b = ( " << blad << ")" << endl << endl;
        cout << "Długość wektora błędu:" << endl << "|| E || = " << blad.dlugosc_wektora() << endl;
    } else {
        cout << "Rozwiązanie:" << endl << URL.get_Nniewiadome() << endl;
        cout << "Nie można wyznaczyć wektora błędu i jego długości." << endl;
    }
}

    /*
    cout << endl << "TEST WCZYTYWANIA I WYSWIETLANIA WEKTORA:" << endl;
    Wektor Wek;
    cin >> Wek;
    cout << endl << Wek << endl;
    
    cout << endl << "TEST WCZYTYWANIA I WYŚWIETLANIA MACIERZY:" << endl;
    Macierz Mac;
    cin >> Mac;
    cout << endl << Mac;
    
    cout << endl << "TEST DZIALAN NA WEKTORACH:" << endl;
    Wektor Wek1, Wek2, WynikW;
    double Lic, WynikL;
    Wek1[0] = 1;
    Wek1[1] = 2;
    Wek1[2] = 3;
    Wek2[0] = 4;
    Wek2[1] = 5;  
    Wek2[2] = 6;
    Lic = 2;

    cout << "DODAWANIE:" << endl;
    WynikW = Wek1 + Wek2;
    cout << WynikW << endl << endl;

    cout << "ODEJMOWANIE:" << endl;
    WynikW = Wek1 - Wek2;
    cout << WynikW << endl << endl;

    cout << "MNOZENIE (ILOCZYN SKALARNY):" << endl;
    WynikL = Wek1 * Wek2;
    cout << WynikL << endl << endl;

    cout << "MNOZENIE PRZEZ LICZBE:" << endl;
    WynikW = Wek1 * Lic;
    cout << WynikW << endl << endl;

    cout << "DZIELENIE PRZEZ LICZBE:" << endl;
    WynikW = Wek1 / Lic;
    cout << WynikW << endl;

    cout << "TEST PODNOSZNIA DO KWADRATU ELEMENTÓW MACIERZY:" << endl;
    Macierz M1, M2;
    cin >> M1;
    M2 = M1.elementy2();
    cout << endl << M2 << endl;

    cout << "TEST ILOCZYNU WEKTOROWEGO:" << endl;
    Wektor W1, W2, Wynik;
    cin >> W1;
    cin >> W2;
    Wynik = W1.iloczyn_wektorowy(W2);
    cout << endl << Wynik << endl;
    
    cout << endl << "KONIEC TESTOW" << endl;
    */