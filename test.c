#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "crypt.h"

#define CBC 1
#define CTR 1
#define ECB 1

#include "aes.h"


int  main(){
	char username[MAX_USERNAME_LEN];
	char password[MAX_PASSWORD_LEN];
	unsigned char result[MAX_PASSWORD_LEN+MAX_USERNAME_LEN];
	unsigned char key[MAX_KEY_LEN];
        struct AES_ctx ctx;

        init_random();

	get_username( username );
	get_password( password );

	printf ("Login: %s\n", username);
	printf ("Passwd: %s\n",password);

	generate_key(key, MAX_KEY_LEN);
        make_entry(result, username, password, MAX_USERNAME_LEN, MAX_PASSWORD_LEN);

        printf("Open entry\n");
        print_hex(result, MAX_PASSWORD_LEN+MAX_USERNAME_LEN);

        printf("ECB encrypt...\n");
        AES_init_ctx(&ctx, key);
        AES_ECB_encrypt(&ctx, result);

	printf("Encrypted entry\n");
	print_hex(result, MAX_PASSWORD_LEN+MAX_USERNAME_LEN);

	printf("Key\n");
	print_hex(key, MAX_KEY_LEN);

	exit(0);
}

