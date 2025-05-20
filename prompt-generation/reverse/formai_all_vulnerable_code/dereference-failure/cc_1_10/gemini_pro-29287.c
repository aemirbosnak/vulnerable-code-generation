//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to test the typing speed of the user
void test_typing_speed() {
    // Generate a random string of length 100
    char *str = generate_random_string(100);

    // Print the string to the console
    printf("Type the following string as quickly and accurately as possible:\n\n");
    printf("%s\n\n", str);

    // Start the timer
    clock_t start_time = clock();

    // Get the input from the user
    char user_input[101];
    fgets(user_input, 101, stdin);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the typing speed in words per minute (WPM)
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double wpm = (strlen(str) / 5) / time_taken;

    // Print the typing speed to the console
    printf("\nYour typing speed is %.2f WPM.\n", wpm);

    // Free the allocated memory
    free(str);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    test_typing_speed();

    return 0;
}