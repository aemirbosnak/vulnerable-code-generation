//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} word_freq;

// Compare function for qsort
int freq_cmp(const void *a, const void *b) {
    const word_freq *ia = (const word_freq *)a;
    const word_freq *ib = (const word_freq *)b;
    return ib->count - ia->count; // Sort in descending order
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input-file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Count the frequency of each word
    word_freq *freq = malloc(sizeof(word_freq));
    int num_words = 0;
    char word_buf[MAX_WORD_LEN+1];
    while (fscanf(fp, "%s", word_buf) != EOF) {
        int found = 0;
        // Convert to lowercase
        for (int i = 0; i < strlen(word_buf); i++) {
            word_buf[i] = tolower(word_buf[i]);
        }
        // Check if word is already in the frequency array
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_buf, freq[i].word) == 0) {
                freq[i].count++;
                found = 1;
                break;
            }
        }
        // Add new word to frequency array
        if (!found) {
            freq = realloc(freq, sizeof(word_freq) * (num_words + 1));
            freq[num_words].word = malloc(strlen(word_buf) + 1);
            strcpy(freq[num_words].word, word_buf);
            freq[num_words].count = 1;
            num_words++;
        }
    }

    // Sort the frequency array
    qsort(freq, num_words, sizeof(word_freq), freq_cmp);

    // Print the results
    printf("Word\t\tFrequency\n");
    printf("==========================\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s %d\n", freq[i].word, freq[i].count);
    }

    // Cleanup
    for (int i = 0; i < num_words; i++) {
        free(freq[i].word);
    }
    free(freq);
    fclose(fp);

    return 0;
}