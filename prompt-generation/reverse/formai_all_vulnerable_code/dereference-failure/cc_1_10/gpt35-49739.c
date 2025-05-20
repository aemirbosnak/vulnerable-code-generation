//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 30
#define MIN_UPPER 2
#define MIN_LOWER 2
#define MIN_DIGIT 2

int charSetLength(char* input) {
    int i = 0;
    while(input[i] != '\0') i++;
    return i;
}

char* randomChar(char* input) {
    int index = rand() % charSetLength(input);
    char* result = malloc(sizeof(char) * 2);
    result[0] = input[index];
    result[1] = '\0';
    return result;
}

char* generatePassword(int length, char* uppercase, char* lowercase, char* digits) {
    int i, upperCount, lowerCount, digitCount;
    char* password = (char*) malloc(sizeof(char) * length + 1);
    srand(time(NULL));
    upperCount = lowerCount = digitCount = 0;
    for(i = 0; i < length; i++) {
        char* nextChar;
        if(digitCount < MIN_DIGIT && (rand() % 2 == 0 || upperCount == MIN_UPPER || lowerCount == MIN_LOWER)) {
            digitCount++;
            nextChar = randomChar(digits);
        } else if(upperCount < MIN_UPPER && (rand() % 2 == 0 || lowerCount == MIN_LOWER)) {
            upperCount++;
            nextChar = randomChar(uppercase);
        } else if(lowerCount < MIN_LOWER) {
            lowerCount++;
            nextChar = randomChar(lowercase);
        } else {
            nextChar = randomChar(uppercase);
        }
        password[i] = nextChar[0];
        free(nextChar);
    }
    password[length] = '\0';
    return password;
}

int main() {
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    char* password = generatePassword(MAX_LENGTH, uppercase, lowercase, digits);
    printf("%s\n", password);
    free(password);
    return 0;
}