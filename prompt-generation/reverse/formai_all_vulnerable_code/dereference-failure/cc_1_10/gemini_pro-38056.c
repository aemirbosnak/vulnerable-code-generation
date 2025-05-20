//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Constants
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

// Function to generate a random character
char generate_random_character() {
    // Get a random number between 33 and 126
    int random_number = rand() % (126 - 33 + 1) + 33;

    // Return the corresponding character
    return (char)random_number;
}

// Function to generate a random password
char *generate_random_password(int length) {
    // Allocate memory for the password
    char *password = (char *)malloc(length + 1);

    // Generate a random character for each position in the password
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character();
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to print a password
void print_password(char *password) {
    // Print the password to the console
    printf("Password: %s\n", password);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_random_password(10);

    // Print the password
    print_password(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}