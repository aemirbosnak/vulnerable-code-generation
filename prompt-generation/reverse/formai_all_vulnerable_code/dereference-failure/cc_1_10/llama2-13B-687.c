//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define MIN_READING_SPEED 200
#define MAX_READING_SPEED 600

// Structure to store information about a word
typedef struct {
    char *word;
    int length;
} word_t;

// Function to generate a random word
word_t *generate_word(void) {
    int length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
    char *word = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    return (word_t *)word;
}

// Function to read a sentence and calculate the reading speed
void read_sentence(word_t *sentence, int *reading_speed) {
    int words_read = 0;
    int total_time = 0;
    clock_t start_time = clock();
    while (words_read < 10) {
        word_t *word = generate_word();
        sentence[words_read++] = *word;
        total_time += clock() - start_time;
    }
    *reading_speed = total_time / (words_read * 1000);
}

int main(void) {
    word_t *sentence = malloc(10 * sizeof(word_t));
    int reading_speed = 0;

    // Read 10 sentences and calculate the reading speed
    for (int i = 0; i < 10; i++) {
        read_sentence(sentence, &reading_speed);
        printf("Sentence %d: %s, reading speed: %f\n", i + 1, sentence[0].word, reading_speed);
    }

    return 0;
}