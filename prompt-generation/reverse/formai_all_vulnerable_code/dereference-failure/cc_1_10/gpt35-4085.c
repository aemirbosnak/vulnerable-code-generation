//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random character
char getRandomChar() {
    char character;
    int randomNumber = rand() % 62;

    if (randomNumber < 26) {
        character = 'a' + randomNumber;
    } else if (randomNumber < 52) {
        character = 'A' + (randomNumber - 26);
    } else {
        character = '0' + (randomNumber - 52);
    }

    return character;
}

// Function to generate a secure password
char* generateSecurePassword(int passwordLength) {
    char* password = malloc(sizeof(char) * (passwordLength + 1));

    for (int i = 0; i < passwordLength; i++) {
        password[i] = getRandomChar();
    }

    password[passwordLength] = '\0';

    return password;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // Check whether the user has provided the password length
    if (argc < 2) {
        printf("Please provide the length of the password as a command line argument.\n");
        exit(1);
    }

    // Get the password length from the command line argument
    int passwordLength = atoi(argv[1]);

    // Check whether the password length is valid
    if (passwordLength < 8) {
        printf("The password length must be at least 8 characters long.\n");
        exit(1);
    }

    char* password = generateSecurePassword(passwordLength);

    // Print the generated password
    printf("The generated password is: %s\n", password);

    // Securely erase the password from memory
    size_t passwordSize = strlen(password);
    memset(password, 0, passwordSize);
    free(password);

    return 0;
}