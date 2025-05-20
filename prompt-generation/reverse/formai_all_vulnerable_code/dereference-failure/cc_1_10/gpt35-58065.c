//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum allowed password length

// Function to generate a random password
char* generatePassword(int length) {
    char* password = (char*) malloc(sizeof(char) * length);

    for(int i = 0; i < length; i++) {
        int num = rand() % 93 + 33; // ASCII values from 33 to 126
        password[i] = (char) num;
    }

    return password;
}

// Function to encrypt the password by shifting characters by 3 positions
void encryptPassword(char* password) {
    int length = strlen(password);

    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            password[i] = (char) ((password[i] - 'a' + 3) % 26 + 'a');
        }
        else if(password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = (char) ((password[i] - 'A' + 3) % 26 + 'A');
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            password[i] = (char) ((password[i] - '0' + 3) % 10 + '0');
        }
    }
}

// Function to prompt the user for a password and validate it
int validatePassword(char* password) {
    char validUpper = 'F', validLower = 'f', validNum = '3';
    int length = strlen(password);

    if(length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for(int i = 0; i < length; i++) {
        if(password[i] == validUpper || password[i] == validLower || password[i] == validNum) {
            return 1;
        }
    }

    printf("Password must contain at least one uppercase letter, one lowercase letter, and one number.\n");
    return 0;
}

// Main function
int main() {
    printf("Welcome to Password Manager.\n");

    // Prompt the user for a valid password
    char* password = (char*) malloc(sizeof(char) * MAX_LENGTH);
    do {
        printf("Please enter a password: ");
        scanf("%s", password);
    } while(!validatePassword(password));

    // Encrypt the password using character shifting
    encryptPassword(password);

    // Generate a random salt
    char* salt = generatePassword(4);

    // Concatenate the salt and the encrypted password
    char* hashedPassword = (char*) malloc(sizeof(char) * MAX_LENGTH);
    strcpy(hashedPassword, salt);
    strcat(hashedPassword, password);

    printf("Your encrypted password is: %s", hashedPassword);

    return 0;
}