#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *outraThread(void *vargp);


int main (void) {
	pthread_t tid;

	fprintf(stderr, "Vou criar a thread\n");
	int rc = pthread_create(&tid, NULL, outraThread, NULL);
    if(rc){
        fprintf(stderr, "Erro: pthread.create() retornou %d\n", rc);
        return 1;
    }
	fprintf(stderr, "Thread criada, esperando pelo término\n");
	//rc = pthread_join(tid, NULL);
    if(rc){
        fprintf(stderr, "Erro: pthread.join() retornou %d\n", rc);
        return 1;
    }
	fprintf(stderr, "Fim da thread principal\n");
	return 0;
}

void *outraThread(void *vargp) {
	puts("Nova thread nascendo...");
	sleep (30);
	puts("Alo mundo!");
	return NULL;
}