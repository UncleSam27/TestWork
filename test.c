#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "crypt.h"

# define TEST


int  main(){
	char username[MAX_USERNAME_LEN];
	char password[MAX_PASSWORD_LEN];

#ifdef TEST
        char test_username[MAX_USERNAME_LEN];
        char test_password[MAX_PASSWORD_LEN];
#endif	

	unsigned char result[MAX_PASSWORD_LEN+MAX_USERNAME_LEN];
	unsigned char key[MAX_KEY_LEN];

        init_random();

	get_username( username );
	get_password( password );


#ifdef TEST
        printf ("Login: %s\n", username);
        printf ("Passwd: %s\n",password);

        //make backup for test
	strcpy(test_username, username);
	strcpy(test_password, password);
#endif

	generate_key(key, MAX_KEY_LEN);
        printf("\nKey\n");
        print_hex(key, MAX_KEY_LEN);

	//make user:password entry
        make_entry(result, username, password, MAX_USERNAME_LEN, MAX_PASSWORD_LEN);

        printf("\nOpen entry\n");
        print_hex(result, MAX_PASSWORD_LEN+MAX_USERNAME_LEN);

	//clean login and password
	memset(username, 0, sizeof(username));
        memset(password, 0, sizeof(password));

        printf("AES encrypt...\n");
        encrypt_aes(key, result);

	printf("\nEncrypted entry\n");
	print_hex(result, MAX_PASSWORD_LEN+MAX_USERNAME_LEN);


        printf("AES decrypt...\n");
        decrypt_aes(key, result);

        printf("\nDecrypted entry\n");
        print_hex(result, MAX_PASSWORD_LEN+MAX_USERNAME_LEN);

        get_entry_values(result, username, password, MAX_USERNAME_LEN, MAX_PASSWORD_LEN);
	
        printf ("Decrypted login: %s\n", username);
        printf ("Decrypted passwd: %s\n",password);


#ifdef TEST
	printf("\n");
        if (strcmp(test_username, username) == 0)
		printf ("Username - Ok\n");
	else
		printf ("Username - Error\n");
        if (strcmp(test_password, password) == 0)
                printf ("Password - Ok\n");
        else
                printf ("Password - Error\n");
	
#endif



	exit(0);
}

