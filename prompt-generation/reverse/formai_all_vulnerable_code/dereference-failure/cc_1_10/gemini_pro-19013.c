//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+=-/";

// Function to generate a random password
char *generatePassword(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Set the initial seed for the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Generate a random character from the character sets
        int characterSet = rand() % 4;
        char character;
        switch (characterSet) {
            case 0:
                character = lowercase[rand() % strlen(lowercase)];
                break;
            case 1:
                character = uppercase[rand() % strlen(uppercase)];
                break;
            case 2:
                character = numbers[rand() % strlen(numbers)];
                break;
            case 3:
                character = symbols[rand() % strlen(symbols)];
                break;
        }

        // Append the character to the password
        password[i] = character;
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generatePassword(length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}