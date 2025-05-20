//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SYMBOLS "!@#$%^&*()-_=+[]{};:,.<>?/|"
#define TOTAL_CHAR_TYPES 4

void generate_password(char *password) {
    const char *char_sets[TOTAL_CHAR_TYPES] = {LOWERCASE, UPPERCASE, DIGITS, SYMBOLS};
    int set_lengths[TOTAL_CHAR_TYPES] = {strlen(LOWERCASE), strlen(UPPERCASE),
                                          strlen(DIGITS), strlen(SYMBOLS)};
    int i;

    // Initialize Random Seed
    srand(time(0));

    // Ensure at least one character from each character set is included
    password[0] = LOWERCASE[rand() % set_lengths[0]];
    password[1] = UPPERCASE[rand() % set_lengths[1]];
    password[2] = DIGITS[rand() % set_lengths[2]];
    password[3] = SYMBOLS[rand() % set_lengths[3]];

    // Fill the remaining password length with random characters from all sets
    for (i = 4; i < PASSWORD_LENGTH; i++) {
        int random_set = rand() % TOTAL_CHAR_TYPES;
        password[i] = char_sets[random_set][rand() % set_lengths[random_set]];
    }

    // Shuffle the password to avoid predictable patterns
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[PASSWORD_LENGTH] = '\0';
}

void print_usage() {
    printf("Usage: ./password_generator <count>\n");
    printf("Generates secure passwords based on the specified count.\n");
}

int main(int argc, char *argv[]) {
    int count, i;

    // Check for proper argument count
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Convert count argument to an integer
    count = atoi(argv[1]);

    // Validate count input
    if (count <= 0) {
        printf("Error: The count must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    char password[PASSWORD_LENGTH + 1];

    printf("Generating %d secure passwords:\n", count);
    for (i = 0; i < count; i++) {
        generate_password(password);
        printf("Password %d: %s\n", i + 1, password);
    }

    return EXIT_SUCCESS;
}