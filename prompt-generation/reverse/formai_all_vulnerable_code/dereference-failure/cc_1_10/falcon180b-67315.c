//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *line) {
    char *key = NULL;
    char *value = NULL;
    char *delimiter = ":";
    char *token = strtok(line, delimiter);
    
    if (token == NULL) {
        return NULL;
    }
    
    key = strdup(token);
    
    token = strtok(NULL, delimiter);
    
    if (token == NULL) {
        free(key);
        return NULL;
    }
    
    value = strdup(token);
    
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->key = key;
    metadata->value = value;
    
    return metadata;
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void metadata_free(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main() {
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    
    FILE *file = fopen("metadata.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata = metadata_parse(line);
        
        if (metadata!= NULL) {
            metadata_print(metadata);
            metadata_free(metadata);
        }
    }
    
    fclose(file);
    
    return 0;
}