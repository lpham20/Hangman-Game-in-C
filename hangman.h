#ifndef HANGMAN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Function was made to count variable as its parameter take the answer, count
//the length of the answer, and whenever the guess input letter is similar to a
//single letter in answer, it will count and inplement the guess letter to the string
//this function return the number of time answer letter is same with guess input
int countchar(const char* answer, char* variable, char guess);

//This function calculate the length of the input and print it, just for the false
//letter that appear on the top of the guess string. This is made in order to
//help player to remember the wrong letter.
void falseletter(char *input);

//This function is to create a string for the false letter and set the input into
// false string
void falseletterarray(char *input, char variable);

//This is basically a make string function, when the input variable is 0, then
// it will print _ but if the input is any letter, it will print the variable
// the length parameter is used for the for loop.
void makestring(char* variable, int length);

//This function is basically draw out the hangman body based on switch statement
//with 6 different cases that can lead to the man to be hanged.
void hangmanbody(int correctLetters);

//This boolean function take guess input letter and false letter and make condition
//if the input is in falsestring it will return true, otherwise it will return false.
//the function return either true or false of the control value.
bool controlfalseletter(char *input, char variable);

#endif
