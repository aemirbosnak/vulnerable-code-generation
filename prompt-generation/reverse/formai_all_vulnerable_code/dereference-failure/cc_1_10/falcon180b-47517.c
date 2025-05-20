//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    char *metadata;
} Metadata;

void extract_metadata(char *filename, char **metadata) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *metadata_string = NULL;
    int metadata_string_size = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, " ");

        if (strcmp(token, "Metadata:") == 0) {
            token = strtok(NULL, " ");

            if (metadata_string == NULL) {
                metadata_string = malloc(strlen(token) + 1);
                strcpy(metadata_string, token);
                metadata_string_size = strlen(metadata_string);
            } else {
                metadata_string_size += strlen(token) + 1;
                metadata_string = realloc(metadata_string, metadata_string_size);
                strcat(metadata_string, " ");
                strcat(metadata_string, token);
            }
        }
    }

    fclose(file);

    *metadata = metadata_string;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *metadata = NULL;

    extract_metadata(filename, &metadata);

    printf("Metadata for file %s:\n%s\n", filename, metadata);

    free(metadata);

    return 0;
}