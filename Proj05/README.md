Napisać program serwera prostej wielodostępnej bazy danych oraz program klienta tej usługi.

Baza danych to tablica o rozmiarze 5 elementów, zawierająca struktury:

     {int ID; char *nazwisko;}
  
(maksymalna długość nazwiska - 20 znaków wraz z kończącym znakiem pustym). Baza danych jest tworzona i wypełniana statycznie przez program serwera. Serwer odbiera ze swojej kolejki wejściowej zapytanie zawierające ID i odsyła do kolejki klienta odpowiadające mu nazwisko lub komunikat "Nie ma", jeżlei nie ma w tablicy takiego ID.
Struktura komunikatu od klienta do serwera:

   ------------------------------------------------ ............ -----------
   |       int        |       int       |    łańcuch (zmienna długość)     |
   ------------------------------------------------ ............ -----------
    długość pozostałej         ID                  $HOME klienta              
    części komunikatu                              lub pełna ścieżka do kolejki

  
Struktura komunikatu od serwera do klienta:
   
   ------------------------------ ............. -----------
   |       int        |     łańcuch (zmienna długość)     |
   ------------------------------ ............. -----------
    długość pozostałej              odpowiedż
    części komunikatu
Nazwa kolejki odbiorczej serwera: serwerfifo .
Nazwa kolejki odbiorczej klienta: klientfifo .

Serwer działa w pętli nieskończonej, klient tylko jednorazowo (pytanie - odpowiedź).

UWAGA: zapewnić niepodzielność wysyłania komunikatów (użyć pojedynczego wywołania funkcji write() do wysłania całego komunikatu).

