#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PERMISION 0777

void getMessage()
{
   int dane = 0;
   char bufor[512];
   memset(&bufor[0], 0, sizeof(bufor));

   while((dane = open("dane.txt", O_RDWR,PERMISION)) < 0) {}

   if(dane != 0)
   {
     while(read(dane,bufor,512) < 1) {}
     printf("\nKLIENT WYSŁAŁ WIADOMOŚĆ:\n%s", bufor);
     printf("\n");
   }
}

void sendMessage()
{
	int wyniki;
	char bufor[512];
	memset(&bufor[0], 0, sizeof(bufor));
	char znak;
	int licznik = 0;

	while(1)
	{
		wyniki = open("wyniki.txt", O_RDWR|O_CREAT|O_EXCL, PERMISION);
		if(wyniki != 0)
		{
			printf("WIADOMOŚĆ ZWROTNA DLA KLIENTA:\n");
			while((znak = getchar()) != 27)
			{
				bufor[licznik] = znak;
				licznik++;
			}
			write(wyniki, bufor, licznik);
//                        close(wyniki);
                        break;
		}
	}
}

void disconnect()
{
		unlink("lockfile");
		unlink("dane.txt");
}

void header()
{
  printf("\n");
  printf("Serwer uruchomiony, oczekuję na zgłoszenia...\n");
}

int main()
{
  header();
	while(1)
	{
		getMessage();
		sendMessage();
		disconnect();
		printf("\nSerwer oczekuje na kolejne zgłoszenie...");
		printf("\n\n");
	}
	return 0;
}
