//Gemma-7B DATASET v1.0 Category: Password management ; Style: automated
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

Password *create_password(char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;
    return new_password;
}

void add_password(Password **head, char *name, char *password) {
    Password *new_password = create_password(name, password);
    if (*head == NULL) {
        *head = new_password;
    } else {
        (*head)->next = new_password;
    }
}

void list_passwords(Password *head) {
    Password *current = head;
    while (current) {
        printf("%s: %s\n", current->name, current->password);
        current = current->next;
    }
}

int main() {
    Password *passwords = NULL;

    // Add some passwords
    add_password(&passwords, "John Doe", "Secret123!");
    add_password(&passwords, "Jane Doe", "StrongPasword!");
    add_password(&passwords, "Peter Pan", "Neverland!");

    // List all passwords
    list_passwords(passwords);

    return 0;
}