#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define ARRAY_SIZE 10000      // trabalho final com o valores 10.000, 100.000, 1.000.000

int main()
{
    int vetor[ARRAY_SIZE+1];
    int i;
    clock_t t;
    omp_set_num_threads(4);    //Numero de Threads
    int debug = 0;

    for (i=0 ; i<ARRAY_SIZE; i++)              
        vetor[i] = ARRAY_SIZE-i;

    printf("\nTamanho Array: %d\n", ARRAY_SIZE);
    

    printf("Comecando a ordenar\n");
    if(debug == 1){
        printf("\nVetor Inicial: ");
        for (i=0 ; i<ARRAY_SIZE; i++)             
            printf("[%d] ", vetor[i]);
    }

    t = clock();

    for (int i = 0; i <= ARRAY_SIZE/2; i++)
    {

        #pragma omp parallel for shared(vetor)
        for (int i = 0; i < ARRAY_SIZE; i = i + 2)
        {   
            if (vetor[i] > vetor[i+1])
            {
                int aux1 = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux1;
            }
        }

        //#pragma omp parallel for default(none), shared(vetor)
        for (int i = 1; i <= ARRAY_SIZE; i = i + 2)
        {
            if (vetor[i] > vetor[i+1])
            {
                int aux2 = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux2;
            }
        }

    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\nOrdenado!!\n");
    if(debug == 1){
        printf("\n\nVetor Final: ");
        for (i=0 ; i<ARRAY_SIZE; i++)
            printf("[%d] ", vetor[i]);
    }

    printf("\nTempo de duracao: %f\n", time_taken);

    printf("\n");
    return 0;
}