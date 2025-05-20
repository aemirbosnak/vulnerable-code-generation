//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    char *metadata_key = NULL;
    char *metadata_value = NULL;
    int metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strstr(line, "metadata-key")!= NULL) {
            metadata_key = strstr(line, "metadata-key") + strlen("metadata-key");
            metadata_key[strcspn(metadata_key, "\n")] = '\0';
            metadata_count++;
        }
        else if (strstr(line, "metadata-value")!= NULL) {
            metadata_value = strstr(line, "metadata-value") + strlen("metadata-value");
            metadata_value[strcspn(metadata_value, "\n")] = '\0';
        }
        else if (metadata_key!= NULL && metadata_value!= NULL) {
            printf("Metadata %d: %s=%s\n", metadata_count, metadata_key, metadata_value);
            metadata_key = NULL;
            metadata_value = NULL;
        }
    }

    if (metadata_key!= NULL && metadata_value!= NULL) {
        printf("Metadata %d: %s=%s\n", metadata_count, metadata_key, metadata_value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <metadata-key>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    char *metadata_key = argv[2];
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strstr(line, metadata_key)!= NULL) {
            printf("Metadata: %s\n", line);
            break;
        }
    }

    fclose(file);
    return 0;
}