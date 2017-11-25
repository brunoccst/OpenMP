#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 75000       // trabalho final com o valores 10.000, 100.000, 1.000.000

int main()
{
    int vetor[ARRAY_SIZE+1];
    int i;
    int controleVar = 0;
    int j;
    clock_t t;

    for (i=0 ; i<ARRAY_SIZE; i++)              
        vetor[i] = ARRAY_SIZE-i;
    
    printf("\nTamanho Array: %d\n", ARRAY_SIZE);
    printf("Comecando a ordenar\n");
    //printf("\nVetor Inicial: ");
    //for (i=0 ; i<ARRAY_SIZE; i++)             
    //    printf("[%d] ", vetor[i]);

    t = clock();
    
    for (i = 0; i <= ARRAY_SIZE; i++)
    {
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

    printf("\nOrdenado!!\n");
    //printf("\n\nVetor Final: ");
    //for (i=0 ; i<ARRAY_SIZE; i++)
    //    printf("[%d] ", vetor[i]);

    printf("\nTempo de duracao: %f\n", time_taken);

    printf("\n");
    return 0;
}