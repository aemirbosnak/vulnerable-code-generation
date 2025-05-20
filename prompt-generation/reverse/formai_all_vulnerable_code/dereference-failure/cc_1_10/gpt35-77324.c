//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000

// Function to generate random strings
char* generateRandomString(int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* randomString = malloc(sizeof(char) * length + 1);
    int i;
    for (i = 0; i < length; i++) {
        randomString[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    randomString[length] = '\0';
    return randomString;
}

// Function to calculate typing speed
void calculateTypingSpeed(int timeTaken, int correctChars) {
    float speed = ((float) correctChars / (float) timeTaken) * 60;
    printf("\nYou typed at a speed of %.2f characters per minute.\n", speed);
}

int main() {
    int numberOfAttempts = 3, attempt = 0, correctChars = 0;
    char* inputString, *randomString;
    clock_t start, end;
    double timeTaken;
    
    printf("Welcome to the C Typing Speed Test.\n");
    
    while (attempt < numberOfAttempts) {
        printf("Attempt %d:\n", attempt + 1);
        int stringLength = (rand() % 10) + 10;
        randomString = generateRandomString(stringLength);
        printf("Type the following string as fast as you can:\n%s\n", randomString);
        start = clock();
        inputString = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
        fgets(inputString, MAX_STRING_LENGTH, stdin);
        end = clock();
        timeTaken = ((double) end - (double) start) / CLOCKS_PER_SEC;
        int i;
        for (i = 0; i < stringLength; i++) {
            if (randomString[i] == inputString[i]) {
                correctChars++;
            }
        }
        calculateTypingSpeed((int) (timeTaken * 60), correctChars);
        attempt++;
        free(inputString);
        free(randomString);
    }
    
    printf("Thank you for taking the Typing Speed Test.\n");
    return 0;
}