//Gemma-7B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

Password passwords[MAX_PASSWORDS];

int main() {
    int i = 0;
    char input[20];
    char *p;

    // Initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
        passwords[i].used = 0;
    }

    // Get user input
    printf("Enter a password: ");
    scanf("%s", input);

    // Check if password is already used
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].name && strcmp(passwords[i].name, input) == 0) {
            printf("Error: password already used.\n");
            return 1;
        }
    }

    // Allocate memory for new password
    p = malloc(20);
    if (p == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    // Store password
    strcpy(p, input);
    passwords[i].name = p;
    passwords[i].password = p;
    passwords[i].used = 1;

    // Print confirmation
    printf("Password stored.\n");

    return 0;
}