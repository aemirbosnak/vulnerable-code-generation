//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char *password;
    char *website;
    char *username;
} Password;

// Define the array of passwords
Password passwords[NUM_PASSWORDS];

// Define the function to add a password to the array
void add_password(char *password, char *website, char *username) {
    // Check if the array is full
    if (passwords[NUM_PASSWORDS - 1].password != NULL) {
        printf("Password array is full\n");
        return;
    }

    // Allocate memory for the password
    passwords[NUM_PASSWORDS - 1].password = malloc(MAX_PASSWORD_LENGTH);

    // Copy the password into the array
    strcpy(passwords[NUM_PASSWORDS - 1].password, password);

    // Allocate memory for the website
    passwords[NUM_PASSWORDS - 1].website = malloc(MAX_PASSWORD_LENGTH);

    // Copy the website into the array
    strcpy(passwords[NUM_PASSWORDS - 1].website, website);

    // Allocate memory for the username
    passwords[NUM_PASSWORDS - 1].username = malloc(MAX_PASSWORD_LENGTH);

    // Copy the username into the array
    strcpy(passwords[NUM_PASSWORDS - 1].username, username);
}

// Define the function to get a password from the array
char *get_password(char *website, char *username) {
    // Iterate over the array of passwords
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        // Check if the website and username match
        if (strcmp(passwords[i].website, website) == 0 && strcmp(passwords[i].username, username) == 0) {
            // Return the password
            return passwords[i].password;
        }
    }

    // Return NULL if the password is not found
    return NULL;
}

// Define the function to delete a password from the array
void delete_password(char *website, char *username) {
    // Iterate over the array of passwords
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        // Check if the website and username match
        if (strcmp(passwords[i].website, website) == 0 && strcmp(passwords[i].username, username) == 0) {
            // Free the memory for the password
            free(passwords[i].password);

            // Free the memory for the website
            free(passwords[i].website);

            // Free the memory for the username
            free(passwords[i].username);

            // Set the password to NULL
            passwords[i].password = NULL;

            // Set the website to NULL
            passwords[i].website = NULL;

            // Set the username to NULL
            passwords[i].username = NULL;

            // Return
            return;
        }
    }

    // Print an error message if the password is not found
    printf("Password not found\n");
}

// Define the function to print the array of passwords
void print_passwords() {
    // Iterate over the array of passwords
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        // Check if the password is not NULL
        if (passwords[i].password != NULL) {
            // Print the password
            printf("Password: %s\n", passwords[i].password);

            // Print the website
            printf("Website: %s\n", passwords[i].website);

            // Print the username
            printf("Username: %s\n", passwords[i].username);
        }
    }
}

// Define the main function
int main() {
    // Add some passwords to the array
    add_password("password1", "website1", "username1");
    add_password("password2", "website2", "username2");
    add_password("password3", "website3", "username3");

    // Print the array of passwords
    print_passwords();

    // Get a password from the array
    char *password = get_password("website1", "username1");

    // Print the password
    printf("Password: %s\n", password);

    // Delete a password from the array
    delete_password("website2", "username2");

    // Print the array of passwords
    print_passwords();

    return 0;
}