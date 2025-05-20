//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random string generator
char* randomString(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

// Typing speed test
void typingSpeedTest() {
    // Get the user's input
    char* targetString = randomString(50);
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", targetString);
    char* inputString = malloc(51);
    scanf("%s", inputString);

    // Calculate the typing speed
    time_t start = time(NULL);
    int correctCharacters = 0;
    for (int i = 0; i < 50; i++) {
        if (inputString[i] == targetString[i]) {
            correctCharacters++;
        }
    }
    time_t end = time(NULL);
    double timeTaken = difftime(end, start);
    double wpm = (correctCharacters / 5.0) / (timeTaken / 60.0);

    // Print the results
    printf("\nYour typing speed is: %.2f WPM\n", wpm);
    free(targetString);
    free(inputString);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    typingSpeedTest();

    return 0;
}