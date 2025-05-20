//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generateRandomString(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed of the user
void testTypingSpeed() {
    // Get the current time
    time_t start = time(NULL);

    // Generate a random string of length 100
    char* str = generateRandomString(100);

    // Print the string to the console
    printf("Type the following string as fast as you can:\n%s", str);

    // Get the input from the user
    char* input = malloc(101);
    scanf("%s", input);

    // Get the current time
    time_t end = time(NULL);

    // Calculate the typing speed in words per minute (WPM)
    double wpm = ((double)strlen(str) / 5.0) / ((double)(end - start) / 60.0);

    // Print the typing speed to the console
    printf("Your typing speed is: %.2f WPM\n", wpm);

    // Free the allocated memory
    free(str);
    free(input);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    testTypingSpeed();

    return 0;
}