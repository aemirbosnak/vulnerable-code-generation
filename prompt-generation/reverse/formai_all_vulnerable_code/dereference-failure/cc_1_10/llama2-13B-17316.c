//LLAMA2-13B DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define POEM_LENGTH 20
#define WORDS_ARRAY_SIZE 20

// Function to generate a random word
char *get_random_word(void)
{
    char *word = malloc(sizeof(char *) * 10);
    int i;

    for (i = 0; i < 10; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to generate a poem
void generate_poem(void)
{
    int i, j;
    char *words[WORDS_ARRAY_SIZE];
    char *current_word = NULL;
    char *previous_word = NULL;

    // Initialize the words array with random words
    for (i = 0; i < WORDS_ARRAY_SIZE; i++) {
        words[i] = get_random_word();
    }

    // Get the user's name
    printf("What is your name? ");
    scanf("%s", &current_word);

    // Create the poem
    for (i = 0; i < POEM_LENGTH; i++) {
        // Select a word from the words array
        current_word = words[rand() % WORDS_ARRAY_SIZE];

        // Check if the current word is the same as the previous word
        if (previous_word != NULL && strcmp(current_word, previous_word) == 0) {
            // If it is, select a new word
            current_word = words[rand() % WORDS_ARRAY_SIZE];
        }

        // Add the current word to the poem
        printf("%s %s\n", previous_word, current_word);

        // Update the previous word
        previous_word = current_word;
    }

    // Print the final poem
    printf("%s\n", previous_word);
}

int main(void)
{
    srand(time(NULL));

    generate_poem();

    return 0;
}