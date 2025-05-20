//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define metadata struct to store extracted metadata
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int track_num;
} metadata;

// Function to extract metadata from given file
metadata extract_metadata(char *filename) {
    metadata data;
    // Open file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // File does not exist or could not be opened
        printf("Error: File not found or could not be opened.\n");
        exit(1);
    }
    // Seek to the end of the file
    fseek(fp, 0, SEEK_END);
    // Get the size of the file
    long size = ftell(fp);
    // Seek back to the beginning of the file
    rewind(fp);
    // Read in the first 128 bytes (ID3v1 tag size)
    char buffer[128];
    fread(buffer, sizeof(char), 128, fp);
    // Check if ID3v1 tag exists
    if (strncmp(buffer + sizeof(buffer) - 128, "TAG", 3) != 0) {
        // ID3v1 tag not found
        printf("Error: No metadata found in file.\n");
        exit(1);
    }
    // Extract metadata from buffer
    strncpy(data.title, buffer + sizeof(buffer) - 125, 30);
    strncpy(data.artist, buffer + sizeof(buffer) - 95, 30);
    strncpy(data.album, buffer + sizeof(buffer) - 65, 30);
    char year[5];
    strncpy(year, buffer + sizeof(buffer) - 35, 4);
    data.year = atoi(year);
    char track_num[2];
    strncpy(track_num, buffer + sizeof(buffer) - 1, 1);
    data.track_num = atoi(track_num);
    // Close file
    fclose(fp);
    // Return extracted metadata
    return data;
}

// Main function to test the metadata extractor
int main() {
    // Extract metadata from sample mp3 file
    metadata data = extract_metadata("sample.mp3");
    // Print extracted metadata
    printf("Title: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Year: %d\n", data.year);
    printf("Track Number: %d\n", data.track_num);
    return 0; 
}