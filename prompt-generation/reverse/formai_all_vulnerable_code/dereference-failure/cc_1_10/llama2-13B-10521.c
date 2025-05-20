//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 5
#define MAX_ATTEMPTS 3

// Define a struct to store password information
struct password {
    char *username;
    char *password;
    int attempts;
};

// Function to generate a random password
void generate_password(struct password *password) {
    int length = 10 + rand() % 5;
    password->password = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        password->password[i] = 'a' + rand() % 26;
    }
}

// Function to check if a password is correct
bool check_password(struct password *password, char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (password->password[i] != input[i]) {
            return false;
        }
    }
    return true;
}

// Function to store a password in the password list
void add_password(struct password **passwords, char *username, char *password) {
    struct password *new_password = malloc(sizeof(struct password));
    new_password->username = username;
    new_password->password = password;
    new_password->attempts = 0;
    *(passwords + sizeof(passwords) / sizeof(struct password)) = new_password;
}

// Function to retrieve a password from the password list
struct password *get_password(struct password **passwords, char *username) {
    for (int i = 0; i < sizeof(passwords) / sizeof(struct password); i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            return passwords[i];
        }
    }
    return NULL;
}

// Function to check if a username and password combination is correct
bool check_credentials(struct password **passwords, char *username, char *password) {
    struct password *password_found = get_password(passwords, username);
    if (password_found == NULL) {
        return false;
    }
    if (check_password(password_found, password)) {
        return true;
    }
    return false;
}

int main() {
    struct password *passwords[MAX_PASSWORDS];
    char *usernames[MAX_PASSWORDS][2] = {
        {"user1", "password1"},
        {"user2", "password2"},
        {"user3", "password3"},
        {"user4", "password4"},
        {"user5", "password5"}
    };

    // Initialize the password list
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        add_password(&passwords, usernames[i][0], usernames[i][1]);
    }

    // Prompt the user to enter their username and password
    char username[50];
    char password[50];
    printf("Enter your username: ");
    fgets(username, 50, stdin);
    printf("Enter your password: ");
    fgets(password, 50, stdin);

    // Check if the credentials are correct
    bool found = check_credentials(passwords, username, password);
    if (found) {
        printf("Access granted!\n");
    } else {
        printf("Invalid credentials. Try again? (y/n): ");
        char retry = getchar();
        if (retry == 'y' || retry == 'Y') {
            // If the user wants to try again, prompt them to enter their credentials again
            printf("Enter your username: ");
            fgets(username, 50, stdin);
            printf("Enter your password: ");
            fgets(password, 50, stdin);
            found = check_credentials(passwords, username, password);
            if (found) {
                printf("Access granted!\n");
            } else {
                printf("Invalid credentials. Try again? (y/n): ");
                retry = getchar();
                if (retry == 'y' || retry == 'Y') {
                    // If the user wants to try again, repeat the loop
                    printf("Enter your username: ");
                    fgets(username, 50, stdin);
                    printf("Enter your password: ");
                    fgets(password, 50, stdin);
                    found = check_credentials(passwords, username, password);
                    if (found) {
                        printf("Access granted!\n");
                    } else {
                        printf("Invalid credentials. Try again? (y/n): ");
                    }
                } else {
                    printf("Invalid credentials. Try again? (y/n): ");
                }
            }
        } else {
            printf("Invalid credentials. Try again? (y/n): ");
        }
    }

    return 0;
}