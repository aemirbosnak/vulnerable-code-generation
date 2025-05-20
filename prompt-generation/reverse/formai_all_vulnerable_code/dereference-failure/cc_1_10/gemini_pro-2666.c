//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
char *generate_password(int length) {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array to store the password
    char *password = malloc(length + 1);

    // Generate a random password
    for (int i = 0; i < length; i++) {
        // Generate a random character
        int character = rand() % 94 + 33;

        // Check if the character is valid
        while (!isalnum(character)) {
            character = rand() % 94 + 33;
        }

        // Add the character to the password
        password[i] = character;
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to print a happy message
void print_happy_message() {
    printf("Here's your happy password! :)\n");
}

// Main function
int main() {
    // Get the length of the password from the user
    int length;
    printf("How long do you want your password to be? ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_password(length);

    // Print a happy message
    print_happy_message();

    // Print the password
    printf("%s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}