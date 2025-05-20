//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define HASHTABLE_SIZE 256

typedef struct PasswordEntry {
    char *password;
    struct PasswordEntry *next;
} PasswordEntry;

PasswordEntry *insert_password(PasswordEntry *head, char *password) {
    PasswordEntry *new_entry = malloc(sizeof(PasswordEntry));
    new_entry->password = strdup(password);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = new_entry;
    }

    return head;
}

int validate_password(PasswordEntry *head, char *password) {
    for (PasswordEntry *entry = head; entry; entry = entry->next) {
        if (strcmp(entry->password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    PasswordEntry *head = NULL;

    // Insert some passwords into the hashtable
    insert_password(head, "strong_password");
    insert_password(head, "weak_password");
    insert_password(head, "super_secret");

    // Check if a password is valid
    if (validate_password(head, "strong_password") == 1) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}