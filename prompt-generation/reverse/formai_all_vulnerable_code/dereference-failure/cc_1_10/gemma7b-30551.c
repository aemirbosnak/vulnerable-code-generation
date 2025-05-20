//Gemma-7B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *createPassword() {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    return new_password;
}

void addPassword(Password *head, char *name, char *password) {
    Password *new_password = createPassword();

    strcpy(new_password->name, name);
    strcpy(new_password->password, password);

    if (head == NULL) {
        head = new_password;
    } else {
        new_password->next = head;
        head = new_password;
    }
}

void printPasswords(Password *head) {
    Password *current = head;

    while (current) {
        printf("Name: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

int main() {
    Password *passwords = NULL;

    addPassword(passwords, "John Doe", "Secret123");
    addPassword(passwords, "Jane Doe", "StrongPassword");
    addPassword(passwords, "Peter Pan", "Neverland");

    printPasswords(passwords);

    return 0;
}