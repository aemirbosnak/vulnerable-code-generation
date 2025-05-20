//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000
#define DELIMITER " "

typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *) a;
    WordCount *wc2 = (WordCount *) b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

void process_line(char *line, int *word_count) {
    char *token;
    int len = strlen(line);

    // Remove leading/trailing spaces
    while (isspace(line[0])) {
        line++;
        len--;
    }
    while (isspace(line[len - 1])) {
        line[--len] = '\0';
    }

    // Count words
    int i = 0;
    char *delimiter = strdup(DELIMITER);
    token = strtok(line, delimiter);
    while (token!= NULL) {
        word_count[i++]++;
        token = strtok(NULL, delimiter);
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_SIZE];
    int word_count[MAX_SIZE];
    int num_words = 0;

    fp = fopen("logfile.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        process_line(line, word_count);
        num_words += 1;
    }

    WordCount *word_counts = malloc(num_words * sizeof(WordCount));

    for (int i = 0; i < num_words; i++) {
        strcpy(word_counts[i].word, "");
        word_counts[i].count = 0;
    }

    for (int i = 0; i < num_words; i++) {
        strcpy(word_counts[i].word, "");
        for (int j = 0; j < num_words; j++) {
            if (strcmp(word_count[j], "") == 0) {
                continue;
            }
            if (strcmp(word_count[j], "") == 0) {
                continue;
            }
            if (strcmp(word_counts[i].word, word_count[j]) == 0) {
                word_counts[i].count += word_count[j];
            } else {
                strcpy(word_counts[i].word, word_count[j]);
                word_counts[i].count = word_count[j];
            }
        }
    }

    print_word_counts(word_counts, num_words);

    fclose(fp);

    return 0;
}