//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random character
char generateRandomChar() {
    // Define the range of characters to choose from
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int charsetSize = strlen(charset);

    // Generate a random index within the range
    int index = rand() % charsetSize;

    // Return the character at the generated index
    return charset[index];
}

// Function to generate a random string
char *generateRandomString(int length) {
    // Allocate memory for the string
    char *string = malloc(length + 1);

    // Generate a random character for each position in the string
    for (int i = 0; i < length; i++) {
        string[i] = generateRandomChar();
    }

    // Terminate the string with a null character
    string[length] = '\0';

    // Return the generated string
    return string;
}

// Function to generate a secure password
char *generateSecurePassword(int length) {
    // Generate a random string
    char *password = generateRandomString(length);

    // Check if the password meets the complexity requirements
    int complexityScore = 0;
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL) { complexityScore++; }
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL) { complexityScore++; }
    if (strpbrk(password, "0123456789") != NULL) { complexityScore++; }
    if (strpbrk(password, "!@#$%^&*()_+") != NULL) { complexityScore++; }

    // If the password does not meet the complexity requirements, generate a new one
    while (complexityScore < 3) {
        free(password);
        password = generateRandomString(length);
        complexityScore = 0;
        if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL) { complexityScore++; }
        if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL) { complexityScore++; }
        if (strpbrk(password, "0123456789") != NULL) { complexityScore++; }
        if (strpbrk(password, "!@#$%^&*()_+") != NULL) { complexityScore++; }
    }

    // Return the generated password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a secure password
    char *password = generateSecurePassword(16);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}