//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char* generateString(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

// Function to test the typing speed
int testTypingSpeed(int duration) {
    // Generate a random string
    char* str = generateString(100);

    // Start the timer
    clock_t start = clock();

    // Prompt the user to start typing
    printf("Start typing:\n");

    // Get the user's input
    char input[101];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    int speed = (int)((strlen(str) / (double)(end - start)) * CLOCKS_PER_SEC);

    // Free the allocated memory
    free(str);

    return speed;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the duration of the test from the user
    int duration;
    printf("Enter the duration of the test (in seconds): ");
    scanf("%d", &duration);

    // Test the typing speed
    int speed = testTypingSpeed(duration);

    // Print the typing speed
    printf("Your typing speed is %d characters per second.\n", speed);

    return 0;
}