//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMetadatExtracter {
    char **metadata_keys;
    int metadata_key_size;
    char **metadata_values;
    int metadata_value_size;
} CMetadatExtracter;

CMetadatExtracter *extract_metadata(char *filename) {
    CMetadatExtracter *extractor = malloc(sizeof(CMetadatExtracter));
    extractor->metadata_keys = NULL;
    extractor->metadata_key_size = 0;
    extractor->metadata_values = NULL;
    extractor->metadata_value_size = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    int read_size = 0;
    while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        char *key_start = strstr(buffer, "key=");
        char *value_start = strstr(buffer, "value=");

        if (key_start && value_start) {
            int key_length = value_start - key_start - 5;
            extractor->metadata_keys = realloc(extractor->metadata_keys, (extractor->metadata_key_size + 1) * sizeof(char *));
            extractor->metadata_keys[extractor->metadata_key_size++] = malloc(key_length + 1);
            memcpy(extractor->metadata_keys[extractor->metadata_key_size - 1], key_start + 5, key_length);
            extractor->metadata_keys[extractor->metadata_key_size - 1][key_length] = '\0';

            int value_length = strlen(value_start) - 6;
            extractor->metadata_values = realloc(extractor->metadata_values, (extractor->metadata_value_size + 1) * sizeof(char *));
            extractor->metadata_values[extractor->metadata_value_size++] = malloc(value_length + 1);
            memcpy(extractor->metadata_values[extractor->metadata_value_size - 1], value_start + 6, value_length);
            extractor->metadata_values[extractor->metadata_value_size - 1][value_length] = '\0';
        }
    }

    fclose(fp);
    return extractor;
}

int main() {
    CMetadatExtracter *extractor = extract_metadata("my_file.txt");

    if (extractor) {
        for (int i = 0; i < extractor->metadata_key_size; i++) {
            printf("%s: %s\n", extractor->metadata_keys[i], extractor->metadata_values[i]);
        }

        free(extractor->metadata_keys);
        free(extractor->metadata_values);
        free(extractor);
    }

    return 0;
}