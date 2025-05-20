//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_METADATA_LENGTH 1000

typedef struct {
    char file_name[256];
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    char genre[MAX_METADATA_LENGTH];
    int year;
} Metadata;

void extract_metadata(const char *filename, Metadata *meta) {
    // Simulated extraction logic
    strcpy(meta->file_name, filename);
    strcpy(meta->title, "Sample Title");
    strcpy(meta->artist, "Sample Artist");
    strcpy(meta->album, "Sample Album");
    strcpy(meta->genre, "Pop");
    meta->year = 2021;
}

void print_metadata(const Metadata *meta) {
    printf("File Name: %s\n", meta->file_name);
    printf("Title: %s\n", meta->title);
    printf("Artist: %s\n", meta->artist);
    printf("Album: %s\n", meta->album);
    printf("Genre: %s\n", meta->genre);
    printf("Year: %d\n", meta->year);
    printf("-----------------------------------------\n");
}

void display_usage() {
    printf("Usage: ./metadata_extractor <file1> <file2> ... <fileN>\n");
    printf("Extract and display metadata from audio files.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_usage();
        return 1;
    }

    Metadata metadata[MAX_FILES];
    int file_count = 0;

    for (int i = 1; i < argc && file_count < MAX_FILES; i++) {
        // Assume that files are read and validated
        extract_metadata(argv[i], &metadata[file_count]);
        file_count++;
    }

    printf("Extracted Metadata:\n");
    printf("-----------------------------------------\n");
    for (int j = 0; j < file_count; j++) {
        print_metadata(&metadata[j]);
    }

    return 0;
}