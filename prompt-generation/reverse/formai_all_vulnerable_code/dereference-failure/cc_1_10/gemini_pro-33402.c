//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_count {
    char *word;
    int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
    word_count *wa = (word_count *)a;
    word_count *wb = (word_count *)b;
    return strcmp(wa->word, wb->word);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *buffer = malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    int num_words = 0;
    int size = 10;
    word_count *word_counts = malloc(sizeof(word_count) * size);
    if (word_counts == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, 1024, fp)) {
        char *word = strtok(buffer, " \n\t");
        while (word) {
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (num_words == size) {
                    size *= 2;
                    word_counts = realloc(word_counts, sizeof(word_count) * size);
                    if (word_counts == NULL) {
                        perror("realloc");
                        return EXIT_FAILURE;
                    }
                }
                word_counts[num_words].word = strdup(word);
                if (word_counts[num_words].word == NULL) {
                    perror("strdup");
                    return EXIT_FAILURE;
                }
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " \n\t");
        }
    }

    fclose(fp);

    qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);
    free(buffer);

    return EXIT_SUCCESS;
}