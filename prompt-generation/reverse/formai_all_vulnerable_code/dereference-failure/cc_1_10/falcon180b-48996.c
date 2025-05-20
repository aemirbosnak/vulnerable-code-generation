//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_log_file(FILE *fp, char *log_buffer, int *log_size) {
    int ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (i >= *log_size - 1) {
            *log_size += MAX_LOG_SIZE;
            log_buffer = realloc(log_buffer, *log_size);
        }

        log_buffer[i++] = ch;
    }

    log_buffer[i] = '\0';
}

void tokenize_log_buffer(char *log_buffer, WordCount *word_counts, int num_word_counts) {
    char *token;
    int i = 0;

    while ((token = strtok(log_buffer, " \t\r\n"))!= NULL) {
        if (i >= num_word_counts) {
            num_word_counts += 10;
            word_counts = realloc(word_counts, num_word_counts * sizeof(WordCount));
        }

        strcpy(word_counts[i].word, token);
        word_counts[i].count = 1;
        i++;
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char log_buffer[MAX_LOG_SIZE];
    int log_size = 0;
    WordCount word_counts[10];
    int num_word_counts = 0;

    fp = fopen("example.log", "r");

    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    read_log_file(fp, log_buffer, &log_size);

    tokenize_log_buffer(log_buffer, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    fclose(fp);

    return 0;
}