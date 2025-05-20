//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: intelligent
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
    password[i] = '\0';
}

// Function to check if the password is correct
int check_password(struct password *password, char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == password->password[i]) {
            password->attempts++;
            return 1;
        }
    }
    return 0;
}

// Function to display the password information
void display_password(struct password *password) {
    printf("Username: %s\n", password->username);
    printf("Password: %s\n", password->password);
    printf("Attempts: %d\n", password->attempts);
}

int main() {
    // Create an array of password structures
    struct password passwords[MAX_PASSWORDS] = {
        {"Alice", "alice", 0},
        {"Bob", "bob", 0},
        {"Charlie", "charlie", 0},
    };

    // Generate a random password for each user
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(passwords[i].password);
    }

    // Display the password information
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        display_password(&passwords[i]);
    }

    // Loop until the user enters a correct password
    while (1) {
        // Ask the user to enter a username and password
        printf("Enter a username and password: ");
        char username[50];
        char password[50];
        fgets(username, 50, stdin);
        fgets(password, 50, stdin);

        // Check if the password is correct
        int found = 0;
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            if (check_password(&passwords[i], password)) {
                found = 1;
                break;
            }
        }

        // If the password is correct, display the corresponding username
        if (found) {
            printf("Welcome, %s!\n", username);
        } else {
            // If the password is incorrect, display an error message
            printf("Incorrect password. Try again.\n");
        }
    }

    return 0;
}