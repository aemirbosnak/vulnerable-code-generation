//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20

char generateRandomChar() {
    char randomChar = 0;
    int randomNum = 0;
    do {
        randomNum = rand() % 127;
    } while (!isalnum(randomNum));
    randomChar = (char) randomNum;
    return randomChar;    
}

int checkForLowerCase(char* password) {
    for (int i = 0; i < strlen(password); i++){
        if (password[i] >= 97 && password[i] <= 122){
            return 1;
        }
    }
    return 0;
}

int checkForUpperCase(char* password) {
    for (int i = 0; i < strlen(password); i++){
        if (password[i] >= 65 && password[i] <= 90){
            return 1;
        }
    }
    return 0;
}

int checkForDigit(char* password) {
    for (int i = 0; i < strlen(password); i++){
        if (password[i] >= 48 && password[i] <= 57){
            return 1;
        }
    }
    return 0;
}

int checkForSpecialChar(char* password) {
    for (int i = 0; i < strlen(password); i++){
        if (!isalnum(password[i])){
            return 1;
        }
    }
    return 0;
}

int checkPasswordComplexity(char* password) {
    if ((strlen(password) < 12) || 
        (checkForLowerCase(password) == 0) ||
        (checkForUpperCase(password) == 0) ||
        (checkForDigit(password) == 0) ||
        (checkForSpecialChar(password) == 0)) {
        return 0;
    }
    return 1;
}

void generatePassword(char* password, int length) {
    int count = 0;
    while (count < length) {
        password[count++] = generateRandomChar();
    }
    password[length] = '\0';
}

int main(int argc, char* argv[]) {
    int passwordLength = 0;
    if (argc > 1) {
        passwordLength = atoi(argv[1]);
    } else {
        printf("Please enter the password length: ");
        scanf("%d", &passwordLength);
    }
    if (passwordLength > MAX_LENGTH) {
        printf("Maximum length allowed is %d\n", MAX_LENGTH);
        exit(1);
    }
    srand(time(0));
    char password[MAX_LENGTH + 1];
    do {
        generatePassword(password, passwordLength);
    } while (!checkPasswordComplexity(password));
    printf("Generated password: %s\n", password);
    return 0;
}