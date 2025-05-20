//GEMINI-pro DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the maximum number of passwords
#define MAX_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char *password;
    int length;
} Password;

// Declare the array of passwords
Password passwords[MAX_PASSWORDS];

// Declare the current number of passwords
int num_passwords = 0;

// Function to add a password to the array
void add_password(char *password) {
    // Check if the array is full
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: The array of passwords is full.\n");
        return;
    }

    // Allocate memory for the password
    passwords[num_passwords].password = malloc(strlen(password) + 1);

    // Copy the password into the array
    strcpy(passwords[num_passwords].password, password);

    // Set the length of the password
    passwords[num_passwords].length = strlen(password);

    // Increment the current number of passwords
    num_passwords++;
}

// Function to remove a password from the array
void remove_password(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_passwords) {
        printf("Error: The index is invalid.\n");
        return;
    }

    // Free the memory for the password
    free(passwords[index].password);

    // Shift the passwords down to fill the gap
    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    // Decrement the current number of passwords
    num_passwords--;
}

// Function to print the passwords
void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i].password);
    }
}

// Main function
int main() {
    // Add some passwords to the array
    add_password("password1");
    add_password("password2");
    add_password("password3");

    // Print the passwords
    print_passwords();

    // Remove a password from the array
    remove_password(1);

    // Print the passwords again
    print_passwords();

    return 0;
}