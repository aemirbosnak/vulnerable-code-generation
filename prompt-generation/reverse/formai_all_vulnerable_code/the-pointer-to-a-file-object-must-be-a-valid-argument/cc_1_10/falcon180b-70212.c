//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 256

typedef struct {
    char *name;
    char *value;
} metadata_t;

typedef struct {
    metadata_t *metadata;
    int num_metadata;
} metadata_list_t;

metadata_t *metadata_create(char *name, char *value) {
    metadata_t *m = malloc(sizeof(metadata_t));
    m->name = strdup(name);
    m->value = strdup(value);
    return m;
}

metadata_list_t *metadata_list_create() {
    metadata_list_t *l = malloc(sizeof(metadata_list_t));
    l->metadata = NULL;
    l->num_metadata = 0;
    return l;
}

void metadata_list_add(metadata_list_t *l, metadata_t *m) {
    l->metadata = realloc(l->metadata, sizeof(metadata_t) * (l->num_metadata + 1));
    l->metadata[l->num_metadata] = *m;
    l->num_metadata++;
}

void metadata_list_free(metadata_list_t *l) {
    for (int i = 0; i < l->num_metadata; i++) {
        free(l->metadata[i].name);
        free(l->metadata[i].value);
    }
    free(l->metadata);
    free(l);
}

int main() {
    FILE *f = fopen("example.txt", "r");
    char line[MAX_LINE_LENGTH];
    metadata_list_t *metadata = metadata_list_create();

    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        char *token = strtok(line, ":");
        char *name = strtok(NULL, ":");
        char *value = strtok(NULL, ":");

        if (name!= NULL && value!= NULL) {
            metadata_t *m = metadata_create(name, value);
            metadata_list_add(metadata, m);
        }
    }

    for (int i = 0; i < metadata->num_metadata; i++) {
        metadata_t *m = metadata->metadata + i;
        printf("%s: %s\n", m->name, m->value);
    }

    metadata_list_free(metadata);
    fclose(f);

    return 0;
}