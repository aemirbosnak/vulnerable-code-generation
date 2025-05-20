//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define NUM_PASSWORDS 5

const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *lower_case = "abcdefghijklmnopqrstuvwxyz";
const char *digits = "0123456789";
const char *special_chars = "!@#$%^&*()-_=+[]{}|;:,.<>?";

void generate_password(char *password) {
    // Ensure the password is reset
    memset(password, '\0', PASSWORD_LENGTH + 1);
    
    // Randomly select characters
    password[0] = upper_case[rand() % strlen(upper_case)]; // At least one uppercase
    password[1] = lower_case[rand() % strlen(lower_case)]; // At least one lowercase
    password[2] = digits[rand() % strlen(digits)];         // At least one digit
    password[3] = special_chars[rand() % strlen(special_chars)]; // At least one special char
    
    // Fill the rest of the password with random characters
    char all_chars[sizeof(upper_case) + sizeof(lower_case) + sizeof(digits) + sizeof(special_chars)];
    strcpy(all_chars, upper_case);
    strcat(all_chars, lower_case);
    strcat(all_chars, digits);
    strcat(all_chars, special_chars);

    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        password[i] = all_chars[rand() % strlen(all_chars)];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_index = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1]; // Array to hold passwords

    printf("Welcome to the Secure Password Generator!\n");
    printf("Generating %d unique passwords of length %d...\n\n", NUM_PASSWORDS, PASSWORD_LENGTH);

    for (int i = 0; i < NUM_PASSWORDS; i++) {
        generate_password(passwords[i]);
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }

    printf("\nHooray! Passwords generated successfully. Remember to keep them safe!\n");

    return 0;
}