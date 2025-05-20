//LLAMA2-13B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT 10
#define LETTER_COUNT 26

// Define a struct to represent a word
struct word {
    char letter[LETTER_COUNT];
    int frequency;
};

// Define a array to store all words
struct word words[WORD_COUNT];

// Function to generate a random word
struct word* generate_word(void) {
    int i, j;
    struct word* word = malloc(sizeof(struct word));
    for (i = 0; i < LETTER_COUNT; i++) {
        word->letter[i] = 'a' + (rand() % LETTER_COUNT);
    }
    word->frequency = 1;
    return word;
}

// Function to add a word to the array
void add_word(struct word* word) {
    int i;
    for (i = 0; i < WORD_COUNT; i++) {
        if (words[i].frequency < word->frequency) {
            break;
        }
    }
    words[i] = *word;
}

// Function to print the most frequent word
void print_most_frequent(void) {
    int max_frequency = 0;
    struct word* max_word = NULL;
    for (int i = 0; i < WORD_COUNT; i++) {
        if (words[i].frequency > max_frequency) {
            max_frequency = words[i].frequency;
            max_word = &words[i];
        }
    }
    printf("The most frequent word is: %s\n", max_word->letter);
}

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < WORD_COUNT; i++) {
        struct word* word = generate_word();
        add_word(word);
    }
    print_most_frequent();
    return 0;
}