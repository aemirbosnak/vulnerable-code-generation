//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

typedef struct {
    char *filename;
    char *line;
    int line_number;
} FileLine;

void read_file(FILE *fp, char *filename, int *line_count) {
    char buffer[MAX_LINE_LEN];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        FileLine *file_line = malloc(sizeof(FileLine));
        file_line->filename = strdup(filename);
        file_line->line = strdup(line);
        file_line->line_number = *line_count;

        *line_count += 1;

        printf("%s:%d: %s\n", file_line->filename, file_line->line_number, file_line->line);
        free(line);
    }

    free(line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    int line_count = 0;
    read_file(fp, filename, &line_count);

    fclose(fp);

    return 0;
}