//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold metadata information
typedef struct {
    char* title;
    char* artist;
    char* album;
    int year;
    char* genre;
} Metadata;

// Function to extract metadata information from a file
Metadata extract_metadata(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    char line[100];
    char* token;

    Metadata metadata;
    metadata.title = NULL;
    metadata.artist = NULL;
    metadata.album = NULL;
    metadata.year = 0;
    metadata.genre = NULL;

    // Iterate through each line of the file and extract metadata information
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "Title") == 0) {
            metadata.title = strtok(NULL, "\n");
        }
        else if (strcmp(token, "Artist") == 0) {
            metadata.artist = strtok(NULL, "\n");
        }
        else if (strcmp(token, "Album") == 0) {
            metadata.album = strtok(NULL, "\n");
        }
        else if (strcmp(token, "Year") == 0) {
            metadata.year = atoi(strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Genre") == 0) {
            metadata.genre = strtok(NULL, "\n");
        }
    }

    fclose(fp);
    return metadata;
}

int main() {
    char* filename = "sample.mp3";
    Metadata metadata = extract_metadata(filename);

    // Print metadata information
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);

    return 0;
}