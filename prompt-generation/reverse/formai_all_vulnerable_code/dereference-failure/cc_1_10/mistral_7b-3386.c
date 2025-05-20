//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char name[32];
    size_t size;
} Metadata;

void extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Oh dear! Could not open file %s!\n", filename);
        return;
    }

    fseek(file, 54, SEEK_SET); // Jump to ID3v2 header

    char id3[3];
    fread(id3, sizeof(char), 3, file);

    if (strcmp(id3, "ID3") != 0) {
        printf("Whoops! Not an ID3 tag in %s!\n", filename);
        fclose(file);
        return;
    }

    Metadata this_song;
    fread(this_song.name, sizeof(char), 30, file);
    this_song.name[30] = '\0';
    fread(&this_song.size, sizeof(size_t), 1, file);

    strcpy(metadata->name, this_song.name);
    metadata->size = this_song.size;

    fclose(file);
    printf("Amazing! Metadata for %s extracted: Name = %s, Size = %zu bytes!\n", filename, metadata->name, metadata->size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uh oh! Expected exactly 1 argument!\n");
        return 1;
    }

    Metadata song_metadata;
    extract_metadata(argv[1], &song_metadata);

    return 0;
}