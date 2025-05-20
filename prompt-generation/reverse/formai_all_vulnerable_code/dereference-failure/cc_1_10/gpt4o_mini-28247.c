//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_METADATA 256

typedef struct {
    char filename[100];
    char title[MAX_METADATA];
    char author[MAX_METADATA];
    char genre[MAX_METADATA];
    int year;
} MediaFile;

void printLogo() {
    printf("=======================================\n");
    printf("          METADATA EXTRACTOR          \n");
    printf("             Retro Edition             \n");
    printf("=======================================\n");
}

void displayFileInfo(MediaFile* file) {
    printf("Filename: %s\n", file->filename);
    printf("Title: %s\n", file->title);
    printf("Author: %s\n", file->author);
    printf("Genre: %s\n", file->genre);
    printf("Year: %d\n", file->year);
    printf("---------------------------------------\n");
}

void initializeFile(MediaFile* file, const char* filename) {
    strcpy(file->filename, filename);
    strcpy(file->title, "Unknown Title");
    strcpy(file->author, "Unknown Author");
    strcpy(file->genre, "Unknown Genre");
    file->year = 0;
}

void extractMetadata(const char* filename, MediaFile* file) {
    // Simulate metadata extraction
    // In a real scenario, parsing would be required here
    if (strstr(filename, ".mp3")) {
        strcpy(file->title, "Retro Tune");
        strcpy(file->author, "Famous Artist");
        strcpy(file->genre, "Synthwave");
        file->year = 1985;
    } else if (strstr(filename, ".mp4")) {
        strcpy(file->title, "Classic Movie");
        strcpy(file->author, "Director Name");
        strcpy(file->genre, "Drama");
        file->year = 1990;
    } else if (strstr(filename, ".jpg")) {
        strcpy(file->title, "Beautiful Scenery");
        strcpy(file->author, "Nature Photographer");
        strcpy(file->genre, "Photography");
        file->year = 2020;
    } else {
        strcpy(file->title, "Unknown Title");
        strcpy(file->author, "Unknown Author");
        strcpy(file->genre, "Unknown Genre");
        file->year = 0;
    }
}

void processFiles(MediaFile files[], int count) {
    for (int i = 0; i < count; i++) {
        extractMetadata(files[i].filename, &files[i]);
        displayFileInfo(&files[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    MediaFile files[MAX_FILES];
    int fileCount = argc - 1;

    printLogo();

    for (int i = 0; i < fileCount; i++) {
        initializeFile(&files[i], argv[i + 1]);
    }

    processFiles(files, fileCount);

    printf("Thank you for using the Metadata Extractor!\n");
    return 0;
}