//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILENAME 256
#define MAX_METADATA 512

void getFileSize(const char *filename, long *size) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        *size = st.st_size;
    } else {
        *size = -1;
    }
}

void getImageWidthHeight(const char *filename, int *width, int *height) {
    // Simple detection for JPEG files (not comprehensive)
    if (strstr(filename, ".jpg") || strstr(filename, ".jpeg")) {
        *width = 1920; // Placeholder example
        *height = 1080; // Placeholder example
    } else {
        *width = *height = 0; // Not an image or unsupported format
    }
}

void getTextFileFirstLine(const char *filename, char *firstLine) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fgets(firstLine, MAX_METADATA, file);
        fclose(file);
    } else {
        strcpy(firstLine, "Error: Unable to open file.");
    }
}

void displayMetadata(const char *filename) {
    long fileSize;
    int imgWidth = 0, imgHeight = 0;
    char firstLine[MAX_METADATA];

    getFileSize(filename, &fileSize);
    getImageWidthHeight(filename, &imgWidth, &imgHeight);
    getTextFileFirstLine(filename, firstLine);

    printf("\n*** Metadata for: %s ***\n", filename);
    printf("File Size: %ld bytes\n", fileSize);
    if (imgWidth > 0 && imgHeight > 0) {
        printf("Image Dimensions: %dx%d pixels\n", imgWidth, imgHeight);
    } else {
        printf("First Line of Text: %s", firstLine);
    }
    printf("**************************\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> <filename2> ... <filenameN>\n", argv[0]);
        return 1;
    }

    printf("Metadata Extractor v1.0 - A Retro Style Program\n");
    printf("==============================================\n");
    for (int i = 1; i < argc; i++) {
        displayMetadata(argv[i]);
    }

    return 0;
}