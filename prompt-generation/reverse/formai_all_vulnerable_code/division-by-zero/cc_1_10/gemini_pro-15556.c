//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generateString(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculateWPM(int numChars, int time) {
    return (numChars / 5) / (time / 60);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's input
    printf("Enter the length of the string you want to type (in characters): ");
    int n;
    scanf("%d", &n);

    // Generate a random string
    char *str = generateString(n);

    // Display the string to the user
    printf("Type the following string as quickly and accurately as possible:\n%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = malloc(n + 1);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    int wpm = calculateWPM(n, end - start);

    // Display the results
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}