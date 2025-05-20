//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define max file name length
#define MAX_FILE_NAME_LENGTH 256

// define metadata structure
typedef struct {
    char title[256];
    char artist[256];
    int year;
    int track;
} metadata;

// declare function for extracting metadata
void extract_metadata(char *file_name, metadata *music_info) {
    // open file in read mode
    FILE *fp = fopen(file_name, "r");

    // check if file exists
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    // declare variables to hold line and string data
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // read each line and extract metadata
    while ((read = getline(&line, &len, fp)) != -1) {
        // strip newline character
        strtok(line, "\n");

        // extract title metadata
        if (strstr(line, "title=") != NULL) {
            char *ptr = strtok(line, "=");
            strcpy(music_info->title, ptr + strlen("title="));
        }

        // extract artist metadata
        else if (strstr(line, "artist=") != NULL) {
            char *ptr = strtok(line, "=");
            strcpy(music_info->artist, ptr + strlen("artist="));
        }

        // extract year metadata
        else if (strstr(line, "year=") != NULL) {
            char *ptr = strtok(line, "=");
            music_info->year = atoi(ptr + strlen("year="));
        }

        // extract track metadata
        else if (strstr(line, "track=") != NULL) {
            char *ptr = strtok(line, "=");
            music_info->track = atoi(ptr + strlen("track="));
        }
    }

    // close file
    fclose(fp);

    // free memory
    if (line)
        free(line);
}

// main function
int main() {
    // declare metadata structure
    metadata music_info;

    // declare file name string
    char file_name[MAX_FILE_NAME_LENGTH];

    // prompt user for file name
    printf("Enter file name: ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);

    // remove newline character from file name
    strtok(file_name, "\n");

    // extract metadata from file
    extract_metadata(file_name, &music_info);

    // print metadata
    printf("Title: %s\n", music_info.title);
    printf("Artist: %s\n", music_info.artist);
    printf("Year: %d\n", music_info.year);
    printf("Track: %d\n", music_info.track);

    return 0;
}