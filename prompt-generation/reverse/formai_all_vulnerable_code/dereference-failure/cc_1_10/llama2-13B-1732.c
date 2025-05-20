//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    int attempts;
} password_info;

// Function to generate a random password
void generate_password(password_info *password) {
    int i, j;
    char c;
    for (i = 0; i < 10; i++) {
        c = 'a' + (rand() % 26);
        password->password[i] = c;
    }
    password->password[i] = '\0';
}

// Function to check if the password is correct
int check_password(password_info *password, char *input_password) {
    int i, j;
    for (i = 0; i < strlen(password->password); i++) {
        if (password->password[i] != input_password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to handle login attempts
void handle_login_attempts(password_info *password, char *input_password) {
    int attempts = password->attempts;
    if (check_password(password, input_password)) {
        // Password is correct, increase the number of attempts
        password->attempts = attempts + 1;
        printf("Welcome, %s!\n", password->username);
    } else {
        // Password is incorrect, display the number of attempts left
        printf("Incorrect password. %d attempts left.\n", attempts);
    }
}

int main() {
    password_info passwords[MAX_PASSWORDS];
    int i, j;

    // Generate random passwords for each user
    for (i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    // Display the passwords and prompt the user to enter a password
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("%d. %s\n", i + 1, passwords[i].username);
    }

    // Loop until the user enters a correct password
    while (1) {
        // Display the list of passwords and prompt the user to enter a password
        for (i = 0; i < MAX_PASSWORDS; i++) {
            printf("%d. %s\n", i + 1, passwords[i].username);
        }

        // Get the user's input and check if it's correct
        char input_password[10];
        printf("Enter your password: ");
        fgets(input_password, 10, stdin);
        for (j = 0; j < strlen(input_password); j++) {
            input_password[j] = tolower(input_password[j]);
        }
        handle_login_attempts(passwords, input_password);
    }

    return 0;
}