#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "crypt.h"

int	username_valid(char username[]){

        int username_len = strlen(username);

	if(username_len >= MAX_USERNAME_LEN-1)
          return -1;

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


void	get_username(char username[]){

	username[0] = 0;
	while( 1 ){
		printf("Enter username: ");
		scanf("%62[^\n]", username);
        	if( username_valid( username ) == 0 ){
                    printf("Good name.\n");
                    break;
                }
                printf("Illegal char in username, A-Z a-z 0-9 allowed");
	}
}

void	get_password(char password[] ){
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



void    print_hex(unsigned char key[], int len){
	
	for(int counter=0; counter<len;counter++){
          int temp = key[counter];
          printf(" %02X", temp);
          if (counter % 16 == 15)
               printf("\n");
        }
}

