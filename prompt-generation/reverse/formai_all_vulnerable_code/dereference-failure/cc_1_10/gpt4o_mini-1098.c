//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{};:'\",.<>?/`~"

// Function prototypes
void generate_password(char *password, size_t length);
void print_welcome_message(void);
void print_generated_password(const char *password);

int main(void) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Welcome message
    print_welcome_message();

    // Prepare a buffer for the password
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator

    // Generate a password
    generate_password(password, PASSWORD_LENGTH);

    // Print the generated password
    print_generated_password(password);

    return 0; // Indicate successful completion!
}

// Function to print a cheerful welcome message
void print_welcome_message(void) {
    printf("**************************************************\n");
    printf("*          Welcome to the Secure Password        *\n");
    printf("*                Generator Program!               *\n");
    printf("**************************************************\n");
    printf("Let's create a strong and secure password!\n");
    printf("Your password will have %d characters. Let's go!\n", PASSWORD_LENGTH);
    printf("**************************************************\n");
}

// Function to generate a password
void generate_password(char *password, size_t length) {
    const char *char_sets[] = {
        UPPERCASE_CHARS,
        LOWERCASE_CHARS,
        DIGITS,
        SPECIAL_CHARS
    };

    // Ensure that the password contains at least one of each type
    for (size_t i = 0; i < length; i++) {
        int char_set_index = rand() % 4; // Randomly select which character set to use
        size_t char_index = rand() % strlen(char_sets[char_set_index]); // Random position within character set
        password[i] = char_sets[char_set_index][char_index]; // Add to password
    }

    // Add a null terminator
    password[length] = '\0';
}

// Function to print the generated password in a cheerful way
void print_generated_password(const char *password) {
    printf("**************************************************\n");
    printf("* Your newly generated strong password is:       *\n");
    printf("*                   %s                           *\n", password);
    printf("* Remember to store it safely!                   *\n");
    printf("**************************************************\n");
}