//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// A custom metadata extractor function
void extract_metadata(const char *buffer, size_t size, char **title, char **author) {
    // Extract the title
    char *start_title = strstr(buffer, "<title>");
    char *end_title = strstr(start_title, "</title>");
    if (start_title && end_title) {
        *title = malloc(end_title - start_title + 1);
        strncpy(*title, start_title + 7, end_title - start_title - 7);
        (*title)[end_title - start_title - 7] = '\0';
    }

    // Extract the author
    char *start_author = strstr(buffer, "<author>");
    char *end_author = strstr(start_author, "</author>");
    if (start_author && end_author) {
        *author = malloc(end_author - start_author + 1);
        strncpy(*author, start_author + 8, end_author - start_author - 8);
        (*author)[end_author - start_author - 8] = '\0';
    }
}

int main() {
    // Read the input HTML from stdin
    char *buffer = NULL;
    size_t size = 0;
    int status = getline(&buffer, &size, stdin);
    if (status < 0) {
        perror("getline");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Extract the metadata
    char *title = NULL, *author = NULL;
    extract_metadata(buffer, size, &title, &author);

    // Print the metadata
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);

    // Free the allocated memory
    free(buffer);
    free(title);
    free(author);
    return EXIT_SUCCESS;
}