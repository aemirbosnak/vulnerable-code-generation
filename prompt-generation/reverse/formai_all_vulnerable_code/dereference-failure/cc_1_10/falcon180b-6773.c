//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1000

typedef struct {
    char *line;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Log;

void read_log_file(const char *filename, Log *log) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int line_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open %s\n", filename);
        exit(1);
    }

    while ((getline(&line, &len, fp))!= -1) {
        if (line_num >= MAX_LINES) {
            fprintf(stderr, "Error: log file has too many lines\n");
            exit(1);
        }
        log->lines[line_num] = (Line) {
           .line = strdup(line),
           .line_num = line_num,
        };
        line_num++;
    }

    free(line);
    fclose(fp);
}

void print_log(const Log *log) {
    for (int i = 0; i < log->num_lines; i++) {
        printf("%d: %s\n", log->lines[i].line_num, log->lines[i].line);
    }
}

int main() {
    Log log;
    read_log_file("example.log", &log);
    print_log(&log);
    for (int i = 0; i < log.num_lines; i++) {
        free(log.lines[i].line);
    }
    free(log.lines);
    return 0;
}