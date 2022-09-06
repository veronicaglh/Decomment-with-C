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

/*Function for the slash state*/
void slashStateHandler(int character,enum States *state){
    if(character == '*'){
        *state = STARBG;
        putchar(' ');
    }
    else if(character == '/'){
        *state = SLASH;
        putchar(character);
    }
    else{
        *state = NORMAL;
        putchar('/');
        putchar(character);
    }
}

/*Function for the stared state*/
void staredStateHandler(int character,enum States *state){
    if(character == '/'){
        *state = NORMAL;
    }
    else if(character == '*'){
        *state = STARED;
    }
    else{
        *state = STARBG;
    }

}

/*Function for the sq_bslash state*/
void sq_bslashStateHandler(int character,enum States *state,int *line){
    if(character =='n'){
        putchar('\n');
        (*line)++;
    }
    else{
        putchar('\\');
        putchar(character);
    }
    *state = SQUOTE;
}

/*Function for the squote state*/
void squoteStateHandler(int character,enum States *state){
    if(character == '\''){
        *state = NORMAL;
        putchar(character);
    }
    else if(character == '\\'){
        *state = SQ_BSLASH;
    }
    else{
        *state = SQUOTE;
        putchar(character);
    }

}

/*Function for the s_bslash state*/
void s_bslashStateHandler(int character,enum States *state,int *line){
    if(character =='n'){
        putchar('\n');
        (*line)++;
    }
    else{
        putchar('\\');
        putchar(character);
    }
    *state = STARBG;
}

/*Function for the bslash state*/
void bslashStateHandler(int character,enum States *state,int *line){
    if(character =='n'){
        *state = NORMAL;
        putchar('\n');
        (*line)++;
    }
    else{
        *state = NORMAL;
        putchar('\\');
        putchar(character);
    }
}

/*Function for the dq_bslash state*/
void dq_bslashStateHandler(int character,enum States *state,int *line){
    if(character =='n'){
        putchar('\n');
        (*line)++;
    }
    else{
        putchar('\\');
        putchar(character);
    }
    *state = DQUOTE;
}
