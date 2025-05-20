//GEMINI-pro DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

// Structure to store a password.
typedef struct {
    char *password;
    char *website;
    char *username;
} Password;

// Array of passwords.
Password passwords[MAX_PASSWORDS];

// Number of passwords stored in the array.
int num_passwords = 0;

// Function to add a new password to the array.
void add_password(char *password, char *website, char *username) {
    // Check if the array is full.
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: The password array is full.\n");
        return;
    }

    // Allocate memory for the new password.
    passwords[num_passwords].password = malloc(strlen(password) + 1);
    passwords[num_passwords].website = malloc(strlen(website) + 1);
    passwords[num_passwords].username = malloc(strlen(username) + 1);

    // Copy the password, website, and username into the new password.
    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].website, website);
    strcpy(passwords[num_passwords].username, username);

    // Increment the number of passwords stored in the array.
    num_passwords++;
}

// Function to delete a password from the array.
void delete_password(int index) {
    // Check if the index is valid.
    if (index < 0 || index >= num_passwords) {
        printf("Error: The index is invalid.\n");
        return;
    }

    // Free the memory allocated for the password.
    free(passwords[index].password);
    free(passwords[index].website);
    free(passwords[index].username);

    // Shift the remaining passwords down one index.
    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    // Decrement the number of passwords stored in the array.
    num_passwords--;
}

// Function to print the passwords stored in the array.
void print_passwords() {
    // Print the header.
    printf("%-20s %-20s %-20s\n", "Password", "Website", "Username");

    // Print each password.
    for (int i = 0; i < num_passwords; i++) {
        printf("%-20s %-20s %-20s\n", passwords[i].password, passwords[i].website, passwords[i].username);
    }
}

// Main function.
int main() {
    // Add some passwords to the array.
    add_password("password1", "website1", "username1");
    add_password("password2", "website2", "username2");
    add_password("password3", "website3", "username3");

    // Print the passwords stored in the array.
    print_passwords();

    // Delete a password from the array.
    delete_password(1);

    // Print the passwords stored in the array.
    print_passwords();

    return 0;
}