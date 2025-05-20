//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct definition to hold metadata
typedef struct {
    char* title;
    char* artist;
    char* album;
    char* release_date;
} Metadata;

// Function to extract metadata from file
Metadata* extract_metadata(char* filepath) {
    // Open file
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("ERROR: Could not open file.\n");
        exit(1);
    }

    // Allocate memory for metadata struct
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->title = malloc(sizeof(char) * 100);
    metadata->artist = malloc(sizeof(char) * 100);
    metadata->album = malloc(sizeof(char) * 100);
    metadata->release_date = malloc(sizeof(char) * 100);

    // Read file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Check if line contains metadata
        if (strstr(line, "Title:") != NULL) {
            strcpy(metadata->title, strchr(line, ':') + 2);
        } else if (strstr(line, "Artist:") != NULL) {
            strcpy(metadata->artist, strchr(line, ':') + 2);
        } else if (strstr(line, "Album:") != NULL) {
            strcpy(metadata->album, strchr(line, ':') + 2);
        } else if (strstr(line, "Release Date:") != NULL) {
            strcpy(metadata->release_date, strchr(line, ':') + 2);
        }
    }

    // Close file
    fclose(file);
    
    // Return metadata
    return metadata;
}

int main() {
    // Test the metadata extractor
    Metadata* metadata = extract_metadata("song.mp3");
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Release Date: %s\n", metadata->release_date);

    // Free memory allocated for metadata struct
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->release_date);
    free(metadata);

    return 0;
}