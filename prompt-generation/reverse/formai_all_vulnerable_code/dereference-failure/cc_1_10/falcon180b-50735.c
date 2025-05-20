//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256
#define MAX_COMMENT_LENGTH 256

typedef struct {
    char *filename;
    int line_number;
    char *comment;
} metadata_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    metadata_t metadata = {0};
    char line[MAX_LINE_LENGTH];
    char comment[MAX_COMMENT_LENGTH] = {0};
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *comment_start = strstr(line, "//");
        if (comment_start!= NULL) {
            char *comment_end = strchr(comment_start, '\n');
            if (comment_end!= NULL) {
                *comment_end = '\0';
            }

            strncat(comment, comment_start + 2, MAX_COMMENT_LENGTH - strlen(comment) - 1);
        }

        if (metadata.filename == NULL) {
            metadata.filename = strdup(argv[1]);
        }

        if (metadata.line_number == 0) {
            metadata.line_number = line_number;
        }

        metadata.comment = strdup(comment);
        printf("Line %d: %s\n", line_number, line);
        line_number++;
    }

    fclose(file);

    printf("Metadata:\n");
    printf("Filename: %s\n", metadata.filename);
    printf("Line number: %d\n", metadata.line_number);
    printf("Comment: %s\n", metadata.comment);

    free(metadata.filename);
    free(metadata.comment);

    return 0;
}