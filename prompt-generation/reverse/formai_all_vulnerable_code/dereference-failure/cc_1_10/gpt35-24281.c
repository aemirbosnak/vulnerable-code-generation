//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition of a structure to hold metadata information */
typedef struct metadata {
    char *title;
    char *artist;
    char *album;
    char *year;
    char *genre;
} metadata_t;

/* Function to parse metadata from a given file */
metadata_t *parse_metadata(char *filename) {

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return NULL;
    }

    /* Allocate memory for the metadata */
    metadata_t *metadata = (metadata_t*) malloc(sizeof(metadata_t));
    metadata->title = NULL;
    metadata->artist = NULL;
    metadata->album = NULL;
    metadata->year = NULL;
    metadata->genre = NULL;

    /* Loop through each line in the file */
    char line[256];
    while (fgets(line, sizeof(line), fp)) {

        /* Remove any trailing newline characters */
        line[strcspn(line, "\r\n")] = 0;

        /* Check each line for metadata keywords */
        if (strstr(line, "TITLE=") != NULL) {
            metadata->title = strdup(line + 6);
        } else if (strstr(line, "ARTIST=") != NULL) {
            metadata->artist = strdup(line + 7);
        } else if (strstr(line, "ALBUM=") != NULL) {
            metadata->album = strdup(line + 6);
        } else if (strstr(line, "YEAR=") != NULL) {
            metadata->year = strdup(line + 5);
        } else if (strstr(line, "GENRE=") != NULL) {
            metadata->genre = strdup(line + 6);
        }
    }

    fclose(fp);
    return metadata;
}

int main() {

    char *filename = "music.mp3";

    /* Parse the metadata from the file */
    metadata_t *metadata = parse_metadata(filename);

    /* Print the extracted metadata */
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %s\n", metadata->year);
    printf("Genre: %s\n", metadata->genre);

    /* Clean up memory */
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->year);
    free(metadata->genre);
    free(metadata);

    return 0;
}