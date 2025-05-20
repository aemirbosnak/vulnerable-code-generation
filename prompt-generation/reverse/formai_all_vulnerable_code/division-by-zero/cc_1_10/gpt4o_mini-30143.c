//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12   // Length of the password
#define NUM_PASSWORDS 5      // Number of passwords to generate
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{}|;:,.<>?/~`"

char *generate_password(int length) {
    static char password[PASSWORD_LENGTH + 1];
    const char *char_sets[] = {LOWERCASE, UPPERCASE, DIGITS, SPECIAL_CHARS};
    int char_set_count = sizeof(char_sets) / sizeof(char_sets[0]);

    // Add at least one character from each category to ensure password complexity
    srand(time(NULL));
    password[0] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[1] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[2] = DIGITS[rand() % strlen(DIGITS)];
    password[3] = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];

    // Fill the rest of the password with random characters from all character sets
    for (int i = 4; i < length; i++) {
        const char *char_set = char_sets[rand() % char_set_count];
        password[i] = char_set[rand() % strlen(char_set)];
    }
    password[length] = '\0';

    // Shuffle the password to avoid character set ordering
    for (int i = 0; i < length - 1; i++) {
        int j = rand() % (length - i) + i;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    return password;
}

void display_generated_passwords(int num_passwords, int length) {
    printf("Generating %d secure passwords of length %d...\n\n", num_passwords, length);
    for (int i = 0; i < num_passwords; i++) {
        printf("Password %d: %s\n", i + 1, generate_password(length));
    }
}

int main() {
    printf("Welcome to the Secure Password Generator!\n");
    printf("Your passwords will be securely generated with various characters.\n");

    display_generated_passwords(NUM_PASSWORDS, PASSWORD_LENGTH);

    printf("\nRemember to store them securely!\n");
    return 0;
}