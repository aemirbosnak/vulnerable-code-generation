//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct WordFrequency {
    char word[50];
    int count;
};

int compare(const void *a, const void *b) {
    // This function is used to sort the word frequencies in descending order
    return ((struct WordFrequency *)b)->count - ((struct WordFrequency *)a)->count;
}

void strip_punctuation(char *str) {
    // This function removes punctuation from a string
    char *src = str;
    char *dst = str;

    while (*src) {
        if(ispunct((unsigned char)*src)) {
            src++;
        } else if (src == dst) {
            src++;
            dst++;
        } else {
            *dst++ = *src++;
        }
    }

    *dst = '\0';
}

int main() {
    char input[10000];
    struct WordFrequency *word_freqs = calloc(1000, sizeof(struct WordFrequency)); // Allocate some memory for the word frequency array

    printf("Enter some text:\n");
    fgets(input, 10000, stdin);

    char *word = strtok(input, " \n");

    while (word != NULL) {
        strip_punctuation(word); // Remove any punctuation from the word

        if (strlen(word) > 0) {
            int found = 0;

            for (int i = 0; i < 1000; i++) {
                if (strcmp(word_freqs[i].word, word) == 0) {
                    word_freqs[i].count++;
                    found = 1;
                    break;
                } else if (word_freqs[i].count == 0) {
                    strcpy(word_freqs[i].word, word);
                    word_freqs[i].count = 1;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Ran out of memory");
                return 1;
            }
        }

        word = strtok(NULL, " \n");
    }

    qsort(word_freqs, 1000, sizeof(struct WordFrequency), compare); // Sort the word frequencies in descending order

    printf("The top 10 most frequent words are:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %d\n", i + 1, word_freqs[i].word, word_freqs[i].count);
    }

    free(word_freqs); // Free the memory used by the word frequency array

    return 0;
}