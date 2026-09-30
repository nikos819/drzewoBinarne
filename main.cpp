#include <iostream>
using namespace std;

// Klasa reprezentująca pojedynczy węzeł drzewa binarnego
class Drzewo {

    // Wartość przechowywana w aktualnym węźle
    int liczba;

    // Wskaźnik na lewe dziecko
    // Będzie przechowywało liczby mniejsze od aktualnej
    Drzewo* lewy;

    // Wskaźnik na prawe dziecko
    // Będzie przechowywało liczby większe lub równe aktualnej
    Drzewo* prawy;

public:

    // ==========================================
    // KONSTRUKTOR
    // ==========================================
    // Konstruktor otrzymuje liczbę, którą
    // chcemy zapisać w nowym węźle
    Drzewo(int w) {

        // Przypisujemy podaną wartość do węzła
        liczba = w;

        // Na początku węzeł nie ma lewego dziecka
        // dlatego ustawiamy wskaźnik na nullptr
        lewy = nullptr;

        // Na początku węzeł nie ma prawego dziecka
        // dlatego ustawiamy wskaźnik na nullptr
        prawy = nullptr;
    }


    // ==========================================
    // DODAWANIE ELEMENTU DO DRZEWA
    // ==========================================
    void dodaj(int w) {

        // Sprawdzamy, czy nowa liczba jest
        // mniejsza od liczby w aktualnym węźle
        if (w < liczba) {

            // Jeżeli nie ma lewego dziecka,
            // możemy utworzyć nowy węzeł
            if (lewy == nullptr) {

                // Tworzymy nowy węzeł za pomocą konstruktora
                // i zapisujemy go jako lewe dziecko
                lewy = new Drzewo(w);

            } else {

                // Jeżeli lewe dziecko już istnieje,
                // wywołujemy dodaj() dla lewego poddrzewa
                lewy->dodaj(w);
            }
        }

        // Jeżeli liczba jest większa lub równa
        // aktualnej liczbie, idziemy w prawo
        else {

            // Sprawdzamy, czy prawe dziecko istnieje
            if (prawy == nullptr) {

                // Jeżeli nie istnieje, tworzymy nowy węzeł
                // i zapisujemy go jako prawe dziecko
                prawy = new Drzewo(w);

            } else {

                // Jeżeli prawe dziecko już istnieje,
                // wywołujemy dodaj() dla prawego poddrzewa
                prawy->dodaj(w);
            }
        }
    }


    // ==========================================
    // WYŚWIETLANIE ELEMENTÓW DRZEWA
    // ==========================================
    void wyswietl() {

        // Najpierw sprawdzamy lewe poddrzewo
        if (lewy != nullptr) {

            // Jeżeli istnieje, wyświetlamy je
            lewy->wyswietl();
        }

        // Wyświetlamy wartość aktualnego węzła
        cout << liczba << " ";

        // Na końcu sprawdzamy prawe poddrzewo
        if (prawy != nullptr) {

            // Jeżeli istnieje, wyświetlamy je
            prawy->wyswietl();
        }
    }


    // ==========================================
    // DESTRUKTOR
    // ==========================================
    // Destruktor jest automatycznie wywoływany
    // podczas usuwania obiektu
    ~Drzewo() {

        // Usuwamy lewe poddrzewo
        // delete wywoła również destruktor
        // dla kolejnych elementów tego poddrzewa
        delete lewy;

        // Usuwamy prawe poddrzewo
        // w ten sam sposób
        delete prawy;
    }
};


// ==========================================
// FUNKCJA GŁÓWNA PROGRAMU
// ==========================================
int main() {

    // Wyświetlamy tekst na początku programu
    cout << "Elementy drzewa: ";


    // ==========================================
    // TWORZENIE KORZENIA DRZEWA
    // ==========================================

    // Tworzymy pierwszy węzeł drzewa.
    // Liczba 10 będzie korzeniem drzewa.
    //
    // new tworzy obiekt w pamięci dynamicznej,
    // a konstruktor Drzewo(10) ustawia jego wartość.
    Drzewo* d = new Drzewo(10);


    // ==========================================
    // DODAWANIE ELEMENTÓW
    // ==========================================

    // Dodajemy liczbę 5
    d->dodaj(5);

    // Dodajemy liczbę 15
    d->dodaj(15);

    // Dodajemy liczbę 3
    d->dodaj(3);

    // Dodajemy liczbę 7
    d->dodaj(7);

    // Dodajemy liczbę 9
    d->dodaj(9);

    // Dodajemy liczbę 2
    d->dodaj(2);

    // Dodajemy ponownie liczbę 2
    // Liczby równe są umieszczane po prawej stronie
    d->dodaj(2);

    // Dodajemy liczbę 4
    d->dodaj(4);


    // ==========================================
    // WYŚWIETLENIE DRZEWA
    // ==========================================

    // Wywołujemy funkcję wyswietl()
    // która przechodzi przez całe drzewo
    // w kolejności:
    // lewe poddrzewo -> korzeń -> prawe poddrzewo
    //
    // Dzięki temu liczby zostaną wyświetlone
    // od najmniejszej do największej.
    d->wyswietl();


    // Przechodzimy do nowej linii
    cout << endl;


    // ==========================================
    // USUNIĘCIE DRZEWA
    // ==========================================

    // Usuwamy korzeń drzewa.
    //
    // Wywołany zostanie destruktor ~Drzewo().
    // Destruktor usunie również lewe i prawe
    // poddrzewo, dzięki czemu zwolniona zostanie
    // cała pamięć zajmowana przez drzewo.
    delete d;


    // Zakończenie programu
    return 0;
}
