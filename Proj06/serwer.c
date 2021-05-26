#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<signal.h>

#define WORD_LEN 512
#define SLOWNIK_SIZE 8
#define SERWER_KEY 666
#define KLIENT_KEY 333

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

wejscie slownik[SLOWNIK_SIZE] =
{
	{ "samochód", "car"},
        { "broń", "gun"},
        { "może", "maybe"},
        { "karta", "card"},
        { "kot", "cat"},
        { "pies", "dog"},
        { "skończony", "complete"},
	{ "Ronaldo", "Best football player"},
};

int g_klientKolejka;
int g_serwerKolejka;

void cleanup(int signal)
{
        msgctl(g_klientKolejka, IPC_RMID,0);
        msgctl(g_serwerKolejka, IPC_RMID,0);
        exit(0);
}

char* tlumacz(char* slowo)
{
        int i = 0;
        for (i; i< SLOWNIK_SIZE;i++)
        {
                if(strcmp(slowo, slownik[i].polski) == 0)
                        return slownik[i].angielski;
        }
        return "[Nie ma takiego słowa w słowniku]";
}

int main()
{
        signal(SIGINT , cleanup);
        g_klientKolejka = msgget(KLIENT_KEY, 0666 | IPC_CREAT);
        g_serwerKolejka = msgget(SERWER_KEY, 0666 | IPC_CREAT);

        wiadomosc wdm;
        while(1)
        {
                msgrcv(g_serwerKolejka, &wdm, sizeof(char) * WORD_LEN, 0, 0);
                strcpy(wdm.slowo,tlumacz(wdm.slowo));
                msgsnd(g_klientKolejka,&wdm, sizeof(char) * WORD_LEN, 0);
        }
return 0;
}
