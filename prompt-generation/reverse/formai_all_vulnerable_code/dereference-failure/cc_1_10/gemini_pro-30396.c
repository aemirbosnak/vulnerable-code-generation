//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure.
typedef struct {
    char *title;
    char *author;
    char *date;
    char *description;
} metadata_t;

// Define the function to extract the metadata from a file.
metadata_t *extract_metadata(FILE *file) {
    // Allocate memory for the metadata structure.
    metadata_t *metadata = malloc(sizeof(metadata_t));

    // Read the first line of the file.
    char line[1024];
    fgets(line, sizeof(line), file);

    // Extract the title from the first line.
    char *title = strtok(line, "|");

    // Extract the author from the second line.
    fgets(line, sizeof(line), file);
    char *author = strtok(line, "|");

    // Extract the date from the third line.
    fgets(line, sizeof(line), file);
    char *date = strtok(line, "|");

    // Extract the description from the fourth line.
    fgets(line, sizeof(line), file);
    char *description = strtok(line, "|");

    // Store the metadata in the structure.
    metadata->title = title;
    metadata->author = author;
    metadata->date = date;
    metadata->description = description;

    // Return the metadata structure.
    return metadata;
}

// Define the function to print the metadata.
void print_metadata(metadata_t *metadata) {
    // Print the title.
    printf("Title: %s\n", metadata->title);

    // Print the author.
    printf("Author: %s\n", metadata->author);

    // Print the date.
    printf("Date: %s\n", metadata->date);

    // Print the description.
    printf("Description: %s\n", metadata->description);
}

// Define the main function.
int main(int argc, char **argv) {
    // Check if the user has specified a file name.
    if (argc != 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    // Open the file.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Extract the metadata from the file.
    metadata_t *metadata = extract_metadata(file);

    // Print the metadata.
    print_metadata(metadata);

    // Free the memory allocated for the metadata structure.
    free(metadata);

    // Close the file.
    fclose(file);

    return 0;
}