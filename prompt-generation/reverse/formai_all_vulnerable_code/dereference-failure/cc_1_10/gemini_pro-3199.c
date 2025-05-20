//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} word_count_t;

int compare_word_count(const void *a, const void *b) {
    return strcmp(((word_count_t *)a)->word, ((word_count_t *)b)->word);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char *buffer = malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    int buffer_size = 1024;
    int buffer_length = 0;
    int word_count = 0;
    word_count_t *word_counts = NULL;

    while ((buffer_length = getline(&buffer, &buffer_size, file)) != -1) {
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                word_count++;
                word_counts = realloc(word_counts, word_count * sizeof(word_count_t));
                word_counts[word_count - 1].word = strdup(token);
                word_counts[word_count - 1].count = 1;
            }

            token = strtok(NULL, " ");
        }
    }

    free(buffer);
    fclose(file);

    qsort(word_counts, word_count, sizeof(word_count_t), compare_word_count);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    for (int i = 0; i < word_count; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}