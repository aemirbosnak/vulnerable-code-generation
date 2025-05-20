//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *password;
    int attempts;
} password_info;

// Function to get password from user
void get_password(password_info *password) {
    printf("Enter your password: ");
    fgets(password->password, 20, stdin);
    password->attempts = 0;
}

// Function to check if password is correct
bool check_password(password_info *password, char *correct_password) {
    if (strcmp(password->password, correct_password) == 0) {
        return true;
    } else {
        return false;
    }
}

// Function to handle incorrect password attempts
void handle_incorrect_attempt(password_info *password) {
    password->attempts++;
    if (password->attempts >= MAX_ATTEMPTS) {
        printf("Incorrect password attempts exceeded. Access denied.\n");
        exit(1);
    }
}

int main() {
    // Array to store password information
    password_info passwords[MAX_PASSWORDS] = {0};

    // Initialize password information
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].password = malloc(20 * sizeof(char));
        passwords[i].attempts = 0;
    }

    // Get password from user
    get_password(&passwords[0]);

    // Check if password is correct
    char correct_password[] = "secret";
    if (!check_password(&passwords[0], correct_password)) {
        handle_incorrect_attempt(&passwords[0]);
    }

    // Check if another password is correct
    char correct_password2[] = "password123";
    if (!check_password(&passwords[1], correct_password2)) {
        handle_incorrect_attempt(&passwords[1]);
    }

    // Check if final password is correct
    char correct_password3[] = "password!123";
    if (check_password(&passwords[2], correct_password3)) {
        printf("Correct password entered! Access granted.\n");
    } else {
        handle_incorrect_attempt(&passwords[2]);
    }

    // Free memory
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].password);
    }

    return 0;
}