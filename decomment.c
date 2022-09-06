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


/* We will need functions to handle each of the states */

/*Function for the normal state*/
void normalStateHandler(int character,enum States *state){
    if(character  =='/'){
        *state = SLASH;
    } 
    else if(character  == '"'){
        *state = DQUOTE;
        putchar(character);
    }
    else if(character  == '\''){
        *state = SQUOTE;
        putchar(character);
    }
    else if(character  == '\\'){
        *state = BSLASH;
    }
    else{
        *state = NORMAL;
        putchar(character);
    }
}

/*Function for the starbg state*/
void starbgStateHandler(int character,enum States *state){
    if(character == '*'){
        *state = STARED;
    }
    else if(character == '\\'){
        *state = S_BSLASH;
    }
    else{
        *state = STARBG;
    }
}

/*Function for the dquote state*/
void dquoteStateHandler(int character,enum States *state){
    if(character == '"'){
        *state = NORMAL;
        putchar(character);
    }
    else if(character == '\\'){
        *state = DQ_BSLASH;
    }
    else{
        *state = DQUOTE;
        putchar(character);
        
    }

}
