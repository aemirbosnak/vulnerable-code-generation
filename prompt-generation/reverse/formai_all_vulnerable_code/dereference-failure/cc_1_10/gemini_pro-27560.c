//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_typing_speed(char *str, int time) {
    int words = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            words++;
        }
    }
    words++; // Add one for the last word
    int wpm = (words * 60) / time;
    return wpm;
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char *str = generate_random_string(100);

    // Print the string to the console
    printf("Type the following string as fast as you can:\n");
    printf("%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the input from the user
    char input[101];
    fgets(input, 101, stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken in seconds
    int time = (end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    int wpm = calculate_typing_speed(str, time);

    // Print the typing speed to the console
    printf("Your typing speed is: %d WPM\n", wpm);

    return 0;
}