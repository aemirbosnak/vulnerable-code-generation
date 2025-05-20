//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    const word_count *wa = (const word_count *)a;
    const word_count *wb = (const word_count *)b;
    return wb->count - wa->count;
}

int main(void) {
    char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";
    char *words[MAX_WORDS];
    int word_counts[MAX_WORDS];
    int num_words = 0;
    char *word;

    // Tokenize the text into words.
    word = strtok(text, " ");
    while (word != NULL) {
        words[num_words] = word;
        word_counts[num_words] = 0;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Count the occurrences of each word.
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_counts[i]++;
            }
        }
    }

    // Sort the words by their frequency.
    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

    // Print the top 10 most frequent words.
    printf("The top 10 most frequent words are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", words[i], word_counts[i]);
    }

    return 0;
}