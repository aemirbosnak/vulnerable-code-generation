//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256
#define MAX_LINE_LENGTH 1024

// Function prototypes
void read_file(FILE *file);
void extract_metadata(char *line);

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Extract metadata from the line
        extract_metadata(line);
    }

    // Close the file
    fclose(file);

    return 0;
}

// Reads the file and calls the extract_metadata function for each line
void read_file(FILE *file) {
    char line[MAX_LINE_LENGTH];

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Extract metadata from the line
        extract_metadata(line);
    }
}

// Extracts metadata from the given line
void extract_metadata(char *line) {
    char *token;

    // Remove leading/trailing whitespace from the line
    while (isspace(*line)) {
        line++;
    }
    while (isspace(*(line + strlen(line) - 1))) {
        line[strlen(line) - 1] = '\0';
    }

    // Extract the author's name
    token = strtok(line, ",");
    if (token!= NULL) {
        printf("Author: %s\n", token);
    }

    // Extract the title
    token = strtok(NULL, ",");
    if (token!= NULL) {
        printf("Title: %s\n", token);
    }

    // Extract the date
    token = strtok(NULL, ",");
    if (token!= NULL) {
        printf("Date: %s\n", token);
    }
}