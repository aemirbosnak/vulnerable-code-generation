//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define NUM_PASSWORDS 5

// Structure to store password information
typedef struct {
    char *password;
    int password_length;
    time_t last_used;
} password_t;

// Function to generate a password
void generate_password(password_t *password) {
    int i, j;
    char c;

    // Generate a password of the specified length
    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        c = 'a' + (rand() % 26);
        password->password[i] = c;
    }

    // Add some special characters to the password
    for (j = 0; j < 3; j++) {
        c = '!@#$%^&*()_-';
        password->password[i++] = c;
    }

    // Set the password length and last used time
    password->password_length = PASSWORD_MAX_LENGTH;
    password->last_used = time(NULL);
}

// Function to check if a password is valid
int check_password(password_t *password, char *input) {
    int i, j;

    // Compare the input password with the stored password
    for (i = 0; i < password->password_length; i++) {
        if (password->password[i] != input[i]) {
            return 0;
        }
    }

    // Check if the password is too old
    if (time(NULL) - password->last_used > 90) {
        return 0;
    }

    return 1;
}

// Function to display the passwords
void display_passwords(password_t *passwords, int num_passwords) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i].password);
    }
}

int main() {
    // Create an array of password structures
    password_t passwords[NUM_PASSWORDS];

    // Generate and store the passwords
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    // Display the passwords
    display_passwords(passwords, NUM_PASSWORDS);

    // Loop forever and ask the user to input a password
    while (1) {
        int password_index = rand() % NUM_PASSWORDS;
        printf("Enter password for index %d: ", password_index + 1);
        char input[PASSWORD_MAX_LENGTH + 1];
        fgets(input, PASSWORD_MAX_LENGTH + 1, stdin);

        // Check if the input password is valid
        if (check_password(&passwords[password_index], input)) {
            printf("Correct password! You have accessed the secret stash!\n");
        } else {
            printf("Incorrect password. Try again!\n");
        }
    }

    return 0;
}