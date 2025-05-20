//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUMBER_OF_LINES 100

// Function to generate a random word from a list of words
char *get_random_word(char *words[], int num_words) {
    int i = rand() % num_words;
    return words[i];
}

// Function to generate a random sentence from a list of sentences
char *get_random_sentence(char *sentences[], int num_sentences) {
    int i = rand() % num_sentences;
    int j = rand() % strlen(sentences[i]);
    char *sentence = malloc(strlen(sentences[i]) + 1);
    for (int k = 0; k < j; k++) {
        sentence[k] = sentences[i][k];
    }
    sentence[j] = '\0';
    return sentence;
}

int main() {
    // List of words
    char words[MAX_NUMBER_OF_LINES][MAX_LINE_LENGTH] = {
        "The", "cat", "sat", "on", "the", "mat",
        "The", "dog", "ran", "away", "with", "the", "bone",
        "The", "sun", "was", "shining", "bright", "and", "warm",
        "The", "birds", "were", "singing", "their", "songs",
    };

    // List of sentences
    char sentences[MAX_NUMBER_OF_LINES][MAX_LINE_LENGTH] = {
        "The cat sat on the mat.",
        "The dog ran away with the bone.",
        "The sun was shining bright and warm.",
        "The birds were singing their songs.",
    };

    int num_words = sizeof(words) / sizeof(words[0]);
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);

    // Randomly select a word and a sentence
    char *word = get_random_word(words, num_words);
    char *sentence = get_random_sentence(sentences, num_sentences);

    // Print the selected word and sentence
    printf("The %s %s\n", word, sentence);

    return 0;
}