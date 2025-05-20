//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define DIGIT_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{}|;:,.<>?/~`"

void generate_password(char *password) {
    // Seed the random number generator using current time
    srand(time(NULL));

    // Create an array to hold all character sets
    const char *char_sets[] = {UPPERCASE_CHARS, LOWERCASE_CHARS, DIGIT_CHARS, SPECIAL_CHARS};
    int char_sets_count = sizeof(char_sets) / sizeof(char_sets[0]);

    // Ensure at least one character from each set is included
    password[0] = char_sets[0][rand() % strlen(UPPERCASE_CHARS)];
    password[1] = char_sets[1][rand() % strlen(LOWERCASE_CHARS)];
    password[2] = char_sets[2][rand() % strlen(DIGIT_CHARS)];
    password[3] = char_sets[3][rand() % strlen(SPECIAL_CHARS)];

    // Fill the rest of the password with random characters from all sets
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        const char *selected_set = char_sets[rand() % char_sets_count];
        password[i] = selected_set[rand() % strlen(selected_set)];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_index = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    // Null-terminate the string
    password[PASSWORD_LENGTH] = '\0';
}

void save_password_to_file(const char *password, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s\n", password);
    fclose(file);
}

void display_password(const char *password) {
    printf("Generated Password: %s\n", password);
}

int main() {
    char password[PASSWORD_LENGTH + 1];
    char filename[100];

    printf("Enter the filename to save the password: ");
    scanf("%99s", filename); // Read the filename, preventing buffer overflow

    generate_password(password);
    display_password(password);
    save_password_to_file(password, filename);

    printf("Password saved to %s\n", filename);
    return 0;
}