//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

// Struct for holding metadata
typedef struct MetaData {
    char title[MAX_STRING_LENGTH];
    char artist[MAX_STRING_LENGTH];
    char album[MAX_STRING_LENGTH];
    char genre[MAX_STRING_LENGTH];
    int year;
} MetaData;

// Function to extract metadata from file
int extractMetaData(const char* filePath, MetaData* metaData) {
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        return 0;
    }

    char line[MAX_STRING_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token = strtok(line, ":");
        if (strcmp(token, "Title") == 0) {
            strcpy(metaData->title, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Artist") == 0) {
            strcpy(metaData->artist, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Album") == 0) {
            strcpy(metaData->album, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Genre") == 0) {
            strcpy(metaData->genre, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Year") == 0) {
            metaData->year = atoi(strtok(NULL, "\n"));
        }
    }

    fclose(fp);
    return 1;
}

int main() {
    char filePath[] = "example.mp3";
    MetaData metaData;
    int success = extractMetaData(filePath, &metaData);

    if (success) {
        printf("Title: %s\n", metaData.title);
        printf("Artist: %s\n", metaData.artist);
        printf("Album: %s\n", metaData.album);
        printf("Genre: %s\n", metaData.genre);
        printf("Year: %d\n", metaData.year);
    }
    else {
        printf("Error: could not open file %s\n", filePath);
    }

    return 0;
}