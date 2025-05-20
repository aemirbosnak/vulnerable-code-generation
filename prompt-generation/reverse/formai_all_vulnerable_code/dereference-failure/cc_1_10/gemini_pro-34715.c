//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of the input text
#define MAX_TEXT_LENGTH 100

// Define the maximum time allowed for the test (in seconds)
#define MAX_TIME 60

// Define the minimum number of words per minute to pass the test
#define MIN_WORDS_PER_MINUTE 60

// Generate a random string of characters
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'a';
    }
    string[length] = '\0';
    return string;
}

// Calculate the number of words per minute based on the input text and time
int calculate_words_per_minute(char *text, int time) {
    int num_words = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            num_words++;
        }
    }
    return (num_words / time) * 60;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate the input text
    char *text = generate_random_string(MAX_TEXT_LENGTH);

    // Print the input text to the console
    printf("Input text:\n%s\n", text);

    // Start the timer
    time_t start_time = time(NULL);

    // Get the user's input
    char input[MAX_TEXT_LENGTH];
    printf("Type the text as quickly and accurately as possible:\n");
    scanf("%s", input);

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the user's typing speed
    int words_per_minute = calculate_words_per_minute(input, end_time - start_time);

    // Print the user's typing speed to the console
    printf("Your typing speed: %d words per minute\n", words_per_minute);

    // Check if the user passed the test
    if (words_per_minute >= MIN_WORDS_PER_MINUTE) {
        printf("Congratulations! You passed the test.\n");
    } else {
        printf("Sorry, you did not pass the test.\n");
    }

    // Free the allocated memory
    free(text);

    return 0;
}