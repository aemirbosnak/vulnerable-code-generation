//Gemma-7B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

void insert_password(Password **head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    printf("Enter password name: ");
    scanf("%s", new_password->name);

    printf("Enter password: ");
    scanf("%s", new_password->password);

    if (*head == NULL) {
        *head = new_password;
    } else {
        (*head)->next = new_password;
    }
}

void search_password(Password *head, char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Password: %s\n", head->password);
            return;
        }
        head = head->next;
    }

    printf("Password not found.\n");
}

int main() {
    Password *head = NULL;

    insert_password(&head);
    insert_password(&head);
    insert_password(&head);

    search_password(head, "John Doe");

    return 0;
}