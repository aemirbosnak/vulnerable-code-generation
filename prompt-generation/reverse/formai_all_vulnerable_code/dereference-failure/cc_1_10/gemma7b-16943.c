//Gemma-7B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 25

typedef struct Password {
    char *name;
    char *password;
} Password;

void create_passwords(Password **passwords) {
    *passwords = (Password *)malloc(MAX_PASSWORDS * sizeof(Password));
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        (*passwords)[i].name = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
        (*passwords)[i].password = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    }
}

void add_password(Password **passwords, char *name, char *password) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if ((*passwords)[i].name == NULL) {
            strcpy((*passwords)[i].name, name);
            strcpy((*passwords)[i].password, password);
            return;
        }
    }

    fprintf(stderr, "Error: Password list full.\n");
}

void print_passwords(Password **passwords) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if ((*passwords)[i].name) {
            printf("%s: %s\n", (*passwords)[i].name, (*passwords)[i].password);
        }
    }
}

int main() {
    Password *passwords = NULL;
    create_passwords(&passwords);

    add_password(passwords, "John Doe", "secret");
    add_password(passwords, "Jane Doe", "another secret");

    print_passwords(passwords);

    free(passwords);

    return 0;
}