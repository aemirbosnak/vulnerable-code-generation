//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure.
typedef struct {
    char *title;
    char *artist;
    char *album;
    char *year;
    char *track_number;
    char *genre;
    char *lyrics;
} metadata;

// Create a new metadata object.
metadata *new_metadata() {
    metadata *m = malloc(sizeof(metadata));
    m->title = NULL;
    m->artist = NULL;
    m->album = NULL;
    m->year = NULL;
    m->track_number = NULL;
    m->genre = NULL;
    m->lyrics = NULL;
    return m;
}

// Free the metadata object.
void free_metadata(metadata *m) {
    if (m->title != NULL) free(m->title);
    if (m->artist != NULL) free(m->artist);
    if (m->album != NULL) free(m->album);
    if (m->year != NULL) free(m->year);
    if (m->track_number != NULL) free(m->track_number);
    if (m->genre != NULL) free(m->genre);
    if (m->lyrics != NULL) free(m->lyrics);
    free(m);
}

// Extract the metadata from the given file.
metadata *extract_metadata(const char *filename) {
    // Open the file.
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("fopen");
        return NULL;
    }

    // Read the file contents into a buffer.
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = malloc(fsize + 1);
    fread(buffer, 1, fsize, f);
    fclose(f);

    // Parse the metadata from the buffer.
    metadata *m = new_metadata();
    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        // Split the line into key and value.
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");

        // Set the metadata field.
        if (strcmp(key, "title") == 0) {
            m->title = strdup(value);
        } else if (strcmp(key, "artist") == 0) {
            m->artist = strdup(value);
        } else if (strcmp(key, "album") == 0) {
            m->album = strdup(value);
        } else if (strcmp(key, "year") == 0) {
            m->year = strdup(value);
        } else if (strcmp(key, "track_number") == 0) {
            m->track_number = strdup(value);
        } else if (strcmp(key, "genre") == 0) {
            m->genre = strdup(value);
        } else if (strcmp(key, "lyrics") == 0) {
            m->lyrics = strdup(value);
        }

        // Get the next line.
        line = strtok(NULL, "\n");
    }

    // Free the buffer.
    free(buffer);

    // Return the metadata.
    return m;
}

int main(int argc, char **argv) {
    // Check the arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file.
    metadata *m = extract_metadata(argv[1]);
    if (m == NULL) {
        fprintf(stderr, "Error: could not extract metadata from file.\n");
        return 1;
    }

    // Print the metadata.
    printf("Title: %s\n", m->title);
    printf("Artist: %s\n", m->artist);
    printf("Album: %s\n", m->album);
    printf("Year: %s\n", m->year);
    printf("Track Number: %s\n", m->track_number);
    printf("Genre: %s\n", m->genre);
    printf("Lyrics: %s\n", m->lyrics);

    // Free the metadata.
    free_metadata(m);

    return 0;
}