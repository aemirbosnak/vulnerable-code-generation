//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
/*
 * Ada Lovelace inspired C Metadata Extractor Program
 * By [Your Name]
 *
 * This program extracts metadata from a file based on its file type. 
 * It is written in C, utilizing struct and files.
 * 
 * Supported file types: 
 *  - JPEG (.jpg, .jpeg, .jfif)
 *  - PNG (.png)
 *  - MP3 (.mp3)
 *  - MP4 (.mp4)
 * 
 * It extracts the following metadata:
 *  - For JPEG: resolution and creation date
 *  - For PNG: resolution and creation date
 *  - For MP3: artist, album, title, and creation date
 *  - For MP4: resolution, duration, and creation date
 *
 * Example usage: 
 * ./metadata_extractor some_image.jpg
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs

typedef struct {
    int width;
    int height;
    char creation_date[20];
} jpeg_metadata;

typedef struct {
    int width;
    int height;
    char creation_date[20];
} png_metadata;

typedef struct {
    char artist[50];
    char album[50];
    char title[50];
    char creation_date[20];
} mp3_metadata;

typedef struct {
    int width;
    int height;
    int duration;
    char creation_date[20];
} mp4_metadata;

// Functions for extracting metadata

jpeg_metadata extract_jpeg_metadata(FILE* file) {
    jpeg_metadata metadata;
    char marker[2];
    int block_size;
    int width;
    int height;

    while (fread(marker, sizeof(char), 2, file) == 2) {
        if (marker[0] == 0xFF) {
            switch (marker[1]) {
                case 0xC0:
                case 0xC2:
                    fseek(file, 3, SEEK_CUR);
                    fread(&height, sizeof(height), 1, file);
                    fread(&width, sizeof(width), 1, file);
                    metadata.height = height;
                    metadata.width = width;
                    return metadata;
                case 0xDD:
                    fseek(file, 4, SEEK_CUR);
                    fread(metadata.creation_date, sizeof(char), 19, file);
                    return metadata;
                default:
                    fseek(file, 2, SEEK_CUR);
                    fread(&block_size, sizeof(block_size), 1, file);
                    fseek(file, block_size - 2, SEEK_CUR);
                    break;
            }
        }
    }

    return metadata;
}

png_metadata extract_png_metadata(FILE* file) {
    png_metadata metadata;
    char header[8];
    int width;
    int height;

    fread(header, sizeof(header), 1, file);
    fseek(file, 4, SEEK_CUR);
    fread(&width, sizeof(width), 1, file);
    fread(&height, sizeof(height), 1, file);
    metadata.width = width;
    metadata.height = height;
    fseek(file, 16, SEEK_CUR);
    fread(metadata.creation_date, sizeof(char), 19, file);

    return metadata;
}

mp3_metadata extract_mp3_metadata(FILE* file) {
    mp3_metadata metadata;
    char header[10];
    char tag[4];
    int size;
    int year_length;

    // Skip to ID3 tag
    fseek(file, -128, SEEK_END);

    // Check for ID3 header
    fread(header, sizeof(header), 1, file);
    if (strncmp(header, "TAG", 3) != 0) {
        printf("No ID3 tag found.\n");
        exit(1);
    }

    // Read metadata
    fread(metadata.title, sizeof(char), 30, file);
    fread(metadata.artist, sizeof(char), 30, file);
    fread(metadata.album, sizeof(char), 30, file);
    fread(&metadata.creation_date, sizeof(char), 4, file);
    fread(tag, sizeof(tag), 1, file);
    size = (tag[0] << 21) | (tag[1] << 14) | (tag[2] << 7) | tag[3];
    fseek(file, size - 10, SEEK_CUR);
    year_length = strlen(metadata.creation_date);
    metadata.creation_date[year_length] = '0';
    metadata.creation_date[year_length + 1] = '0';
    metadata.creation_date[year_length + 2] = '\0';

    return metadata;
}

mp4_metadata extract_mp4_metadata(FILE* file) {
    mp4_metadata metadata;
    char header[8];
    int size;
    int type;
    int width;
    int height;
    int duration;
    int ascii_duration[4];

    fseek(file, 4, SEEK_CUR);
    fread(header, sizeof(header), 1, file);
    fseek(file, 4, SEEK_CUR);
    fread(header, sizeof(header), 1, file);
    fread(&size, sizeof(size), 1, file);
    fread(&type, sizeof(type), 1, file);
    if (type == 0x6D766864) {
        fseek(file, 4, SEEK_CUR);
        fseek(file, 4, SEEK_CUR);
        fseek(file, 4, SEEK_CUR);
        fread(&width, sizeof(width), 1, file);
        fread(&height, sizeof(height), 1, file);
        metadata.width = width;
        metadata.height = height;
    }
    fseek(file, 4, SEEK_CUR);
    fread(header, sizeof(header), 1, file);
    fread(&duration, sizeof(duration), 1, file);
    metadata.duration = duration / 1000;
    fseek(file, 8, SEEK_CUR);
    fread(metadata.creation_date, sizeof(char), 19, file);

    return metadata;
}

// Main function

int main(int argc, char** argv) {
    // Open file
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Determine file type
    char* ext = strrchr(argv[1], '.');
    if (ext == NULL) {
        printf("Invalid file type.\n");
        exit(1);
    }

    // Extract metadata based on file type
    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0 || strcmp(ext, ".jfif") == 0) {
        jpeg_metadata metadata = extract_jpeg_metadata(file);
        printf("Width: %d\n", metadata.width);
        printf("Height: %d\n", metadata.height);
        printf("Creation date: %s\n", metadata.creation_date);
    }
    else if (strcmp(ext, ".png") == 0) {
        png_metadata metadata = extract_png_metadata(file);
        printf("Width: %d\n", metadata.width);
        printf("Height: %d\n", metadata.height);
        printf("Creation date: %s\n", metadata.creation_date);
    }
    else if (strcmp(ext, ".mp3") == 0) {
        mp3_metadata metadata = extract_mp3_metadata(file);
        printf("Title: %s\n", metadata.title);
        printf("Artist: %s\n", metadata.artist);
        printf("Album: %s\n", metadata.album);
        printf("Creation date: %s\n", metadata.creation_date);
    }
    else if (strcmp(ext, ".mp4") == 0) {
        mp4_metadata metadata = extract_mp4_metadata(file);
        printf("Width: %d\n", metadata.width);
        printf("Height: %d\n", metadata.height);
        printf("Duration: %d seconds\n", metadata.duration);
        printf("Creation date: %s\n", metadata.creation_date);
    }
    else {
        printf("Invalid file type.\n");
        exit(1);
    }

    // Close file
    fclose(file);

    return 0;
}