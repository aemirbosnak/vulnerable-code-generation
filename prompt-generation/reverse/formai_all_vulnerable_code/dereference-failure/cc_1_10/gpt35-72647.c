//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORD_COUNT 10

// A structure to hold password data
typedef struct PasswordEntry {
    char* username;
    char* password;
} PasswordEntry;

// A function to asynchronously read passwords from file
void readPasswords(PasswordEntry* passwords, int* passwordCount, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening passwords file\n");
        return;
    }

    char username[MAX_PASSWORD_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    int count = 0;
    while (fscanf(file, "%s %s", username, password) == 2) {
        passwords[count].username = malloc(strlen(username) + 1);
        strncpy(passwords[count].username, username, strlen(username) + 1);
        passwords[count].password = malloc(strlen(password) + 1);
        strncpy(passwords[count].password, password, strlen(password) + 1);
        count++;
    }

    *passwordCount = count;
    fclose(file);
}

// A function to validate a password's strength
bool isPasswordStrong(char* password) {
    int length = strlen(password);
    if (length < 8) {
        return false;
    }

    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSpecial = false;
    char specialCharacters[] = "~!@#$%^&*()_+=-{}][;'.,/?|";
    int specialLength = strlen(specialCharacters);

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = true;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasNumber = true;
        } else {
            for (int j = 0; j < specialLength; j++) {
                if (password[i] == specialCharacters[j]) {
                    hasSpecial = true;
                    break;
                }
            }
        }
    }

    return hasLower && hasUpper && hasNumber && hasSpecial;
}

// A function to asynchronously update a password's strength
void updatePasswordStrength(char* password, bool* isStrong, bool* isProcessing) {
    *isProcessing = true;

    // Simulate processing time
    for (int i = 0; i < 100000000; i++) {}

    *isStrong = isPasswordStrong(password);

    *isProcessing = false;
}

// A function to asynchronously prompt the user for a new password and validate it
void promptUserForPassword(char* password, bool* isStrong, bool* isProcessing) {
    printf("Enter new password: ");
    scanf("%s", password);

    updatePasswordStrength(password, isStrong, isProcessing);

    while (*isProcessing) {}

    if (!(*isStrong)) {
        printf("Error: Password is not strong enough\n");
        promptUserForPassword(password, isStrong, isProcessing);
    }
}

// A function to add a new password to the password list
void addPassword(PasswordEntry* passwords, int* passwordCount) {
    if (*passwordCount == MAX_PASSWORD_COUNT) {
        printf("Error: Maximum password count reached\n");
        return;
    }

    bool isStrong = false;
    bool isProcessing = false;
    char* password = malloc(MAX_PASSWORD_LENGTH + 1);

    promptUserForPassword(password, &isStrong, &isProcessing);

    passwords[*passwordCount].username = malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    printf("Enter username: ");
    scanf("%s", passwords[*passwordCount].username);
    passwords[*passwordCount].password = password;

    (*passwordCount)++;
}

// A function to print the password list
void printPasswords(PasswordEntry* passwords, int passwordCount) {
    printf("Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("%s %s\n", passwords[i].username, passwords[i].password);
    }
}

// A function to asynchronously write passwords to file
void writePasswords(PasswordEntry* passwords, int passwordCount, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening passwords file\n");
        return;
    }

    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s %s\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

// The main function that runs the password manager
int main() {
    PasswordEntry passwords[MAX_PASSWORD_COUNT];
    int passwordCount = 0;

    readPasswords(passwords, &passwordCount, "passwords.txt");

    char input[MAX_PASSWORD_LENGTH + 1];
    while (true) {
        printf("Enter a command (add, print, save, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            addPassword(passwords, &passwordCount);
        } else if (strcmp(input, "print") == 0) {
            printPasswords(passwords, passwordCount);
        } else if (strcmp(input, "save") == 0) {
            writePasswords(passwords, passwordCount, "passwords.txt");
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command\n");
        }
    }

    for (int i = 0; i < passwordCount; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}