//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Get the current time in milliseconds
long long get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random string of length 100
    char *str = generate_string(100);

    // Print the string to the console
    printf("%s\n", str);

    // Get the current time
    long long start_time = get_time();

    // Wait for the user to type the string
    char input[101];
    scanf("%s", input);

    // Get the current time
    long long end_time = get_time();

    // Check if the user typed the string correctly
    int correct = 1;
    for (int i = 0; i < 100; i++) {
        if (input[i] != str[i]) {
            correct = 0;
            break;
        }
    }

    // Calculate the typing speed
    double speed = 100.0 / (end_time - start_time) * 1000.0;

    // Print the typing speed to the console
    printf("Your typing speed is: %.2f words per minute\n", speed);

    // Free the memory allocated for the string
    free(str);

    return 0;
}