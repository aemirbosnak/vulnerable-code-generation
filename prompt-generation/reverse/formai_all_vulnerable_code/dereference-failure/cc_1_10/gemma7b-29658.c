//Gemma-7B DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MAX 20
#define HASH_LEN 64

typedef struct Password {
    char *name;
    char *hash;
    struct Password *next;
} Password;

Password *create_password(char *name, char *hash) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->hash = strdup(hash);
    new_password->next = NULL;
    return new_password;
}

void add_password(Password *head, char *name, char *hash) {
    Password *new_password = create_password(name, hash);
    if (head == NULL) {
        head = new_password;
    } else {
        new_password->next = head;
        head = new_password;
    }
}

char *get_password_hash(Password *head, char *name) {
    for (Password *curr = head; curr; curr = curr->next) {
        if (strcmp(curr->name, name) == 0) {
            return curr->hash;
        }
    }
    return NULL;
}

int main() {
    Password *passwords = NULL;

    // Add some passwords
    add_password(passwords, "John Doe", "Secret1");
    add_password(passwords, "Jane Doe", "Secret2");
    add_password(passwords, "Alice White", "Secret3");

    // Get the password hash for "John Doe"
    char *hash = get_password_hash(passwords, "John Doe");

    // Print the hash
    if (hash) {
        printf("Hash: %s\n", hash);
    } else {
        printf("Password not found.\n");
    }

    return 0;
}