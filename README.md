# Drzewo binarne

Prosty program w języku **C++**, który przedstawia działanie drzewa binarnego wyszukiwania (BST).

## Opis projektu

Program umożliwia:
- tworzenie drzewa binarnego,
- dodawanie elementów do drzewa,
- wyświetlanie elementów drzewa,
- automatyczne usuwanie elementów drzewa za pomocą destruktora.

Projekt wykorzystuje **klasę `Drzewo`**, konstruktor oraz destruktor.

## Zasada działania

Każdy węzeł drzewa przechowuje:
- liczbę,
- wskaźnik na lewe dziecko,
- wskaźnik na prawe dziecko.

Podczas dodawania elementu:
- liczby mniejsze od aktualnego węzła trafiają do lewego poddrzewa,
- liczby większe lub równe aktualnemu węzłowi trafiają do prawego poddrzewa.

## Zastosowane elementy C++

W projekcie wykorzystano:
- klasy,
- konstruktor,
- destruktor,
- wskaźniki,
- dynamiczne tworzenie obiektów za pomocą `new`,
- usuwanie obiektów za pomocą `delete`,
- rekurencję.

## Przykładowe dane

Do drzewa dodawane są liczby:

```text
10, 5, 15, 3, 7, 9, 2, 2, 4
```
Wyświetlanie

Elementy drzewa są wyświetlane w kolejności od najmniejszej do największej.

Przykładowy wynik:
```
2 2 3 4 5 7 9 10 15
```
Struktura klasy

Klasa Drzewo posiada:
```
int liczba;
Drzewo* lewy;
Drzewo* prawy;
```

Konstruktor tworzy nowy węzeł i ustawia jego wartość oraz wskaźniki na nullptr.
Destruktor usuwa lewe i prawe poddrzewo, dzięki czemu pamięć zajmowana przez drzewo zostaje zwolniona.

Program można skompilować za pomocą kompilatora C++, np.:
```
g++ drzewo.cpp -o drzewo
```
Następnie uruchomić:
```
./drzewo
```
Autor
Nicolas Cage
Projekt wykonany w ramach nauki języka C++.

:::
