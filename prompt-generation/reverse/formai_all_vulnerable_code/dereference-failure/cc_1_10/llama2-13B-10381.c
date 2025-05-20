//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

struct password {
    char *name;
    char *password;
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i;

    // Initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(MAX_LENGTH * sizeof(char));
        passwords[i].password = malloc(MAX_LENGTH * sizeof(char));
        memset(passwords[i].name, 0, MAX_LENGTH);
        memset(passwords[i].password, 0, MAX_LENGTH);
    }

    // Password prompt and storage
    printf("Enter your password: ");
    fgets(passwords[0].name, MAX_LENGTH, stdin);
    printf("Enter your password again: ");
    fgets(passwords[0].password, MAX_LENGTH, stdin);

    // Password validation
    for (i = 1; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, passwords[0].name) != 0) {
            printf("Incorrect password\n");
            return 1;
        }
        if (strcmp(passwords[i].password, passwords[0].password) != 0) {
            printf("Incorrect password\n");
            return 1;
        }
    }

    // Password storage
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Stored password: %s\n", passwords[i].name);
    }

    // Password retrieval
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Retrieved password: %s\n", passwords[i].password);
    }

    // Password deletion
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].name);
        free(passwords[i].password);
    }

    return 0;
}