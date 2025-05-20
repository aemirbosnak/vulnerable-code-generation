//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (char)('a' + rand() % 26);
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed of the user
void test_typing_speed() {
    // Generate a random string of length 100
    char *str = generate_random_string(100);

    // Print the string to the console
    printf("Type the following string as quickly and accurately as possible:\n");
    printf("%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the input from the user
    char *input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute (WPM)
    double wpm = (double)(strlen(str) / 5) / time_taken;

    // Print the typing speed to the console
    printf("Your typing speed is %.2f WPM\n", wpm);

    // Free the allocated memory
    free(str);
    free(input);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    test_typing_speed();

    return 0;
}