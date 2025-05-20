//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    const word_count *wc1 = (const word_count *)a;
    const word_count *wc2 = (const word_count *)b;

    return wc2->count - wc1->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[1024];
    int words_count = 0;
    word_count *words = malloc(sizeof(word_count) * MAX_WORDS);
    if (words == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        int word_len;
        int i;
        for (i = 0; i < strlen(buf); i++) {
            if (isalpha(buf[i])) {
                word_len = 0;
                while (i < strlen(buf) && isalpha(buf[i])) {
                    words[words_count].word[word_len++] = tolower(buf[i++]);
                }
                words[words_count].word[word_len] = '\0';
                words_count++;
            }
        }
    }

    fclose(fp);

    qsort(words, words_count, sizeof(word_count), compare_word_counts);

    for (int i = 0; i < words_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);

    return EXIT_SUCCESS;
}