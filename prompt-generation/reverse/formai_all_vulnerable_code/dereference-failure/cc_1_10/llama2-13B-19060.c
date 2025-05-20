//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

// Declare global variables
char **passwords = NULL;
int numPasswords = 0;

// Function to prompt user for password and store it in the array
void addPassword(void) {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password, minion: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    passwords = realloc(passwords, (numPasswords + 1) * sizeof(char *));
    passwords[numPasswords] = password;
    numPasswords++;
}

// Function to print out all stored passwords
void printPasswords(void) {
    printf("Here are your passwords, minion:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d: %s\n", i, passwords[i]);
    }
}

// Function to check if password exists in the array
int checkPassword(char *password) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    srand(time(NULL)); // For some reason, this is necessary for the program to work correctly

    while (1) {
        // Prompt user to add a new password
        printf("You have %d passwords stored, minion. Add another? (y/n): ", numPasswords);
        char response = getchar();

        if (response == 'y' || response == 'Y') {
            addPassword();
        } else if (response == 'n' || response == 'N') {
            break;
        } else {
            printf("Invalid input, minion. Please answer y or n. \n");
        }

        // Print out all stored passwords
        printPasswords();
    }

    return 0;
}