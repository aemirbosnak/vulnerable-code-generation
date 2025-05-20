//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random password
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random password
    for (int i = 0; i < length; i++) {
        password[i] = (rand() % 94) + 33;
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified a password length
    if (argc < 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    // Get the password length from the user
    int length = atoi(argv[1]);

    // Generate a random password
    char *password = generate_password(length);
    if (password == NULL) {
        printf("Error: could not allocate memory for password\n");
        return 1;
    }

    // Print the password to the console
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}