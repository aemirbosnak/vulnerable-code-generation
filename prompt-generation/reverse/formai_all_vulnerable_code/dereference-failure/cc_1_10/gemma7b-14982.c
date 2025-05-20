//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10

typedef struct PasswordEntry {
    char *password;
    struct PasswordEntry *next;
} PasswordEntry;

PasswordEntry *insertPassword(PasswordEntry *head, char *password) {
    PasswordEntry *newEntry = (PasswordEntry *)malloc(sizeof(PasswordEntry));
    newEntry->password = strdup(password);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }

    return head;
}

int checkPasswordStrength(PasswordEntry *head, char *password) {
    for (PasswordEntry *entry = head; entry; entry = entry->next) {
        if (strcmp(password, entry->password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    PasswordEntry *head = NULL;

    char *password = "MySecretPassword";
    insertPassword(head, password);

    password = "WeakPassword";
    insertPassword(head, password);

    password = "StrongPassword123";
    insertPassword(head, password);

    password = "BadPassword";
    insertPassword(head, password);

    if (checkPasswordStrength(head, password) == 1) {
        printf("Password found!\n");
    } else {
        printf("Password not found.\n");
    }

    return 0;
}