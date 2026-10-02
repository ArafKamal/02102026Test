#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    // fork(); duplica area di memoria (Code segment), quindi fa 2 volte 4AII
    // il fork crea un processo figlio

    // vogliamo printf su PID padre
    // printf diverso per il figlio

    // il fork returna 3 cose diverse:
    // 0 per processo figlio
    // PID del figlio
    // -1 se c'è errore

    // codice dove padre stampa padre, figlio stampa figlio.
    pid_t pid = fork();

    if (pid < 0) {

        perror("fork");
        // printf("errore\n");
        exit(-1); // esce dal programma
        // return -1; // esce e ritorna all'inizio - in questo caso uguale

    } else if (pid == 0) {

        sleep(1);
        // se aggiungo questo sleep sul figlio, non stampa il figlio, perchè?
        // Dato che il processo padre finisce il programma totale, quindi finisce anche il figlio,
        // per questo motivo non stampa il figlio, non termina, è in background ma diventa un processo orfano,
        // non scrive dato che non ha il terminale del padre dove scrivere

        printf("figlio\n");
        // Si usa exit zero, così che esce del processo e non
        // continua a fare le robe del padre;
        exit(0);

    } else {
        // sleep(1);
        // Da qui in poi c'è solo processo padre
        printf("padre\n");
    }

    // certe volte il figlio viene scritto prima del figlio,
    // processi gestiti dal sistema operativo, quindi non è garantito

    // viene maggior parte dei casi stampato prima padre, dato che il processo figlio
    // deve essere ancora creato, dipende scheduling processi

    // system D, processo primo che da avvio a tutti gli altri
    // gerarchia di processi è ad albero, se il processo diventa orfano, il processo viene ereditato dal
    // processo system D, cioè il processo 1, ha dei metodi per capire come killare orfano

    // padre aspetti il figlio, come si fa (si usa wait)
    wait(NULL); // il padre aspetta che il figlio finisca il processo

    return 0;
}