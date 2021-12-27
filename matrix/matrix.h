#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define N 5
typedef  int matrix[N][N]; /* type holding an N*N neighboring matrix */
typedef  matrix *ptr; /* type holding an N*N neighboring matrix */
int input(int *matrix);
int getNumber();
int check(int *matrix ) ;
void output( int *matrix ,int i,int good);