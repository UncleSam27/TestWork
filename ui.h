#ifndef _UI_H_
#define _UI_H_

#define MAX_USERNAME_LEN 64
#define MAX_PASSWORD_LEN 64

#define PASSWD_MIN_LEN    8
#define PASSWD_LC_MIN     2
#define PASSWD_UC_MIN     2
#define PASSWD_DIGIT_MIN  1
#define PASSWD_SP_MIN     1


int	username_valid(char string[]);
int	passwd_valid(char pass[]);
int	get_keylen();
void	get_username(char username[]);
void	get_password(char* password );
void    print_hex(unsigned char key[], int len);

#endif /*  __UI_H_ */
