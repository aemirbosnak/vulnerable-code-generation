//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Post-Apocalyptic Password Generator
#define MAX_LENGTH 20
#define PASSWORD_LENGTH 12
#define NUM_DIGITS 10
#define NUM_UPPERCASE 26
#define NUM_LOWERCASE 26
#define SPECIAL_CHARACTERS "!@#$%^&*()_-+=<>?{}[]~"

void generate_password(char *password) {
    const char *digits = "0123456789";
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t special_characters_length = strlen(SPECIAL_CHARACTERS);
    
    // Seed the random number generator
    srand(time(NULL));

    // Ensuring at least one character from each category is included
    password[0] = lowercase[rand() % NUM_LOWERCASE];
    password[1] = uppercase[rand() % NUM_UPPERCASE];
    password[2] = digits[rand() % NUM_DIGITS];
    password[3] = SPECIAL_CHARACTERS[rand() % special_characters_length];

    // Fill the rest of the password with random characters
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0:
                password[i] = lowercase[rand() % NUM_LOWERCASE];
                break;
            case 1:
                password[i] = uppercase[rand() % NUM_UPPERCASE];
                break;
            case 2:
                password[i] = digits[rand() % NUM_DIGITS];
                break;
            case 3: 
                password[i] = SPECIAL_CHARACTERS[rand() % special_characters_length];
                break;
        }
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the string
    password[PASSWORD_LENGTH] = '\0';
}

void wasteland_log(const char *message) {
    FILE *file = fopen("passwords.log", "a");
    if (file) {
        time_t now;
        time(&now);
        fprintf(file, "[%s] %s\n", ctime(&now), message);
        fclose(file);
    }
}

void print_help() {
    printf("=== Wasteland Password Generator ===\n");
    printf("In this desolate world, strong passwords are your shield.\n");
    printf("Usage: ./password_generator [count]\n");
    printf("  count  - Number of passwords to generate (default: 1)\n");
    printf("--------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    int count = 1;

    // Handle command line arguments
    if (argc > 1) {
        count = atoi(argv[1]);

        if (count <= 0) {
            print_help();
            return 1;
        }
    }

    printf("Generating %d secure passwords...\n", count);
    char password[PASSWORD_LENGTH + 1];

    for (int i = 0; i < count; i++) {
        generate_password(password);
        printf("Password %d: %s\n", i + 1, password);
        
        // Log password creation to the wasteland log
        char log_message[100];
        snprintf(log_message, sizeof(log_message), "Generated Password %d: %s", i + 1, password);
        wasteland_log(log_message);
    }
    
    printf("Passwords are forged in the fires of the wasteland.\n");
    printf("Protect your secrets, for the end is just the beginning.\n");
    return 0;
}