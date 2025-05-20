//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_BUFFER_SIZE 128

// Function prototypes
void generatePassword(char *password, int length);
void fillCharacterSet(char *set, int *setSize);
void shufflePassword(char *password, int length);
void printUsage();

int main(int argc, char *argv[]) {
    // Seed random number generator
    srand(time(NULL));

    // Check for valid command line arguments
    if (argc != 2) {
        printUsage();
        return 1;
    }

    int passwordLength = atoi(argv[1]);

    // Validate password length
    if (passwordLength <= 0 || passwordLength > PASSWORD_BUFFER_SIZE) {
        printUsage();
        return 1;
    }

    char password[PASSWORD_BUFFER_SIZE];
    generatePassword(password, passwordLength);
    
    printf("Generated Password: %s\n", password);
    return 0;
}

// Function to generate a random password
void generatePassword(char *password, int length) {
    // Define character sets
    char characterSet[70];
    int setSize = 0;

    fillCharacterSet(characterSet, &setSize);

    // Ensure the password includes at least one character from each category
    password[0] = characterSet[rand() % 26]; // Uppercase
    password[1] = characterSet[26 + rand() % 26]; // Lowercase
    password[2] = characterSet[52 + rand() % 10]; // Digit
    password[3] = characterSet[62 + rand() % 8]; // Special character

    // Fill the rest of the password with random characters
    for (int i = 4; i < length; ++i) {
        password[i] = characterSet[rand() % setSize];
    }

    password[length] = '\0'; // Null-terminate the string
    shufflePassword(password, length); // Shuffle the generated password
}

// Function to fill the character set
void fillCharacterSet(char *set, int *setSize) {
    // Uppercase letters
    for (char c = 'A'; c <= 'Z'; ++c) {
        set[(*setSize)++] = c;
    }
    
    // Lowercase letters
    for (char c = 'a'; c <= 'z'; ++c) {
        set[(*setSize)++] = c;
    }
    
    // Digits
    for (char c = '0'; c <= '9'; ++c) {
        set[(*setSize)++] = c;
    }

    // Special characters
    char specialChars[] = "!@#$%^&*()-_=+[]{};:,.<>?";
    for (int i = 0; i < strlen(specialChars); ++i) {
        set[(*setSize)++] = specialChars[i];
    }
}

// Function to shuffle the password array
void shufflePassword(char *password, int length) {
    for (int i = 0; i < length; ++i) {
        int j = rand() % length;
        // Swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

// Function to print usage instructions
void printUsage() {
    printf("Usage: password_generator <length>\n");
    printf("Length must be a positive integer (max %d)\n", PASSWORD_BUFFER_SIZE);
}