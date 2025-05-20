//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Character sets
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()-+=_>";

// Length of the password
const int passwordLength = 16;

// Function to generate a random character from a character set
char generateRandomChar(const char *charset) {
    int index = rand() % strlen(charset);
    return charset[index];
}

// Function to generate a random password
char *generatePassword() {
    char *password = malloc(passwordLength + 1);
    for (int i = 0; i < passwordLength; i++) {
        // Randomly choose a character set
        int charsetIndex = rand() % 4;
        switch (charsetIndex) {
            case 0:
                password[i] = generateRandomChar(lowercase);
                break;
            case 1:
                password[i] = generateRandomChar(uppercase);
                break;
            case 2:
                password[i] = generateRandomChar(digits);
                break;
            case 3:
                password[i] = generateRandomChar(symbols);
                break;
        }
    }
    password[passwordLength] = '\0';
    return password;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generatePassword();

    // Print the generated password
    printf("Your secure password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}