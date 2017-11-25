#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main()
{
    int ARRAY_SIZE = 75000;
    int vetor[ARRAY_SIZE];
    int i;
    clock_t t;
    omp_set_num_threads(1);    //Numero de Threads
    int debug = 0;
    int j;
    int controleVar = 0;

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

    for (i = 0; i <= ARRAY_SIZE; i++)
    {
        #pragma omp parallel for
        for (j = controleVar; j < ARRAY_SIZE - 1; j = j + 2)
        {   
            if (vetor[j] > vetor[j+1])
            {
                int aux1 = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux1;
            }
        }

        if(controleVar == 1){
            controleVar = 0;
        }else{
            controleVar = 1;
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n\nOrdenado!!\n");
    if(debug == 1){
        printf("\nVetor Final: ");
        for (i=0 ; i<ARRAY_SIZE; i++)
            printf("[%d] ", vetor[i]);
    }

    printf("\nTempo de duracao: %f\n", time_taken);

    printf("\n");
    return 0;
}