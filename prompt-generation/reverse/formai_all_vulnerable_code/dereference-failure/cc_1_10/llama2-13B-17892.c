//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
typedef struct {
    char *password;
    int attempts;
} password_info_t;

// Function to generate a random password
void generate_password(password_info_t *password) {
    int i;
    for (i = 0; i < 10; i++) {
        password->password[i] = 'a' + (rand() % 26);
    }
    password->password[i] = '\0';
}

// Function to check if the password matches
int check_password(password_info_t *password, char *input) {
    int i;
    for (i = 0; i < strlen(password->password); i++) {
        if (password->password[i] != input[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to login and store the password
void login(password_info_t *password, char *input) {
    int attempts = 0;
    while (!check_password(password, input) && attempts < MAX_ATTEMPTS) {
        generate_password(password);
        attempts++;
        input[0] = '\0';
    }
    if (attempts >= MAX_ATTEMPTS) {
        printf("Incorrect password. Access denied.\n");
    } else {
        printf("Welcome, %s!\n", password->password);
    }
}

int main() {
    password_info_t passwords[MAX_PASSWORDS];
    int i;

    // Initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].password = (char *)malloc(10 * sizeof(char));
        passwords[i].attempts = 0;
        generate_password(&passwords[i]);
    }

    // Loop until the user logs out
    while (1) {
        // Display the login menu
        printf("Login:\n");
        for (i = 0; i < MAX_PASSWORDS; i++) {
            printf("   %d: %s\n", i + 1, passwords[i].password);
        }

        // Get the user's input
        char input[10];
        printf("Enter the number of the password you want to use: ");
        scanf("%d", &input[0]);

        // Login and store the password
        login(&passwords[input[0] - 1], input);
    }

    return 0;
}