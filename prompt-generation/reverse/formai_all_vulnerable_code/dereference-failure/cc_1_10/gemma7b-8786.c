//Gemma-7B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *insertPassword(Password *head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    printf("Enter password name: ");
    scanf("%s", new_password->name);

    printf("Enter password: ");
    scanf("%s", new_password->password);

    if (head == NULL) {
        head = new_password;
    } else {
        head->next = new_password;
    }

    return head;
}

void displayPasswords(Password *head) {
    Password *current = head;

    printf("List of passwords:\n");
    while (current) {
        printf("Name: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

int main() {
    Password *passwords = NULL;

    // Insert passwords
    passwords = insertPassword(passwords);
    insertPassword(passwords);
    insertPassword(passwords);

    // Display passwords
    displayPasswords(passwords);

    return 0;
}