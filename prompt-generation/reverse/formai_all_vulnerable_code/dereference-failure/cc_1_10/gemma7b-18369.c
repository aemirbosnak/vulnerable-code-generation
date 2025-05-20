//Gemma-7B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *head = NULL;

void addPassword(char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (head == NULL) {
        head = new_password;
    } else {
        head->next = new_password;
    }
}

void findPassword(char *name) {
    Password *current_password = head;

    while (current_password) {
        if (strcmp(current_password->name, name) == 0) {
            printf("Password: %s\n", current_password->password);
            return;
        }
        current_password = current_password->next;
    }

    printf("No password found for name: %s\n", name);
}

int main() {
    addPassword("John Doe", "Secret123");
    addPassword("Jane Doe", "StrongPswd");

    findPassword("John Doe");
    findPassword("Jane Doe");

    return 0;
}