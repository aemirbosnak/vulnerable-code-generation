//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_wpm(int characters_typed, int time_elapsed) {
    return characters_typed / 5 / (time_elapsed / 60);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random string of length 100
    char *string = generate_random_string(100);

    // Get the current time
    time_t start_time = time(NULL);

    // Prompt the user to start typing
    printf("Start typing the following string:\n%s\n", string);

    // Get the user's input
    char input[101];
    scanf("%s", input);

    // Get the current time
    time_t end_time = time(NULL);

    // Calculate the time elapsed
    int time_elapsed = end_time - start_time;

    // Calculate the number of characters typed
    int characters_typed = strlen(input);

    // Calculate the typing speed
    int wpm = calculate_wpm(characters_typed, time_elapsed);

    // Print the typing speed
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the allocated memory
    free(string);

    return 0;
}