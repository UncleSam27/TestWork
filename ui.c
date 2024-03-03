#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "crypt.h"


#define MAX_FORMAT_LEN 16

void    clear_input_buffer(){
	scanf("%*[^\n]");
	scanf("%*c");
}


int	username_valid(char username[]){

        int username_len = strlen(username);

	if(username_len >= MAX_USERNAME_LEN-1){
          clear_input_buffer();
          return -1;
        }

        if(username_len == 0 )  //username must contain 1 char. min
          return -1;

	for(int i=0; i<username_len; i++){
          if (username[i] >= 'a' && username[i] <= 'z') continue;
          if (username[i] >= 'A' && username[i] <= 'Z') continue;
          if (username[i] >= '0' && username[i] <= '9') continue;
          if (username[i] == 0) break;
          return -1;
	}
        return 0;
}

int	passwd_valid(char pass[]){
     int lower_case_count = 0;
     int upper_case_count = 0;
     int digit_count = 0;
     int special = 0;

     
     int passwd_len = strlen(pass);
     if(passwd_len > MAX_PASSWORD_LEN-1){
          return -1;
     }
     for (int i = 0; i < passwd_len; i++) {
          if (pass[i] >= 'a' && pass[i] <= 'z') ++lower_case_count;
          if (pass[i] >= 'A' && pass[i] <= 'Z') ++upper_case_count;
          if (pass[i] >= '0' && pass[i] <= '9') ++digit_count;
          if (pass[i] == '@') ++special;
          if (pass[i] == '#') ++special;
          if (pass[i] == '$') ++special;
          if (pass[i] == '^') ++special;
          if (pass[i] == '&') ++special;
     }    
     if ( passwd_len >= PASSWD_MIN_LEN 
       && lower_case_count >= PASSWD_LC_MIN
       && upper_case_count >= PASSWD_UC_MIN
       && digit_count >= PASSWD_DIGIT_MIN
       && special >= PASSWD_SP_MIN
     ){
          return 0;
     }
     return -1;
}


void   remove_newline(char * buffer){
	char* temp_ptr;
	temp_ptr = strchr (buffer,'\r');
	if(temp_ptr)
		*temp_ptr = 0;

        temp_ptr = strchr (buffer,'\n');
        if(temp_ptr)
                *temp_ptr = 0;
}





void	get_username(char username[]){
	while( 1 ){
		printf("Enter username: ");
                fgets(username, MAX_USERNAME_LEN, stdin);
                remove_newline(username);
        	if( username_valid( username ) == 0 ){
                    printf("Good name.\n");
                    break;
                }
                printf("Name too long, or illegal char in username, A-Z a-z 0-9 allowed\n");
	}
}

void	get_password(char* password ){
        char* newpass;

        while( 1 ){
                newpass = getpass("Password: ");
                if( passwd_valid( newpass ) == 0 ){
                  printf("Strong password\n");
                  break;
                }
	        printf("The password must be at least %d characters long, and contain at least %d lowercase characters, %d uppercase characters, %d digit, and %d special character (@#$^&).\n"
	          , PASSWD_MIN_LEN
	          , PASSWD_LC_MIN
	          , PASSWD_UC_MIN
	          , PASSWD_DIGIT_MIN
	          , PASSWD_SP_MIN
	        );
        }
        strcpy(password, newpass);
}


int     get_keylen(){
	while(1){      // переделать на fgets
		printf("Select key lenght: \n1 - 256bit \n2 - 192bit \n3 - 128bit\n");
		char ch=getchar();   
		if(ch == '1') return 256;
		if(ch == '2') return 192;
		if(ch == '3') return 128;
		printf("Only 1,2,3 allowed\n");
		clear_input_buffer();

	}
}

void    print_hex(unsigned char key[], int len){
	
	for(int counter=0; counter<len;counter++){
          int temp = key[counter];
          printf(" %02X", temp);
          if (counter % 16 == 15)
               printf("\n");
        }
}

