//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of string to be typed
#define MAX_TIME 60 // Maximum time limit for typing test in seconds
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog." // Sample text for typing test

// Function to generate a random character
char randomChar() {
    char c = 'a' + rand() % 26;
    return c;
}

// Function to generate a random string of given length
char* randomString(int length) {
    char* str = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        str[i] = randomChar();
    }
    return str;
}

// Function to calculate typing speed in words per minute (wpm)
int calcWpm(int numChars, int time) {
    int numWords = numChars / 5;
    int wpm = numWords * 60 / time;
    return wpm;
}

// Main function to run typing speed test
int main() {
    srand(time(NULL)); // Seed for random number generation
    char* sample = strdup(SAMPLE_TEXT); // Duplicate sample text
    int numChars = strlen(sample); // Number of characters in sample text
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be asked to type the following phrase:\n\n");
    printf("%s\n\n", sample);
    printf("Press ENTER to start the timer and begin typing.\n");
    getchar(); // Wait for user input
    time_t start = time(NULL); // Start timing
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin); // Read user input
    time_t end = time(NULL); // End timing
    int timeTaken = (int) difftime(end, start); // Calculate time taken in seconds
    int wpm = calcWpm(strlen(input) - 1, timeTaken); // Calculate wpm
    printf("You typed %d characters in %d seconds.\n", strlen(input) - 1, timeTaken);
    printf("Your typing speed is %d words per minute.\n", wpm);
    free(sample); // Free allocated memory
    return 0;
}