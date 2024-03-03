#ifndef _CRYPT_H_
#define _CRYPT_H_

#include <stdint.h>
#define MAX_KEY_LEN 256/8


#ifndef UNUSED
#define UNUSED(expr) do { (void)(expr); } while (0)
#endif


void init_random();
void generate_key(unsigned char key[], int len);
void make_entry(unsigned char result[], char username[], char password[], int username_len, int password_len);
void get_entry_values(unsigned char entry[], char username[], char password[], int username_len, int password_len);
void encrypt_aes(unsigned char key[], unsigned char result[], uint16_t KeyLen);
void decrypt_aes(unsigned char key[], unsigned char result[], uint16_t KeyLen);

#endif /*  __CRYPT_H_ */
