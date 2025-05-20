//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char* generateRandomString(int length) {
    char* string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'a';
    }
    string[length] = '\0';
    return string;
}

// Function to test the typing speed
void testTypingSpeed() {
    // Generate a random string
    char* string = generateRandomString(100);

    // Print the string to the console
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", string);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int typingSpeed = (int)((strlen(string) / timeTaken) * 60);

    // Print the results
    printf("\nYour typing speed is %d words per minute.\n", typingSpeed);

    // Free the allocated memory
    free(string);
    free(input);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed
    testTypingSpeed();

    return 0;
}