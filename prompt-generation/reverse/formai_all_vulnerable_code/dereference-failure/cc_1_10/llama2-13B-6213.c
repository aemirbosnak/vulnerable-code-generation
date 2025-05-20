//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the password storage structure
typedef struct {
    char *password;
    int frequency;
} password_t;

// Define a function to generate a random password
void generate_random_password(password_t *password) {
    // Generate a random password of the maximum length
    password->password = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = 'a' + (rand() % 26);
    }
    password->frequency = 0;
}

// Define a function to check if a password is valid
int check_password(password_t *password, char *input) {
    // Check if the input password matches the stored password
    if (strcmp(password->password, input) == 0) {
        // Increment the frequency of the password if it's valid
        password->frequency++;
        return 1;
    }
    return 0;
}

// Define a function to update the password storage
void update_password(password_t *password) {
    // Generate a new random password if the frequency is below a threshold
    if (password->frequency < 5) {
        generate_random_password(password);
    }
    // Update the frequency of the password
    password->frequency++;
}

int main() {
    // Create an array of password structures
    password_t passwords[5];

    // Initialize the password structures with random passwords
    for (int i = 0; i < 5; i++) {
        generate_random_password(&passwords[i]);
    }

    // Print the initial passwords
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", i, passwords[i].password);
    }

    // Ask the user to input a password
    char user_input[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    fgets(user_input, MAX_PASSWORD_LENGTH, stdin);

    // Check if the input password is valid for any of the stored passwords
    for (int i = 0; i < 5; i++) {
        if (check_password(&passwords[i], user_input)) {
            // If the input password is valid, update the frequency of the password
            update_password(&passwords[i]);
            printf("Valid password! %d: %s\n", i, passwords[i].password);
        } else {
            printf("Invalid password. Try again!\n");
        }
    }

    // Print the final passwords and their frequencies
    for (int i = 0; i < 5; i++) {
        printf("%d: %s (%d)\n", i, passwords[i].password, passwords[i].frequency);
    }

    return 0;
}