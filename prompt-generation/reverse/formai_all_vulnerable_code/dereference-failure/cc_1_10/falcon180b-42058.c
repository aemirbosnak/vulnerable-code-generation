//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char *name;
    int line_number;
} Line;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char *file_name = argv[1];
    int file_name_length = strlen(file_name);
    if (file_name_length > MAX_FILE_NAME_SIZE) {
        printf("Error: file name too long\n");
        return 1;
    }

    Line *lines = NULL;
    int line_number = 0;
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int line_length = strlen(line);
        if (line_length > MAX_LINE_SIZE - 1) {
            printf("Error: line too long\n");
            return 1;
        }

        char *line_copy = malloc(line_length + 1);
        strcpy(line_copy, line);
        lines = realloc(lines, sizeof(Line) * ++line_number);
        lines[line_number - 1].name = line_copy;
        lines[line_number - 1].line_number = line_number;
    }

    fclose(file);

    printf("File: %s\n", file_name);
    printf("Line number\tLine\n");
    for (int i = 0; i < line_number; i++) {
        printf("%d\t%s\n", lines[i].line_number, lines[i].name);
    }

    free(lines);
    return 0;
}