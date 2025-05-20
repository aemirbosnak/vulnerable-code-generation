//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMetaStruct {
    char *name;
    char *description;
    char *author;
    char *version;
    char *license;
} CMetaStruct;

CMetaStruct extract_c_metadata(char *filename) {
    CMetaStruct meta_data;
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    int line_number = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return meta_data;
    }

    while (!feof(fp)) {
        fgets(buffer, MAX_BUFFER_SIZE, fp);
        line_number++;

        // Extract metadata lines
        if (buffer[0] == '{' && buffer[1] == '}') {
            char *key = strchr(buffer, ':');
            char *value = strchr(key, '}');

            // Set metadata values
            if (strcmp(key, "name") == 0) {
                meta_data.name = strdup(value);
            } else if (strcmp(key, "description") == 0) {
                meta_data.description = strdup(value);
            } else if (strcmp(key, "author") == 0) {
                meta_data.author = strdup(value);
            } else if (strcmp(key, "version") == 0) {
                meta_data.version = strdup(value);
            } else if (strcmp(key, "license") == 0) {
                meta_data.license = strdup(value);
            }
        }
    }

    fclose(fp);

    return meta_data;
}

int main() {
    CMetaStruct meta_data = extract_c_metadata("my_program.c");

    printf("Name: %s\n", meta_data.name);
    printf("Description: %s\n", meta_data.description);
    printf("Author: %s\n", meta_data.author);
    printf("Version: %s\n", meta_data.version);
    printf("License: %s\n", meta_data.license);

    return 0;
}