//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PASSWORD_LENGTH 20
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

// Structure to store password information
typedef struct {
    char *password; // Password as a string
    int length; // Length of the password
    int age; // Age of the password (in days)
} password_t;

// Function to generate a new password
password_t *generate_password(int length) {
    // Generate a random password using the CHAR_SET
    char *password = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        password[i] = CHAR_SET[rand() % strlen(CHAR_SET)];
    }
    return (password_t *)malloc(sizeof(password_t));
}

// Function to check the strength of a password
int check_strength(password_t *password) {
    // Calculate the entropy of the password
    int entropy = calculate_entropy(password->password, password->length);
    return (entropy / 10); // Scale the entropy to a 0-100 scale
}

// Function to calculate the entropy of a password
int calculate_entropy(char *password, int length) {
    // Calculate the probability of each character in the password
    int prob[256];
    for (int i = 0; i < 256; i++) {
        prob[i] = (password[i] == 0) ? 0 : (1.0 / strlen(CHAR_SET)) * strlen(CHAR_SET[i]);
    }
    // Calculate the entropy using the probabilities
    int entropy = 0;
    for (int i = 0; i < length; i++) {
        entropy += prob[password[i]];
    }
    return entropy;
}

int main() {
    // Create a password to use for testing
    password_t *test_password = generate_password(PASSWORD_LENGTH);
    printf("Generated password: %s\n", test_password->password);

    // Create a new password to store
    password_t *new_password = generate_password(PASSWORD_LENGTH);
    printf("New password: %s\n", new_password->password);

    // Check the strength of the test password
    int test_strength = check_strength(test_password);
    printf("Test password strength: %d\n", test_strength);

    // Check the strength of the new password
    int new_strength = check_strength(new_password);
    printf("New password strength: %d\n", new_strength);

    // Print the age of the test password
    int age = (time(NULL) - test_password->age) / 86400;
    printf("Test password age: %d days\n", age);

    // Print the age of the new password
    age = (time(NULL) - new_password->age) / 86400;
    printf("New password age: %d days\n", age);

    return 0;
}