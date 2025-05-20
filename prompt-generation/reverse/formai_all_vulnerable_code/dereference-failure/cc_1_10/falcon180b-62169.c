//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

void remove_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i - 1));

            num_passwords--;

            break;
        }
    }
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s:%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char *username = "test";
    char *password = "password";

    add_password(username, password);
    print_passwords();

    remove_password(username);
    print_passwords();

    return 0;
}