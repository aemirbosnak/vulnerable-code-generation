//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char* title;
    char* artist;
    char* album;
    int year;
} Metadata;

Metadata* extract_metadata(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File does not exist!\n");
        return NULL;
    }
    
    // Read ID3 tag
    char buffer[128];
    fseek(file, -128, SEEK_END);
    fread(buffer, sizeof(buffer), 1, file);
    
    if (strncmp(buffer, "TAG", 3) != 0) {
        printf("No ID3 tag found!\n");
        return NULL;
    }
    
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->title = malloc(sizeof(char) * 31);
    metadata->artist = malloc(sizeof(char) * 31);
    metadata->album = malloc(sizeof(char) * 31);
    
    // Extract metadata fields
    strncpy(metadata->title, buffer + 3, 30);
    strncpy(metadata->artist, buffer + 33, 30);
    strncpy(metadata->album, buffer + 63, 30);
    char year_buffer[5];
    strncpy(year_buffer, buffer + 93, 4);
    metadata->year = atoi(year_buffer);
    
    fclose(file);
    return metadata;
}

int main() {
    Metadata* music_metadata = extract_metadata("my_music.mp3");
    if (music_metadata == NULL) {
        return EXIT_FAILURE;
    }
    
    printf("Title: %s\n", music_metadata->title);
    printf("Artist: %s\n", music_metadata->artist);
    printf("Album: %s\n", music_metadata->album);
    printf("Year: %d\n", music_metadata->year);
    
    free(music_metadata->title);
    free(music_metadata->artist);
    free(music_metadata->album);
    free(music_metadata);
    
    return EXIT_SUCCESS;
}