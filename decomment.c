/*This program will decomment the user input using c language*/
/*For example let us say user inputs the following text: abc/*defghi the output will just be abc*/
/*The program will also decomment other types of user inputs*/

#include <stdio.h>
#include <stdlib.h>


/* Let us first make an enum to store all the possible states of the DFA*/
enum States
{
    NORMAL, SLASH, STARBG, STARED, DQUOTE, SQUOTE, BSLASH, DQ_BSLASH, SQ_BSLASH, S_BSLASH 
};
