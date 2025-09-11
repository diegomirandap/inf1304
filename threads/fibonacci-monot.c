/**
 * Fibonacci mono thread
    *
    * Compile: gcc -o fibonacci-monot fibonacci-monot.c
    * Run: ./fibonacci-monot
    * 
    * Descrição: Cálculo de Fibonacci de forma monothread
 */

/**
 * includes
 */
#include <stdio.h>

/**
 * protótipos
 */
long fibonacci(int n);

/**
 * typedefs e structs
 */
struct lista_fibonacci {
    int n;
    long valor;
    struct lista_fibonacci *proximo;
};
struct lista_tasks {
    struct lista_fibonacci *pfib;
    struct lista_tasks *pnext;
};


int main(void) {
    struct lista_tasks *ptasks = NULL;
    int i;
    long result;
    
    for(long limit= 0;; limit++) {
        struct lista_tasks *new_task = malloc(sizeof(struct lista_tasks));
        if(new_task == NULL) {
            fprintf(stderr, "Erro na alocação de memória\n");
            return 1;
        }
        new_task->pfib = NULL;
        new_task->pnext = ptasks;
        ptasks = new_task;
        //aqui começa uma nova task
        //adicionar o resultado em lista encadeada, pronta para o consumidor salvar em disco
        //percorrer a lista 

        for (i = 0;; i++) {
            struct lista_fibonacci *new_fib = malloc(sizeof(struct lista_fibonacci));
            if(new_fib == NULL) {
                fprintf(stderr, "Erro na alocação de memória\n");
                return 1;
            }
            //para casa: acrescentar no final da lista e não no início
            result = fibonacci(i);
            new_fib->n = i;
            new_fib->valor = fibonacci(i);
            new_fib->proximo = ptasks->pfib;
            printf("Fibonacci(%d) = %ld\n", i, result);
            
        }
        //aqui termina a task
    }
    return 0;
}

long fibonacci(int n) {
    /*
    qtd++;
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
    */
    long a = 0, b = 1, c;
    if (n == 0) return a;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
