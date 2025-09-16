#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

void *theThread(void *arg);
int main(void) {
    struct timespec inicio, fim;
    clock_gettime(CLOCK_TAI, &inicio);
    for(int i = 0; i < 1000; i++) {
        pthread_t thread_id;
        int err = pthread_create(&thread_id, NULL, theThread, NULL);
        if(err != 0) {
            fprintf(stderr, "Erro ao criar thread\n");
            exit(1);
        } else {
            // Thread criada com sucesso
        }
    }
    clock_gettime(CLOCK_TAI, &fim);
    double tempo_gasto = fim.tv_sec - inicio.tv_sec + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    printf("Tempo gasto: %fs\n", tempo_gasto);
    return 0;
}
void *theThread(void *arg) {
    // Corpo da thread
    pthread_exit(NULL);
    return NULL;
}