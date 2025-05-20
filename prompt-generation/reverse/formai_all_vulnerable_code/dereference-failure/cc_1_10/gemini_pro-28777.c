//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 100

// Define the maximum number of passwords
#define MAX_NUM_PASSWORDS 100

// Define the password structure
typedef struct {
    char *password;
    int length;
} Password;

// Create an array of passwords
Password passwords[MAX_NUM_PASSWORDS];

// Create a counter for the number of passwords
int num_passwords = 0;

// Get a password from the user
void get_password(Password *password) {
    // Prompt the user for the password
    printf("Enter a password: ");

    // Get the password from the user
    char *input = fgets(password->password, MAX_PASSWORD_LENGTH, stdin);

    // Remove the newline character from the password
    input[strcspn(input, "\n")] = 0;

    // Set the password length
    password->length = strlen(password->password);
}

// Add a password to the array of passwords
void add_password(Password password) {
    // Check if the array of passwords is full
    if (num_passwords >= MAX_NUM_PASSWORDS) {
        printf("The array of passwords is full.\n");
        return;
    }

    // Add the password to the array
    passwords[num_passwords++] = password;
}

// Print the array of passwords
void print_passwords() {
    // Loop through the array of passwords
    for (int i = 0; i < num_passwords; i++) {
        // Print the password
        printf("%s\n", passwords[i].password);
    }
}

// Main function
int main() {
    // Get a password from the user
    Password password;
    get_password(&password);

    // Add the password to the array of passwords
    add_password(password);

    // Print the array of passwords
    print_passwords();

    return 0;
}