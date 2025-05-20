//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from the given character set
char generate_random_character(char *character_set) {
    int index = generate_random_number(0, strlen(character_set) - 1);
    return character_set[index];
}

// Function to generate a random password of the given length
char *generate_random_password(int length) {
    // Create a character set containing all the characters that can be used in the password
    char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character(character_set);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to test the password generator
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random password of length 10
    char *password = generate_random_password(10);

    // Print the password
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}