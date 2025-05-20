//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASS_LENGTH 8
#define MAX_PASS_LENGTH 128

// Function to generate a random character
char generate_random_character()
{
    // Generate a random number between 0 and 61
    int random_number = rand() % 62;

    // Convert the random number to a character
    char random_character = '\0';
    if (random_number < 26) {
        random_character = 'a' + random_number;
    } else if (random_number < 52) {
        random_character = 'A' + random_number - 26;
    } else {
        random_character = '0' + random_number - 52;
    }

    return random_character;
}

// Function to generate a random password
char *generate_random_password(int length)
{
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate a random password
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character();
    }

    // Terminate the password with a null character
    password[length] = '\0';

    return password;
}

int main(int argc, char *argv[])
{
    // Seed the random number generator
    srand(time(NULL));

    // Check if the user specified a password length
    int length = MIN_PASS_LENGTH;
    if (argc > 1) {
        length = atoi(argv[1]);
    }

    // Check if the password length is valid
    if (length < MIN_PASS_LENGTH || length > MAX_PASS_LENGTH) {
        fprintf(stderr, "Error: Password length must be between %d and %d\n", MIN_PASS_LENGTH, MAX_PASS_LENGTH);
        return EXIT_FAILURE;
    }

    // Generate a random password
    char *password = generate_random_password(length);

    // Print the password to the console
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return EXIT_SUCCESS;
}