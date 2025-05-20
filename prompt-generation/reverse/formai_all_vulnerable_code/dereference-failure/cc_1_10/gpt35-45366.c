//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"
#define SYMBOLS "!@#$%^&*"

#define MIN_PASSWORD_LENGTH 8 // Minimum password length
#define MAX_PASSWORD_LENGTH 16 // Maximum password length

// Function declarations
char* generatePassword(int len);
int getRandomInt(int min, int max);
char getRandomChar(char* chars, int len);

int main() {
    // Set the seed for random number generator
    srand(time(NULL));
    
    // Generate a secure password of random length between MIN_PASSWORD_LENGTH and MAX_PASSWORD_LENGTH
    char* password = generatePassword(getRandomInt(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH));
    printf("Your secure password is: %s\n", password);
    
    // Free the memory allocated for password
    free(password);
    
    return 0;
}

// Function to generate a secure password of specified length
char* generatePassword(int len) {
    // Allocate memory for password of specified length
    char* password = (char*) malloc(len+1);
    
    // Array of characters to choose from for generating password
    char* chars[] = {ALPHABET, NUMBERS, SYMBOLS};
    int numSets = sizeof(chars)/sizeof(chars[0]);
    
    // Generate password as a combination of characters from ALPHABET, NUMBERS and SYMBOLS
    for(int i=0; i<len; i++) {
        // Select a random set of characters (0, 1 or 2)
        int setIndex = getRandomInt(0, numSets-1);
        char* selectedChars = chars[setIndex];
        int numChars = strlen(selectedChars);
        
        // Select a random character from the selected set of characters
        char randomChar = getRandomChar(selectedChars, numChars);
        password[i] = randomChar;
    }
    
    // Add '\0' at the end of the password to terminate the string
    password[len] = '\0';
    
    return password;
}

// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return rand() % (max-min+1) + min;
}

// Function to generate a random character from the specified array of characters
char getRandomChar(char* chars, int len) {
    int randomIndex = getRandomInt(0, len-1);
    return chars[randomIndex];
}