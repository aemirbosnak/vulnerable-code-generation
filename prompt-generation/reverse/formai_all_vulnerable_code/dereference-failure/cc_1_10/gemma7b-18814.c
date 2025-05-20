//Gemma-7B DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *head = NULL;

void add_password(char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (head == NULL) {
        head = new_password;
    } else {
        Password *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_password;
    }
}

char *get_password(char *name) {
    Password *current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->password;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    add_password("John Doe", "Secret123!");
    add_password("Jane Doe", "StrongPasword!");
    add_password("Alice White", "CuriousCat!");

    char *password = get_password("Jane Doe");
    if (password) {
        printf("Password for Jane Doe: %s\n", password);
    } else {
        printf("No password found for Jane Doe.\n");
    }

    return 0;
}