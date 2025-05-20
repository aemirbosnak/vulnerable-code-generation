//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to store metadata
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    char year[5];
} Metadata;

// Define function to extract metadata from file
Metadata extract_metadata(const char* filename) {
    // Declare variables
    Metadata data;
    char buffer[1024], *token;
    FILE* file;

    // Check if file is accessible
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    // Loop through each line in file
    while (fgets(buffer, 1024, file)) {
        // Tokenize line and extract metadata
        token = strtok(buffer, ":");
        if (strcmp(token, "Title") == 0) {
            token = strtok(NULL, "\n");
            strncpy(data.title, token, 100);
        }
        else if (strcmp(token, "Artist") == 0) {
            token = strtok(NULL, "\n");
            strncpy(data.artist, token, 100);
        }
        else if (strcmp(token, "Album") == 0) {
            token = strtok(NULL, "\n");
            strncpy(data.album, token, 100);
        }
        else if (strcmp(token, "Year") == 0) {
            token = strtok(NULL, "\n");
            strncpy(data.year, token, 5);
        }
    }

    // Close file
    fclose(file);

    // Return metadata
    return data;
}

// Define function to print metadata
void print_metadata(Metadata data) {
    printf("Title: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Year: %s\n", data.year);
}

int main() {
    // Extract metadata and print
    Metadata data = extract_metadata("example.txt");
    print_metadata(data);

    return 0;
}