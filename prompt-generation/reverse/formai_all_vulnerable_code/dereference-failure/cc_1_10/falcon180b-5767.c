//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char *word;
    int count;
} WordCount;

void split_line(char *line, char **words) {
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        *words++ = word;
        word = strtok(NULL, ",.?!;:");
    }
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void count_words(char **words, int num_words, WordCount *word_counts) {
    qsort(words, num_words, sizeof(char *), compare_words);

    for (int i = 0; i < num_words; i++) {
        WordCount *word_count = word_counts + i;
        word_count->word = strdup(words[i]);
        word_count->count = 1;
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        WordCount *word_count = word_counts + i;
        printf("%s: %d\n", word_count->word, word_count->count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LEN];
    char *filename = argv[1];

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    WordCount *word_counts = calloc(MAX_WORD_LEN, sizeof(WordCount));
    int num_words = 0;

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        char *words[MAX_WORD_LEN];
        split_line(line, words);

        count_words(words, strlen(line), word_counts);
        num_words += strlen(line);

        if (num_words >= MAX_WORD_LEN) {
            printf("Warning: maximum number of words (%d) reached\n", MAX_WORD_LEN);
            break;
        }
    }

    print_word_counts(word_counts, num_words);

    fclose(file);

    return 0;
}