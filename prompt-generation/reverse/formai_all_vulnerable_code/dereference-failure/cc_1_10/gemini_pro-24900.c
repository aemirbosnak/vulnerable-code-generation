//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Custom metadata structure
typedef struct {
    char *title;
    char *author;
    int year;
    bool has_cover;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(const char *filename) {
    // Open the file for reading
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the metadata
    Metadata *metadata = malloc(sizeof(Metadata));
    if (!metadata) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Initialize the metadata
    metadata->title = NULL;
    metadata->author = NULL;
    metadata->year = 0;
    metadata->has_cover = false;

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Extract the title
        if (sscanf(line, "Title: %s", metadata->title) == 1) {
            metadata->title = strdup(metadata->title);
            continue;
        }

        // Extract the author
        if (sscanf(line, "Author: %s", metadata->author) == 1) {
            metadata->author = strdup(metadata->author);
            continue;
        }

        // Extract the year
        if (sscanf(line, "Year: %d", &metadata->year) == 1) {
            continue;
        }

        // Extract the cover status
        if (sscanf(line, "Has cover: %s", metadata->has_cover) == 1) {
            continue;
        }
    }

    // Close the file
    fclose(fp);

    // Return the metadata
    return metadata;
}

// Function to print the metadata
void print_metadata(const Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Year: %d\n", metadata->year);
    printf("Has cover: %s\n", metadata->has_cover ? "Yes" : "No");
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract the metadata from the file
    Metadata *metadata = extract_metadata(argv[1]);
    if (!metadata) {
        return EXIT_FAILURE;
    }

    // Print the metadata
    print_metadata(metadata);

    // Free the memory allocated for the metadata
    free(metadata->title);
    free(metadata->author);
    free(metadata);

    return EXIT_SUCCESS;
}