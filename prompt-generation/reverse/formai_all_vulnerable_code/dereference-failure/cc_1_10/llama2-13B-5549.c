//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: thoughtful
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
void generate_password(password_info *password) {
    int len = 10;
    char password_char[len];
    for (int i = 0; i < len; i++) {
        password_char[i] = 'a' + (rand() % 26);
    }
    password->password = password_char;
}

// Function to check if the password is correct
int check_password(password_info *password, char *input_password) {
    int len = strlen(password->password);
    for (int i = 0; i < len; i++) {
        if (password->password[i] != input_password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to login to the system
int login(password_info *password) {
    char input_password[10];
    printf("Enter your password: ");
    fgets(input_password, 10, stdin);
    if (check_password(password, input_password)) {
        printf("Login successful! Welcome, %s\n", password->username);
        return 1;
    } else {
        printf("Incorrect password. Try again\n");
        password->attempts++;
        if (password->attempts >= MAX_ATTEMPTS) {
            printf("Too many incorrect attempts. Account locked\n");
            return 0;
        }
        generate_password(password);
        return 0;
    }
}

int main() {
    password_info passwords[MAX_PASSWORDS];
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = "user" + (i + 1);
        passwords[i].password = NULL;
        passwords[i].attempts = 0;
    }

    // Login loop
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (login(passwords + i)) {
            break;
        }
    }

    return 0;
}