#Linked List

**Dlaczego Linked List**\
Wybieramy Linked List dlatego, że tablice mają następujące ograniczenia:\
**1.** Rozmiar tablicy jest stały: musi więc znać górną granicę liczby elementów z góry. Ponadto tablica zawsze zajmuje tyle samo pamięci niezależnie od ilości elementów znajdujących się w niej.\
**2.** Wstawienie nowego elementu jest kosztowne ponieważ wymaga przesunięcia reszty elementów. Tak samo jest z usunięciem elementu\\

**Przewaga Linked List nad tablicami**\
**1.** Dynamiczny rozmiar\
**2.** Latwość wstawiania / usuwania\

**Wady Linked List**\
**1.** Brak losowego dostepu, musimy zawsze zaczynać od początku\
**2.** Dodatkowe miejsce na wskaźniki\
**3.** Nie jest przyjazne dla pamięci podręcznej, elementy sa porozrzucane w pamięci głównej\

**Reprezentacja**\
Lista jest reprezentowana przez wskaźnik do pierwszego elementu, pierwszy element zawiera wskaźnik do kolejnego i tak dalej. Jeśli połaczona jest lista pusta wskaźnik wskazuje na NULL. Każdy węzeł na liście składa się z co najmniej dwóch części:\
1. dane\
2. Wskaźnik do następnego węzła\

W C reprezentujemy Liste za pomoca struktur, w pozostałych językach (C++, Java, Python) za pomocą klas.\
