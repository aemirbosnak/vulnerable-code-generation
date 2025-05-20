//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_METADATA 50
#define METADATA_SIZE 1024

// Structure to store metadata information
struct Metadata {
    char key[METADATA_SIZE];
    char value[METADATA_SIZE];
};

// Function to extract metadata from file
bool extractMetadata(char* filepath, struct Metadata metadata[MAX_METADATA]) {
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error opening file %s: %s\n", filepath, strerror(errno));
        return false;
    }

    int metadataCount = 0;
    bool inMetadata = false;
    char* line = (char*)malloc(METADATA_SIZE * sizeof(char));

    while (read(fd, line, 1) != 0 && metadataCount < MAX_METADATA) {
        if (*line == '\n') {
            if (inMetadata) {
                inMetadata = false;
                char* delimiter = strchr(line, ':');
                if (delimiter != NULL) {
                    *delimiter = '\0';
                    strncpy(metadata[metadataCount].key, line, METADATA_SIZE);
                    strncpy(metadata[metadataCount].value, delimiter + 2, METADATA_SIZE);
                    metadataCount++;
                }
            }
        } else if (*line == '#') {
            inMetadata = true;
        }
    }

    free(line);
    close(fd);

    if (metadataCount == 0) {
        return false;
    } else {
        return true;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        return 1;
    }

    // Initialize metadata array
    struct Metadata metadata[MAX_METADATA] = {0};

    bool success = extractMetadata(argv[1], metadata);

    if (!success) {
        fprintf(stderr, "No metadata found in file %s\n", argv[1]);
        return 1;
    }

    printf("Metadata found in file %s:\n", argv[1]);
    for (int i = 0; i < MAX_METADATA; i++) {
        if (strlen(metadata[i].key) > 0 && strlen(metadata[i].value) > 0) {
            printf("%s: %s\n", metadata[i].key, metadata[i].value);
        } else {
            break;
        }
    }

    return 0;
}