//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LENGTH 256

char* extract_metadata(char *filename) {
    FILE *fp;
    char *metadata = malloc(sizeof(char) * MAX_METADATA_LENGTH);
    char buffer[MAX_METADATA_LENGTH];
    memset(metadata, 0, MAX_METADATA_LENGTH);
    memset(buffer, 0, MAX_METADATA_LENGTH);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    while (fgets(buffer, MAX_METADATA_LENGTH, fp) != NULL) {
        if (strncmp(buffer, "Metadata:", 9) == 0) {
            int length = strlen(buffer);
            if (length > 10) {
                // Copy the metadata into our output buffer
                strncpy(metadata, buffer + 10, length - 10);
                metadata[length - 11] = '\0';
            }
            break;
        }
    }

    fclose(fp);
    return metadata;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *metadata = extract_metadata(argv[1]);

    if (metadata == NULL) {
        printf("No metadata found in file: %s\n", argv[1]);
    } else {
        printf("Metadata extracted from file %s: %s\n", argv[1], metadata);
        free(metadata);
    }

    return 0;
}