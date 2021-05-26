Utworzyć prostą parę programów klient - serwer iteracyjny, komunikujące się przez dwa pliki (dla danych i wyników), działając na zasadzie ciągłego odpytywania plików (w pętli aktywnego czekania).

 
    wczytanie                     |  dane  |
    ---------> |--------------| -->------------> |--------------|
               |proces klienta|                  |proces serwera|
    <--------- |--------------| <------------<-- |--------------|
    wyświetlenie                   | wyniki |
                               
Klient pobiera z klawiatury i zapisuje do pliku dane: pojedynczą liczbę całkowitą. Serwer pobiera daną z pliku, oblicza jakąś prostą funkcję arytmetyczną (np. nieduży wielomian) i wynik zapisuje do pliku wyniki . Klient odbiera odpowiedź z pliku, wyświetla i kończy działanie. Serwer działa nadal w pętli oczekując na kolejne zgłoszenia.
UWAGI:

Nie wprowadzać żadnych "sztucznych opóźnień" (sleep, wyświetlanie tekstów przez serwer itp.).
Pamiętać o natychmiastowym (zaraz po odczytaniu) opróżnianiu buforów po stronie serwera i po stronie klienta.
Uruchamiać najpierw serwer, a potem dopiero klienta.