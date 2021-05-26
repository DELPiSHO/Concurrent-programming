#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PERMISION 0777

void connect()
{
	while (open("lockfile",O_CREAT|O_EXCL, 0)==-1)
  	{
    		printf("Serwer zajęty, proszę czekać!\n");
    		sleep(3);
  	}
}

void sendMessage()
{
	int dane;
	char bufor[512];
	memset(&bufor[0], 0, sizeof(bufor));
	char znak;
	int licznik = 0;

	char nazwa_uzytkownika[100];
	getlogin_r(nazwa_uzytkownika, 100);
	char output[1024];

	while(1)
	{
		dane = open("dane.txt", O_RDWR|O_CREAT|O_APPEND, PERMISION);
		if(dane != 0)
		{
			printf("\n%s:\n", nazwa_uzytkownika);
			while((znak = getchar()) != 27)
			{
				bufor[licznik] = znak;
				licznik++;
			}
			licznik = sprintf(output, "%s:\n%s ", nazwa_uzytkownika, bufor);
                       	write(dane, output, licznik);
			close(dane);
                       	break;

		}
	}
}

void getMessage()
{
	int wyniki = 0;
	char bufor[512];
	memset(&bufor[0], 0, sizeof(bufor));

	while((wyniki = open("wyniki.txt", O_RDWR, PERMISION)) < 0) {}
		if(wyniki != 0)
		{
			while(read(wyniki,bufor,512) < 1) {}
			printf("\nSERWER WYSŁAŁ WIADOMOŚĆ:\n%s", bufor);
			printf("\n");
		}
}

void disconnect()
{
	unlink("wyniki.txt");
}

void header(char nazwa_uzytkownika[100])
{
	printf("Wyślij wiadomość do serwera i czekaj na odpowiedź.");
	printf("\n");
	printf("UŻYTKOWNIK: %s\n", nazwa_uzytkownika);
}

int main(int argc, char *argv[])
{
	char nazwa_uzytkownika[100];
	getlogin_r(nazwa_uzytkownika, 100);
	header(nazwa_uzytkownika);
	connect();
	sendMessage();
	getMessage();
	disconnect();
  getchar();
  return 0;
}
