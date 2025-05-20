//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Function to generate a random number within a given range
int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a given character set
char generate_random_char(char *charset) {
    int index = generate_random(0, strlen(charset) - 1);
    return charset[index];
}

// Function to generate a secure password of a given length
char *generate_password(int length) {
    char *password = malloc(length + 1);  // Allocate memory for the password
    
    // Initialize the password with random characters from each character set
    password[0] = generate_random_char(lowercase);
    password[1] = generate_random_char(uppercase);
    password[2] = generate_random_char(digits);
    password[3] = generate_random_char(symbols);
    
    // Generate the remaining characters randomly
    for (int i = 4; i < length; i++) {
        password[i] = generate_random_char(lowercase);
        password[i] = generate_random_char(uppercase);
        password[i] = generate_random_char(digits);
        password[i] = generate_random_char(symbols);
    }
    
    // Ensure that the password meets the security requirements
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int symbol_count = 0;
    
    for (int i = 0; i < length; i++) {
        if (strchr(lowercase, password[i])) {
            lowercase_count++;
        } else if (strchr(uppercase, password[i])) {
            uppercase_count++;
        } else if (strchr(digits, password[i])) {
            digit_count++;
        } else if (strchr(symbols, password[i])) {
            symbol_count++;
        }
    }
    
    while (lowercase_count < 1 || uppercase_count < 1 || digit_count < 1 || symbol_count < 1) {
        for (int i = 0; i < length; i++) {
            if (lowercase_count < 1) {
                password[i] = generate_random_char(lowercase);
                lowercase_count++;
            } else if (uppercase_count < 1) {
                password[i] = generate_random_char(uppercase);
                uppercase_count++;
            } else if (digit_count < 1) {
                password[i] = generate_random_char(digits);
                digit_count++;
            } else if (symbol_count < 1) {
                password[i] = generate_random_char(symbols);
                symbol_count++;
            }
        }
    }
    
    // Terminate the password string with a null character
    password[length] = '\0';
    
    // Return the generated password
    return password;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Generate a random password length between 12 and 20 characters
    int length = generate_random(12, 20);
    
    // Generate a secure password
    char *password = generate_password(length);
    
    // Print the generated password
    printf("Generated Password: %s\n", password);
    
    // Free the allocated memory
    free(password);
    
    return 0;
}