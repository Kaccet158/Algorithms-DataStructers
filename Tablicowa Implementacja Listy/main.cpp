#include <iostream>
#include <climits>

using namespace std;

using element = int; // Definiowanie typu elementu jako "int"

const int MAX_ROZMIAR = 100; // Max rozmiar tablicy

// Tworzenie klasy
class TablicaListowna {
    private:
        element dane[MAX_ROZMIAR]; // Tablica na elementy
        int last; // ostatni lement
    public:
        // Jesli tablica nie ma zadnych eleemntow
        TablicaListowna() {
            last = -1;
        }

        // First()
        int First() const {
            // Jesli nie ma elementow (-1)
            if(last == -1) {
                return -1;
            }
            return 0; // Indeks pierwszego elementu (0)
        }

        // End()
        int End() const {
            return last + 1; // Pozycja za ostatnim elementem
        }

        // Next(int p) - zwraca nastepny element
        int Next(int p) const {
            if(p >= 0 && p < last) {
                return p + 1; // Kolejny element
            }
            return -1; // Jesli nie istnieje
        }

        // Previous(int p)
        int Previous(int p) const {
            if(p > 0 && p <= last) {
                return p - 1; // Poprzedni element
            }
            return -1; // Jesli nie istnieje
        }

        // Insert(element x, int p)
        bool  Insert(element x, int p) {
            // Miejsce w tablicy
            if( last + 1 >=MAX_ROZMIAR ) {
                return false;
            }

            // Przedzial <0, last + 1> pozycji p
            if( 0 > p || p >= last + 1) {
                return false;
            }

            // Przesuniecie elementow
            for( int i = last; i >= p; i-- ) {
                dane[i+1] = dane[i]; // Przesuniecie, po prstu elementy ida o 1 do przodu od p
            }

            // Wstawienie elementu
            dane[p] = x;
            last++; // Bo przybywa nowy element w liscie najoeirw przesuwamy wszystko w prawo więc jest o 1 wiecej
            return true;
        }

        // Usuniecie elementu
        bool Delete(p) {
            // Przedzial <0, last + 1> pozycji p
            if( p < 0 || p > last ) {
                return false;
            }

            // Przesuniecie w lewo
            for( int i = p; i < last; i++) {
                dane[i] = dane[i+1];
            }

            last--;
            return true;
        }
}

// Locate(element x) - w
    int Locate(element x) const {
        for (int i = 0; i <= last; i++) {
            if (data[i] == x) {
                return i; // Znaleziono
            }
        }
        return -1;
    }

    // Retrieve(int p) - z
    element Retrieve(int p) const {
        if (p >= 0 && p <= last) {
            return data[p];
        }
        return INT_MIN;
    }

    // Metoda pomocnicza do podglądu zawartości listy
    void Print() const {
        cout << "Lista (rozmiar: " << last + 1 << "): [ ";
        for (int i = 0; i <= last; i++) {
            cout << dane[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    TablicaListowna l;

    cout << "Poczatkowy First(): " << l.First() << "\n"; // -1 (pusta)
    cout << "Poczatkowy End(): " << l.End() << "\n";     // 0

    // Wstawianie elementow
    l.Insert(10, 0);
    l.Insert(20, 1);
    l.Insert(30, 2);
    l.Insert(99, 1);
    l.Print();

    // Test nawigacji
    cout << "Pierwszy element na indeksie: " << l.First() << "\n"; // 0
    cout << "Nastepnik indeksu 1: " << l.Next(1) << "\n";           // 2
    cout << "Poprzednik indeksu 1: " << l.Previous(1) << "\n";       // 0
    cout << "Nastepnik ostatniego (" << l.End() - 1 << "): " << l.Next(3) << "\n"; // -1

    // Pobranie i lokalizacja
    cout << "Wartos pod indeksem 1: " << l.Retrieve(1) << "\n"; // 99
    cout << "Pozycja wartosci 20: " << l.Locate(20) << "\n";     // 2
    cout << "Pozycja wartosci 777: " << l.Locate(777) << "\n";   // -1

    // Usuwanie
    l.Delete(1);
    l.Print();

    return 0;
}
