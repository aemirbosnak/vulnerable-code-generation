//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_METADATA_VALUE_LENGTH 100

typedef struct {
    char key[MAX_METADATA_VALUE_LENGTH];
    char value[MAX_METADATA_VALUE_LENGTH];
} Metadata;

int read_metadata_from_file(char *file_path, Metadata **metadata_list, int *num_metadata_entries) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_path);
        return -1;
    }
    
    char line[MAX_METADATA_VALUE_LENGTH * 2];
    *num_metadata_entries = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");
        if (key == NULL || value == NULL) {
            printf("Malformed metadata entry in file %s: %s\n", file_path, line);
            continue;
        }
        Metadata *new_metadata = (Metadata *) malloc(sizeof(Metadata));
        if (new_metadata == NULL) {
            printf("Error allocating memory for new metadata entry in file %s\n", file_path);
            return -1;
        }
        strncpy(new_metadata->key, key, strlen(key));
        strncpy(new_metadata->value, value, strlen(value));
        (*metadata_list)[*num_metadata_entries] = *new_metadata;
        (*num_metadata_entries)++;
    }
    
    fclose(fp);
    return 0;
}

int main() {
    Metadata *metadata_list = (Metadata *) malloc(sizeof(Metadata) * 100);
    int num_metadata_entries;
    
    char file_path[MAX_FILE_PATH_LENGTH] = "example_metadata.txt";
    if (read_metadata_from_file(file_path, &metadata_list, &num_metadata_entries) == -1) {
        printf("Error reading metadata from file %s\n", file_path);
        return -1;
    }
    
    printf("Metadata entries in file %s:\n", file_path);
    for (int i = 0; i < num_metadata_entries; i++) {
        printf("%s=%s\n", metadata_list[i].key, metadata_list[i].value);
    }
    
    return 0;
}