//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE 256

struct metadata {
    char title[256];
    char artist[256];
    char album[256];
    int year;
    int track_number;
};

// Function to extract metadata from a file
struct metadata extract_metadata(char *file_path) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct metadata data;

    file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {
        // Extract the title
        if (strstr(line, "Title")) {
            char *title = strtok(line, ":");
            title = strtok(NULL, "");
            title[strlen(title) - 1] = '\0';
            strcpy(data.title, title);
        }
        // Extract the artist
        else if (strstr(line, "Artist")) {
            char *artist = strtok(line, ":");
            artist = strtok(NULL, "");
            artist[strlen(artist) - 1] = '\0';
            strcpy(data.artist, artist);
        }
        // Extract the album
        else if (strstr(line, "Album")) {
            char *album = strtok(line, ":");
            album = strtok(NULL, "");
            album[strlen(album) - 1] = '\0';
            strcpy(data.album, album);
        }
        // Extract the year
        else if (strstr(line, "Year")) {
            char *year_str = strtok(line, ":");
            year_str = strtok(NULL, "");
            year_str[strlen(year_str) - 1] = '\0';
            data.year = atoi(year_str);
        }
        // Extract the track number
        else if (strstr(line, "Track number")) {
            char *track_number_str = strtok(line, ":");
            track_number_str = strtok(NULL, "");
            track_number_str[strlen(track_number_str) - 1] = '\0';
            data.track_number = atoi(track_number_str);
        }
    }

    fclose(file);
    if (line) {
        free(line);
    }

    return data;
}

int main() {
    char file_path[MAX_FILE];
    printf("Welcome to the C Metadata Extractor!\n\n");
    while (1) {
        printf("Please enter the path of a file to extract metadata from (or 'quit' to exit): ");
        scanf("%s", file_path);

        if (strcmp(file_path, "quit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }

        struct metadata data = extract_metadata(file_path);
        printf("\nTitle: %s\nArtist: %s\nAlbum: %s\nYear: %d\nTrack Number: %d\n\n", 
            data.title, data.artist, data.album, data.year, data.track_number);
    }
    return 0;
}