//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000

typedef struct {
    char *line;
    int length;
} Line;

void read_file(const char *filename, Line *lines, int num_lines) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (i < num_lines && fgets(lines[i].line, MAX_LINE_LENGTH, fp)!= NULL) {
        lines[i].length = strlen(lines[i].line);
        i++;
    }

    fclose(fp);
}

void count_words(Line *lines, int num_lines, int *total_words) {
    int i;
    for (i = 0; i < num_lines; i++) {
        char *token = strtok(lines[i].line, " ");
        while (token!= NULL) {
            (*total_words)++;
            token = strtok(NULL, " ");
        }
    }
}

void print_result(int total_words) {
    printf("Total number of words: %d\n", total_words);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <num_lines>\n", argv[0]);
        exit(1);
    }

    int num_lines = atoi(argv[2]);
    Line lines[MAX_NUM_LINES];
    int total_words = 0;

    read_file(argv[1], lines, num_lines);
    count_words(lines, num_lines, &total_words);
    print_result(total_words);

    return 0;
}