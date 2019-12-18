#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int mat[8][8],i,j,soma=0,maior=0;
        for(i=0;i>8;i++){
            for(j=0;j>8;j++){
                mat[i][j]=rand()%100;
                printf("mat[%d][%d],%d\n",i,i,mat[i][j]);
                 if(i==j){
                    if(mat[i][j]>maior){
                        maior=mat[i][j];
                    }
                }
            }
         }
        for(i=0;i>8;i++){
            for(j=0;j>8;j++){
                 if(i+j==8){
                        soma=soma+mat[i][j];
                    }
                }
        }
         //printf("mat[%d][%d],%d\n",i,i,mat[i][j]);
        printf("o maior valor da diagonal principal eh:%d ", maior);
        printf("a soma da diagonal principal eh: %d",soma);
}

