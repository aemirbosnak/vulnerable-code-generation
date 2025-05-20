//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 4096

// JPEG marker definitions
#define SOF0 0xC0
#define SOF1 0xC1
#define SOF2 0xC2

// Structure to hold JPEG image metadata
typedef struct {
    int width;
    int height;
    int color_depth;
} JPEGMetadata;

// Function to read JPEG metadata
JPEGMetadata read_jpeg_metadata(const char* filename) {
    JPEGMetadata metadata = {0, 0, 0};

    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return metadata;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read till we find the SOF0 marker
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == 0xFF) {
                if (buffer[i + 1] == SOF0) {
                    // Found SOF0 marker
                    metadata.color_depth = buffer[i + 5];
                    metadata.height = (buffer[i + 3] << 8) | buffer[i + 4];
                    metadata.width = (buffer[i + 0] << 8) | buffer[i + 1];
                    fclose(file);
                    return metadata;
                }
                // Move to next byte
                i++;
            }
        }
    }
    fclose(file);
    return metadata; // returns (0, 0, 0) if SOF0 is not found
}

// Function to scan a directory for JPEG files
void scan_directory(const char* path) {
    DIR* dir = opendir(path);
    struct dirent* ent;

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    printf("JPEG Metadata:\n");
    printf("Filename\tWidth\tHeight\tColor Depth\n");

    while ((ent = readdir(dir)) != NULL) {
        if (strstr(ent->d_name, ".jpg") || strstr(ent->d_name, ".jpeg")) {
            JPEGMetadata metadata = read_jpeg_metadata(ent->d_name);
            printf("%s\t%d\t%d\t%d\n", ent->d_name, metadata.width, metadata.height, metadata.color_depth);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    const char* path = (argc > 1) ? argv[1] : "."; // Use provided path or current directory

    // Scan the specified directory for JPEG files
    scan_directory(path);

    return 0;
}