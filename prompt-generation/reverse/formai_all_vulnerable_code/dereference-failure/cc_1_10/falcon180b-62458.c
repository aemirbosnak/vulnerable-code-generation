//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *filename;
    int line_count;
    int word_count;
} FileStats;

void count_words(char *line, char **words) {
    char *token = strtok(line, " ");
    int count = 0;
    while (token!= NULL) {
        if (strlen(token) > 0) {
            words[count] = token;
            count++;
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./program <log_file>\n");
        exit(1);
    }

    char log_file[MAX_LINE_LENGTH];
    strcpy(log_file, argv[1]);

    FILE *fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    FileStats stats = {0};
    char line[MAX_LINE_LENGTH];
    char *words[MAX_WORD_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        stats.line_count++;
        count_words(line, words);
        stats.word_count += strlen(line) - 1; // exclude newline character
    }
    fclose(fp);

    printf("File Stats:\n");
    printf("Filename: %s\n", stats.filename);
    printf("Line Count: %d\n", stats.line_count);
    printf("Word Count: %d\n", stats.word_count);

    return 0;
}