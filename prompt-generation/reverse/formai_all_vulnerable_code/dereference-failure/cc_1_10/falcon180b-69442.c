//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    int linenumber;
} Error;

void handle_error(Error *error) {
    printf("Error in file %s at line %d:\n", error->filename, error->linenumber);
    exit(1);
}

void read_file(const char *filename, char **lines, int *num_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error(&(Error){.filename = filename,.linenumber = 0});
    }

    char *line = NULL;
    size_t len = 0;
    int num_lines_read = 0;

    *lines = NULL;
    *num_lines = 0;

    while (getline(&line, &len, file)!= -1) {
        if (num_lines_read >= *num_lines) {
            *num_lines += 10; // Increase the number of lines by 10 if we run out of space
            *lines = realloc(*lines, *num_lines * sizeof(char *));
        }
        (*lines)[num_lines_read] = strdup(line);
        num_lines_read++;
    }

    if (ferror(file)) {
        handle_error(&(Error){.filename = filename,.linenumber = num_lines_read});
    }

    fclose(file);
}

int main() {
    char **lines = NULL;
    int num_lines = 0;

    read_file("example.txt", &lines, &num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}