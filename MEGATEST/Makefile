CC=gcc
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-MMD
PREF_SRC=./src/
PREF_OBJ=./obj/
SRC=$(wildcard $(PREF_SRC)*.c)
OBJ=$(patsubst $(PREF_SRC)%.c,$(PREF_OBJ)%.o,$(SRC))


all: app

app:$(OBJ)
	$(CC) $(CFLAGS) -o app $(OBJ)
$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm app $(PREF_OBJ)*.o