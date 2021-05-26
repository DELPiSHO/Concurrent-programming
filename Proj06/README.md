Utworzyć program serwera udostępniającego dwie kolejki komunikatów: wejściową i wyjściową, oraz program klienta przesyłającego pojedyncze zapytanie z PID-em swojego procesu jako typem komunikatu, a następnie odbierającego odpowiedź z drugiej kolejki.

Serwer realizuje funkcję słownika polsko-angielskiego (otrzymuje napis zawierający słowo polskie i odsyła odpowiadające mu słowo angielskie lub komunikat "Nie znam takiego słowa").

UWAGI 

przyjąć, że numery (klucze) obu kolejek serwera są ustalone i znane klientowi.
ponieważ są osobne kolejki wejściowa i wyjściowa, serwer może odbierać komunikaty dowolnego typu (parametr mtype = 0), a odpowiedzi do klientów mogę iść do wspólnej kolejki bo rozróżni je typ będący  numerem procesu klienta
