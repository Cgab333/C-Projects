/*
 * File Name: par.c
 * Program that checks propriety of text represent c program
 *
 * Programmer: Shay Gabison
 */

#include <stdlib.h>
#include <stdio.h>
#define MAX_LINE_LEGHNT 100 /* The maximum length of line we will receive from the user */
#define TRUE 1
#define FALSE 0
void checkLine(char line[], int* rowIndex, int* counter);
void balancedLinePrint(char line[], int rowIndex, int i);
int checkComments(char line[], int j, int i);


int main() {
    char line[MAX_LINE_LEGHNT] = "";
    int curleyCounter = 0;
    int rowIndex = 0;
    
    while (fgets(line, 100, stdin) != NULL) {
        checkLine(line, &rowIndex, &curleyCounter);
    }

    if (curleyCounter != 0)/* Checking if the all text is proper by curley closers check */
        printf("\n\n---This text is NOT balanced---\n");
    else
        printf("\n\n---This text is balanced---\n");
    return 0;
}

/* checkLine getting line from the text , line number and the curleyCounter .
 * The method cheking iteratively every char in line and for spcifiec chars it has spcifiec actions.
 */
void  checkLine(char line[], int* rowIndex, int* counter) {
    char symbolsPerLine[MAX_LINE_LEGHNT] = "";
    int charIndex = 0;
    int symbolsPerLineCounter = 0;


    while (line[charIndex] != '\0' && line[charIndex] != EOF) {


        if ((line[charIndex] == '/') && (line[charIndex + 1] == '*')) {
            *rowIndex = checkComments(line, charIndex, *rowIndex);
            return;

        }
        if (line[charIndex] == '"') {
            charIndex++;
            while (line[charIndex] != '"')
                charIndex++;
        }

        switch (line[charIndex]) {
        case '(':

            symbolsPerLine[symbolsPerLineCounter] = '(';
            symbolsPerLineCounter++;
            break;

        case '[':

            symbolsPerLine[symbolsPerLineCounter] = '[';
            symbolsPerLineCounter++;
            break;

        case '{':
            *counter = *counter + 1;
            symbolsPerLine[symbolsPerLineCounter] = '{';
            symbolsPerLineCounter++;
            break;

        case ')':
            if (symbolsPerLine[symbolsPerLineCounter - 1] == '(') {
                symbolsPerLine[symbolsPerLineCounter - 1] = (char)0;
                symbolsPerLineCounter--;
                break;
            }
            *rowIndex = *rowIndex + 1;
            balancedLinePrint(line, *rowIndex++, FALSE);
            return;

        case ']':

            if (symbolsPerLine[symbolsPerLineCounter - 1] == '[') {
                symbolsPerLine[symbolsPerLineCounter - 1] = (char)0;
                symbolsPerLineCounter--;
                break;
            }
            *rowIndex = *rowIndex + 1;
            balancedLinePrint(line, *rowIndex++, FALSE);
            return;

        case '}':
            *counter = *counter - 1;
            if (symbolsPerLine[symbolsPerLineCounter - 1] == '{') {
                symbolsPerLine[symbolsPerLineCounter - 1] = (char)0;
                symbolsPerLineCounter--;
            }
            else {
                symbolsPerLine[symbolsPerLineCounter] = '}';
                symbolsPerLineCounter++;
                
            }

            break;
            *rowIndex = *rowIndex + 1;
            balancedLinePrint(line, *rowIndex, FALSE);
            return;
            /* operator doesn't match any case constant (, [, {,),],}*/
        default:

            break;

        }

        charIndex++;
    }

    if (symbolsPerLine[0] != '\0') {
        *rowIndex = *rowIndex + 1;
        balancedLinePrint(line, *rowIndex, FALSE);
        return;
    }
    *rowIndex = *rowIndex + 1;
    balancedLinePrint(line, *rowIndex, TRUE);
    return;
}



/* balancedLinePrint getting line , line number and the information if line is balanced or not .
 * The method printing the line number, the line and if its balanced or not.
 */

void balancedLinePrint(char line[], int rowIndex, int i) {
    if (i) {
        printf("\n%d: %s\n", rowIndex, line);
        printf("This line is balanced\n");
        return;
    }
    else
        printf("\n%d: %s\n", rowIndex, line);
    printf("\nThis line is NOT balanced");
    return;
}

/* checkComments getting line , char index in the line and  line number.
 * This method will be used if the checkLine method recognize '/'+'*' in a row .
 *The  checkComments search for '*'+'/' in a row and return just if it find so. (that how the program  recognize end of comment)
 */
int checkComments(char line[], int charIndex, int rowIndex) {
    while (line[charIndex] != '\0') {
        if ((line[charIndex] == '*') && (line[charIndex + 1] == '/')) {
            rowIndex++;
            balancedLinePrint(line, rowIndex, TRUE);
            return rowIndex;

        }
        charIndex++;
    }

    balancedLinePrint(line, rowIndex++, TRUE);
    if (fgets(line, 100, stdin) != NULL) {

        rowIndex = checkComments(line, 0, rowIndex++);
    }
    return rowIndex;
}