//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>

// Define a structure for our metadata
typedef struct {
    char *title;
    char *author;
    char *date;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(FILE *file) {
    char line[1024];
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->title = NULL;
    metadata->author = NULL;
    metadata->date = NULL;

    // Read the first line of the file, which should contain the title
    fgets(line, sizeof(line), file);
    metadata->title = strdup(line);

    // Read the next line of the file, which should contain the author
    fgets(line, sizeof(line), file);
    metadata->author = strdup(line);

    // Read the third line of the file, which should contain the date
    fgets(line, sizeof(line), file);
    metadata->date = strdup(line);

    return metadata;
}

// Function to print metadata
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
}

// Function to free metadata
void free_metadata(Metadata *metadata) {
    free(metadata->title);
    free(metadata->author);
    free(metadata->date);
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    Metadata *metadata = extract_metadata(file);
    if (metadata == NULL) {
        printf("Error extracting metadata from file %s\n", argv[1]);
        return 1;
    }

    print_metadata(metadata);

    free_metadata(metadata);
    fclose(file);

    return 0;
}