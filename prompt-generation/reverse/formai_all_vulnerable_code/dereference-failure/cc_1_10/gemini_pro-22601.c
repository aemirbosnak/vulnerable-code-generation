//GEMINI-pro DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to store password details
typedef struct password {
    char *website;
    char *username;
    char *password;
} password;

// Array to store all passwords
password *passwords[100];

// Index of the last password
int password_index = 0;

// Function to get a password by website
password *get_password(char *website) {
    for (int i = 0; i < password_index; i++) {
        if (strcmp(passwords[i]->website, website) == 0) {
            return passwords[i];
        }
    }
    return NULL;
}

// Function to add a new password
void add_password(char *website, char *username, char *password) {
    if (password_index == 100) {
        printf("Password manager is full!\n");
        return;
    }
    passwords[password_index] = malloc(sizeof(password));
    passwords[password_index]->website = strdup(website);
    passwords[password_index]->username = strdup(username);
    passwords[password_index]->password = strdup(password);
    password_index++;
}

// Function to delete a password
void delete_password(char *website) {
    for (int i = 0; i < password_index; i++) {
        if (strcmp(passwords[i]->website, website) == 0) {
            free(passwords[i]->website);
            free(passwords[i]->username);
            free(passwords[i]->password);
            free(passwords[i]);
            for (int j = i; j < password_index - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            password_index--;
            return;
        }
    }
    printf("Password not found!\n");
}

int main() {
    // Create a password
    add_password("google.com", "username", "password");

    // Get the password
    password *google_password = get_password("google.com");

    // Print the password
    printf("Website: %s\n", google_password->website);
    printf("Username: %s\n", google_password->username);
    printf("Password: %s\n", google_password->password);

    // Delete the password
    delete_password("google.com");

    return 0;
}