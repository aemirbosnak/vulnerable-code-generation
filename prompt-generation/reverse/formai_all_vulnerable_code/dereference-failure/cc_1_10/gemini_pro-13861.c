//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()-=_+";

// Define the password length
int password_length = 10;

// Function to generate a random number between 0 and max
int random_number(int max) {
    return rand() % max;
}

// Function to generate a random character from a character set
char random_character(char *charset) {
    int index = random_number(strlen(charset));
    return charset[index];
}

// Function to generate a random password
char *generate_password() {
    // Allocate memory for the password
    char *password = malloc(password_length + 1);

    // Initialize the password to all zeros
    memset(password, 0, password_length + 1);

    // Generate a random character for each position in the password
    for (int i = 0; i < password_length; i++) {
        // Choose a random character set
        char *charset;
        int choice = random_number(4);
        switch (choice) {
            case 0:
                charset = lowercase;
                break;
            case 1:
                charset = uppercase;
                break;
            case 2:
                charset = numbers;
                break;
            case 3:
                charset = symbols;
                break;
        }

        // Generate a random character from the chosen character set
        password[i] = random_character(charset);
    }

    // Return the password
    return password;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_password();

    // Print the password
    printf("Your love-crafted password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}