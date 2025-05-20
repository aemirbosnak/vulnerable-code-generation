//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char* title;
    char* artist;
    char* album;
    char* genre;
    unsigned int track_number;
    unsigned int year;
} SongMetadata;

SongMetadata* extract_metadata(const char* filename) {
    // Open file for reading
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: file %s not found.\n", filename);
        return NULL;
    }
    
    // Allocate space for metadata
    SongMetadata* metadata = malloc(sizeof(SongMetadata));
    metadata->title = malloc(sizeof(char) * MAX_STRING_LENGTH);
    metadata->artist = malloc(sizeof(char) * MAX_STRING_LENGTH);
    metadata->album = malloc(sizeof(char) * MAX_STRING_LENGTH);
    metadata->genre = malloc(sizeof(char) * MAX_STRING_LENGTH);
    metadata->track_number = 0;
    metadata->year = 0;
    memset(metadata->title, 0, sizeof(char) * MAX_STRING_LENGTH);
    memset(metadata->artist, 0, sizeof(char) * MAX_STRING_LENGTH);
    memset(metadata->album, 0, sizeof(char) * MAX_STRING_LENGTH);
    memset(metadata->genre, 0, sizeof(char) * MAX_STRING_LENGTH);
    
    // Read file contents into buffer
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = malloc(sizeof(char) * length);
    fread(buffer, sizeof(char), length, file);
    
    // Extract metadata from buffer
    char* tag = strstr(buffer, "TAG");
    if (!tag) {
        printf("Error: no metadata found in file %s.\n", filename);
        return NULL;
    }
    strncpy(metadata->title, tag+3, 30);
    strncpy(metadata->artist, tag+33, 30);
    strncpy(metadata->album, tag+63, 30);
    strncpy(metadata->year, tag+93, 4);
    strncpy(metadata->genre, tag+97, 1);
    metadata->track_number = buffer[length-1];
    
    // Clean up and return
    free(buffer);
    fclose(file);
    return metadata;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file.mp3>\n", argv[0]);
        return 1;
    }
    
    SongMetadata* metadata = extract_metadata(argv[1]);
    if (!metadata) {
        printf("Failed to extract metadata from file %s.\n", argv[1]);
        return 2;
    }
    
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Genre: %s\n", metadata->genre);
    printf("Track Number: %d\n", metadata->track_number);
    printf("Year: %d\n", metadata->year);
    
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->genre);
    free(metadata);
    
    return 0;
}