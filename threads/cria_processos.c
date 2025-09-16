#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    struct timespec inicio, fim;
    clock_gettime(CLOCK_TAI, &inicio);
    for(int i = 0; i < 1000; i++) {
        pid_t pid = fork();
        if(pid < 0) {
            fprintf(stderr, "Erro ao criar processo filho\n");
            exit(1);
        } else if(pid == 0) {
            // Processo filho
            exit(0);
        } else {
            // Processo pai
        }
    }
    clock_gettime(CLOCK_TAI, &fim);
    double tempo_gasto = fim.tv_sec - inicio.tv_sec + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    printf("Tempo gasto: %fs\n", tempo_gasto);
    return 0;
}