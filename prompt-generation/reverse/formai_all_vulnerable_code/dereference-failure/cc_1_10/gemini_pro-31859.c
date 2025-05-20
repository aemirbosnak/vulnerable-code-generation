//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed of the user
void test_typing_speed() {
    // Generate a random string of length 100
    char* str = generate_random_string(100);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    double wpm = (100 / 5) / time_taken;

    // Print the results
    printf("Your typing speed is: %.2f words per minute\n", wpm);
    free(input);
    free(str);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    test_typing_speed();

    return 0;
}