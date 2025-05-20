//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define NUM_PASSWORDS 5

const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()-_=+[]{};:,.<>?/|`~";

void generate_password(char *password) {
    // Define the sources of characters
    const char *sources[] = {uppercase, lowercase, digits, symbols};
    int source_count = sizeof(sources) / sizeof(sources[0]);
    
    // Randomly select characters to form the password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_source_index = rand() % source_count;
        const char *selected_source = sources[random_source_index];
        int random_char_index = rand() % strlen(selected_source);
        password[i] = selected_source[random_char_index];
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

// Function to ensure uniqueness of passwords
int is_unique(char passwords[][PASSWORD_LENGTH + 1], char *new_password, int num_generated) {
    for (int i = 0; i < num_generated; i++) {
        if (strcmp(passwords[i], new_password) == 0) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

// Function to generate unique passwords
void generate_unique_passwords(char passwords[][PASSWORD_LENGTH + 1], int num_passwords) {
    int count = 0;
    while (count < num_passwords) {
        char new_password[PASSWORD_LENGTH + 1];
        generate_password(new_password);
        
        if (is_unique(passwords, new_password, count)) {
            strcpy(passwords[count], new_password);
            count++;
        }
    }
}

void print_passwords(char passwords[][PASSWORD_LENGTH + 1], int num_passwords) {
    printf("Generated Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d: %s\n", i + 1, passwords[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Array to store generated passwords
    char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1];
    
    // Generate unique passwords
    generate_unique_passwords(passwords, NUM_PASSWORDS);
    
    // Print the generated passwords
    print_passwords(passwords, NUM_PASSWORDS);
    
    return 0;
}