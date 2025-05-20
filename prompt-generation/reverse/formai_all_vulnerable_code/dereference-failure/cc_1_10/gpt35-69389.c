//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} word_count;

word_count *word_frequency(char *filename, int *count) {
    FILE *fp;
    char line[1000];
    int i, j, k;
    word_count *wc = NULL;
    int wc_count = 0;
    char *word;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    while (fgets(line, 1000, fp)) {
        i = 0;
        while (line[i]) {
            j = i;
            while (line[j] && isalpha(line[j])) {
                j++;
            }
            if (i != j) {
                // We have found a word.
                if (wc == NULL) {
                    wc = (word_count *) malloc(sizeof(word_count));
                } else {
                    wc = (word_count *) realloc(wc, (wc_count + 1) * sizeof(word_count));
                }
                wc_count++;
                word = (char *) malloc((j - i + 1) * sizeof(char));
                for (k = i; k < j; k++) {
                    word[k - i] = tolower(line[k]);
                }
                word[j - i] = '\0';
                strcpy(wc[wc_count - 1].word, word);
                wc[wc_count - 1].count = 1;
                free(word);
            }
            i = j;
            while (line[i] && !isalpha(line[i])) {
                i++;
            }
        }
    }

    fclose(fp);

    // Sort the word frequency array by word.
    qsort(wc, wc_count, sizeof(word_count), (int (*)(const void *, const void *)) strcmp);

    // Calculate the frequency of each word.
    for (i = 0; i < wc_count; i++) {
        j = i;
        while (j < wc_count && strcmp(wc[i].word, wc[j].word) == 0) {
            j++;
        }
        wc[i].count = j - i;
    }

    *count = wc_count;

    return wc;
}

int main(int argc, char **argv) {
    int i, count;
    word_count *wc;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    wc = word_frequency(argv[1], &count);

    if (wc == NULL) {
        return 0;
    }

    // Print the word frequency table.
    printf("%-20s %s\n", "Word", "Frequency");
    printf("----------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-20s %d\n", wc[i].word, wc[i].count);
    }
    printf("----------------------------------------\n");

    free(wc);

    return 0;
}