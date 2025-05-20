//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_METADATA_SIZE 1024

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char genre[MAX_LINE_LENGTH];
} Metadata;

void extract_metadata(const char *line, Metadata *metadata) {
    char *token[3];
    char *delim = ":\t ";
    int count = 0;

    while (sscanf(line, "%s%s%s%s", token[0], token[1], token[2], NULL) == 3) {
        if (strcmp(token[0], "Title") == 0) {
            strcpy(metadata->title, token[1]);
        } else if (strcmp(token[0], "Author") == 0) {
            strcpy(metadata->author, token[1]);
        } else if (strcmp(token[0], "Genre") == 0) {
            strcpy(metadata->genre, token[1]);
            count++;
            break;
        }
        line += strlen(line) + strlen(delim);
    }

    if (count == 0) {
        fprintf(stderr, "Invalid metadata line: %s\n", line);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Metadata metadata;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '[') { // Metadata line
            extract_metadata(line + 1, &metadata);
            printf("Title: %s\n", metadata.title);
            printf("Author: %s\n", metadata.author);
            printf("Genre: %s\n", metadata.genre);
        }
    }

    fclose(file);
    return 0;
}

// Input: "[Title: Love's Labour's Lost][Author: William Shakespeare][Genre: Romance]"
// Output:
// Title: Love's Labour's Lost
// Author: William Shakespeare
// Genre: Romance