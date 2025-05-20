//Gemma-7B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 25

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

void initializePasswords(Password *passwords) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(MAX_PASSWORD_LENGTH);
        passwords[i].password = malloc(MAX_PASSWORD_LENGTH);
        passwords[i].used = 0;
    }
}

void addPassword(Password *passwords, char *name, char *password) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (!passwords[i].used) {
            passwords[i].name = name;
            passwords[i].password = password;
            passwords[i].used = 1;
            return;
        }
    }

    printf("Error: No more passwords can be added.\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    initializePasswords(passwords);

    addPassword(passwords, "John Doe", "Secret123!");
    addPassword(passwords, "Jane Doe", "StrongPaswd!");
    addPassword(passwords, "Alice White", "Curious01!");

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].used) {
            printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
        }
    }

    return 0;
}