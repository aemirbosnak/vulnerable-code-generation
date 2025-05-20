//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *wa = (const word_count_pair *)a;
    const word_count_pair *wb = (const word_count_pair *)b;
    return wb->count - wa->count;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    word_count_pair *word_counts = malloc(sizeof(word_count_pair) * MAX_WORDS);
    if (word_counts == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    int num_words = 0;

    while ((nread = getline(&line, &len, fp)) != -1) {
        char *word;
        while ((word = strtok(line, " \n\t")) != NULL) {
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
        }
    }

    qsort(word_counts, num_words, sizeof(word_count_pair), compare_word_count_pairs);

    for (int i = 0; i < num_words; i++) {
        printf("%s %d\n", word_counts[i].word, word_counts[i].count);
        free(word_counts[i].word);
    }

    free(word_counts);
    free(line);
    fclose(fp);

    return EXIT_SUCCESS;
}