//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12

void generatePassword(char* password);

int main() {

    char password[PASSWORD_LENGTH + 1];

    srand(time(0));
    generatePassword(password);

    printf("Your new cyber-password is: %s\n", password);
    return 0;
}

void generatePassword(char* password) {

    int i, randomNum;
    char symbolArr[] = "!@#$%^&*()_+",
        lowerCaseArr[] = "abcdefghijklmnopqrstuvwxyz",
        upperCaseArr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        numberArr[] = "0123456789",
        charsArr[PASSWORD_LENGTH];

    // Password must contain at least one symbol, lowercase letter, uppercase letter, and number
    charsArr[0] = symbolArr[randomNum = rand() % (strlen(symbolArr))];
    charsArr[1] = lowerCaseArr[randomNum = rand() % (strlen(lowerCaseArr))];
    charsArr[2] = upperCaseArr[randomNum = rand() % (strlen(upperCaseArr))];
    charsArr[3] = numberArr[randomNum = rand() % (strlen(numberArr))];

    // Fill in remaining characters randomly
    for (i = 4; i < PASSWORD_LENGTH; ++i) {
        randomNum = rand() % (strlen(symbolArr) + strlen(lowerCaseArr) + strlen(upperCaseArr) + strlen(numberArr));
        if (randomNum < strlen(symbolArr)) charsArr[i] = symbolArr[randomNum];
        else if ((randomNum -= strlen(symbolArr)) < strlen(lowerCaseArr)) charsArr[i] = lowerCaseArr[randomNum];
        else if ((randomNum -= strlen(lowerCaseArr)) < strlen(upperCaseArr)) charsArr[i] = upperCaseArr[randomNum];
        else charsArr[i] = numberArr[randomNum - strlen(upperCaseArr)]; // Extract remaining amount
    } 

    // Perform shuffling of array to ensure characters in random positions
    for (i = 0; i < PASSWORD_LENGTH; ++i) {
        randomNum = rand() % PASSWORD_LENGTH;
        if (randomNum != i) {
            charsArr[i] ^= charsArr[randomNum];
            charsArr[randomNum] ^= charsArr[i];
            charsArr[i] ^= charsArr[randomNum];
        }
    }

    memcpy(password, charsArr, PASSWORD_LENGTH + 1);
}