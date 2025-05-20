//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random sentence
char *generateSentence(int length) {
    char *sentence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sentence[i] = 'a' + rand() % 26;
    }
    sentence[length] = '\0';
    return sentence;
}

// Function to test the user's typing speed
int testTypingSpeed(int timeLimit) {
    // Generate a random sentence
    char *sentence = generateSentence(100);

    // Start the timer
    time_t start = time(NULL);

    // Get the user's input
    char input[101];
    printf("Type the following sentence as quickly and accurately as possible:\n%s\n", sentence);
    scanf("%s", input);

    // Stop the timer
    time_t end = time(NULL);

    // Calculate the typing speed
    int timeTaken = end - start;
    int typingSpeed = strlen(sentence) / timeTaken;

    // Free the memory allocated for the sentence
    free(sentence);

    return typingSpeed;
}

// Main function
int main() {
    // Set the time limit for the test
    int timeLimit = 60;

    // Test the user's typing speed
    int typingSpeed = testTypingSpeed(timeLimit);

    // Print the user's typing speed
    printf("Your typing speed is %d words per minute.\n", typingSpeed);

    return 0;
}