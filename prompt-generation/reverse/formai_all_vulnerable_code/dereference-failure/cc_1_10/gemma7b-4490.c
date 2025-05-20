//Gemma-7B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *pass;
    struct Password *next;
} Password;

int main() {
    Password *passwords = NULL;
    char password[20];
    int i = 0;

    // Allocate memory for the first password
    passwords = malloc(sizeof(Password));
    passwords->name = strdup("Bob");
    passwords->pass = strdup("Secret");
    passwords->next = NULL;

    // Create a loop to add more passwords
    while (i < MAX_PASSWORDS) {
        printf("Enter a password: ");
        scanf("%s", password);

        // Allocate memory for a new password
        Password *new_passwords = malloc(sizeof(Password));
        new_passwords->name = strdup("User");
        new_passwords->pass = strdup(password);
        new_passwords->next = NULL;

        // Add the new password to the list
        passwords->next = new_passwords;
        passwords = new_passwords;
        i++;
    }

    // Print the passwords
    passwords = passwords->next;
    while (passwords) {
        printf("Name: %s, Password: %s\n", passwords->name, passwords->pass);
        passwords = passwords->next;
    }

    return 0;
}