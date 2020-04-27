#include "LZespolona.hh"

/*
 * Metoda realizuje podstawianie części
 * rzeczywistej, a za część urojoną
 * podstawia zero.
 * 
 * Argument:
 *    Lic - liczba, która zostanie
 *          podstawiona za część
 *          rzeczywistą.
 * 
 * Zwraca:
 *    Liczbe zespoloną po takich
 *    podstawieniach.
 */ 
void LZespolona::operator = (double Lic)
{
  this->re = Lic;
  this->im = 0;
}



/*
 * Metoda realizuje dodanie dwóch liczb
 * zespolonych i podstawienie wyniku w 
 * miejscu pierwszej z nich.
 * 
 * Argument:
 *    LZ - liczba zespolona, która 
 *         zostanie dodana.
 * 
 * Zwraca:
 *    Liczbę zespoloną będącą
 *    podstawioną sumą.
 */ 
LZespolona LZespolona::operator += (LZespolona LZ)
{
  *this = *this + LZ;

  return *this;
}



/*
 * Metoda realizuje mnożenie liczby
 * zespolonej przez liczbę typu double.
 * 
 * Argument:
 *    - lic - liczba typu double, przez
 *            którą zostanie pomnożona
 *            liczba zespolona.
 * 
 * Zwraca:
 *    Liczbę zespoloną, której część 
 *    rzeczywista i urojona zostały 
 *    pomnożone przez tę liczbę.
 */ 
LZespolona LZespolona::operator * (double lic) const
{
  LZespolona Wynik;

  Wynik.re = this->re * lic;
  Wynik.im = this->im * lic;

  return Wynik;
}



/*
 * Metoda realizuje porównanie liczby
 * zespolonej z liczbą typu double.
 * 
 * Argumenty:
 *    - lic - liczba typu double, z którą
 *            zostanie porównana liczba 
 *            zespolona.
 * 
 * Zwraca:
 *    True jeśli część rzeczywista jest równa 
 *    lic i urojona 0, false jeśli częśc
 *    rzeczywista jest różna od lic lub 
 *    urojona różna od 0.
 */ 
bool LZespolona::operator == (double lic) const
{
  if (re == lic && im == 0)
  {
    return true;
  } else {
    return false;
  }
}



/*
 * Metoda realizuje porównanie liczby
 * zespolonej z liczbą typu double.
 * 
 * Argumenty:
 *    - lic - liczba typu double, z którą
 *            zostanie porównana liczba 
 *            zespolona.
 * 
 * Zwraca:
 *    True jeśli część rzeczywista jest różna
 *    od lic i urojona równa 0, false jeśli
 *    częśc rzeczywista jest równa lic lub
 *    urojona różna od 0.
 */ 
bool LZespolona::operator != (double lic) const
{
  if (re != lic && im == 0)
  {
    return true;
  } else {
    return false;
  }
}



/*!
 * Realizuje dodawanie dwoch liczb zespolonych.
 * 
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * 
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



/*
 * Realizuje odejmowanie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * 
 * Zwraca:
 *    Roznice odjemnej i odjemnika przekazanych
 *    jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*
 * Realizuje mnozenie dwoch liczb zespolonych.
 * 
 * Argumenty:
 *    Skl1 - pierwszy czynnik mnozenia,
 *    Skl2 - drugi czynnik mnozenia.
 * 
 * Zwraca: 
 *    Iloczyn dwoch czynnikow przekazanych jako
 *    parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}



/*
 * Oblicza sprzezenie liczby zespolonej.
 * 
 * Argument:
 *    Skl2 - liczba zespolona, ktorej sprzezenie
 *           zostanie obliczone.
 * 
 * Zwraca:
 *    Sprzezenie liczby zespolonej przekazanej
 *    jako parametr.
 */
LZespolona Sprzezenie (LZespolona Skl2)
{
  Skl2.im = -1 * Skl2.im;
  return Skl2;
}



/*
 * Oblicza modul liczby zespolonej podnisiony
 * do kwadratu.
 * 
 * Argument:
 *    Skl2 - liczba zespolna, ktorej modul podniesiony
 *           do kwadratu zostanie obliczony.
 * 
 * Zwraca:
 *     Podniosiony do kwadratu modul liczby zespolonej
 *     przekazanej jako parametr.
 */
double Modul2 (LZespolona Skl2)
{
  double M2 = Skl2.re * Skl2.re + Skl2.im * Skl2.im;
  return M2;
}



/*
 * Realizuje dzielenie liczby zespolonej przez 
 * liczbe typu double.
 * 
 * Argumenty:
 *    Wynik - liczba zespolona bedaca dzielna,
 *    M2 - liczba typu double bedaca dzielnikiem.
 * 
 * Warunek wstepny:
 *    - Liczba typu double musi byc rozna od zera.
 *      (jesli jest rowna zeru to wyswietla sie
 *      stosowny komunikat o bledzie)
 *  
 * Zwraca:
 *    Liczbe zespolona bedaca ilorazem dzielnej i
 *    dzielnika przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Wynik, double M2)
{
  LZespolona LZpD;

  if (M2 != 0)
  {
    LZpD.re = Wynik.re / M2;
    LZpD.im = Wynik.im / M2;
  } else {
    cerr << "Blad: dzielenie przez zero" << endl;
  }
  return LZpD;
}



/*
 * Realizuje dzielenie dwoch liczb zespolonych przy
 * wykorzystaniu przeciazenia operatora mnozenia dla 
 * liczb zespolonych, przeciazenia operatora dzielenia
 * liczby zespolonej przez liczbe typu double oraz 
 * funkcji obliczajacych sprzezenie i modul 
 * podniosiony do kwadratu.
 * 
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * 
 * Warunek wstepny:
 *    - Modul liczby zespolonej podniesiony do kwadratu
 *      musi byc rozny od zera. (jesli jest rowny zeru
 *      to wyswietla sie stosowny komunikat o bledzie)
 * 
 * Zwraca:
 *    Iloraz dzielnej i dzielnika przekazanych jako
 *    parametry.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = operator * (Skl1, Sprzezenie (Skl2));
  Wynik = Wynik / Modul2 (Skl2);
  return Wynik;
}



/*
 * Funkcja wczytuje liczbe zespolona wpisana 
 * przez uzytkownika na standardowym wejsciu.
 * 
 * Warunek wstepny:
 *    - Liczba zespolona musi byc wpisana przez uzytkownika
 *      w odpowiedniej postaci, np.: (1+2i).
 *      (wpisanie w innej postaci powoduje wyswietlenie
 *      komunikatu o bledzie)
 * 
 * Zwraca: 
 *    W przypadku powodzenia wczytana liczbe zespolona, a
 *    w przeciwnym przypadku wyswietla też stosowny komunikat o
 *    bledzie.
 */
LZespolona WczytajLZ ()
{
  LZespolona LZ;
  char pom;

  cin >> pom;
  if (pom == '(')
  {
    cin >> LZ.re;
    cin >> LZ.im;
    cin >> pom;
    if (pom != 'i')
    {
      cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
    } else {
      cin >> pom;
      if (pom != ')')
      {
        cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
      }
    }
  } else {
    cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
  }
  return LZ;
}



/*
 * Funkcja wyswietla na standardowym wyjsciu
 * liczbe zespolona.
 * 
 * Argument:
 *    Wynik - liczba zespolona, ktora
 *            zostanie wyswietlona.
 * 
 * Warunek wstepny:
 *    - Poprawnie zainicjowane elementy
 *      struktury LZespolona.
 */ 
void Wyswietl (LZespolona Wynik)
{
  cout << " (" << Wynik.re;
  if (Wynik.im >= 0) 
    {
      cout << "+" << Wynik.im << "i)";
    } else {
      cout << Wynik.im << "i)";
    }
}



/*
 * Funkcja wczytuje liczbe zespolona wpisana
 * przez uzytkownika na standardowym wejsciu.
 * 
 * Argumenty:
 *      StreamWej - zmienna typu istream
 *                  przekazana przez referencje,
 *      LZ - liczba zespolona, ktora zostanie
 *           wczytana. (tez przekazana przez
 *           referencje)
 * 
 * Warunek wstepny:
 *      - Pierwszy parametr musi byc przekazany
 *        przez referencje.
 *      - Drugi parametr tez musi byc przekazany
 *        przez referencje.
 *      - Liczba zespolona musi byc wpisana przez uzytkownika
 *        w odpowiedniej postaci, np.: (1+2i).
 *        (wpisanie w innej postaci powoduje postawienie 
 *        odpowniedniej flagi sygnalizujacej wystapienie bledu
 *        podczas wczytywania)
 * 
 * Zwraca:
 *      Referencje do pierwszego parametru.
 */ 
istream & operator >> (istream & StreamWej, LZespolona & LZ)
{
  char pom;

  StreamWej >> pom;
  if (pom == '(')
  {
    StreamWej >> LZ.re;
    StreamWej >> LZ.im;
    StreamWej >> pom;
    if (pom == 'i')
    {
      StreamWej >> pom;     
      if (!StreamWej.eof())
      {  
        if (pom == ')')
        {
          return StreamWej;
        } else {
          StreamWej.setstate(ios_base::failbit);       
        }
      } else {
          StreamWej.setstate(ios_base::failbit);
      }  
    } else {
      StreamWej.setstate(ios_base::failbit);
    }
  } else {
    StreamWej.setstate(ios_base::failbit);
  }
  return StreamWej;
}



/*
 * Funkcja wyswietla na standardowym wyjsciu
 * liczbe zespolona.
 * 
 * Argumenty:
 *      StreamWyj - zmienna typu ostream
 *                  przekazana przez referencje,
 *      LZ - liczba zespolona, ktora zostanie
 *           wyswietlona.
 * 
 * Warunki wstepne:
 *      - Pierwszy parametr musi byc przekazany
 *        przez referencje.
 *      - Poprawnie zainicjowane elementy 
 *        struktury LZespolona.
 * 
 * Zwraca:
 *       Referencje do pierwszego parametru.
 */ 
ostream & operator << (ostream & StreamWyj, LZespolona LZ)
{
  StreamWyj << " (" << LZ.re;
  if (LZ.im >= 0)
  {
    StreamWyj << "+" << LZ.im << "i)";
  } else {
    StreamWyj << LZ.im << "i)";
  }
  return StreamWyj;
}



/*
 * Funkcja porównuje ze soba dwie
 * liczby zespolone.
 *
 * Argumenty:
 *      LZ1 - pierwsza z porównywanych liczb,
 *      LZ2 - druga z porównywanych liczb.
 *
 * Zwraca:
 *      True jeśli liczby sa takie same lub
 *      false jeśli roznia sie.
 */
bool operator == (LZespolona LZ1, LZespolona LZ2)
{
   if (LZ1.re != LZ2.re || LZ1.im != LZ2.im)
    {
      cout << " Blad. Prawidlowym wynikiem jest:" << LZ2 << endl;
      cout << endl;
      return false;
    } else {
      cout << " Odpowiedz poprawna" << endl;
      cout << endl;
      return true;
    }
}



/*
 * Realizuje dzielenie modulo dwoch liczb
 * zespolonych.
 *
 * Argumenty:
 *      LZ1 - pierwszy element dzielenia modulo,
 *      LZ2 - drugi element dzielenia modulo.
 *
 * Warunek wstepny:
 *      - Czesc rzeczywista i urojona drugiego
 *        elementu dzialania musza byc rozne od 
 *        zera.
 *
 * Zwraca:
 *      Zwraca liczbe zespolona, ktorej czesc
 *      rzeczywista jest wynikiem dzielenia modulo
 *      czesci rzeczywistych elementow dzialania oraz
 *      czesc urojona jest wynikiem dzielenia modulo
 *      czesci urojonych elementow dzialania.
 */
LZespolona operator % (LZespolona LZ1, LZespolona LZ2)
{
  int pomre, pomim, LZ1rei, LZ1imi, LZ2rei, LZ2imi;
  LZespolona pomLZ;

  LZ1rei = LZ1.re;
  LZ1imi = LZ1.im;
  LZ2rei = LZ2.re;
  LZ2imi = LZ2.im;

  pomre = LZ1rei % LZ2rei;
  pomim = LZ1imi % LZ2imi;

  if (pomre == 0 && pomim == 0)
  {
    pomLZ.re = pomre;
    pomLZ.im = pomim;
  }

  if (pomre != 0 && pomim != 0)
  {
    pomLZ.re = pomre;
    pomLZ.im = pomim;
  }

  if (pomre != 0 && pomim == 0)
  {
    pomLZ.re = pomre;
    pomLZ.im = pomim;
  }
  
  return pomLZ;
}