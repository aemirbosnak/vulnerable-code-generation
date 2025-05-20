//Falcon-180B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int password_length = strlen(password);
    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
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

            passwords[i] = passwords[num_passwords - 1];
            num_passwords--;

            return;
        }
    }

    printf("Error: Password not found.\n");
}

void list_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Username\t\tPassword\n");
    printf("---------------------------------------------------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    char *username = "example_username";
    char *password = "example_password";

    add_password(username, password);

    list_passwords();

    remove_password(username);

    list_passwords();
}