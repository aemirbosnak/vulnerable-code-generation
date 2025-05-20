//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* name;
    char* value;
} metadata_t;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 2;
    }

    metadata_t metadata;
    metadata.name = malloc(MAX_LINE_SIZE);
    metadata.value = malloc(MAX_LINE_SIZE);

    int in_metadata = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (in_metadata) {
            if (line[0] == '\n') {
                in_metadata = 0;
            } else {
                strcat(metadata.value, line);
            }
        } else {
            if (strncmp(line, "metadata:", 8) == 0) {
                in_metadata = 1;
                strcpy(metadata.name, line + 8);
                metadata.value[0] = '\0';
            }
        }
    }

    if (metadata.name!= NULL && metadata.value!= NULL && metadata.value[0]!= '\0') {
        printf("Filename: %s\n", argv[1]);
        printf("Metadata:\n");
        printf("  Name: %s\n", metadata.name);
        printf("  Value: %s\n", metadata.value);
    } else {
        printf("No metadata found in file %s\n", argv[1]);
    }

    free(metadata.name);
    free(metadata.value);
    fclose(file);
    return 0;
}