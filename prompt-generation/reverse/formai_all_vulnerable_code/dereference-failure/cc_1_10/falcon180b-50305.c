//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *author;
    char *title;
    char *date;
    char *url;
} metadata_t;

// Function to extract metadata from a given string
metadata_t *extract_metadata(char *input) {
    metadata_t *metadata = malloc(sizeof(metadata_t));

    // Initialize all fields to NULL
    metadata->author = NULL;
    metadata->title = NULL;
    metadata->date = NULL;
    metadata->url = NULL;

    // Parse the input string for metadata
    char *author_start = strstr(input, "author: ");
    if (author_start) {
        metadata->author = strdup(author_start + strlen("author: "));
    }

    char *title_start = strstr(input, "title: ");
    if (title_start) {
        metadata->title = strdup(title_start + strlen("title: "));
    }

    char *date_start = strstr(input, "date: ");
    if (date_start) {
        metadata->date = strdup(date_start + strlen("date: "));
    }

    char *url_start = strstr(input, "url: ");
    if (url_start) {
        metadata->url = strdup(url_start + strlen("url: "));
    }

    return metadata;
}

// Function to print the metadata
void print_metadata(metadata_t *metadata) {
    if (metadata->author) {
        printf("Author: %s\n", metadata->author);
    }

    if (metadata->title) {
        printf("Title: %s\n", metadata->title);
    }

    if (metadata->date) {
        printf("Date: %s\n", metadata->date);
    }

    if (metadata->url) {
        printf("URL: %s\n", metadata->url);
    }
}

// Main function
int main() {
    char *input = "author: John Doe\ntitle: The Adventures of Sherlock Holmes\ndate: 1892-09-01\nurl: www.example.com";
    metadata_t *metadata = extract_metadata(input);
    print_metadata(metadata);

    free(metadata->author);
    free(metadata->title);
    free(metadata->date);
    free(metadata->url);
    free(metadata);

    return 0;
}