//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

// Structure to store user information
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_info;

// Function to generate a secure password
void generate_password(user_info *user) {
    int i, j;
    char password[MAX_PASSWORD_LENGTH];
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    strcpy(user->password, password);
}

// Function to validate a password
int validate_password(user_info *user, char *password) {
    int i, j;
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        if (password[i] != user->password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to register a new user
void register_user(user_info *user) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%19s", username);
    generate_password(user);
    strcpy(user->username, username);
    strcpy(user->password, password);
    printf("User registered successfully!\n");
}

// Function to log in to the system
int log_in(user_info *user) {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%19s", password);
    if (validate_password(user, password)) {
        printf("Logged in successfully!\n");
        return 1;
    } else {
        printf("Invalid password. Try again.\n");
        return 0;
    }
}

int main() {
    user_info user;
    register_user(&user);
    log_in(&user);
    return 0;
}