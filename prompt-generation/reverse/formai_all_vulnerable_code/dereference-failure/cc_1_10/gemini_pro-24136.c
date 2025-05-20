//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *title;
    char *author;
    char *description;
    char *keywords;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }
    fread(buffer, file_size, 1, file);
    fclose(file);
    buffer[file_size] = '\0';

    // Extract the metadata from the buffer
    Metadata *metadata = malloc(sizeof(Metadata));
    if (metadata == NULL) {
        free(buffer);
        return NULL;
    }

    // Extract the title
    const char *title_start = strstr(buffer, "<title>");
    if (title_start == NULL) {
        metadata->title = NULL;
    } else {
        const char *title_end = strstr(title_start, "</title>");
        if (title_end == NULL) {
            metadata->title = NULL;
        } else {
            metadata->title = malloc(title_end - title_start - 7 + 1);
            if (metadata->title == NULL) {
                free(metadata);
                free(buffer);
                return NULL;
            }
            memcpy(metadata->title, title_start + 7, title_end - title_start - 7);
            metadata->title[title_end - title_start - 7] = '\0';
        }
    }

    // Extract the author
    const char *author_start = strstr(buffer, "<author>");
    if (author_start == NULL) {
        metadata->author = NULL;
    } else {
        const char *author_end = strstr(author_start, "</author>");
        if (author_end == NULL) {
            metadata->author = NULL;
        } else {
            metadata->author = malloc(author_end - author_start - 8 + 1);
            if (metadata->author == NULL) {
                free(metadata->title);
                free(metadata);
                free(buffer);
                return NULL;
            }
            memcpy(metadata->author, author_start + 8, author_end - author_start - 8);
            metadata->author[author_end - author_start - 8] = '\0';
        }
    }

    // Extract the description
    const char *description_start = strstr(buffer, "<description>");
    if (description_start == NULL) {
        metadata->description = NULL;
    } else {
        const char *description_end = strstr(description_start, "</description>");
        if (description_end == NULL) {
            metadata->description = NULL;
        } else {
            metadata->description = malloc(description_end - description_start - 13 + 1);
            if (metadata->description == NULL) {
                free(metadata->title);
                free(metadata->author);
                free(metadata);
                free(buffer);
                return NULL;
            }
            memcpy(metadata->description, description_start + 13, description_end - description_start - 13);
            metadata->description[description_end - description_start - 13] = '\0';
        }
    }

    // Extract the keywords
    const char *keywords_start = strstr(buffer, "<keywords>");
    if (keywords_start == NULL) {
        metadata->keywords = NULL;
    } else {
        const char *keywords_end = strstr(keywords_start, "</keywords>");
        if (keywords_end == NULL) {
            metadata->keywords = NULL;
        } else {
            metadata->keywords = malloc(keywords_end - keywords_start - 10 + 1);
            if (metadata->keywords == NULL) {
                free(metadata->title);
                free(metadata->author);
                free(metadata->description);
                free(metadata);
                free(buffer);
                return NULL;
            }
            memcpy(metadata->keywords, keywords_start + 10, keywords_end - keywords_start - 10);
            metadata->keywords[keywords_end - keywords_start - 10] = '\0';
        }
    }

    // Free the buffer
    free(buffer);

    // Return the metadata
    return metadata;
}

// Function to print the metadata
void print_metadata(const Metadata *metadata) {
    if (metadata->title != NULL) {
        printf("Title: %s\n", metadata->title);
    }
    if (metadata->author != NULL) {
        printf("Author: %s\n", metadata->author);
    }
    if (metadata->description != NULL) {
        printf("Description: %s\n", metadata->description);
    }
    if (metadata->keywords != NULL) {
        printf("Keywords: %s\n", metadata->keywords);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if a filename was provided
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract the metadata from the file
    Metadata *metadata = extract_metadata(argv[1]);
    if (metadata == NULL) {
        printf("Error extracting metadata from file\n");
        return EXIT_FAILURE;
    }

    // Print the metadata
    print_metadata(metadata);

    // Free the metadata
    free(metadata->title);
    free(metadata->author);
    free(metadata->description);
    free(metadata->keywords);
    free(metadata);

    return EXIT_SUCCESS;
}