Rozbudować parę programów z zadania wprowadzającego  tak, aby otrzymać parę klient-serwer składającą się na prosty komunikator tekstowy. Plikom będącym buforami klienta i serwera przydzielić odpowiednie prawa dostępu (na czas trwania zajęć).

Do zrozumienia poniższego opisu pomocny może być następujący szkic.

Serwer działa w pętli nieskończonej, klient tylko jednorazowo (pytanie - odpowiedź). Program klienta jako parametr wywołania otrzymuje nazwę pliku z danymi wejściowymi dla serwera (tylko nazwa pliku, jeżeli klienta i serwera uruchamiamy w tym samym katalogu, w przeciwnym razie trzeba podać całą ścieżkę do pliku). Serwer jest jeden, klientów może być wielu, działających równocześnie, np. z różnych okien.

Klient przesyła do bufora serwera:

nazwę swojego pliku do przesłania odpowiedzi (każdy klient ma swój osobny plik);
kolejne linie swojego tekstu wprowadzonego przez użytkownika (dowolnie dużo);
znacznik końca tekstu (kod Esc).
Serwer (działający w innym oknie) czyta i wyświetla cały tekst  klienta po czym odsyła klientowi:
kolejne linie swojego tekstu (wprowadzone ręcznie przez właściciela serwera);
znacznik końca tekstu (kod Esc).
Dostęp do bufora serwera powinien być synchronizowany plikiem zamkowym (lockfile) tworzonym przez klienta w katalogu roboczym serwera i usuwanym przez serwer po udzieleniu odpowiedzi klientowi. Jeżeli serwer czasowo nie jest dostępny, klient wyświetla w pętli co kilka sekund informację: Serwer zajęty, proszę czekać.  Wykorzystać w programie klienta następującą konstrukcję (lub jej odpowiednik, jeżeli używamy innych bibliotek operujących na plikach):
   ...
   
   while (open("ścieżka_dostępu/lockfile",O_CREAT|O_EXCL,0)==-1) {
      printf("Serwer zajety, prosze czekac\n");
      sleep( ... );
   }
   
   ...
   
Po udzieleniu odpowiedzi serwer usuwa utworzony przez klienta plik lockfile.
UWAGA 1: Żeby przetestować sytuację, że serwer może być zajęty, należy utworzyć dwóch klientów: jeden wysyła do serwera dane, a drugi, jeszcze przed odpowiedzią serwera do pierwszego też próbuje się skomunikować z serwerem.

UWAGA 2: W przypadku uruchamiania programów na sigmie, mogą wystąpić opóźnienia związane z działaniem sieciowego systemu plików. W przypadku wystąpienia takich problemów należy przenieść bufory do katalogu /var/sandbox i tam testować programy.

