#include <stdio.h>
#include <stdlib.h>
int *p,*q,pp,a,b;

void troca(int *x,int *y);

 int main(){

    //printf("%d ", sizeof(char));
    //printf("%d ", sizeof(int));
    //printf("%d ", sizeof(float));
    //("%d ", sizeof(double));
    //printf("%d ", sizeof(void));

    p = (int*) malloc(5 * sizeof(int));
    if(p == NULL){
        printf("\nerro de malloc");
        exit(1);
    }else{
        printf("\nmalloc com sucesso");
    }

    q = (int*) calloc(5,sizeof(int));
    if(q == NULL){
        printf("\nerro de calloc");
        exit(1);
    }else{
        printf("\ncalloc com sucesso");
    }

    int i;

    /*for(i = 0; i<5; i++){
    printf("\ndigite o p int %i: ",i);
    scanf("%i", &p[i]);
    printf("\n digitou %i em %d", p[i], &p[i]);
    }*/

   for(i = 0; i<5; i++){
    printf("\ndigite o q int %i: ",i);
    scanf("%i", &q[i]);
    pp = q + (sizeof(int)*i);
    printf("\n digitou %i em %d", q[i], pp);
    }

    //p = (int*) realloc(p, 10*sizeof(int));
    q = (int*) realloc(q, 10*sizeof(int));

    if(q == NULL){
        printf("\nerro de realloc!");
        exit(1);
    }else{
        printf("\nrealloc bom!");
    }
    for ( i = 0; i < 10; i++)
    {
        pp = q + (sizeof(int)*i);
        printf("\n%i em %i",q[i],pp);
    }

    free(p);
    free(q);

    return 0;
 }

 void troca(int *x, int *y){

 }