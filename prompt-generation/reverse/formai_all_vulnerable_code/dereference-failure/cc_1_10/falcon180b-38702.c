//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// Struct to hold metadata information
typedef struct {
    char *title;
    char *author;
    char *date;
} metadata_t;

// Function to extract metadata from a line of text
metadata_t extract_metadata(char *line) {
    metadata_t metadata = {NULL, NULL, NULL};
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strcasecmp(token, "Title:") == 0) {
            metadata.title = strdup(strtok(NULL, " "));
        } else if (strcasecmp(token, "Author:") == 0) {
            metadata.author = strdup(strtok(NULL, " "));
        } else if (strcasecmp(token, "Date:") == 0) {
            metadata.date = strdup(strtok(NULL, " "));
        }
        token = strtok(NULL, " ");
    }
    return metadata;
}

// Function to print metadata information
void print_metadata(metadata_t metadata) {
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    metadata_t metadata = {NULL, NULL, NULL};
    char line[MAX_LINE_LENGTH];
    bool found_metadata = false;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata_t line_metadata = extract_metadata(line);
        if (line_metadata.title!= NULL) {
            if (found_metadata) {
                printf("Error: multiple metadata blocks found\n");
                return 1;
            }
            metadata = line_metadata;
            found_metadata = true;
        }
    }

    if (!found_metadata) {
        printf("Error: no metadata found\n");
        return 1;
    }

    print_metadata(metadata);

    fclose(file);
    return 0;
}