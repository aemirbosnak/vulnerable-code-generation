//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* description;
} Metadata;

void extract_metadata(char* file_path, Metadata* metadata) {
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char* name_end = strchr(line, ':');
        if (name_end == NULL) {
            printf("Invalid metadata format in file: %s\n", file_path);
            continue;
        }

        char* name = strndup(line, name_end - line);
        char* description = strndup(name_end + 1, strlen(line) - (name_end - line) - 1);

        metadata->name = name;
        metadata->description = description;
    }

    fclose(fp);
}

int main() {
    char file_path[256];
    printf("Enter file path: ");
    fgets(file_path, sizeof(file_path), stdin);

    Metadata metadata;
    extract_metadata(file_path, &metadata);

    printf("Metadata:\n");
    printf("Name: %s\n", metadata.name);
    printf("Description: %s\n", metadata.description);

    free(metadata.name);
    free(metadata.description);

    return 0;
}