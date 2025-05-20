//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// The list of words to be typed
char *words[] = {
    "apocalypse", "barren", "catastrophe", "desolation", "devastation",
    "entropy", "famine", "holocaust", "inferno", "madness",
    "nightmare", "oblivion", "plague", "ruin", "wasteland",
    "annihilation", "bedlam", "carnage", "chaos", "darkness",
    "despair", "doom", "extermination", "fury", "havoc",
    "horror", "judgement", "obliteration", "pandemonium", "rapture",
    "Armageddon", "Cataclysm", "Deluge", "Earthquake", "Eruption",
    "Firestorm", "Flood", "Ice Age", "Meteor", "Plague",
    "Tempest", "Tornado", "Tsunami", "Volcano", "War"
};

// The main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of words to be typed
    int num_words = rand() % MAX_WORDS + 1;

    // Create an array to store the words to be typed
    char **words_to_type = malloc(sizeof(char *) * num_words);

    // Select the words to be typed
    for (int i = 0; i < num_words; i++) {
        words_to_type[i] = words[rand() % MAX_WORDS];
    }

    // Print the words to be typed
    printf("Type these words as quickly as you can:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words_to_type[i]);
    }
    printf("\n");

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = malloc(sizeof(char) * MAX_WORD_LEN * num_words);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the words
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    double typing_speed = num_words / time_taken * 60;

    // Print the typing speed
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    // Free the allocated memory
    free(words_to_type);
    free(input);

    return 0;
}