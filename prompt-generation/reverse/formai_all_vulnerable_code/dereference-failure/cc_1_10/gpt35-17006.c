//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 32

char generateRandomChar() {
    int asciiValue = rand() % 93 + 33; // generate ASCII value between 33 and 126
    return (char) asciiValue;
}

void generateSecurePassword(char* password, int length, int numDigits, int numSymbols) {
    srand(time(NULL));
    
    // determine number of alphabet characters
    int numAlpha = length - numDigits - numSymbols;
    
    // generate random alphabet characters
    for (int i = 0; i < numAlpha; i++) {
        password[i] = generateRandomChar();
    }
    
    // generate random digits
    for (int i = numAlpha; i < numAlpha + numDigits; i++) {
        password[i] = (char) (rand() % 10 + 48); // generate ASCII value between 48 and 57
    }
    
    // generate random symbols
    for (int i = numAlpha + numDigits; i < length; i++) {
        password[i] = generateRandomChar();
    }
    
    // randomly shuffle the password
    for (int i = 0; i < length; i++) {
        int j = rand() % length; // generate random index
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    int length, numDigits, numSymbols;
    char password[MAX_LENGTH];
    
    // get user input for desired password length, number of digits, and number of symbols
    printf("Enter desired password length (max 32): ");
    scanf("%d", &length);
    printf("Enter number of digits: ");
    scanf("%d", &numDigits);
    printf("Enter number of symbols: ");
    scanf("%d", &numSymbols);
    
    // check if input is valid
    if (length < numDigits + numSymbols) {
        printf("Invalid input: password length must be greater than or equal to the sum of digits and symbols.\n");
        return 1;
    }
    
    // generate password
    generateSecurePassword(password, length, numDigits, numSymbols);
    printf("Secure password: %s\n", password);
    
    return 0;
}