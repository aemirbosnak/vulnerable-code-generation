//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants for password generation
#define PW_MIN_LENGTH 8
#define PW_MAX_LENGTH 64
#define PW_CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~!@#$%^&*"

// Function to generate a random number
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random character from the character set
char rand_char() {
    return PW_CHARSET[rand_int(0, strlen(PW_CHARSET) - 1)];
}

// Function to generate a random password
char *rand_pw(int length) {
    // Check if the length is valid
    if (length < PW_MIN_LENGTH || length > PW_MAX_LENGTH) {
        return NULL;
    }

    // Allocate memory for the password
    char *pw = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        pw[i] = rand_char();
    }

    // Null-terminate the password
    pw[length] = '\0';

    // Return the password
    return pw;
}

// Function to test the password generator
void test_pw_generator() {
    // Generate 10 random passwords
    for (int i = 0; i < 10; i++) {
        // Generate a random password length
        int length = rand_int(PW_MIN_LENGTH, PW_MAX_LENGTH);

        // Generate the password
        char *pw = rand_pw(length);

        // Print the password
        printf("Password %d: %s\n", i + 1, pw);

        // Free the memory allocated for the password
        free(pw);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Test the password generator
    test_pw_generator();

    return 0;
}