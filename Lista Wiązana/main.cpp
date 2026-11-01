#include <iostream>

using namespace std;

template <typename T> // Dzialanie listy dla odowlnego rodzaju danych
class ListaJednokierunkowa {
    public:
        using element = T;

        // Wezel listy komorka
        sruct cell {
            element val; // Wartosc w jednej komorce
            cell* next// Adres do nastepnej komorki

            // Konstruktor cell
            cell(element v, cell* n = nullptr) : val(v), next(n) {}
        }
    protected:
        cell * header; // głowa listy
    public:
        Lista();    //konstruktor
        ~Lista();  //destruktor
        void Insert(element x, cell * p); // wstawia element x na pozycję next komórki o wskaźniku p
                                                         // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
        bool Delete(cell * p); // usuwa komórkę z pozycji next komórki o wskaźniku p i zwraca true; zwraca false, gdy usunięcie nie jest możliwe
        element Retrieve(cell * p); // zwraca element komórki o wskaźniku p
        cell * Locate(element x); // zwraca wskaźnik do pierwszej komórki z elementem x
        cell * First(); // zwraca wskaźnik do pierwszej komórki na liście
        cell * Next(cell * p); // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
        cell * Previous(cell * p); // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
        cell * Last(); // zwraca wskaźnik do ostatniej komórki na liście

        void print(); // wyświetla wszystkie elementy listy
};

int main() {
    return 0;
}
