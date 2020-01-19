#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msg_t
{
     long mtype; //ez egy szabadon hasznalhato ertek, pl uzenetek osztalyozasara
     char mtext[1024];
};

typedef int bool;
enum
{
    false,
    true
};

typedef struct rendeles
{
    char lakcim[100];
    float meret;
    char reszmunkak[100];
    struct tm *mtime;
    char eredmeny[100];

}rendeles;


void rogzit()
{
rendeles rendelesek;
time_t currentime;

printf("Rendelo lakcime: ");
scanf(" %[^\n]",rendelesek.lakcim);
printf("Lakas merete(pozitiv,valos szam): ");
scanf(" %f",&rendelesek.meret);
printf ("Rendelt szolgaltatas(ok): ");
scanf(" %[^\n]",rendelesek.reszmunkak);

currentime = time(NULL);
currentime =  rand() / 100  + currentime;
rendelesek.mtime = localtime(&currentime);


FILE* fpt;
fpt =  fopen("rendelesek.txt","a");
if (fpt == NULL)
{
  perror("Nem tudja megnyitni a kimeneti fajlt! %s!\n");
  exit(1);
}

fprintf(fpt,"%s. %.2fm2 %s. %i %i %i. %s\n",rendelesek.lakcim,rendelesek.meret,rendelesek.reszmunkak,rendelesek.mtime->tm_year + 1900,rendelesek.mtime->tm_mon + 1,rendelesek.mtime->tm_mday,"felujitas");

fclose(fpt);
}


void listaz()
{
    FILE *f = fopen("rendelesek.txt","r");
    if( f == NULL)
    {
        perror("Nem tudja megnyitni a kimeneti fajlt!\n");
        exit(1);
    }
     char sor[300];
     while(fgets(sor,sizeof(sor),f))
     {
         printf("%s\n",sor);
     }

   fclose(f);

}

void modosit()
{

 rendeles  rendelesek;
 time_t currentime;

 FILE *f;
 FILE *g;
 f = fopen("rendelesek.txt","r");
 g = fopen("uj.txt","a");
 if( f == NULL)
 {
    perror("Nem tudja megnyitni a bemeneti fajlt!\n");
    exit(1);
 }
 if( g == NULL)
 {
    perror("Nem tudja megnyitni a kimeneti fajlt!\n");
    exit(1);
 }
 char cim[100];
 printf("A modositani kivant megrendelo lakcime:");

 scanf(" %[^\n]s",cim);

 printf("Lakas merete(pozitiv,valos szam): ");
 scanf(" %f",&rendelesek.meret);
 printf ("Rendelt szolgaltatas(ok): ");
 scanf(" %[^\n]",rendelesek.reszmunkak);

currentime = time(NULL);
currentime =  rand() / 100  + currentime;
rendelesek.mtime = localtime(&currentime);

char sor[300];

 while(fgets(sor,sizeof(sor),f))
 {

      if(strstr(sor,cim)==NULL)
      {
	     fprintf(g,"%s",sor);
      }else
      {

         strcpy(rendelesek.lakcim,cim);
         fprintf(g,"%s. %.2fm2 %s. %i %i %i. %s\n",rendelesek.lakcim,rendelesek.meret,rendelesek.reszmunkak,rendelesek.mtime->tm_year + 1900,rendelesek.mtime->tm_mon + 1,rendelesek.mtime->tm_mday,"felujitas");
      }

}
fclose(f);
fclose(g);
remove("rendelesek.txt");
rename("uj.txt","rendelesek.txt");

}
void torles()
{
 char lcim[100];
 printf("Kerem adja meg rendeleshez tartozo lakcimet:");
 scanf(" %[^\n]s",lcim);
 FILE *f = fopen("rendelesek.txt","r");
    if( f == NULL) {
        perror("Nem tudja megnyitni a bemeneti fajlt!\n");
        exit(1);
    }
 FILE *g = fopen("uj.txt","a");
    if( g == NULL) {
        perror("Nem tudja megnyitni a kimeneti fajlt!\n");
        exit(1);
    }

char sor[300];
 while(fgets(sor,sizeof(sor),f))
 {
      if(strstr(sor,lcim)==NULL)
      {
	     fprintf(g,"%s",sor);
      }
 }

fclose(f);
fclose(g);
remove("rendelesek.txt");
rename("uj.txt","rendelesek.txt");

}

void handler(int signumber)
{
    printf("\nHANDLER: Megerkezett a Signal a(z) %i szammal.\n", signumber);
}

void spaces(char *s)
{
    if(s == NULL)
    {
        return;
    }
    else
    {
    int n = 0;
	int i;
        for(i=0;i<strlen(s);++i)
        {
            if(s[i] != ' ')
            {
                s[n++] = s[i];
            }
        }
        s[n] = '\0';
    }
}


rendeles sdf()
{
    rendeles minrendeles;
    minrendeles.meret = 30.0; // hibajelzesre
    char temp[300];
    char meret[300];
    char ido[11];
    char tmp[11];
    char konvyear[20];
    char konvmonth[2];
    char konvday[2];
    int tomb[3];
    time_t currentime = time(NULL);
    currentime =  rand() / 100  + currentime;
    struct tm *tt = localtime(&currentime);

    int minnap = 0;
    FILE *f = fopen("rendelesek.txt","r");
    if( f == NULL)
    {
        perror("Nem tudja megnyitni a kimeneti fajlt!\n");
        exit(1);
    }
     char sor[300];
     while(fgets(sor,sizeof(sor),f))
     {
         rendeles rendelesek;
         rendelesek.mtime = tt;
         //printf("\n");
         sscanf(sor,"%[^.]. %[^m]m2 %[^.]. %[^.]. %s",rendelesek.lakcim,meret,rendelesek.reszmunkak,ido,rendelesek.eredmeny);
         rendelesek.meret = atof(meret);
         strcpy(tmp,ido);
         spaces(tmp);

        char *t;
        t = strtok(ido," ");
        int i = 0;
        while( t != NULL )
        {
            tomb[i] = atoi(t);
            t = strtok(NULL, " ");
            ++i;
        }

        sprintf(konvyear, "%i", tomb[0]);
        if(tomb[1] < 10)
        {
            konvmonth[0] = '0';
            sprintf(konvmonth + 1, "%i", tomb[1]);
        }
        else
        {
            sprintf(konvmonth, "%i", tomb[1]);
        }
        if(tomb[2] < 10)
        {
            konvday[0] = '0';
            sprintf(konvday + 1, "%i", tomb[2]);
        }
        else
        {
            sprintf(konvday, "%i", tomb[2]);
        }
        strcat(konvyear,konvmonth);
        strcat(konvyear,konvday);
        int actnap = atoi(konvyear);

        bool vane = strcmp(rendelesek.eredmeny, "elkeszult") != 0;
        if (vane && (actnap < minnap || minnap == 0))
        {
            rendelesek.mtime->tm_year = tomb[0] - 1900;
            rendelesek.mtime->tm_mon = tomb[1] - 1;
            rendelesek.mtime->tm_mday = tomb[2];

            minnap = actnap;
            minrendeles = rendelesek;
        }
     }
     //printf("\n");
     //printf("%i\n",minnap);
     fclose(f);
     return minrendeles;
}


void rendelestochar(char rend[], rendeles rendelesek)
{
    char s[50];
    char yc[4];
    char mc[2];
    char dc[2];
    int y,m,d;
    strcat(rend, rendelesek.lakcim);
    strcat(rend, " ");
    gcvt(rendelesek.meret,5,s);
    strcat(rend, s);
    strcat(rend, " ");
    strcat(rend, rendelesek.reszmunkak);
    strcat(rend, " ");
    y = rendelesek.mtime->tm_year + 1900;
    m = rendelesek.mtime->tm_mon + 1;
    d = rendelesek.mtime->tm_mday;
    sprintf(yc,"%i",y);
    if(m < 10)
    {
         mc[0] = '0';
         sprintf(mc + 1, "%i", m);
    }
    else
    {
	sprintf(mc,"%i",m);
    }
    if(d < 10)
    {
          dc[0] = '0';
          sprintf(dc + 1, "%i", d);
    }
    else
    {
          sprintf(dc, "%i", d);
    }
    strcat(rend,yc);
    strcat(rend," ");
    strcat(rend,mc);
    strcat(rend," ");
    strcat(rend,dc);

}



void munkatmodosit(struct rendeles rendelesek)
{
    char meret[300];
    char ido[11];
    char tmp1[11];
    int tomb[3];
    time_t currentime = time(NULL);
    currentime =  rand() / 100  + currentime;
    struct tm *tt = localtime(&currentime);
    FILE *f;
    f=fopen("rendelesek.txt","r");
    if (f==0)
    {
        perror("Nem tudja megnyitni a kimeneti fajlt!\n");
        exit(1);
    }

    FILE *g;
    g=fopen("uj.txt", "w");
    if (g==0)
    {
        perror("Nem tudja megnyitni a kimeneti fajlt!\n");
        exit(1);
    }

    struct rendeles tmp;
    tmp.mtime = tt;

    char sor[500];
    bool m = false;
    while (fgets(sor, sizeof(sor), f))
    {
         sscanf(sor,"%[^.]. %[^m]m2 %[^.]. %[^.]. %s",tmp.lakcim,meret,tmp.reszmunkak,ido,tmp.eredmeny);
         tmp.meret = atof(meret);
         strcpy(tmp1,ido);
         spaces(tmp1);

         char *t;
         t = strtok(ido," ");
         int i = 0;
         while( t != NULL )
         {
            tomb[i] = atoi(t);
            t = strtok(NULL, " ");
            ++i;
         }
         tmp.mtime->tm_year = tomb[0] - 1900;
         tmp.mtime->tm_mon = tomb[1] - 1;
         tmp.mtime->tm_mday = tomb[2];
         if(strcmp(rendelesek.lakcim,tmp.lakcim)==0)
         {
            strcpy(tmp.eredmeny, rendelesek.eredmeny);

            printf("PARENT: A rendelest modositottuk: ");
            printf("%s %.2f %s %i %i %i %s\n",tmp.lakcim,tmp.meret,tmp.reszmunkak,tmp.mtime->tm_year + 1900,tmp.mtime->tm_mon + 1,tmp.mtime->tm_mday,tmp.eredmeny);
            fprintf(g,"%s. %.2fm2 %s. %i %i %i. %s\n",tmp.lakcim,tmp.meret,tmp.reszmunkak,tmp.mtime->tm_year + 1900,tmp.mtime->tm_mon + 1,tmp.mtime->tm_mday,tmp.eredmeny);

            m = true;
         }
         else
         {
            fprintf(g, sor);
         }
    }
    if(m)
    {
        printf("PARENT:A modositas sikeresen elmentve\n\n");
    }
    else
    {
        printf("PARENT:A modositas nem tortent meg.\n\n");
    }

    fclose(f);
    fclose(g);

    remove("rendelesek.txt");
    rename("uj.txt","rendelesek.txt");
}


proc()
{
    int pipefd[2]; // unnamed pipe file descriptor array
    pid_t pid;
    char sz[500];  // char array for reading from pipe
    signal(SIGTERM, handler);
    rendeles rendelesek = sdf();

    char s[100];
    float h = rendelesek.meret;

    if(h == 30.000000)
    {
        printf("Hiba!Minden rendeles elkeszult.\n");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1)
    {
        perror("Hiba a pipe nyitaskor!");
        exit(EXIT_FAILURE);
    }

    key_t k = ftok("./a.out", 1);
    printf("A kulcs: %d\n", k);
    int uzenetsor = msgget(k, 0600 | IPC_CREAT);
    if (uzenetsor < 0)
    {
        perror("msgget");
    }
    int stat;
    pid = fork();
    if(pid == -1)
    {
        perror("Fork hiba");
        return 1;
        //exit(EXIT_FAILURE);
    }
    else if(pid == 0)
    {
        // Gyerek
        printf("\nCHILD: 1 mp es keszen allunk!\n");
        sleep(1);
        kill(getppid(), SIGTERM);

        sleep(2);
        close(pipefd[1]);                //Usually we close the unused write end
        read(pipefd[0], sz, sizeof(sz)); // reading max 100 chars
        printf("\nCHILD: Megkaptuk a munkat: %s\n", sz);
        close(pipefd[0]); // finally we close the used read end

        srand(time(NULL));   //the starting value of random number generation
        int r = rand() % 10; //number between 0-9

        char m[1024];
        if (r != 0)
        {
            printf("CHILD: Tartottuk a hataridot!\n");
            strcpy(m, "elkeszult");
        }
        else
        {
            printf("CHILD: Kicsusztunk a hataridobol!\n");
            strcpy(m, "csuszas");
        }

        struct msg_t ms;
        ms.mtype = 5;
        strcpy(ms.mtext, m);
        //printf("%s gyerek\n",ms.mtext);

        int msgStatus = msgsnd(uzenetsor, &ms, strlen(ms.mtext) + 1,0);
        if (msgStatus < 0)
            perror("msgsnd");
        //sleep(3);
        printf("CHILD: Folyamat vege\n");
	exit(0);

    }
    else
    {
        // Szulo
        pause(); //waits till a signal arrive
        printf("\nPARENT: Csapat keszenall, kuldom a munkat...\n");


        char rend[500];
        strcpy(rend,"");

        rendelestochar(rend, rendelesek);
        close(pipefd[0]); //Usually we close unused read end
        write(pipefd[1], rend, strlen(rend)+1);
        close(pipefd[1]); // Closing write descriptor

        printf("PARENT: Munka elkuldve: %s\n", rend);
        sleep(3);

        struct msg_t ms;
        //printf("%s elott1\n",ms.mtext);
        int msgStatus = msgrcv(uzenetsor, &ms, 1024, 5,0);
        //printf("%s elott2\n",ms.mtext);
        waitpid(pid, &stat, 0);
       //printf("%s utan\n",ms.mtext);

        if (msgStatus < 0) {
            perror("msgsnd");
        } else {
            printf("\nPARENT: Munka eredmenye: %s\n", ms.mtext);
        }

        strcpy(rendelesek.eredmeny, ms.mtext);
        munkatmodosit(rendelesek);
        printf("PARENT: Eredmeny elkonyvelve.\n");


        printf("PARENT: Folyamat vege\n");
        stat = msgctl( uzenetsor, IPC_RMID, NULL );
          if ( stat < 0 )
               perror("msgctl");

    }



}


void Menu() {

int valasztas;

do
    {
        printf("\n");
        printf("\n");
        printf("1.Uj rendeles felvetele\n2.Rendelesek kilistazasa\n3.Rendeles modositasa\n4.Rendeles torlese lakcim alapjan\n5.Rendeles teljesitese\n6. Kilepes\n");
        printf("Melyik opciot valasztja?(1-6): ");

        scanf(" %i", &valasztas);

        switch (valasztas) {
            case 1:
                rogzit();
                break;
            case 2:
                listaz();
                break;
            case 3:
                modosit();
                break;
            case 4:
                torles();
                break;
            case 5:
                proc();
                break;
            case 6:
                exit(0);
		break;
            default:
                printf(" Hibas valasztas\n");
                break;
        }


}while(valasztas!=6);


}

int main()
{

    Menu();

    return 0;
}
