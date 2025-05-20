//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
struct password {
    char *username;
    char *password;
    int attempts;
};

// Function to generate a random password
void generate_password(char *password) {
    int i, j;
    for (i = 0; i < 10; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    password[10] = '\0';
}

// Function to check if the password is correct
int check_password(struct password *password, char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (password->password[i] != input[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to display the password information
void display_password(struct password *password) {
    printf("Username: %s\n", password->username);
    printf("Password: %s\n", password->password);
    printf("Attempts: %d\n", password->attempts);
}

int main() {
    // Create an array to store the password information
    struct password passwords[MAX_PASSWORDS];

    // Initialize the passwords array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = (char *)malloc(20 * sizeof(char));
        passwords[i].password = (char *)malloc(20 * sizeof(char));
        passwords[i].attempts = 0;
        generate_password(passwords[i].password);
    }

    // Display the password information
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        display_password(passwords + i);
    }

    // Loop until the user quits
    while (1) {
        // Ask the user to enter a username and password
        printf("Enter a username: ");
        fgets(passwords[0].username, 20, stdin);
        printf("Enter a password: ");
        fgets(passwords[0].password, 20, stdin);

        // Check if the password is correct
        for (int i = 1; i < MAX_PASSWORDS; i++) {
            if (check_password(passwords + i, passwords[0].password)) {
                // If the password is correct, display the corresponding username
                display_password(passwords + i);
                break;
            }
        }

        // If the password is incorrect, display an error message
        if (passwords[0].attempts >= MAX_ATTEMPTS) {
            printf("Incorrect password! Access denied.\n");
        } else {
            passwords[0].attempts++;
            printf("Incorrect password. Try again.\n");
        }
    }

    // Free the memory allocated for the passwords array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}