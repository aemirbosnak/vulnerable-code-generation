//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed
void test_typing_speed() {
    // Generate a random string
    char *str = generate_random_string(100);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[MAX_STRING_LENGTH];
    printf("Type the following string as quickly as possible:\n");
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double typing_speed = (double)strlen(str) / time_taken;

    // Print the results
    printf("You typed %d characters in %.2f seconds.\n", strlen(str), time_taken);
    printf("Your typing speed is %.2f characters per second.\n", typing_speed);

    // Free the memory
    free(str);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed
    test_typing_speed();

    return 0;
}