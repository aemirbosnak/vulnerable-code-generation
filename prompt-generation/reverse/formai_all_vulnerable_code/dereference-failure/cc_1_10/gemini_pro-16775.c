//GEMINI-pro DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

// Structure to store a password
typedef struct {
    char *password;
    char *website;
    char *username;
} Password;

// Array of passwords
Password passwords[MAX_PASSWORDS];

// Number of passwords
int num_passwords = 0;

// Function to add a password to the array
void add_password(char *password, char *website, char *username) {
    // Check if the array is full
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password array is full.\n");
        return;
    }

    // Allocate memory for the password
    passwords[num_passwords].password = malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords].password, password);

    // Allocate memory for the website
    passwords[num_passwords].website = malloc(strlen(website) + 1);
    strcpy(passwords[num_passwords].website, website);

    // Allocate memory for the username
    passwords[num_passwords].username = malloc(strlen(username) + 1);
    strcpy(passwords[num_passwords].username, username);

    // Increment the number of passwords
    num_passwords++;
}

// Function to find a password by website
Password *find_password(char *website) {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Check if the website matches
        if (strcmp(passwords[i].website, website) == 0) {
            // Return the password
            return &passwords[i];
        }
    }

    // Return NULL if the password was not found
    return NULL;
}

// Function to print the passwords
void print_passwords() {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Print the password
        printf("%s: %s (%s)\n", passwords[i].website, passwords[i].password, passwords[i].username);
    }
}

// Main function
int main() {
    // Add some passwords to the array
    add_password("password1", "website1", "username1");
    add_password("password2", "website2", "username2");
    add_password("password3", "website3", "username3");

    // Find a password by website
    Password *password = find_password("website2");

    // Print the password
    printf("Password for website2: %s\n", password->password);

    // Print all the passwords
    print_passwords();

    return 0;
}