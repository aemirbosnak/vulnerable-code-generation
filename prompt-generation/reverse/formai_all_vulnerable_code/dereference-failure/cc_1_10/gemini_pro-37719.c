//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style password management program

// Define the struct that will store the password information
typedef struct {
    char *username;
    char *password;
} password_info;

// Define the function that will create a new password
password_info *create_password(char *username, char *password) {
    // Allocate memory for the new password
    password_info *new_password = malloc(sizeof(password_info));

    // Copy the username and password into the new password
    new_password->username = strdup(username);
    new_password->password = strdup(password);

    // Return the new password
    return new_password;
}

// Define the function that will free the memory allocated for a password
void free_password(password_info *password) {
    // Free the memory allocated for the username and password
    free(password->username);
    free(password->password);

    // Free the memory allocated for the password struct
    free(password);
}

// Define the function that will compare two passwords
int compare_passwords(password_info *password1, password_info *password2) {
    // Compare the usernames
    if (strcmp(password1->username, password2->username) != 0) {
        return 0;
    }

    // Compare the passwords
    if (strcmp(password1->password, password2->password) != 0) {
        return 0;
    }

    // The passwords are the same
    return 1;
}

// Define the main function
int main() {
    // Create a new password for Romeo
    password_info *romeo_password = create_password("Romeo", "My mistress' eyes are nothing like the sun");

    // Create a new password for Juliet
    password_info *juliet_password = create_password("Juliet", "My bounty is as boundless as the sea");

    // Compare the passwords
    int passwords_match = compare_passwords(romeo_password, juliet_password);

    // Print the result
    if (passwords_match) {
        printf("Romeo and Juliet's passwords match!\n");
    } else {
        printf("Romeo and Juliet's passwords do not match!\n");
    }

    // Free the memory allocated for the passwords
    free_password(romeo_password);
    free_password(juliet_password);

    return 0;
}