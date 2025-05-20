//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random integer within range
int randomInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min; 
}

// Function to generate a random uppercase character
char randomUppercase() {
    return (char) randomInRange(65, 90); 
}

// Function to generate a random lowercase character
char randomLowercase() {
    return (char) randomInRange(97, 122); 
}

// Function to generate a random digit
char randomDigit() {
    return (char) randomInRange(48, 57);
}

// Function to generate a random special character
char randomSpecialChar() {
    int specialCharsCount = 13;
    char specialChars[specialCharsCount];
    specialChars[0] = '!';
    specialChars[1] = '"';
    specialChars[2] = '#';
    specialChars[3] = '$';
    specialChars[4] = '%';
    specialChars[5] = '&';
    specialChars[6] = '\'';
    specialChars[7] = '(';
    specialChars[8] = ')';
    specialChars[9] = '*';
    specialChars[10] = '+';
    specialChars[11] = ',';
    specialChars[12] = '-';
    return specialChars[randomInRange(0, specialCharsCount - 1)];
}

// Function to generate a secure password
char* generateSecurePassword(int length) {
    char* password = (char*) malloc(sizeof(char) * (length + 1));
    password[length] = '\0';
    int i;
    for (i=0; i<length; i++) {
        int charType = randomInRange(1, 4);
        switch(charType) {
            case 1:
                password[i] = randomUppercase();
                break;
            case 2:
                password[i] = randomLowercase();
                break;
            case 3:
                password[i] = randomDigit();
                break;
            case 4:
                password[i] = randomSpecialChar();
                break;
        }
    }
    return password;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int passwordLength = 12;
    if (argc == 2) {
        passwordLength = atoi(argv[1]);
    }
    printf("Generated password: %s\n", generateSecurePassword(passwordLength));
    return 0;
}