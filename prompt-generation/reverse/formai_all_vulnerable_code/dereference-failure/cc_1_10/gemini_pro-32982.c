//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed of the user
int test_typing_speed() {
    // Generate a random string of length 100
    char* str = generate_string(100);

    // Get the current time
    clock_t start_time = clock();

    // Prompt the user to type the string
    printf("Type the following string as quickly as possible:\n%s\n", str);

    // Get the user's input
    char* user_input = malloc(101);
    scanf("%s", user_input);

    // Get the current time
    clock_t end_time = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    double wpm = (double)strlen(str) / 5.0 / time_taken;

    // Print the typing speed
    printf("Your typing speed is %.2f words per minute.\n", wpm);

    // Free the allocated memory
    free(str);
    free(user_input);

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    test_typing_speed();

    return 0;
}