#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int solution (int [], int [], int, int [], int);

void main(){
    int N,M;
    printf("Cuantas tablas se deben clavar? ");
    scanf("%d",&N);
    fflush(stdin);
    printf("\nCuantos clavos estan disponibles?");
    scanf("%d",&M);
    fflush(stdin);
    int A[100],B[100],C[100];
    solution(A,B,N,C,M);


}

int solution (int A[], int B[], int N, int C[], int M){
    int lengthTable = N;
    int lengthNails = M;
    int i;
    for (i=0; i<=lengthTable-1; i++){
        printf("Ingrese el inicio de la tabla %d: ", i+1);
        scanf("%d",&A[i]);
        fflush(stdin);
        printf("Ingrese el final de la tabla %d: ", i+1);
        scanf("%d",&B[i]);
        fflush(stdin);
    }
    for (i=0; i<=lengthNails-1; i++){
        printf("Ingrese posicion del clavo %d: ", i+1);
        scanf("%d",&C[i]);
        fflush(stdin);
    }
    int j,k;
    int posible = 1,count=0;
    for (i=0; i<=lengthTable-1; i++){
        for (k=0; k<=lengthNails-1; k++){
            if (C[k]>=A[i] && C[k]<=B[i]){
                count++;
            }
        }
        if (count==0){
            posible = 0;
            i=lengthTable;
        }else{
            count = 0;
        }
    }
    int over=0, counter=0;
    if(posible == 1){
        int statusT[100];
        int statusC[100];
        for (k=0; k<=lengthTable-1; k++){
            for (i=0; i<=lengthNails-1; i++){
                if (C[i]>=A[k] && C[i]<=B[k]){
                    statusT[k] = 1;
                    statusC[i] = 1;
                    counter++;
                    i= lengthNails+1;
                }
            }
            int l;
            for (l=0;l<lengthTable-1;l++){
                if (statusT[l]==1){
                    over++;
                }
            }
            if (over==lengthTable){
                i=lengthNails+1;
                k=lengthTable+1;
            }else{
                over=0;
            }
        }
        return counter;
    }else{
        return -1;
    }

}