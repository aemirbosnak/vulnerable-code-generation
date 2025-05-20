//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata tags
#define TITLE "Title"
#define ARTIST "Artist"
#define ALBUM "Album"
#define YEAR "Year"
#define GENRE "Genre"

// Helper function to extract a metadata tag from a string
char *get_metadata(char *str, char *tag) {
    char *start = strstr(str, tag);
    if (start == NULL) {
        return NULL;
    }
    start += strlen(tag) + 1; // Skip over tag name and colon
    char *end = strchr(start, ';');
    if (end == NULL) {
        end = start + strlen(start);
    }
    int len = end - start;
    char *result = malloc(len + 1);
    strncpy(result, start, len);
    result[len] = '\0';
    return result;
}

// Main function to extract metadata from a file
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file into a string
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *file_contents = malloc(fsize + 1);
    fread(file_contents, fsize, 1, fp);
    file_contents[fsize] = '\0';
    fclose(fp);

    // Extract the metadata tags
    char *title = get_metadata(file_contents, TITLE);
    char *artist = get_metadata(file_contents, ARTIST);
    char *album = get_metadata(file_contents, ALBUM);
    char *year = get_metadata(file_contents, YEAR);
    char *genre = get_metadata(file_contents, GENRE);

    // Print the metadata
    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);
    printf("Genre: %s\n", genre);

    // Free the allocated memory
    free(title);
    free(artist);
    free(album);
    free(year);
    free(genre);
    free(file_contents);

    return EXIT_SUCCESS;
}