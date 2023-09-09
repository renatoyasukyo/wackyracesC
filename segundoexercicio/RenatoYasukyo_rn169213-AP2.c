#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int numerocarro;
    char nomecorredor[21];
    int posicao;
}Corredor;


int main(){

    int N, i, j, ultpssg, c1, c2;
    Corredor aux;

        scanf("%d", &N);

    Corredor* corredores = (Corredor*)malloc(N * sizeof(Corredor));

    for(i = 0; i < N; i++){
        scanf("%d %s", &(corredores[i].numerocarro), corredores[i].nomecorredor);
        corredores[i].posicao = i+1;
    }


    do{
        if(ultpssg >= 1 && ultpssg < N){
            c1 = ultpssg - 1;
            c2 = ultpssg;

            aux = corredores[c1];
            corredores[c1] = corredores[c2];
            corredores[c2] = aux;

            corredores[c1].posicao = c1 + 1;
            corredores[c2].posicao = c2 + 1;
        }
        scanf("%d", &ultpssg);
    }while(ultpssg != -1);

    for (i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            if(corredores[i].posicao > corredores[j].posicao){
                aux = corredores[i];
                corredores[i] = corredores[j];
                corredores[j] = aux;
            }
        }
    }

    for(i = 0; i < 3; i++){
        printf("%d %s\n", corredores[i].numerocarro, corredores[i].nomecorredor);
    }

    free(corredores);

    return 0;
}


