//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16
#define NUM_OF_SPECIAL_CHARS 11

char generateRandomChar();
char *generatePassword(int length);

char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '?'};

int main(){
    srand(time(NULL)); // Initialize random number generator based on current time

    // Generate a password with default length
    char *password = generatePassword(PASSWORD_LENGTH);
    printf("Randomly generated password: %s\n", password);

    // Generate a password with user-specified length
    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);
    password = generatePassword(length);
    printf("Randomly generated password: %s\n", password);

    // Free memory allocated for password
    free(password);

    return 0;
}

// Function to generate a random character
char generateRandomChar(){
    // ASCII values for uppercase, lowercase, and numeric characters
    int upperBound = 90;
    int lowerBound = 65;
    int numBound = 48;

    int randomIndex = rand() % 3; // Choose random category of character to generate
    int asciiValue;

    switch(randomIndex){
        case 0:
            asciiValue = rand() % (upperBound - lowerBound + 1) + lowerBound; // Generate a random uppercase letter
            break;
        case 1:
            asciiValue = rand() % (lowerBound - numBound + 1) + numBound; // Generate a random numeric digit
            break;
        case 2:
            asciiValue = rand() % (upperBound - lowerBound + 1) + lowerBound; // Generate a random lowercase letter
            asciiValue += 32; // Convert ASCII value to lowercase
            break;
    }

    return (char) asciiValue;
}

// Function to generate a secure password with the specified length
char *generatePassword(int length){
    char *password = (char*) malloc(sizeof(char) * (length + 1)); // Allocate memory for password string

    for(int i = 0; i < length; i++){
        password[i] = generateRandomChar();
    }

    int randomIndex = rand() % length; // Choose random index to insert special character
    password[randomIndex] = specialChars[rand() % NUM_OF_SPECIAL_CHARS]; // Insert a random special character at specified index

    password[length] = '\0'; // Add null terminator to end of password string

    return password;
}