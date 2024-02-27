#ifndef _CRYPT_H_
#define _CRYPT_H_

#define MAX_KEY_LEN 256/8

void init_random();
void generate_key(unsigned char key[], int len);
void make_entry(unsigned char result[], char username[], char password[], int username_len, int password_len);

#endif /*  __CRYPT_H_ */
