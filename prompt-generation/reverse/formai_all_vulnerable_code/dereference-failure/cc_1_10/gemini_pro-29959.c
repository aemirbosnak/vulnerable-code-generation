//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character from the given character set
char rand_char(const char *charset) {
    return charset[rand_range(0, strlen(charset) - 1)];
}

// Function to generate a random password of the given length
char *rand_password(int length) {
    // Character set for the password
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = rand_char(charset);
    }

    // Null-terminate the password
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to test the password generator
void test_password_generator() {
    // Generate 10 random passwords of length 10
    for (int i = 0; i < 10; i++) {
        char *password = rand_password(10);
        printf("Password %d: %s\n", i + 1, password);
        free(password);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the password generator
    test_password_generator();

    return 0;
}