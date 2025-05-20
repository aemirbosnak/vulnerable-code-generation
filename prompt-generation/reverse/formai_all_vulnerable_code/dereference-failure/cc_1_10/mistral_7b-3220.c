//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 4 // Number of character sets
#define SET_SIZE 26 // Size of each character set
#define MIN_LENGTH 8 // Minimum password length
#define MAX_LENGTH 32 // Maximum password length

// Character sets
const char *character_sets[CHAR_COUNT] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyz",
    "0123456789",
    "!@#$%^&*()_+-=[]{};':\"|,.<>/?`~"
};

int main() {
    char password[MAX_LENGTH + 1];
    int length, i, j, random_index;
    int password_valid = 0;

    // Seed random number generator
    srand(time(NULL));

    do {
        printf("Enter password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);

        // Error handling for invalid user input
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid password length. Try again.\n");
            continue;
        }

        password_valid = 1;

        // Generate random password
        for (i = 0; i < length; i++) {
            random_index = rand() % CHAR_COUNT;
            password[i] = character_sets[random_index][rand() % SET_SIZE];
        }

        // Set password terminator
        password[length] = '\0';

        printf("Generated password: %s\n", password);

    } while (!password_valid); // Loop until valid password length is entered

    return 0;
}