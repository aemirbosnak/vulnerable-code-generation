//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_PASSWORDS 5

// Define a struct to store password information
struct password {
    char password[50];
    int guesses;
};

// Function to read a password file
struct password *read_password_file(const char *filename) {
    struct password *passwords = NULL;
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the file line by line
    while (fgets(passwords[i].password, 50, file) != NULL) {
        passwords[i].guesses = 0;
        i++;
    }

    fclose(file);
    return passwords;
}

// Function to check if a password is correct
int check_password(const char *password, const char *correct_password) {
    int i = 0;
    int len = strlen(password);

    // Compare the passwords character by character
    for (i = 0; i < len; i++) {
        if (password[i] != correct_password[i]) {
            break;
        }
    }

    // If the passwords match, return 1
    if (i == len) {
        return 1;
    }

    // If the passwords don't match, return 0
    return 0;
}

// Function to main game loop
int main() {
    struct password *passwords = read_password_file("passwords.txt");
    if (passwords == NULL) {
        printf("Error reading passwords file\n");
        return 1;
    }

    int chosen_password = -1;
    int correct_password = -1;
    int guesses = 0;

    // Loop until the correct password is found or all guesses are used up
    while (guesses < MAX_PASSWORDS && chosen_password != correct_password) {
        // Generate a random password to guess
        chosen_password = rand() % MAX_PASSWORDS;

        // Print the chosen password and ask the user to guess
        printf("Chosen password: %s\n", passwords[chosen_password].password);
        printf("Guess a password: ");

        // Read the user's guess
        char guess[50];
        fgets(guess, 50, stdin);

        // Check if the guess is correct
        correct_password = check_password(guess, passwords[chosen_password].password);

        // Increment the number of guesses
        guesses++;
    }

    // Print the result
    if (chosen_password == correct_password) {
        printf("Congratulations, you guessed the correct password! %s\n", passwords[chosen_password].password);
    } else {
        printf("Sorry, you ran out of guesses. The correct password was %s\n", passwords[chosen_password].password);
    }

    // Free the memory allocated for the passwords
    free(passwords);

    return 0;
}