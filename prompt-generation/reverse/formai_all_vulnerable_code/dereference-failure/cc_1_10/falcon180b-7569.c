//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Function to extract metadata from a given file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        char_count += strlen(line);

        // Extract words from the line
        char *token = strtok(line, " ");
        while (token!= NULL) {
            word_count++;
            strcpy(word, token);
            printf("Word %d: %s\n", word_count, word);
            token = strtok(NULL, " ");
        }
    }

    // Print the total number of words and characters in the file
    printf("Total number of words: %d\n", word_count);
    printf("Total number of characters: %d\n", char_count);
    printf("Total number of lines: %d\n", line_count);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <metadata_type>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *metadata_type = argv[2];

    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    // Extract metadata from the file
    if (strcmp(metadata_type, "word_count") == 0) {
        extract_metadata(file, filename);
    } else if (strcmp(metadata_type, "char_count") == 0) {
        extract_metadata(file, filename);
    } else if (strcmp(metadata_type, "line_count") == 0) {
        extract_metadata(file, filename);
    } else {
        printf("Error: Invalid metadata type '%s'\n", metadata_type);
        return 1;
    }

    // Close the file
    fclose(file);

    return 0;
}