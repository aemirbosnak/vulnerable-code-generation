//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *name;
    int line_num;
} FileLine;

void print_file_lines(FileLine *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s:%d: %s\n", lines[i].name, lines[i].line_num, lines[i].name);
    }
}

int main() {
    char *filename = "example.c";
    int num_lines = 0;
    FileLine *lines = NULL;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        num_lines++;
        lines = realloc(lines, sizeof(FileLine) * num_lines);
        lines[num_lines - 1].name = strdup(filename);
        lines[num_lines - 1].line_num = num_lines;
    }

    fclose(fp);

    print_file_lines(lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].name);
    }
    free(lines);

    return 0;
}