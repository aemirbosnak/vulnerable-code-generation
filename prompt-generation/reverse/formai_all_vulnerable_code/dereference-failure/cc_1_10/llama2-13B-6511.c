//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WORDS_PER_LINE 20
#define LINES_PER_FILE 50
#define MAX_SENTENCE_LENGTH 50

// Structure to represent a sentence
typedef struct sentence {
    char *text;
    int length;
} sentence;

// Function to generate random sentences
sentence *generate_sentences(int num_sentences) {
    sentence *sentences = malloc(num_sentences * sizeof(sentence));
    int i, j, word_count;

    for (i = 0; i < num_sentences; i++) {
        sentences[i].text = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
        word_count = rand() % 10 + 1;
        for (j = 0; j < word_count; j++) {
            sentences[i].text[j] = 'a' + (rand() % 26);
        }
        sentences[i].length = word_count;
    }

    return sentences;
}

// Function to print sentences
void print_sentences(sentence *sentences, int num_sentences) {
    int i;

    for (i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    srand(time(NULL));
    int num_sentences = LINES_PER_FILE * WORDS_PER_LINE;
    sentence *sentences = generate_sentences(num_sentences);
    print_sentences(sentences, num_sentences);

    return 0;
}