//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void initialize_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }
}

void count_words(WordCount *word_counts, char *line, int num_words) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *log_file = fopen("log_file.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    int num_words = 0;
    char word[MAX_WORD_SIZE];
    fscanf(log_file, "%s", word);
    while (strcmp(word, "")!= 0) {
        num_words++;
        WordCount *word_counts = malloc(num_words * sizeof(WordCount));
        initialize_word_counts(word_counts, num_words);
        fscanf(log_file, "%s", word);
        while (strcmp(word, "")!= 0) {
            count_words(word_counts, word, num_words);
            fscanf(log_file, "%s", word);
        }
        print_word_counts(word_counts, num_words);
        free(word_counts);
        fscanf(log_file, "%s", word);
    }

    fclose(log_file);
    return 0;
}