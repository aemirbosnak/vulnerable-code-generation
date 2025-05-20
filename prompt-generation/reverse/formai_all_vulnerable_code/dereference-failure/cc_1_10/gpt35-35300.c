//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char name[50];
    char author[50];
    char version[20];
    char date_created[20];
    char date_modified[20];
} metadata_t;

metadata_t* extract_metadata(const char* filepath);

int main() {
    const char* file_path = "example.c";
    metadata_t* metadata = extract_metadata(file_path);

    if (metadata == NULL) {
        printf("Failed to extract metadata from file: %s\n", file_path);
        return 1;
    }

    printf("Name: %s\n", metadata->name);
    printf("Author: %s\n", metadata->author);
    printf("Version: %s\n", metadata->version);
    printf("Date created: %s\n", metadata->date_created);
    printf("Date modified: %s\n", metadata->date_modified);

    free(metadata);

    return 0;
}

metadata_t* extract_metadata(const char* filepath) {
    FILE* fp = fopen(filepath, "r");

    if (fp == NULL) {
        printf("Failed to open file: %s\n", filepath);
        return NULL;
    }

    metadata_t* metadata = (metadata_t*)malloc(sizeof(metadata_t));
    memset(metadata, 0, sizeof(metadata_t));

    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "// Name:", strlen("// Name:")) == 0) {
            strcpy(metadata->name, line + strlen("// Name:"));
            metadata->name[strcspn(metadata->name, "\n")] = '\0';
        }

        if (strncmp(line, "// Author:", strlen("// Author:")) == 0) {
            strcpy(metadata->author, line + strlen("// Author:"));
            metadata->author[strcspn(metadata->author, "\n")] = '\0';
        }

        if (strncmp(line, "// Version:", strlen("// Version:")) == 0) {
            strcpy(metadata->version, line + strlen("// Version:"));
            metadata->version[strcspn(metadata->version, "\n")] = '\0';
        }

        if (strncmp(line, "// Date created:", strlen("// Date created:")) == 0) {
            strcpy(metadata->date_created, line + strlen("// Date created:"));
            metadata->date_created[strcspn(metadata->date_created, "\n")] = '\0';
        }

        if (strncmp(line, "// Date modified:", strlen("// Date modified:")) == 0) {
            strcpy(metadata->date_modified, line + strlen("// Date modified:"));
            metadata->date_modified[strcspn(metadata->date_modified, "\n")] = '\0';
        }
    }

    fclose(fp);

    return metadata;
}