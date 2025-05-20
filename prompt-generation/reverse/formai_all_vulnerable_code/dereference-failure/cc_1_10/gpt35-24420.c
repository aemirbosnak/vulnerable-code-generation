//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct Metadata {
    char artist[50];
    char title[50];
    char album[50];
    int year;
} Metadata;

void extract_metadata(FILE *file_ptr, Metadata *metadata) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file_ptr)) != -1) {
        if (strstr(line, "ARTIST=") != NULL) {
            strcpy(metadata->artist, line + 7);
            metadata->artist[strcspn(metadata->artist, "\n")] = 0;
        } else if (strstr(line, "TITLE=") != NULL) {
            strcpy(metadata->title, line + 6);
            metadata->title[strcspn(metadata->title, "\n")] = 0;
        } else if (strstr(line, "ALBUM=") != NULL) {
            strcpy(metadata->album, line + 6);
            metadata->album[strcspn(metadata->album, "\n")] = 0;
        } else if (strstr(line, "YEAR=") != NULL) {
            metadata->year = atoi(line + 5);
        }
    }

    free(line);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }

    char file_name[50];
    strcpy(file_name, argv[1]);

    FILE *file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL) {
        printf("Unable to open file.\n");
        return 0;
    }

    Metadata metadata = {
        .artist = "",
        .title = "",
        .album = "",
        .year = 0
    };

    extract_metadata(file_ptr, &metadata);

    printf("Artist: %s\n", metadata.artist);
    printf("Title: %s\n", metadata.title);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);

    fclose(file_ptr);

    return 0;
}