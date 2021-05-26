#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define WORD_LEN 512
#define KLIENT_KEY 333
#define SERWER_KEY 666

typedef struct wejscie_t
{
	char polski[WORD_LEN];
	char angielski[WORD_LEN];
} wejscie;

typedef struct wiadomosc_t
{
	long type;
	char slowo[WORD_LEN];
} wiadomosc;

int main(int argc,char* argv[])
{
	int klientKolejka = msgget(KLIENT_KEY, 0666);
	int serwerKolejka = msgget(SERWER_KEY, 0666);

	wiadomosc wdm;
	strcpy(wdm.slowo,argv[1]);
	wdm.type = 1;

	msgsnd(serwerKolejka, &wdm, sizeof(char) * WORD_LEN, 0);
	msgrcv(klientKolejka, &wdm, sizeof(char) * WORD_LEN, 0, 0);

	printf("POLSKI: %s\n",argv[1]);
	printf("ANGIELSKI: %s\n",wdm.slowo);

	return 0;
}

