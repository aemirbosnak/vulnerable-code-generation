//Gemma-7B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *insertPassword(Password *head, char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (head == NULL) {
        head = new_password;
    } else {
        head->next = new_password;
    }

    return head;
}

void searchPassword(Password *head, char *name) {
    Password *current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Password: %s\n", current->password);
            return;
        }

        current = current->next;
    }

    printf("Password not found.\n");
}

int main() {
    Password *head = NULL;

    insertPassword(head, "John Doe", "secret123");
    insertPassword(head, "Jane Doe", "secret456");
    insertPassword(head, "Bob Smith", "secret789");

    searchPassword(head, "John Doe");
    searchPassword(head, "Jane Doe");
    searchPassword(head, "Bob Smith");
    searchPassword(head, "Random User");

    return 0;
}