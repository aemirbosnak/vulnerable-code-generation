//Falcon-180B DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

void initialize_word_count_table(WordCount *table, int size) {
    for (int i = 0; i < size; ++i) {
        table[i].word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
        table[i].count = 0;
    }
}

void destroy_word_count_table(WordCount *table, int size) {
    for (int i = 0; i < size; ++i) {
        free(table[i].word);
    }
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

void count_words(char *line, WordCount *table, int size) {
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        int index = 0;
        while (index < size && table[index].word!= NULL) {
            if (strcmp(table[index].word, word) == 0) {
                table[index].count++;
                break;
            }
            ++index;
        }
        if (index == size) {
            table[index].word = strdup(word);
            table[index].count = 1;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void print_word_count_table(WordCount *table, int size) {
    qsort(table, size, sizeof(WordCount), compare_words);
    for (int i = 0; i < size; ++i) {
        printf("%s: %d\n", table[i].word, table[i].count);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount *word_count_table = (WordCount *) malloc(100 * sizeof(WordCount));
    initialize_word_count_table(word_count_table, 100);

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        count_words(line, word_count_table, 100);
    }

    fclose(input_file);

    print_word_count_table(word_count_table, 100);

    destroy_word_count_table(word_count_table, 100);

    return 0;
}