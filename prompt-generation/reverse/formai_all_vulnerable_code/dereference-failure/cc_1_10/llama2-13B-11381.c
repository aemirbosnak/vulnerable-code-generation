//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    int attempts;
} password_info;

// Function to generate a random password
void generate_password(char *password) {
    int i, j;
    for (i = 0; i < 10; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    password[i] = '\0';
}

// Function to check if the password matches the stored password
int check_password(char *password, password_info *info) {
    if (strcmp(password, info->password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to login to the system
int login(password_info *info) {
    int attempts = 0;
    char password[10];

    // Generate a random password
    generate_password(password);

    // Check if the password matches the stored password
    if (check_password(password, info)) {
        // Password matches, so let the user in
        printf("Welcome, %s!\n", info->username);
        return 1;
    } else {
        // Password does not match, so increment attempts and try again
        attempts++;
        if (attempts >= MAX_ATTEMPTS) {
            // Too many attempts, lock the user out
            printf("Too many incorrect attempts. Locking out %s.\n", info->username);
            return 0;
        }
        printf("Incorrect password. Try again (%d attempts left).\n", attempts);
        return 0;
    }
}

int main() {
    password_info info[MAX_PASSWORDS];
    int i;

    // Initialize the password information structure
    for (i = 0; i < MAX_PASSWORDS; i++) {
        info[i].username = malloc(10 * sizeof(char));
        info[i].password = malloc(10 * sizeof(char));
        info[i].attempts = 0;
    }

    // Read in the user's input
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Enter username: ");
        scanf("%9s", info[i].username);
        printf("Enter password: ");
        scanf("%9s", info[i].password);
    }

    // Login to the system
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (login(info + i)) {
            break;
        }
    }

    // Clean up memory
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(info[i].username);
        free(info[i].password);
    }

    return 0;
}