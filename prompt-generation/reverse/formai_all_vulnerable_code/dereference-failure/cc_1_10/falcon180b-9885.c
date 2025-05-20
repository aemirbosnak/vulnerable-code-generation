//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int num_words = 0;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));
    if (word_counts == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        struct word_count *wc = word_counts + num_words;
        strcpy(wc->word, word);
        wc->count = 1;
        num_words++;
    }

    fclose(fp);

    printf("Number of words: %d\n", num_words);

    double threshold = 0.05; // Spam threshold
    int num_spam = 0;

    for (int i = 0; i < num_words; i++) {
        struct word_count *wc = word_counts + i;
        if (wc->count > (double)num_words * threshold) {
            printf("%s is a spam word with count %d\n", wc->word, wc->count);
            num_spam++;
        }
    }

    printf("Number of spam words: %d\n", num_spam);

    free(word_counts);
    return 0;
}