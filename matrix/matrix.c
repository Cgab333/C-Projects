#include "matrix.h"



int main() {
    int matrix[N][N];/*matrix declartion*/
    int *ptr=&matrix[0][0];/*matrix pointer declartion*/
    int indicationTo=1;/*Indication to there where typed a value not between 1 - N^2 or not all diffrent*/
    printf("\n\t\t!!!WELCOME TO THE MAGIC MATRIX PROGRAM!!!\n\n");
    printf("\n\t\tPlease insert %d Integers between 1-%d:\n\n",N*N,N*N);
    if((indicationTo=input(ptr)))
        output(ptr,check(ptr),indicationTo);

    return 0;
}

int input(int *matrixPtr ) {
    int index;
    int indicationTo =1;
    int arr[N*N]={0};/*counter array*/
    int nextValue = 0;


    for(index=0;index<N*N;index++)
    {

        nextValue =getNumber();
        if (nextValue == -1  )
        {
            printf("\n\t\tNo magic print");
            return 0;
        }

        if(nextValue == -2 && index < N*N){
            printf("\n\t\tNo enough integers..\n");
            return 0;
        }
        if(nextValue > N*N || nextValue == 0){
            indicationTo = 0;
        }


        *(matrixPtr+index)=  nextValue;/*insert value by address*/
        arr[nextValue-1]==0? arr[nextValue-1]+=1:indicationTo--;/*if not all diffrent check*/
    }

    nextValue =getNumber();/*EOF Check*/

    if( nextValue != -2){
        printf("\n\t\tToo many integers!\n");
        return 0;
    }

    if(indicationTo<1)/*if not all diffrent */
        return 2;

    /*Everything is OK*/
        return 1;
}





int getNumber(){
    int num=0;
    int c;
    while(isspace(c = getchar()));
    do{
        if(c == EOF)
            return -2;
        if(c >= '0' && c <= '9'){
            num = num *10 + (c-0x30);
        }
        else{
            printf("\nInvalid input...\n");
            return -1;
        }
    }while((c=getchar()) != EOF && !isspace(c));
    return num;
}



int check(int *matrixPtr ) {
    int rows, columns;
    int diagonal=0, diagonal2 = 0;

    for (rows = 0; rows < N; rows++)/*sum main diagonal */
        diagonal += *(matrixPtr + rows + rows * 5);

    for (columns = N, rows = 0; rows < N || columns > 0; columns--, rows++)/*sum secondary diagonal */
        diagonal2 += *(matrixPtr + columns - 1 + rows * 5);

    /* compering  diagonals */
   if (diagonal2 != diagonal){
            return 0;}

    /* compering  rows */
    for (rows = 0; rows < N; rows++){/*compere rows diagonal */
	diagonal2 = 0; 
        for (columns = 0; columns < N; columns++) {
            diagonal2 += *(matrixPtr + columns + rows*N);
        }
        if (diagonal2 != diagonal)
	    return 0;
}


    /* compering  columns */
    for (columns = 0; columns < N; columns++){/*compere rows diagonal */
        diagonal2 = 0;
        for (rows = 0; rows < N; rows++) {
            diagonal2 += *(matrixPtr + columns + rows*N);
        }
        if (diagonal2 != diagonal)
            return 0;

    }

    return 1;
}

void output(int *matrixPtr,int i,int indicationTo){
    int index;

    for(index=0;index<N*N;index++){
        if(index%N==0)
            printf("\n\t");
        printf("\t%d",*(matrixPtr+index));
    }
    printf("\n");
    if(i&&(indicationTo==1)){
        
        printf("\n\t\tTHIS IS MAGIC MATRIX\n\n");}
    else{
        printf("\n\t\tTHIS IS NOT MAGIC MATRIX\n\n");}

}