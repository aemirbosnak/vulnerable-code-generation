//GEMINI-pro DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} PasswordEntry;

int main() {
    // Create an array of password entries
    PasswordEntry passwords[100];

    // Get the number of password entries from the user
    int numEntries;
    printf("How many password entries do you want to create? ");
    scanf("%d", &numEntries);

    // Get the username and password for each entry
    for (int i = 0; i < numEntries; i++) {
        printf("Enter username for entry %d: ", i + 1);
        char username[100];
        scanf("%s", username);

        printf("Enter password for entry %d: ", i + 1);
        char password[100];
        scanf("%s", password);

        // Allocate memory for the username and password
        passwords[i].username = malloc(strlen(username) + 1);
        passwords[i].password = malloc(strlen(password) + 1);

        // Copy the username and password into the array
        strcpy(passwords[i].username, username);
        strcpy(passwords[i].password, password);
    }

    // Print the password entries
    printf("\nYour password entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }

    // Free the memory allocated for the usernames and passwords
    for (int i = 0; i < numEntries; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}