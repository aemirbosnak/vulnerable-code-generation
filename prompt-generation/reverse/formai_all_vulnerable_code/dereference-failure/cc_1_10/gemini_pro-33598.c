//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the data structure to store a password
typedef struct {
    char *password;
    char *website;
    char *username;
} Password;

// Define the function to create a new password
Password *create_password(char *password, char *website, char *username) {
    Password *new_password = malloc(sizeof(Password));
    new_password->password = malloc(strlen(password) + 1);
    strcpy(new_password->password, password);
    new_password->website = malloc(strlen(website) + 1);
    strcpy(new_password->website, website);
    new_password->username = malloc(strlen(username) + 1);
    strcpy(new_password->username, username);
    return new_password;
}

// Define the function to delete a password
void delete_password(Password *password) {
    free(password->password);
    free(password->website);
    free(password->username);
    free(password);
}

// Define the function to print a password
void print_password(Password *password) {
    printf("Password: %s\n", password->password);
    printf("Website: %s\n", password->website);
    printf("Username: %s\n", password->username);
}

// Define the main function
int main() {
    // Create an array of passwords
    Password *passwords[NUM_PASSWORDS];

    // Create a new password
    passwords[0] = create_password("password1", "website1", "username1");

    // Print the password
    print_password(passwords[0]);

    // Delete the password
    delete_password(passwords[0]);

    return 0;
}