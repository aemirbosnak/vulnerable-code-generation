//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 1000

typedef struct {
    char *line;
    int line_number;
} log_line;

log_line *log_lines;
int num_log_lines;

void read_log_file(char *filename) {
    FILE *fp;
    char line[MAX_LOG_LINE_LENGTH];
    int line_number = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    while (fgets(line, MAX_LOG_LINE_LENGTH, fp) != NULL) {
        log_lines[line_number].line = strdup(line);
        log_lines[line_number].line_number = line_number;
        line_number++;
    }

    fclose(fp);

    num_log_lines = line_number;
}

void print_log_lines() {
    int i;

    for (i = 0; i < num_log_lines; i++) {
        printf("%d: %s", log_lines[i].line_number, log_lines[i].line);
    }
}

void free_log_lines() {
    int i;

    for (i = 0; i < num_log_lines; i++) {
        free(log_lines[i].line);
    }

    free(log_lines);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    log_lines = malloc(sizeof(log_line) * MAX_LOG_LINES);
    if (log_lines == NULL) {
        perror("Error allocating memory for log lines");
        exit(1);
    }

    read_log_file(argv[1]);
    print_log_lines();
    free_log_lines();

    return 0;
}