//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} Metadata;

int compare_metadata(const void *a, const void *b) {
    Metadata *metadata_a = (Metadata *) a;
    Metadata *metadata_b = (Metadata *) b;

    return strcmp(metadata_a->key, metadata_b->key);
}

void parse_metadata(char *line, Metadata *metadata) {
    char *key_value_pair = strstr(line, ": ");
    if (key_value_pair == NULL) {
        return;
    }

    *key_value_pair = '\0';
    metadata->key = strdup(line);
    metadata->value = strdup(key_value_pair + 2);
}

void free_metadata(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char **argv) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    Metadata *metadata = NULL;
    int metadata_count = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        parse_metadata(line, metadata);
        metadata_count++;
    }

    qsort(metadata, metadata_count, sizeof(Metadata), compare_metadata);

    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    free(metadata);
    fclose(input_file);

    return 0;
}