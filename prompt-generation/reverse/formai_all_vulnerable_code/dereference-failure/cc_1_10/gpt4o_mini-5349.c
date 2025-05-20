//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define JPEG_HEADER 0xD8FF
#define MAX_METADATA 256

void extract_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Curious miss! Could not open file %s.\n", filename);
        return;
    }

    unsigned char buffer[2];
    fread(buffer, 1, 2, file);
    
    unsigned short marker = (buffer[0] << 8) | buffer[1];

    if (marker != JPEG_HEADER) {
        printf("Hmm, %s is not a JPEG file. Skipping...\n", filename);
        fclose(file);
        return;
    }

    printf("Found a JPEG file: %s. Here’s what I found!\n", filename);
    
    fseek(file, 0, SEEK_SET);
    while (fread(buffer, 1, 2, file) == 2) {
        marker = (buffer[0] << 8) | buffer[1];

        // Skip to the next segment if it's not a marker we're interested in
        if (marker == 0xFFC0 || marker == 0xFFC2 || marker == 0xFFC4 || marker == 0xFFC1 || marker == 0xFFDB) {
            unsigned short length;
            fread(&length, sizeof(length), 1, file);
            length = ntohs(length); // Convert from network byte order to host byte order

            unsigned char *data = (unsigned char *)malloc(length - 2);
            fread(data, 1, length - 2, file);

            if (marker == 0xFFC0) {
                printf("Curious moment! Found Baseline DCT.\n");
            }

            // For brevity, we'll just print the length
            printf("Segment Length: %d bytes\n", length);
            free(data);
        } else {
            // If we encounter a different marker, read and skip
            unsigned short length;
            fread(&length, sizeof(length), 1, file);
            length = ntohs(length); // Convert from network byte order to host byte order
            fseek(file, length - 2, SEEK_CUR); // Skip the segment data
        }
    }

    fclose(file);
}

void list_files(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    
    if (dp == NULL) {
        printf("Curious miss! Could not open directory %s.\n", directory);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            extract_metadata(filepath);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hey! Please provide a directory path as an argument to explore.\n");
        return 1;
    }

    printf("Venture forth into the realm of JPEG files in the directory: %s!\n", argv[1]);
    list_files(argv[1]);
    printf("Curiosity has been satisfied! Explore again!\n");

    return 0;
}