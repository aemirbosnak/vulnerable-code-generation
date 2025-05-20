//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a custom metadata structure.
typedef struct {
    char *title;
    char *author;
    char *date;
    int word_count;
} Metadata;

// Function to extract metadata from a text file.
Metadata *extract_metadata(char *filename) {
    // Open the file.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the first line of the file.
    char line[1024];
    fgets(line, sizeof(line), file);

    // Parse the title from the first line.
    char *title = strtok(line, "|");

    // Read the second line of the file.
    fgets(line, sizeof(line), file);

    // Parse the author from the second line.
    char *author = strtok(line, "|");

    // Read the third line of the file.
    fgets(line, sizeof(line), file);

    // Parse the date from the third line.
    char *date = strtok(line, "|");

    // Read the fourth line of the file.
    fgets(line, sizeof(line), file);

    // Parse the word count from the fourth line.
    int word_count = atoi(strtok(line, "|"));

    // Close the file.
    fclose(file);

    // Create a new metadata structure.
    Metadata *metadata = malloc(sizeof(Metadata));

    // Set the metadata fields.
    metadata->title = strdup(title);
    metadata->author = strdup(author);
    metadata->date = strdup(date);
    metadata->word_count = word_count;

    // Return the metadata structure.
    return metadata;
}

// Function to print the metadata.
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
    printf("Word count: %d\n", metadata->word_count);
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if a filename was specified.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file.
    Metadata *metadata = extract_metadata(argv[1]);

    // Check if the metadata was successfully extracted.
    if (metadata == NULL) {
        printf("Error extracting metadata from file.\n");
        return 1;
    }

    // Print the metadata.
    print_metadata(metadata);

    // Free the metadata structure.
    free(metadata->title);
    free(metadata->author);
    free(metadata->date);
    free(metadata);

    return 0;
}