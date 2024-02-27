################################################################################
################################################################################

NAME = test
SOURCES = test.c ui.c crypt.c aes.c
OBJECTS =  $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -g

all: $(NAME)


$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)


clean:
	rm -rf $(OBJECTS)
	rm -rf $(NAME)

