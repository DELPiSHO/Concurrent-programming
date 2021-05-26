Zaprogramować grę w "kółko i krzyżyk" dla dwóch graczy (plansza - tablica znakowa 3x3, wypełniona spacjami, znakami 'X' lub 'O'). Umieścić planszę w pamięci współdzielonej, zapewnić synchronizację dostępu przy użyciu pary semaforów. 

Należy ulepszyć rozwiązanie synchronizacji podane tutaj, w postaci dwóch komunikujących się programów  rozm1a.c, rozm2a.c i zrobić JEDEN (uniwersalny) program do użytku obu graczy - wstępną rywalizację o wykonanie pierwszego ruchu (i używanie znaków 'X') wygrywa ten, kto jako pierwszy utworzy tablicę semaforów (wskazówka: ...IPC_CREAT|IPC_EXCL ...). 

Program powinien sprawdzać prawidłowość ruchów (wykluczać pola już zajęte i poza planszą), rozpoznawać sytuację wygranej, przegranej i remisu oraz  wyświetlać obu graczom odpowiednie komunikaty.