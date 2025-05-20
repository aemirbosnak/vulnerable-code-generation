//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *word_frequency_counter(char *text) {
    Word *words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    char *word = NULL;
    int word_length = 0;

    for (int j = 0; text[j] != '\0'; j++) {
        if (word == NULL) {
            word = malloc(20 * sizeof(char));
            word_length = 0;
        }

        if (text[j] != ' ' && text[j] != '\t' && text[j] != '\n') {
            word_length++;
        } else {
            if (word_length > 0) {
                words[i].word = malloc((word_length + 1) * sizeof(char));
                words[i].word = strcpy(words[i].word, word);
                words[i].frequency = 1;
                i++;
            }

            word_length = 0;
            word = NULL;
        }
    }

    return words;
}

int main() {
    char *text = "This is a sample text that will be used to count the frequency of each word. The text contains many different words, including some common words such as the, of, and a. It also contains some less common words, such as moo and bar. The text is long enough to provide a good sample of words.";

    Word *words = word_frequency_counter(text);

    for (int i = 0; words[i].word != NULL; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    free(words);

    return 0;
}