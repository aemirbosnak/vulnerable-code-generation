//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: modular
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

// Function to calculate the typing speed
int calculate_typing_speed(char *target, char *input, int time) {
    // Calculate the number of correct characters typed
    int correct_characters = 0;
    for (int i = 0; i < strlen(target); i++) {
        if (target[i] == input[i]) {
            correct_characters++;
        }
    }

    // Calculate the typing speed in words per minute (WPM)
    int wpm = (correct_characters / 5) * (60 / time);
    return wpm;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random target string
    int target_length = 100;
    char *target = generate_random_string(target_length);

    // Get the input from the user
    char input[101];
    printf("Type the following string as quickly and accurately as possible:\n%s\n", target);
    scanf("%s", input);

    // Calculate the time taken to type the input
    clock_t start = clock();
    scanf("%s", input);
    clock_t end = clock();
    int time = (end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int wpm = calculate_typing_speed(target, input, time);

    // Print the typing speed
    printf("Your typing speed is %d WPM.\n", wpm);

    return 0;
}