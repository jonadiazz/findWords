#include <stdio.h>
#include "variables.h"
#include <string.h>
#include <stdlib.h>

int main (void) {
    
    /*gets first row of letters from the file into a 2d array*/
    while((letter=getchar()) != '\n') {
        if( letter != ' ')
            matrix[0][k++] = letter;
    }
    /*knowing the dimension length of the matrix we continue 
     passing the letters into the square 2d array*/
    for(row=1; row < k; row++) { i=0;
        for(c=0; c <= k*2; c++) {
            letter = getchar();
            if(letter != ' ')
                matrix[row][i++] = letter;
        }
    }
    
   /* prints original matrix*/
    while(j < k) { y = 0;
        while(y < k) {
            matrix2[j][y] = ' ';
            printf("%c  ", matrix[j][y++]);
        }
        j++; printf("\n");
    }

    /*find matching initial letter positions then calls findword()
     which recursively finds if there is a matching word in the matrix*/
    while(getword() == 1)
        for(b=0; b<k; b++)
            for(v=0; v<k; v++)
                if(matrix[b][v] == word[0])
                    findword(b, v, word, 0,0,0);

    /*prints the list of words to to be found*/
    while(u < p)
        printf("%c", palabras[u++]);
    
    /*prints resultant 2-dimensional array*/
    j= 0;
    while(j < k) { y = 0;
        while(y < k)
            printf("%c  ", matrix2[j][y++]);
        j++; printf("\n");
    }
    
}

int findword(int j, int y, char word[50], int down, int right, int n) {

    int boln = 0;

    if(word[n] == '\n')
        return 1;

    if(matrix[j][y] == word[n])
        boln = 2;

    if((boln==2) && ((y<k && down==0 && right == 1) || (down==0 && right==0)) && findword (j, y+1, word, 0, 1, n+1) == 1) {
        matrix2[j][y] = matrix[j][y];
        boln = 1;
    }
    
    if((boln==2) && ((j>=0 && down == -1 && right==0) || (down==0 && right==0)) && findword (j-1, y, word, -1, 0, n+1) == 1) {
        matrix2[j][y] = matrix[j][y];
        boln = 1;
    }
    
    if((boln==2) && ((y>=0 && down==0 && right == -1) || (down==0 && right==0)) && findword (j, y-1, word, 0, -1, n+1) == 1) {
        matrix2[j][y] = matrix[j][y];
        boln = 1;
    }
    
    if((boln==2) && ((j<=k+1 && down == 1 && right == 0) || (down==0 && right==0)) && findword (j+1, y, word, 1, 0, n+1) == 1) {
        matrix2[j][y] = matrix[j][y];
        boln = 1;
    }
    
    if((boln==2) && ((j<k && y<k && down==1 && right ==1) || (down==0 && right==0)) && findword (j+1, y+1, word, 1, 1, n+1) == 1) {
            matrix2[j][y] = matrix[j][y];
            boln = 1;
    }
    
    if((boln==2) && ((j>0 && y<k && down==-1 && right==1) || (down==0 && right==0)) && findword (j-1, y+1, word, -1, 1, n+1) == 1){
            matrix2[j][y] = matrix[j][y];
            boln = 1;
    }
    
    if((boln==2) && ((j<k && y>0 && down==1 && right==-1) || (down==0 && right==0)) && findword (j+1, y-1, word, 1, -1, n+1) == 1){
            matrix2[j][y] = matrix[j][y];
            boln = 1;
    }
    
    if((boln==2) && ((j>0 && y>0 && down==-1 && right==-1) || (down==0 && right==0)) && findword (j-1, y-1, word, -1, -1, n+1) == 1){
            matrix2[j][y] = matrix[j][y];
            boln = 1;
    }
    
    return boln;
}

int getword() {
    
    if(fgets(word, 50, stdin) == NULL) {
        return 0;
    } else { lers = 0;
        wlen = strlen(word);
        while(wlen > lers)
            palabras[p++] = word[lers++];
        return 1;
    }
}





