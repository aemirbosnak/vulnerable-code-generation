//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Linus Torvalds style
#define PRINTK(fmt, ...) printf(fmt, ##__VA_ARGS__)

// Random string generator
char *random_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = 'a' + rand() % ('z' - 'a' + 1);
    }
    str[len] = '\0';
    return str;
}

// Typing speed test
void typing_speed_test() {
    // Generate a random string
    char *str = random_string(100);

    // Display the string
    PRINTK("\nType the following string as fast as you can:\n\n%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = malloc(101);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (double)strlen(str) / time_taken;

    // Display the typing speed
    PRINTK("\nYour typing speed is: %.2f words per minute\n", speed);

    // Free the allocated memory
    free(str);
    free(input);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Run the typing speed test
    typing_speed_test();

    return 0;
}