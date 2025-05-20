//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char artist[100];
    char album[100];
    char genre[50];
    int year;
} metadata;

metadata* extract_metadata(char* file_path) {
    metadata* result = (metadata*) malloc(sizeof(metadata));
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("File cannot be opened.\n");
        return NULL;
    }

    char line[200];
    char key[100];
    char value[100];

    while (fgets(line, 200, file) != NULL) {
        sscanf(line, "%[^:]: %[^\n]", key, value);
        if (strcmp(key, "ARTIST") == 0) {
            strcpy(result->artist, value);
        } else if (strcmp(key, "ALBUM") == 0) {
            strcpy(result->album, value);
        } else if (strcmp(key, "GENRE") == 0) {
            strcpy(result->genre, value);
        } else if (strcmp(key, "YEAR") == 0) {
            result->year = atoi(value);
        }
    }

    fclose(file);
    return result;
}

int main() {
    metadata* meta = extract_metadata("example_song.txt");

    if (meta != NULL) {
        printf("Artist: %s\n", meta->artist);
        printf("Album: %s\n", meta->album);
        printf("Genre: %s\n", meta->genre);
        printf("Year: %d\n", meta->year);
        free(meta);
    }

    return 0;
}