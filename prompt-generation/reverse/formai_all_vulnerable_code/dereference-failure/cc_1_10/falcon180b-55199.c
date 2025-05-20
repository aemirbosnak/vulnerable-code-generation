//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100

typedef struct {
    char *key;
    char *value;
} metadata_t;

int compare_metadata(const void *a, const void *b) {
    metadata_t *ma = (metadata_t *) a;
    metadata_t *mb = (metadata_t *) b;
    return strcmp(ma->key, mb->key);
}

void print_metadata(metadata_t *metadata, int count) {
    qsort(metadata, count, sizeof(metadata_t), compare_metadata);
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    metadata_t *metadata = NULL;
    int count = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            printf("Invalid metadata format in line: %s\n", line);
            continue;
        }

        metadata = realloc(metadata, sizeof(metadata_t) * ++count);
        metadata[count - 1].key = strdup(key);
        metadata[count - 1].value = strdup(value);
    }

    fclose(file);
    print_metadata(metadata, count);
    for (int i = 0; i < count; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}