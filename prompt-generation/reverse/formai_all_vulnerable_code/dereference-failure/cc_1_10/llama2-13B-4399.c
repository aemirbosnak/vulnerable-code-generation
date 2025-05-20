//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *password;
    int attempts;
} password_info;

// Function to generate a random password
void generate_password(char *password) {
    int i, j;
    for (i = 0; i < 10; i++) {
        password[i] = 'a' + (rand() % 26);
    }
}

// Function to check if the given password matches the stored password
int check_password(char *password, password_info *info) {
    int i, j;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] != info->password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to increment the attempts and print the status message
void update_attempts(password_info *info) {
    info->attempts++;
    if (info->attempts == MAX_ATTEMPTS) {
        printf("Locked out after %d attempts\n", MAX_ATTEMPTS);
        exit(1);
    }
    printf("Incorrect password attempt %d of %d\n", info->attempts, MAX_ATTEMPTS);
}

int main() {
    // Array to store password information
    password_info passwords[MAX_PASSWORDS];

    // Initialize the passwords and attempts
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].password = malloc(10 * sizeof(char));
        generate_password(passwords[i].password);
        passwords[i].attempts = 0;
    }

    // Main password entry loop
    while (1) {
        // Print the password menu
        printf("Password Menu\n");
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            printf("Password %d: %s\n", i + 1, passwords[i].password);
        }

        // Read the user's input
        int choice;
        printf("Enter your choice (1-%d): ", MAX_PASSWORDS);
        scanf("%d", &choice);

        // Check if the user entered a valid choice
        if (choice < 1 || choice > MAX_PASSWORDS) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        // Get the password information for the chosen password
        password_info *info = &passwords[choice - 1];

        // Check if the user knows the password
        if (check_password(getpass(), info)) {
            printf("Correct password entered. Good job!\n");
            break;
        }

        // Increment the attempts and print the status message
        update_attempts(info);
    }

    // Free the memory allocated for the passwords
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].password);
    }

    return 0;
}