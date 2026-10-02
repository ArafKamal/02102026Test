#include <stdio.h>
#include <unistd.h>

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
        printf("errore\n");
    } else if (pid == 0) {
        printf("figlio\n");
    } else {
        printf("padre\n");
    }

    return 0;
}