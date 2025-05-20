//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: irregular
// The land of passwordia, where passwords rule supreme

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store passwords
typedef struct {
    char *username;
    char *password;
} password_t;

// Function to prompt user for input
void get_input(password_t *password) {
    printf("Enter username: ");
    fgets(password->username, 50, stdin);
    printf("Enter password: ");
    fgets(password->password, 50, stdin);
}

// Function to print password
void print_password(password_t password) {
    printf("Password for %s: %s\n", password.username, password.password);
}

// Function to check if password matches
int check_password(password_t password, char *expected) {
    if (strcmp(password.password, expected) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main program
int main() {
    password_t password;

    // Prompt user for input
    get_input(&password);

    // Print password
    print_password(password);

    // Check if password matches expected value
    if (check_password(password, "password123")) {
        printf("Correct password! Welcome to the land of passwordia.\n");
    } else {
        printf("Incorrect password. Sorry, you can't enter the land of passwordia.\n");
    }

    return 0;
}