//Gemma-7B DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *passwords = NULL;

void add_password(char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (passwords == NULL) {
        passwords = new_password;
    } else {
        passwords->next = new_password;
        passwords = new_password;
    }
}

char *get_password(char *name) {
    Password *current_password = passwords;

    while (current_password) {
        if (strcmp(current_password->name, name) == 0) {
            return current_password->password;
        }
        current_password = current_password->next;
    }

    return NULL;
}

int main() {
    add_password("John Doe", "Secret123!");
    add_password("Jane Doe", "Secret456!");

    char *password = get_password("John Doe");

    if (password) {
        printf("Password for John Doe: %s\n", password);
    } else {
        printf("No password found for John Doe.\n");
    }

    return 0;
}