//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *words;

void analyze_sentiment(char *text) {
    // Split the text into words
    char *words_ptr = strtok(text, " ");
    char **words_array = malloc(MAX_WORDS * sizeof(char *));
    int i = 0;
    while (words_ptr) {
        words_array[i++] = strdup(words_ptr);
        words_ptr = strtok(NULL, " ");
    }

    // Create a list of words and their frequencies
    words = malloc(MAX_WORDS * sizeof(Word));
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word = NULL;
        words[i].frequency = 0;
    }

    for (i = 0; words_array[i] != NULL; i++) {
        int found = 0;
        for (int j = 0; words[j].word != NULL; j++) {
            if (strcmp(words_array[i], words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
            }
        }
        if (!found) {
            words[i].word = strdup(words_array[i]);
            words[i].frequency = 1;
        }
    }

    // Free the memory allocated for the words array
    free(words_array);
}

int main() {
    char *text = "I am happy. I am sad. I am angry.";
    analyze_sentiment(text);

    // Print the words and their frequencies
    for (int i = 0; words[i].word != NULL; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    // Free the memory allocated for the words
    free(words);

    return 0;
}