//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *words;

void incrementWord(char *word) {
    Word *w = words;
    for (int i = 0; w && i < MAX_WORDS; i++) {
        if (strcmp(w->word, word) == 0) {
            w->frequency++;
            return;
        }
        w++;
    }

    words = realloc(words, (MAX_WORDS + 1) * sizeof(Word));
    w = words;
    w->word = strdup(word);
    w->frequency = 1;
}

int main() {
    words = malloc(MAX_WORDS * sizeof(Word));

    // Simulate post-apocalyptic environment
    char *text = "The ruins of the city once shone brightly, but now only remnants remain. The wind howls through the streets, carrying with it the scent of decay and despair. A lone survivor, scavenging for supplies, stumbled upon a hidden cache, its contents a testament to the former glory of the once-thriving metropolis.";

    // Increment words in the text
    char *word = strtok(text, " ");
    while (word) {
        incrementWord(word);
        word = strtok(NULL, " ");
    }

    // Print the most frequent words
    Word *w = words;
    printf("The most frequent words in the text are:\n");
    for (int i = 0; w && i < MAX_WORDS; i++) {
        printf("%s: %d\n", w->word, w->frequency);
        w++;
    }

    free(words);
    return 0;
}