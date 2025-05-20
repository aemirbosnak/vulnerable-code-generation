//Falcon-180B DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *word;
    int count;
} WordCount;

void initialize_word_count(WordCount *count) {
    count->word = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
    count->count = 0;
}

void increment_word_count(WordCount *count) {
    count->count++;
}

void print_word_count(WordCount *count) {
    printf("Word: %s, Count: %d\n", count->word, count->count);
}

int compare_words(const void *a, const void *b) {
    WordCount *word_a = (WordCount*)a;
    WordCount *word_b = (WordCount*)b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    WordCount word_count;

    initialize_word_count(&word_count);

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            if (strlen(token) <= MAX_WORD_SIZE) {
                strcpy(word_count.word, token);
                increment_word_count(&word_count);
            }
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(file);

    qsort(word_count.word, strlen(word_count.word), sizeof(char), compare_words);

    printf("Word count:\n");
    for (int i = 0; i < strlen(word_count.word); i++) {
        printf("%.*s ", MAX_WORD_SIZE, word_count.word + i * MAX_WORD_SIZE);
    }

    return 0;
}