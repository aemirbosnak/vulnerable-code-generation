//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Function to extract metadata from a given file
void extract_metadata(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Read the first few bytes to determine the file type
    char magic_bytes[4];
    fread(magic_bytes, 1, 4, file);
    fseek(file, 0, SEEK_SET);

    if (strcmp(magic_bytes, "RIFF") == 0) {
        // WAV file
        printf("File type: WAV\n");
        printf("File size: %d bytes\n", ftell(file));
    } else if (strcmp(magic_bytes, "ID3") == 0) {
        // MP3 file
        printf("File type: MP3\n");
        printf("File size: %d bytes\n", ftell(file));
    } else if (strcmp(magic_bytes, "JFIF") == 0) {
        // JPEG file
        printf("File type: JPEG\n");
        printf("File size: %d bytes\n", ftell(file));
    } else {
        printf("File type: Unknown\n");
        printf("File size: %d bytes\n", ftell(file));
    }

    fclose(file);
}

// Function to print help message
void print_help() {
    printf("Usage: metadata_extractor <filename>\n");
    printf("Extracts metadata from a given file.\n");
    printf("Supported file types: WAV, MP3, JPEG\n");
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_help();
        return 1;
    }

    extract_metadata(argv[1]);
    return 0;
}