//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 5
#define MAX_LENGTH 15
#define MAX_TIME 30

// Generates a random string of length between MIN_LENGTH and MAX_LENGTH
char* generateRandomString() {
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    char* randomString = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        randomString[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    randomString[length] = '\0';
    return randomString;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given random strings and you have to type them as fast as you can.\n");
    printf("You have %d seconds to type as many strings as you can.\n", MAX_TIME);
    printf("Press ENTER to start the test.\n");
    getchar();

    int correctCount = 0;
    int incorrectCount = 0;
    int typedCount = 0;
    time_t startTime = time(NULL);

    while (difftime(time(NULL), startTime) < MAX_TIME) {
        char* randomString = generateRandomString();
        printf("Type the following string as fast as you can: ");
        printf("%s\n", randomString);

        char typedString[MAX_LENGTH];
        fgets(typedString, MAX_LENGTH, stdin);
        typedCount++;

        if (strcmp(randomString, typedString) == 0) {
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Incorrect!\n");
            incorrectCount++;
        }

        free(randomString);
    }

    double accuracy = (double) correctCount / typedCount * 100;
    double speed = (double) typedCount / MAX_TIME * 60;

    printf("\n--- Results ---\n");
    printf("Correct: %d\n", correctCount);
    printf("Incorrect: %d\n", incorrectCount);
    printf("Typed: %d\n", typedCount);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f words per minute\n", speed);

    return 0;
}