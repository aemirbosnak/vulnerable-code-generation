//Falcon-180B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int count;
};

void initialize_word_frequency(struct WordFrequency *word_frequency) {
    memset(word_frequency, 0, sizeof(struct WordFrequency) * MAX_WORD_COUNT);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *word;
    int line_count = 0;
    int word_count = 0;
    struct WordFrequency *word_frequency = malloc(sizeof(struct WordFrequency) * MAX_WORD_COUNT);
    initialize_word_frequency(word_frequency);

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        exit(2);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_frequency, MAX_WORD_COUNT, sizeof(struct WordFrequency), compare_words);

    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Top 10 most frequent words:\n");

    for (int i = 0; i < 10 && i < MAX_WORD_COUNT; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].count);
    }

    free(word_frequency);
    fclose(input_file);

    return 0;
}