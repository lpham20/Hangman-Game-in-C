#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

//Function was made to count variable as its parameter take the answer, count
//the length of the answer, and whenever the guess input letter is similar to a
//single letter in answer, it will count and inplement the guess letter to the string
//this function return the number of time answer letter is same with guess input
int countchar(const char* answer, char* variable, char guess) { //function to count variable
    int count = 0;
    int length = strlen(answer);
    for (int i = 0; i < length; i++) {
        if (answer[i] == guess) {
            count++;
            variable[i] = guess;
        }
    }
    return count;
}

//This function calculate the length of the input and print it, just for the false
//letter that appear on the top of the guess string. This is made in order to
//help player to remember the wrong letter.
void falseletter(char *input) { //print false letter input
     int length = strlen(input);
     for (int i = 0; i < length; i++) {
          printf("%c", input[i]);
          printf(" ");
     }
     printf("\n");
}

//This function is to create a string for the false letter and set the input into
// false string
void falseletterarray(char *input, char variable) { //put false letter to array
     int length = strlen(input);
     for (int i = 0; i < 6; i++) {
          if (variable == input[i]) {
              break;
          }
          else {
              input[length] = variable;
              break;
          }
     }
}

//This is basically a make string function, when the input variable is 0, then
// it will print _ but if the input is any letter, it will print the variable
// the length parameter is used for the for loop.
void makestring(char* variable, int length) { //make string function
     for (int i = 0; i < length; i++) {
          if (variable[i] == 0) {
              printf("_");
          }
          else {
          printf("%c", variable[i]);
          }
     printf(" ");
     }
  printf("\n");
}

//This function is basically draw out the hangman body based on switch statement
//with 6 different cases that can lead to the man to be hanged.
void hangmanbody(int correctLetters) { //hangman body
     printf("\t\t\t\t\t\tHangman: ");
     switch(correctLetters) {

            case 1:
                printf("\t  O\n");
                break;
            case 2:
                printf("\t  O\n");
                printf("\t\t\t\t\t\t\t\t  |\n");
			          printf("\t\t\t\t\t\t\t\t  |\n");
                break;
            case 3:
                printf("\t  O\n");
                printf("\t\t\t\t\t\t\t\t--|\n");
			          printf("\t\t\t\t\t\t\t\t  |\n");
                break;
            case 4:
                printf("\t  O\n");
                printf("\t\t\t\t\t\t\t\t--|--\n");
			          printf("\t\t\t\t\t\t\t\t  |\n");
                break;
            case 5:
                printf("\t  O\n");
                printf("\t\t\t\t\t\t\t\t--|--\n");
			          printf("\t\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t\t /\n");
                break;
            case 6:
                printf("\t    O\n");
                printf("\t\t\t\t\t\t\t\t /|\\\n");
			          printf("\t\t\t\t\t\t\t\t  |\n");
                printf("\t\t\t\t\t\t\t\t / \\\n");
                break;
            default:
                return;
     }
}


//This boolean function take guess input letter and false letter and make condition
//if the input is in falsestring it will return true, otherwise it will return false.
//the function return either true or false of the control value.
bool controlfalseletter(char *input, char variable) { //separate the guess letter from false letter array
     bool control;
     for (int i = 0; i < 6; i++) {
          if (input[i] == variable) {
              control = true;
          }
          else {
              control = false;
          }
     }
     return control;
}
