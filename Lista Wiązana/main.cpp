#include <iostream>
#include <stdexcept> // Wymagany do runtime_error

using namespace std;

template <typename T> // Działanie listy dla dowolnego rodzaju danych
class ListaJednokierunkowa {
    public:
        using element = T;

        // Węzeł listy komórka
        struct cell {
            element val; // Wartosc w jednej komorce
            cell* next// Adres do nastepnej komorki

            // Konstrukcja cell
            cell(element v, cell* n = nullptr) : val(v), next(n) {}
            };
    protected:
        cell * header; // głowa listy
    public:
        ListaJednokierunkowa() : header(nullptr);    // Konstruktor pustej listy
        ~ListaJednokierunkowa() {
            while(header!=nullptr) {
                cell* temp = header; // Wsazuje zawsze na pierwszą komórkę (tą po head)
                header = header -> next; // Przeskakuje na nastepną (next)
                delete temp; // Usuwa węzeł
            }
        };  // Destruktor zwalnia pamięć

        // wstawia element x na pozycję next komórki o wskaźniku p (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
        void Insert(element x, cell * p) {
            if(header == nullptr ||p == nullptr) {
                // Wstawienie na poczatek listy, gdy 1) jest pusta LUB 2) ma elementy ale chcemy na poczatek
                cell* new_cell = new cell(x, header); // Zmiana wskazywania nowa komórka wskazuje na to co wskazywał header
                header = new_cell; // Header wsazuje na nową komórke
            } else {
                // Wsawienie elementu na pozycje komórki p
                cell* new_cell = new cell(x, p->next); // Zmiana nowa komórka ma pokazywać na to co pokazywała komórka p
                p->next = new_cell; // Komórka p wsazuej na nową komórke tak jakby tą co była w jej miejscu
            }
        };

        // usuwa komórkę z pozycji next komórki o wskaźniku p i zwraca true; zwraca false, gdy usunięcie nie jest możliwe
        bool Delete(cell * p) {
            // Gdy header jest puste
            if(header == nullptr) { return false; } // Poniewaz nie moze nic usunąć (pusta lista)

            // Usunięcie elementu jeśli p jest nullptr
            if(p == nullptr) {
                cell* to_delete = header; // Usuwanie tej komórki na którą wskazuje header
                header = to_delete->next; // Zmiana tego naco header wskazuje
                delete to_delete;
                return true;
            }

            // Usunięcie elementu za p, który jest nullptr
            if(p->next==nullptr) {
                return false;
            }

            // Reszta przypadków
            cell* to_delete = p->next; // Wskazanie komórki do usunięcia
            p->next = to_delete->next; // Zmiana wsazywanai na to co wskazywała usunięta komórka
            delete to_delete;
            return true;
        };

        // zwraca element komórki o wskaźniku p
        element Retrieve(cell * p) {
            // Jeśli wartość nullptr
            if(p==nullptr) {
                throw runtime_error("Error - Proba pobrania wartosci nullptr"); // Wyrzucenie błedu
            }

           // Reszta przypadków
           return p->val; // Zwrócenie wartości
        };

        // Zwraca wskaźnik do pierwszej komórki z elementem x
        cell * Locate(element x) {
            cell* current = header; // Zaczyna od samego początku
            while(current!=nullptr) {
                if(current->val == x) // Sprawdza czy to ta wartość
                    return current;
                current = current->next;
            }
            return nullptr; // Jeśli nie znajdzie takiej wartości
        };

        // Zwraca wskaźnik do pierwszej komórki na liście
        cell * First() {
            return header; // Zwraca wsażnik na głowe - pustą komórke
            // return header-> next; // Tutaj już na tą z wartościami
        };

        // Zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
        cell * Next(cell * p) {
            if(p!=nullptr) {
                return p->next;
            }
            return nullptr;
            /* cell* current = p;
                return current->next; */
        };

        // Zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
        cell * Previous(cell * p) {
            cell* current = header;
            if(p==nullptr || p==header) { return nullptr; } // Bo brak
            // Sprawdza od głowy do ostatniego przed p, jeśli current == p to pętla się kończy i to oznacza, że ten current jest wskaźnikiem poprzedzającym p
            while(current!=nullptr && current->t!=p) {
                current = current->next; // Przejście
            }
            return current;
        };

        cell * Last(); // zwraca wskaźnik do ostatniej komórki na liście

        void print(); // wyświetla wszystkie elementy listy
};

int main() {
    return 0;
}
