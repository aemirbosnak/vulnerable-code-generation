//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
// Declaring the metadata structure
struct Metadata {
    char *title;
    char *author;
    char *date;
    char *keywords;
    char *description;
};

// Declaring the function to extract metadata
struct Metadata *extract_metadata(char *filename) {
    // Creating a new metadata object
    struct Metadata *metadata = malloc(sizeof(struct Metadata));

    // Opening the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    // Reading the file
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        // Checking for the title
        if (strstr(line, "Title: ")) {
            metadata->title = strdup(line + 7);
        }
        // Checking for the author
        else if (strstr(line, "Author: ")) {
            metadata->author = strdup(line + 8);
        }
        // Checking for the date
        else if (strstr(line, "Date: ")) {
            metadata->date = strdup(line + 6);
        }
        // Checking for the keywords
        else if (strstr(line, "Keywords: ")) {
            metadata->keywords = strdup(line + 10);
        }
        // Checking for the description
        else if (strstr(line, "Description: ")) {
            metadata->description = strdup(line + 12);
        }
    }

    // Closing the file
    fclose(file);

    // Returning the metadata object
    return metadata;
}

// Declaring the function to print metadata
void print_metadata(struct Metadata *metadata) {
    // Printing the title
    printf("Title: %s\n", metadata->title);

    // Printing the author
    printf("Author: %s\n", metadata->author);

    // Printing the date
    printf("Date: %s\n", metadata->date);

    // Printing the keywords
    printf("Keywords: %s\n", metadata->keywords);

    // Printing the description
    printf("Description: %s\n", metadata->description);
}

// Declaring the main function
int main() {
    // Extracting metadata from a file
    struct Metadata *metadata = extract_metadata("metadata.txt");

    // Printing the metadata
    print_metadata(metadata);

    // Freeing the metadata object
    free(metadata);

    return 0;
}