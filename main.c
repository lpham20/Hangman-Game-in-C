#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

int main() {
    char *defaultstring = "wallet";
    char *correctstring;
    char input;
    char *falsestring;
    int wordlength;
    int falseletterlength = 0;
    int correctletter = 0;
    int falseguess = 0;
    int lifes = 6;
    wordlength = strlen(defaultstring);
    correctstring = malloc(sizeof(char) * (wordlength + 1));
    falsestring = calloc(sizeof(char), lifes + 1);

    while (correctletter < wordlength) {
           falseletter(falsestring);
           makestring(correctstring, wordlength);
           printf("Please guess a character: ");
           input = tolower(getchar());
           while (getchar() != 10);
           falseletterlength = countchar(defaultstring, correctstring, input);

           if (falseletterlength != 0) {
               correctletter += falseletterlength;
           }
           else {
               printf("False Letter.\n");

               if (!controlfalseletter(falsestring, input)) {
                   falseguess++;
                   falseletterarray(falsestring, input);
               }

               hangmanbody(falseguess);

               if (lifes - falseguess != 0)
                   printf("Guess times left: %d\n", lifes - falseguess);
               else               
                   printf("GAME OVER");

               getchar();
               while(getchar() != 10);
           }
     }
     makestring(correctstring, wordlength);
     printf("YOU ARE THE WINNER\n");
     return 0;
}
