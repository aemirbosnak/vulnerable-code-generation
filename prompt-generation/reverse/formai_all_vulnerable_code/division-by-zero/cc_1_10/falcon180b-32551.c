//Falcon-180B DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE (10 * 1024 * 1024)

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char *line;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    File f = {
       .filename = argv[1],
       .file = fopen(argv[1], "r"),
       .line_number = 0,
       .line = NULL
    };

    if (f.file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;

    while (getline(&buffer, &buffer_size, f.file)!= -1) {
        if (buffer_size >= MAX_LINE_SIZE) {
            fprintf(stderr, "Error: line too long\n");
            return 1;
        }

        if (f.line!= NULL) {
            free(f.line);
        }

        f.line = strdup(buffer);
        f.line_number++;
    }

    fclose(f.file);

    printf("File: %s\n", f.filename);
    printf("Number of lines: %d\n", f.line_number);
    printf("Longest line: %d\n", strlen(f.line));
    printf("Shortest line: %d\n", strlen(f.line));
    printf("Average line length: %d\n", (int) (strlen(f.line) / f.line_number));

    free(f.line);
    free(buffer);

    return 0;
}