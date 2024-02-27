#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void init_random(){
    srand(time(NULL));
}


void generate_key(unsigned char key[], int len){
    for(int counter = 0; counter< len; counter++)
      key[counter] = rand();
}

void make_entry(unsigned char result[], char username[], char password[], int username_len, int password_len){
    int total_len= username_len + password_len;

    char* temp = (char*) result;

    //add random in entry
    for(int counter = 0; counter < total_len; counter++)
      result[counter] = rand();

    //copy username and password to entry
    strcpy(temp, username);
    temp+=username_len;
    strcpy(temp, password);    

}



