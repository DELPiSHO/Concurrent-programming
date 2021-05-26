Utworzyć skrypt o dwóch argumentach: 

szukaj plik katalog 

który (podobnie, jak polecenie find) znajduje wszystkie wystąpienia pliku o podanej nazwie plik w poddrzewie katalogów zaczynając od podanej nazwy ścieżkowej katalog. Skrypt powinien działać na zasadzie współbieżnych, rekurencyjnych wywołań dla wszystkich podkatalogów danego katalogu i powinien wykorzystywać  mechanizm exit - wait do przekazywania informacji od procesów potomnych do rodzicielskich.

Uwaga: w przypadku, gdy skrypt nie znajdzie ani jednego wystąpienia danego pliku, powinien wyświetlić komunikat "Nie znaleziono", ale TYLKO RAZ.