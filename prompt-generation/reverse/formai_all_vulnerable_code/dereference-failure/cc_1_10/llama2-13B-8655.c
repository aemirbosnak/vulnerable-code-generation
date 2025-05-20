//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *password;
    int attempts;
} password_t;

// Function to generate a random password
void generate_password(password_t *password) {
    int i, j;
    for (i = 0; i < 10; i++) {
        password->password[i] = 'a' + (rand() % 26);
    }
    password->attempts = 0;
}

// Function to check if a password is correct
int check_password(password_t *password, char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (password->password[i] != input[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to handle password attempts
void handle_attempts(password_t *password, char *input) {
    if (check_password(password, input)) {
        printf("Correct password entered! Access granted.\n");
        return;
    }
    if (password->attempts >= MAX_ATTEMPTS) {
        printf("Too many incorrect attempts. Access denied.\n");
        return;
    }
    password->attempts++;
    printf("Incorrect attempt %d. Try again...\n", password->attempts);
    generate_password(password);
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int i;

    // Generate random passwords for each slot
    for (i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    // Loop until a correct password is entered
    while (1) {
        printf("Enter a password: ");
        char input[100];
        fgets(input, 100, stdin);

        // Check if the password is correct
        for (i = 0; i < MAX_PASSWORDS; i++) {
            handle_attempts(&passwords[i], input);
        }
    }

    return 0;
}