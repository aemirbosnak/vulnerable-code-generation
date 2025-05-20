//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define macros for easier error handling
#define TRY(expr) {int err = (expr); if (err) {goto error;}}

#define MAX_METADATA_SIZE 1024 // maximum size of metadata in bytes

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    // read file into memory
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *file_data = malloc(file_size);
    TRY(fread(file_data, 1, file_size, fp) != file_size);

    // find metadata section
    char *metadata_start = strstr(file_data, "METADATA:");
    if (!metadata_start) {
        printf("No metadata found!\n");
        goto error;
    }
    metadata_start += strlen("METADATA:");
    char *metadata_end = strstr(metadata_start, "\n");
    if (!metadata_end) {
        printf("Invalid metadata format!\n");
        goto error;
    }

    // extract metadata
    int metadata_size = metadata_end - metadata_start;
    if (metadata_size > MAX_METADATA_SIZE) {
        printf("Metadata too large!\n");
        goto error;
    }
    char metadata[MAX_METADATA_SIZE + 1];
    strncpy(metadata, metadata_start, metadata_size);
    metadata[metadata_size] = '\0';

    // print metadata
    printf("Metadata: %s\n", metadata);

    // cleanup
    free(file_data);
    fclose(fp);
    return 0;

error:
    free(file_data);
    fclose(fp);
    return 1;
}