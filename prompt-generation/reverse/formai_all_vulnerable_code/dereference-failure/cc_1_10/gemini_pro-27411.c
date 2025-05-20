//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed
int calculate_typing_speed(char* str, int time) {
    int len = strlen(str);
    return (len * 60) / time;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char* str = generate_random_string(100);

    // Display the string to the user
    printf("Type the following string as quickly as possible:\n\n%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* input = malloc(101);
    fgets(input, 101, stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    int time = (int)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int speed = calculate_typing_speed(str, time);

    // Display the results
    printf("\nYour typing speed is %d words per minute.\n", speed);

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}