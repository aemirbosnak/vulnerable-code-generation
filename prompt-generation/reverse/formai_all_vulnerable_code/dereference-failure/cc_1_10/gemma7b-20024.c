//Gemma-7B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LEN 20

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

void create_password(Password **head) {
    *head = malloc(sizeof(Password));
    (*head)->name = strdup("John Doe");
    (*head)->password = strdup("StrongPassw0rd");
    (*head)->next = NULL;
}

void add_password(Password **head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup("Jane Doe");
    new_password->password = strdup("AnotherStrongPassw0rd");
    new_password->next = NULL;

    if (*head) {
        (*head)->next = new_password;
    } else {
        *head = new_password;
    }
}

void list_passwords(Password *head) {
    while (head) {
        printf("%s: %s\n", head->name, head->password);
        head = head->next;
    }
}

int main() {
    Password *head = NULL;

    create_password(&head);
    add_password(&head);

    list_passwords(head);

    return 0;
}