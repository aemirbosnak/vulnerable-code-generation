//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (100 * 1024 * 1024) // 100 MB

typedef struct {
    char *key;
    char *value;
} Metadata;

typedef struct {
    int count;
    Metadata *metadata;
} MetadataList;

static void addMetadata(MetadataList *list, char *key, char *value) {
    if (list->count >= MAX_FILE_SIZE) {
        printf("Error: Maximum file size reached.\n");
        exit(1);
    }

    list->metadata = realloc(list->metadata, sizeof(Metadata) * ++list->count);
    list->metadata[list->count - 1].key = strdup(key);
    list->metadata[list->count - 1].value = strdup(value);
}

static void printMetadata(MetadataList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->metadata[i].key, list->metadata[i].value);
    }
}

static void freeMetadata(MetadataList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->metadata[i].key);
        free(list->metadata[i].value);
    }
    free(list->metadata);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    MetadataList metadataList = {0};

    char line[1024];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (key == NULL || value == NULL) {
            continue;
        }

        addMetadata(&metadataList, key, value);
    }

    fclose(inputFile);

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        freeMetadata(&metadataList);
        return 1;
    }

    printMetadata(&metadataList);

    fclose(outputFile);
    freeMetadata(&metadataList);

    return 0;
}