//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 20 // Maximum length of the password

// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random lowercase character
char getRandomLowercaseChar() {
    return (char)getRandomInt(97, 122); // ASCII values for lowercase letters
}

// Function to generate a random uppercase character
char getRandomUppercaseChar() {
    return (char)getRandomInt(65, 90); // ASCII values for uppercase letters
}

// Function to generate a random digit
char getRandomDigit() {
    return (char)getRandomInt(48, 57); // ASCII values for digits
}

// Function to generate a random special character
char getRandomSpecialChar() {
    char specialChars[] = "!@#$%^&*()_+{}[]|\\:;<>,.?/";
    int index = getRandomInt(0, strlen(specialChars) - 1);
    return specialChars[index];
}

// Function to generate a secure password
char* generateSecurePassword() {
    char* password = malloc(MAX_LENGTH + 1);
    int length = getRandomInt(8, MAX_LENGTH);
    int i;

    for (i = 0; i < length; i++) {
        int type = getRandomInt(1, 4); // 1: lowercase, 2: uppercase, 3: digit, 4: special
        switch (type) {
            case 1:
                password[i] = getRandomLowercaseChar();
                break;
            case 2:
                password[i] = getRandomUppercaseChar();
                break;
            case 3:
                password[i] = getRandomDigit();
                break;
            case 4:
                password[i] = getRandomSpecialChar();
                break;
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator
    
    char* password = generateSecurePassword();
    printf("Your secure password is: %s\n", password);
    free(password);

    return 0;
}