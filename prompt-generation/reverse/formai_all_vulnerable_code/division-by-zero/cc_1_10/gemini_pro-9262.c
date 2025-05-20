//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int i, words, seconds, accuracy;
    float speed;
    char text[1000], typedText[1000];

    // Initialize variables
    words = 0;
    seconds = 0;
    accuracy = 0;
    speed = 0.0;

    // Get the text from the user
    printf("Enter the text to be typed: ");
    scanf("%s", text);

    // Start the timer
    clock_t start = clock();

    // Get the typed text from the user
    printf("Start typing: ");
    scanf("%s", typedText);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    seconds = (end - start) / CLOCKS_PER_SEC;

    // Calculate the words per minute
    words = strlen(text) / 5;

    // Calculate the accuracy
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == typedText[i]) {
            accuracy++;
        }
    }

    accuracy = (accuracy * 100) / strlen(text);

    // Calculate the speed
    speed = (words * 60) / seconds;

    // Print the results
    printf("Words per minute: %d\n", words);
    printf("Accuracy: %d%%\n", accuracy);
    printf("Speed: %.2f words per minute\n", speed);

    return 0;
}