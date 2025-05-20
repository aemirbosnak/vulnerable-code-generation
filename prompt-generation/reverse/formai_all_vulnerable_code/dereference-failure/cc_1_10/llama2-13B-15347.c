//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 5
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    int attempts;
} password_info;

// Function to generate a random password
void generate_password(password_info *pwd) {
    int len = 10; // Password length
    char *password = malloc(len);
    for (int i = 0; i < len; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    pwd->password = password;
}

// Function to check if the given password matches the stored password
int check_password(password_info *pwd, char *input_password) {
    if (strcmp(pwd->password, input_password) == 0) {
        return 1; // Password matches
    }
    return 0; // Password does not match
}

// Function to handle password attempts
void handle_attempts(password_info *pwd, char *input_password) {
    if (check_password(pwd, input_password)) {
        // Password matched, no need to record attempts
        return;
    }
    // Increment attempts and print warning message
    pwd->attempts++;
    printf("Warning: Incorrect password attempt %d of %d. Next attempt will lock the account.\n",
           pwd->attempts, MAX_ATTEMPTS);
}

// Function to lock the account after maximum attempts
void lock_account(password_info *pwd) {
    printf("Account locked due to maximum incorrect password attempts.\n");
    pwd->attempts = -1; // Mark the account as locked
}

int main() {
    // Create an array to store password information
    password_info passwords[MAX_PASSWORDS];

    // Initialize the array with some sample passwords
    passwords[0].username = "user1";
    passwords[0].password = "password1";
    passwords[1].username = "user2";
    passwords[1].password = "password2";
    passwords[2].username = "user3";
    passwords[2].password = "password3";

    // Generate a random password for each user
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    // Loop until the user quits
    while (1) {
        // Print the username and password for each user
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            printf("User %s, Password: %s\n", passwords[i].username, passwords[i].password);
        }

        // Get the user's input and check if it matches the stored password
        char input_password[100];
        printf("Enter the password for user %s: ", passwords[0].username);
        fgets(input_password, 100, stdin);
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            handle_attempts(&passwords[i], input_password);
        }

        // Lock the account if maximum attempts exceeded
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            if (passwords[i].attempts >= MAX_ATTEMPTS) {
                lock_account(&passwords[i]);
            }
        }

        // Print a message and ask the user to continue
        printf("Do you want to continue? (y/n): ");
        char cont[2];
        scanf("%1s", cont);
        if (cont[0] != 'y') {
            break;
        }
    }

    // Free the memory allocated for the password array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].password);
    }

    return 0;
}