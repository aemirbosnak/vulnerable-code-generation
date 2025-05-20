//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 1024
#define MAX_METADATA_LENGTH 4096

/**
 * This function extracts metadata from a given C source file.
 * Metadata is defined by comments starting with '@' character.
 * The metadata must be in the form '@key value'.
 * The function returns a key-value map in the form of a char array.
 * The caller is responsible for freeing the returned memory.
 */
char* extract_metadata_from_c_file(const char* file_path)
{
    char* metadata = (char*) malloc(sizeof(char) * MAX_METADATA_LENGTH);
    memset(metadata, 0, MAX_METADATA_LENGTH);

    FILE* c_file = fopen(file_path, "r");
    if (c_file == NULL) {
        printf("Failed to open file: %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), c_file) != NULL) {
        if (line[0] == '@') {
            char key[1024];
            char value[1024];
            memset(key, 0, sizeof(key));
            memset(value, 0, sizeof(value));

            // Find key
            int i = 1;
            while (line[i] != ' ' && line[i] != '\n' && i < sizeof(line)) {
                key[i - 1] = line[i];
                i++;
            }

            // Find value
            int j = i + 1;
            while (line[j] != '\n' && j < sizeof(line)) {
                value[j - i - 1] = line[j];
                j++;
            }

            // Append key value pair to metadata
            sprintf(metadata + strlen(metadata), "%s=%s\n", key, value);
        }
    }

    fclose(c_file);
    return metadata;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <path-to-c-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char file_path[MAX_FILE_PATH];
    strncpy(file_path, argv[1], sizeof(file_path));

    char* metadata = extract_metadata_from_c_file(file_path);
    printf("Metadata for file %s:\n%s", file_path, metadata);
    free(metadata);

    return 0;
}