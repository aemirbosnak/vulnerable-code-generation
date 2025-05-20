//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

typedef struct {
    char *filename;
    int num_metadata;
    Metadata *metadata;
} File;

void add_metadata(File *file) {
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    int i;
    FILE *fp = fopen(file->filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file->filename);
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        i = 0;
        name = strtok(line, ":");
        value = strtok(NULL, ":");
        if (name == NULL || value == NULL) {
            printf("Invalid metadata in file %s\n", file->filename);
            exit(1);
        }
        if (file->num_metadata >= MAX_FILE_NAME_LENGTH) {
            printf("Too many metadata in file %s\n", file->filename);
            exit(1);
        }
        file->metadata[file->num_metadata].name = strdup(name);
        file->metadata[file->num_metadata].value = strdup(value);
        file->num_metadata++;
    }
    fclose(fp);
}

void print_metadata(File *file) {
    int i;
    for (i = 0; i < file->num_metadata; i++) {
        printf("%s: %s\n", file->metadata[i].name, file->metadata[i].value);
    }
}

int main(int argc, char *argv[]) {
    int i;
    if (argc < 2) {
        printf("Usage: %s file1.txt file2.txt...\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        File file;
        file.filename = argv[i];
        file.num_metadata = 0;
        file.metadata = NULL;
        add_metadata(&file);
        print_metadata(&file);
        free(file.metadata);
    }
    return 0;
}