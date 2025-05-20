//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// An array of all the possible characters for our passwords
char password_chars[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*"};

// Generate a random number between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random character from the password_chars array
char random_char() {
    int index = random_int(0, strlen(password_chars) - 1);
    return password_chars[index];
}

// Generate a random password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = random_char();
    }

    // Terminate the string
    password[length] = '\0';

    // Return the password
    return password;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random password of a given length
    int password_length = 16;
    char *password = generate_password(password_length);

    // Print the password
    printf("Your secure password is: %s", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}