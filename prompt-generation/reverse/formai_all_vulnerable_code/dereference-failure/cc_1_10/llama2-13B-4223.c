//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: surprised
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

// Function to generate a password
void generate_password(password_info *password) {
    int length = 10;
    char password_characters[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    password->password = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        password->password[i] = password_characters[rand() % (sizeof(password_characters) - 1)];
    }
}

// Function to check if the password is correct
int check_password(password_info *password, char *input_password) {
    int length = strlen(password->password);
    for (int i = 0; i < length; i++) {
        if (password->password[i] != input_password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to login
int login(password_info *password) {
    char input_password[10];
    printf("Enter your password: ");
    fgets(input_password, 10, stdin);
    if (check_password(password, input_password)) {
        printf("Login successful! Welcome, %s!\n", password->username);
        return 1;
    } else {
        printf("Incorrect password. Try again.\n");
        password->attempts++;
        if (password->attempts >= MAX_ATTEMPTS) {
            printf("Too many incorrect attempts. Account locked.\n");
            return 0;
        }
        generate_password(password);
        return 0;
    }
}

int main() {
    password_info passwords[MAX_PASSWORDS];
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = malloc(20 * sizeof(char));
        passwords[i].password = malloc(20 * sizeof(char));
        passwords[i].attempts = 0;
        generate_password(&passwords[i]);
    }

    int user_choice;
    do {
        printf("Welcome to the password manager!\n");
        printf("Select a password to login: ");
        for (int i = 0; i < MAX_PASSWORDS; i++) {
            printf("%d. %s\n", i + 1, passwords[i].username);
        }
        scanf("%d", &user_choice);
        if (user_choice < 1 || user_choice > MAX_PASSWORDS) {
            printf("Invalid input. Try again.\n");
        } else {
            if (login(passwords + user_choice - 1)) {
                break;
            }
        }
    } while (1);

    return 0;
}