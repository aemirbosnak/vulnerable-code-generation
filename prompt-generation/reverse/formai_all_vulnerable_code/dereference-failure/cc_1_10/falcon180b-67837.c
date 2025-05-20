//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
    int linenumber;
} file_t;

void init_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (!file->fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    file->linenumber = 0;
}

void close_file(file_t *file) {
    if (file->fp) {
        fclose(file->fp);
        file->fp = NULL;
    }
    free(file->filename);
}

char *read_line(file_t *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    do {
        read = getline(&line, &len, file->fp);
        if (read == -1) {
            if (ferror(file->fp)) {
                fprintf(stderr, "Error: Failed to read line from file '%s'\n", file->filename);
                exit(1);
            } else {
                break;
            }
        }
    } while (line[read - 1]!= '\n' && read == MAX_LINE_LENGTH - 1);

    if (line) {
        line[read - 1] = '\0'; // Remove newline character
    }

    return line;
}

int main() {
    file_t file;
    char *line;

    init_file(&file, "example.txt");

    while ((line = read_line(&file))!= NULL) {
        printf("Line %d: %s\n", file.linenumber++, line);
    }

    close_file(&file);

    return 0;
}