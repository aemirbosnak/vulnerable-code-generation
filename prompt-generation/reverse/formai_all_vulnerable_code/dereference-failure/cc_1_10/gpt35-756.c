//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8

// Function to generate a random integer between given min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random lowercase letter
char generateRandomLowercaseLetter() {
    return (char)generateRandomNumber(97, 122);
}

// Function to generate a random uppercase letter
char generateRandomUppercaseLetter() {
    return (char)generateRandomNumber(65, 90);
}

// Function to generate a random digit
char generateRandomDigit() {
    return (char)generateRandomNumber(48, 57);
}

// Function to generate a random special character
char generateRandomSpecialChar() {
    char specialChars[] = "!@#$%^&*()_+-=[]{}|;:',.<>/?";
    int index = generateRandomNumber(0, strlen(specialChars) - 1);
    return specialChars[index];
}

// Function to generate a secure random password
char* generateSecurePassword() {
    char* password = malloc(sizeof(char) * (MAX_LENGTH + 1));
    int length = generateRandomNumber(MIN_LENGTH, MAX_LENGTH);
    int i = 0;
    while (i < length) {
        int charType = generateRandomNumber(1, 4);
        switch (charType) {
            case 1:
                password[i++] = generateRandomLowercaseLetter();
                break;
            case 2:
                password[i++] = generateRandomUppercaseLetter();
                break;
            case 3:
                password[i++] = generateRandomDigit();
                break;
            case 4:
                password[i++] = generateRandomSpecialChar();
                break;
        }
    }
    password[length] = '\0';
    return password;
}

int main() {
    srand(time(NULL));
    char* password = generateSecurePassword();
    printf("Secure Password: %s\n", password);
    free(password);
    return 0;
}