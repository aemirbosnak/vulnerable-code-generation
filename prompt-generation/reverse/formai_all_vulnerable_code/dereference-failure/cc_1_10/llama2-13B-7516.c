//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to store password information
struct password {
    char *username;
    char *password;
    int age;
};

// Define a function to print the password information
void print_password(struct password *password) {
    printf("Username: %s\nPassword: %s\nAge: %d\n",
           password->username, password->password, password->age);
}

// Define a function to set the password information
void set_password(struct password *password, char *username, char *password_new, int age_new) {
    strcpy(password->username, username);
    strcpy(password->password, password_new);
    password->age = age_new;
}

// Define a function to check if the password is correct
bool check_password(struct password *password, char *password_input) {
    if (strcmp(password->password, password_input) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Create a password struct
    struct password password;

    // Set the password information
    set_password(&password, "johndoe", "password123", 30);

    // Print the password information
    print_password(&password);

    // Prompt the user to input their password
    printf("Enter your password: ");
    char password_input[20];
    fgets(password_input, 20, stdin);

    // Check if the password is correct
    if (check_password(&password, password_input)) {
        printf("Correct password! Welcome, %s.\n", password.username);
    } else {
        printf("Incorrect password. Try again.\n");
    }

    return 0;
}