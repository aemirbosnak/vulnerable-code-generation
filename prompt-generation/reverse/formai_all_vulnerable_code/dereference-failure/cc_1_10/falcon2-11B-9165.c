//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *filename;
    int num_lines;
    int num_words;
    int num_chars;
} LogFileStats;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    char *logfile = argv[1];

    FILE *fp = fopen(logfile, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open %s for reading.\n", logfile);
        return 1;
    }

    LogFileStats stats;
    stats.filename = strdup(logfile);
    stats.num_lines = 0;
    stats.num_words = 0;
    stats.num_chars = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        stats.num_lines++;
        stats.num_words += count_words(line);
        stats.num_chars += strlen(line);
    }

    fclose(fp);

    printf("Log file stats:\n");
    printf("Filename: %s\n", stats.filename);
    printf("Number of lines: %d\n", stats.num_lines);
    printf("Number of words: %d\n", stats.num_words);
    printf("Number of characters: %d\n", stats.num_chars);

    free(stats.filename);

    return 0;
}

int count_words(const char *str) {
    int count = 0;
    for (; *str; str++) {
        if (isspace(*str)) {
            count++;
        }
    }
    return count;
}