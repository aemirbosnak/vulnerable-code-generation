//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char **line) {
    char ch;
    int len = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (len >= MAX_LINE_LENGTH - 1) {
            *line = realloc(*line, sizeof(char) * (len + MAX_LINE_LENGTH));
        }
        (*line)[len++] = ch;
    }
    (*line)[len] = '\0';
}

void tokenize(char *line, WordCount *word_counts, int count) {
    char *token = strtok(line, " \t\r\n\f\v.,!?;:\"'");
    while (token!= NULL && count < MAX_WORD_COUNT) {
        int len = strlen(token);
        if (len > 0 && len <= MAX_WORD_LENGTH) {
            strcpy(word_counts[count].word, token);
            word_counts[count].count = 1;
            count++;
        }
        token = strtok(NULL, " \t\r\n\f\v.,!?;:\"'");
    }
}

void print_word_counts(WordCount *word_counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    WordCount word_counts[MAX_WORD_COUNT];
    int count = 0;

    file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (read > 0 && len > 0) {
            tokenize(line, word_counts, count);
        }
        line[--len] = '\0';
    }

    print_word_counts(word_counts, count);

    free(line);
    fclose(file);

    return 0;
}