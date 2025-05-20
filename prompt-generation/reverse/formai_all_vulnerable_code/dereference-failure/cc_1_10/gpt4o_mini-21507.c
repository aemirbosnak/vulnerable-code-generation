//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-=_+[]{}|;:,.<>?/`~"

void generate_password(char *password) {
    const char *sets[] = {LOWERCASE, UPPERCASE, DIGITS, SPECIAL_CHARS};
    int set_count = sizeof(sets) / sizeof(sets[0]);
    int password_index = 0;

    // Ensuring at least one character from each set
    for (int i = 0; i < set_count; i++) {
        int random_index = rand() % strlen(sets[i]);
        password[password_index++] = sets[i][random_index];
    }

    // Filling the remaining password length with random characters
    while (password_index < PASSWORD_LENGTH) {
        int random_set = rand() % set_count;
        int random_index = rand() % strlen(sets[random_set]);
        password[password_index++] = sets[random_set][random_index];
    }

    // Shuffle the password to avoid any recognizable patterns
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_index = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the password
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator

    printf("Generating a secure password...\n");
    generate_password(password);
    printf("Generated Password: %s\n", password);

    // Securely erasing the password from memory (not really needed here, but good practice)
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = '\0';
    }

    return 0;
}