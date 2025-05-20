//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store password information
typedef struct {
    char *username;
    char *password;
} password_info_t;

// Function to read password from user
void read_password(password_info_t *password) {
    printf("Enter username: ");
    scanf("%s", password->username);
    printf("Enter password: ");
    scanf("%s", password->password);
}

// Function to display password
void display_password(password_info_t password) {
    printf("Username: %s\n", password.username);
    printf("Password: %s\n", password.password);
}

// Function to check if password is correct
int check_password(password_info_t password, char *correct_password) {
    if (strcmp(password.password, correct_password) == 0) {
        return 1; // Password is correct
    } else {
        return 0; // Password is incorrect
    }
}

int main() {
    password_info_t password;
    char correct_password[] = "correct_password";

    // Read password from user
    read_password(&password);

    // Display password
    display_password(password);

    // Check if password is correct
    if (check_password(password, correct_password)) {
        printf("Password is correct!\n");
    } else {
        printf("Password is incorrect... 😔\n");
    }

    return 0;
}