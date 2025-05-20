//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Struct to hold metadata information
typedef struct {
    char* author;
    char* title;
    char* date;
} Metadata;

// Function to extract metadata from a line of text
Metadata* extract_metadata(char* line) {
    Metadata* metadata = malloc(sizeof(Metadata));
    char* token = strtok(line, ":");
    metadata->author = strdup(token);

    token = strtok(NULL, ":");
    metadata->title = strdup(token);

    token = strtok(NULL, ":");
    metadata->date = strdup(token);

    return metadata;
}

// Function to print metadata in a formatted way
void print_metadata(Metadata* metadata) {
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n\n", metadata->date);
}

// Function to read a file and extract metadata
void extract_metadata_from_file(FILE* file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Metadata* metadata = extract_metadata(line);
        print_metadata(metadata);
        free(metadata->author);
        free(metadata->title);
        free(metadata->date);
        free(metadata);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    extract_metadata_from_file(file);

    fclose(file);
    return 0;
}