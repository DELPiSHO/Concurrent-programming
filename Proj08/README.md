Utworzyć prostą aplikację typu klient-serwer opartą na komunikacji  przez gniazdo datagramowe w domenie internetowej . 

Uruchamiamy lokalnie serwer prostej funkcji arytmetycznej, który przez port UDP o numerze np. 5000 przyjmuje jedną liczbę całkowitą czterobajtową (int) i w odpowiedzi odsyła jedną liczbę tego samego typu - wynik jakiegoś prostego obliczenia. Przykład takiego serwera w C jest zapisany w pliku serwerUDP.c (z niewypełnionym realizowanym obliczeniem). Napisać program klienta, który komunikuje się z tym lokalnym  serwerem czyli na IP 127.0.0.1

UWAGA: pamiętać o przekształcaniu danych i adresu do postaci sieciowej i na odwrót (funkcje htonl() i ntohl()).