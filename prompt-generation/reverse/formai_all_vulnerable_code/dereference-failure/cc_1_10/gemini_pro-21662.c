//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random string
char *randomString(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int c = rand() % 26;
        str[i] = 'a' + c;
    }
    str[length] = '\0';
    return str;
}

// Function to test typing speed
int testTypingSpeed(int timeLimit) {
    // Generate random string
    char *str = randomString(100);

    // Start timer
    clock_t start = clock();

    // Get user input
    printf("Type the following string as fast as you can:\n%s\n", str);
    char input[101];
    scanf("%s", input);

    // Stop timer
    clock_t end = clock();

    // Calculate time taken
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    // Check if input matches random string
    int correct = strcmp(input, str) == 0;

    // Calculate typing speed
    int wordsPerMinute = (int)(strlen(str) / 5 / timeTaken * 60);

    // Print results
    printf("\nResults:\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Correct: %s\n", correct ? "Yes" : "No");
    printf("Words per minute: %d\n", wordsPerMinute);

    // Free memory
    free(str);

    return wordsPerMinute;
}

int main() {
    // Set the time limit for the test
    int timeLimit = 60;

    // Start the test
    int wpm = testTypingSpeed(timeLimit);

    // Print the results
    printf("\nYour typing speed is %d words per minute.\n", wpm);

    return 0;
}