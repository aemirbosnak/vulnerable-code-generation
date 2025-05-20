//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    char *author;
    char *title;
    char *date;
} Metadata;

Metadata parse_metadata(char *line) {
    Metadata metadata = {0};
    char *delimiter = ": ";
    char *token;

    // Extract the filename
    token = strtok(line, delimiter);
    metadata.filename = strdup(token);

    // Extract the author
    token = strtok(NULL, delimiter);
    metadata.author = strdup(token);

    // Extract the title
    token = strtok(NULL, delimiter);
    metadata.title = strdup(token);

    // Extract the date
    token = strtok(NULL, delimiter);
    metadata.date = strdup(token);

    return metadata;
}

void print_metadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("Author: %s\n", metadata.author);
    printf("Title: %s\n", metadata.title);
    printf("Date: %s\n", metadata.date);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Metadata metadata;
    int line_number = 0;

    // Open the file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;

        // Parse the metadata from the line
        metadata = parse_metadata(line);

        // Print the metadata
        printf("Metadata for line %d:\n", line_number);
        print_metadata(metadata);
    }

    // Close the file
    fclose(file);

    return 0;
}