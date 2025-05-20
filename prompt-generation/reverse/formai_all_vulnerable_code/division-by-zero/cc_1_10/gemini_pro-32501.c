//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program tests your typing speed by displaying a phrase and then timing you as you type it.

// The words to be typed
char *words[] = {
    "The quick brown fox jumps over the lazy dog.",
    "The rain in Spain falls mainly on the plain.",
    "Now is the time for all good men to come to the aid of their country.",
    "I love you more than words can say.",
    "I will never forget the day we met."
};

// The number of words to be typed
int num_words = sizeof(words) / sizeof(char *);

// The time limit for typing the words (in seconds)
int time_limit = 60;

// The main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the current time
    time_t start_time = time(NULL);

    // Choose a random word to type
    int word_index = rand() % num_words;

    // Display the word to type
    printf("Type the following word as fast as you can:\n\n");
    printf("%s\n\n", words[word_index]);

    // Wait for the user to type the word
    char input[100];
    scanf("%s", input);

    // Get the current time
    time_t end_time = time(NULL);

    // Calculate the time taken to type the word
    int time_taken = end_time - start_time;

    // Calculate the typing speed (in words per minute)
    int typing_speed = (num_words * 60) / time_taken;

    // Display the typing speed
    printf("\nYour typing speed is %d words per minute.\n", typing_speed);

    return 0;
}