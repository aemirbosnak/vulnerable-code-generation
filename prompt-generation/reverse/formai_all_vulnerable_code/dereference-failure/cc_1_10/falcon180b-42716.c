//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
} LogAnalysis;

void read_log_file(FILE *fp, LogAnalysis *la) {
    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            WordCount wc = {.word = token,.count = 1};
            int i;
            for (i = 0; i < la->num_words; i++) {
                if (strcmp(la->words[i].word, token) == 0) {
                    la->words[i].count++;
                    break;
                }
            }
            if (i == la->num_words) {
                la->num_words++;
                la->words = realloc(la->words, la->num_words * sizeof(WordCount));
                la->words[la->num_words - 1] = wc;
            }
            token = strtok(NULL, " ");
        }
    }
}

void print_word_counts(LogAnalysis la) {
    int i;
    for (i = 0; i < la.num_words; i++) {
        printf("%s: %d\n", la.words[i].word, la.words[i].count);
    }
}

int main() {
    FILE *fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    LogAnalysis la = {.words = NULL,.num_words = 0};
    read_log_file(fp, &la);

    print_word_counts(la);

    free(la.words);
    fclose(fp);

    return 0;
}