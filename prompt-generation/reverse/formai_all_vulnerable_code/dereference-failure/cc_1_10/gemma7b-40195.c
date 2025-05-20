//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 20

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *word_frequency_counter(char *text) {
    Word *words = NULL;
    char *token = strtok(text, " ");

    // Allocate memory for the words
    words = malloc(sizeof(Word) * MAX_WORD_SIZE);

    // Iterate over the tokens and count their frequency
    int i = 0;
    while (token) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(token, words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
            }
        }
        if (!found) {
            words[i].word = strdup(token);
            words[i].frequency = 1;
            i++;
        }
        token = strtok(NULL, " ");
    }

    return words;
}

int main() {
    char *text = "This is a sample text that I am using to demonstrate the word frequency counter. The text contains many different words, but I am only interested in the words that appear more than once. Can you find the words that appear more than once in this text?";

    Word *words = word_frequency_counter(text);

    // Print the words that appear more than once
    for (int i = 0; words[i].word; i++) {
        if (words[i].frequency > 1) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}