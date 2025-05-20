//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void initialize(WordCount *word_counts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        word_counts[i].count = 0;
    }
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void count_words(char *text, WordCount *word_counts) {
    char *word = strtok(text, " \t\r\n\f\v.,!?;:\"'");
    while (word!= NULL) {
        int i = 0;
        while (i < MAX_WORD_LEN && word[i]!= '\0') {
            word_counts[i].word[i] = tolower(word[i]);
            i++;
        }
        word_counts[i].word[i] = '\0';
        word_counts[i].count++;
        word = strtok(NULL, " \t\r\n\f\v.,!?;:\"'");
    }
}

void print_word_counts(WordCount *word_counts) {
    qsort(word_counts, MAX_WORDS, sizeof(WordCount), compare_strings);
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    char *text = NULL;
    size_t text_size = 0;
    if (fread(text, 1, MAX_WORDS * MAX_WORD_LEN, file)!= 0) {
        printf("Error reading file '%s'.\n", argv[1]);
        fclose(file);
        return 1;
    }

    fclose(file);

    WordCount word_counts[MAX_WORDS];
    initialize(word_counts);

    count_words(text, word_counts);

    print_word_counts(word_counts);

    free(text);

    return 0;
}