//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_FREQ 200

struct WordFreq {
    char word[MAX_WORD_LENGTH+1];
    int freq;
};

void remove_punctuation(char *s) {
    for (int i = 0; s[i]; i++) {
        if (ispunct((unsigned char)s[i]))
            memmove(&s[i], &s[i+1], strlen(&s[i+1])+1);
    }
}

int compare_freq(const void *pa, const void *pb) {
    const struct WordFreq *a = *(const struct WordFreq **)pa;
    const struct WordFreq *b = *(const struct WordFreq **)pb;
    return b->freq - a->freq;
}

int main() {
    char buffer[MAX_WORD_LENGTH+1];
    struct WordFreq *freq[MAX_WORDS];
    int num_words = 0;

    // read words from input, remove punctuation and convert to lowercase
    while (scanf("%50s", buffer) == 1) {
        remove_punctuation(buffer);
        for (int i = 0; buffer[i]; i++)
            buffer[i] = tolower((unsigned char)buffer[i]);

        // search for the word in the list of frequencies
        int i = 0;
        for (; i < num_words; i++) {
            if (strcmp(buffer, freq[i]->word) == 0) {
                freq[i]->freq++;
                break;
            }
        }

        // add the word to the list of frequencies if it is not already present
        if (i == num_words) {
            struct WordFreq *word = malloc(sizeof(struct WordFreq));
            strncpy(word->word, buffer, MAX_WORD_LENGTH+1);
            word->freq = 1;
            freq[num_words++] = word;
        }
    }

    // sort the list of frequencies by decreasing frequency
    qsort(freq, num_words, sizeof(struct WordFreq *), compare_freq);

    // print the top 10 most frequent words
    int max_display = (num_words > MAX_FREQ ? MAX_FREQ : num_words);
    for (int i = 0; i < max_display; i++)
        printf("%3d: %s\n", freq[i]->freq, freq[i]->word);

    // free memory
    for (int i = 0; i < num_words; i++)
        free(freq[i]);
    return 0;
}