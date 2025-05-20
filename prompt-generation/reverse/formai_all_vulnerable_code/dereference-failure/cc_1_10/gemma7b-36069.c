//Gemma-7B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

void insert_password(Password **head, char *name, char *password) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (*head == NULL) {
        *head = new_password;
    } else {
        (*head)->next = new_password;
    }
}

int search_password(Password *head, char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Password *head = NULL;

    insert_password(&head, "John Doe", "secret");
    insert_password(&head, "Jane Doe", "another secret");

    if (search_password(head, "John Doe") == 1) {
        printf("John Doe's password is secret\n");
    }

    return 0;
}