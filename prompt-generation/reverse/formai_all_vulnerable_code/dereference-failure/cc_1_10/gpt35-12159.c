//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold metadata information
struct metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Define a function to extract metadata from a given mp3 file
struct metadata extract_metadata(char* filename) {
    // Open the file in binary mode
    FILE* fp = fopen(filename, "rb");

    // Seek to the location of ID3v2 header
    fseek(fp, 0, SEEK_SET);
    char id3v2[3];
    fread(id3v2, sizeof(char), 3, fp);
    if(strcmp(id3v2, "ID3")) {
        printf("Error: ID3v2 header not found");
        exit(1);
    }

    // Get the version of the ID3v2 tag
    fseek(fp, 3, SEEK_SET);
    char version[2];
    fread(version, sizeof(char), 2, fp);
    int major_version = (int) version[0];
    int minor_version = (int) version[1];

    // Determine the size of the ID3v2 tag
    fseek(fp, 6, SEEK_SET);
    char size[4];
    fread(size, sizeof(char), 4, fp);
    int tag_size = (((int) size[0] << 21) | ((int) size[1] << 14) | ((int) size[2] << 7) | ((int) size[3])) + 10;

    // Seek to the start of the metadata information
    fseek(fp, 10, SEEK_SET);
    if(major_version == 3) {
        fseek(fp, 2, SEEK_CUR);
    }
    else {
        fseek(fp, 4, SEEK_CUR);
    }

    // Extract metadata information
    struct metadata meta;
    fread(meta.title, sizeof(char), 30, fp);
    fread(meta.artist, sizeof(char), 30, fp);
    fread(meta.album, sizeof(char), 30, fp);
    fseek(fp, 2, SEEK_CUR);
    fread(&meta.year, sizeof(int), 1, fp);

    // Close the file and return metadata information
    fclose(fp);
    return meta;
}

// Define a main function to extract metadata from a given mp3 file
int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <mp3_filename>\n", argv[0]);
        exit(1);
    }
    struct metadata meta = extract_metadata(argv[1]);
    printf("Title: %s\n", meta.title);
    printf("Artist: %s\n", meta.artist);
    printf("Album: %s\n", meta.album);
    printf("Year: %d\n", meta.year);
    return 0;
}