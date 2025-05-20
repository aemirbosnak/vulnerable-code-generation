//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

// Function to extract metadata from a file
void extract_metadata(char *filename) {
    FILE *file;
    char magic[4];
    int i;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Check for magic numbers at the beginning of the file
    fseek(file, 0, SEEK_SET);
    fread(magic, 1, 4, file);
    if (strcmp(magic, "GIF8") == 0) {
        printf("File type: GIF\n");
    } else if (strcmp(magic, "JFIF") == 0 || strcmp(magic, "Exif") == 0) {
        printf("File type: JPEG\n");
    } else if (strcmp(magic, "BM") == 0) {
        printf("File type: BMP\n");
    } else if (strcmp(magic, "II*") == 0) {
        printf("File type: TIFF\n");
    } else if (strcmp(magic, "MM") == 0) {
        printf("File type: MP3\n");
    } else {
        printf("File type: Unknown\n");
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Extract metadata
    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return;
    }

    fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    // Print metadata
    printf("File size: %ld bytes\n", filesize);
    printf("MD5 hash: ");
    for (i = 0; i < 16; i++) {
        printf("%02x", (unsigned char)buffer[i]);
    }
    printf("\n");
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1]);
    return 0;
}