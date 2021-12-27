/*
 * File Name: con.c
 * Program gets text from user and find row of ascii alphanumric chars - if so , its take the first and last and print it nicely.
 *
 *For exmple:"abcdegfd12343" ---->  "a-egfd1-43"
 *
 * Programmer: Shay Gabison
 */
#include<ctype.h>
#include <stdio.h>
#define MAX_LEGHNT 100
int contractHelp( char s1,  char s2); /*Makes sure char is alphanumric*/
void contract( char s1[],  char s2[]);


int main() {
    char userString[MAX_LEGHNT];
    char outputString[MAX_LEGHNT]="";
    printf("Please write a String \n");
    fgets(userString, MAX_LEGHNT, stdin);
    contract( userString,  outputString);
    printf("%s",outputString);
    return 0;
}


void contract( char s1[],  char s2[]){
    int i,j,l, a;
    a=0;
    for (l=0; s1[l] != '\0'; l++){
      
      }
    for (i=0;i<l;i+=1){
        if((s1[i]-s1[i+1]==-1 && s1[i+ 1] - s1[i + 2] == -1)&&(contractHelp( s1[i],   s1[i+2]))){ /*Makes sure chars is alphanumric and in a row*/
            for (j=i+2;j<l;j+=1){
                if(s1[j]-s1[j+1]!=-1){
                    s2[a]=s1[i];
                    s2[a+1]='-';
                    s2[a+2]=s1[j];
                    i=j;
                    a+=3;
                    break;}
            }
        }
        else {
            s2[a] = s1[i];
            a++;
        }
      
        
    
}
}
int contractHelp( char s1,  char s2){
    if((isalpha(s1)&&isalpha(s2))||(isdigit(s1)&&isdigit(s2)))
    return 1;
    return 0;
      }