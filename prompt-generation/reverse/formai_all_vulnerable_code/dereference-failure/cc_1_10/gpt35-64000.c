//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *key;
    char *value;
} metadata_t;

metadata_t metadata_decode(const char *data) {
    metadata_t metadata = { .key = NULL, .value = NULL};

    const char *eq = strchr(data, '=');
    if (!eq) goto fail;
    metadata.key = strndup(data, eq-data);

    size_t len = strlen(eq+1);
    metadata.value = malloc(len+1);
    if (!metadata.value) goto fail;

    memcpy(metadata.value, eq+1, len);
    metadata.value[len] = '\0';

    return metadata;

fail:
    free((void*)metadata.key);
    free(metadata.value);
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    free((void*)metadata->key);
    free(metadata->value);
    metadata->key = NULL;
    metadata->value = NULL;
}

void metadata_print(metadata_t *metadata) {
    printf("key: %s, value: %s\n", metadata->key, metadata->value);
}

int main(int argc, char **argv) {
    const char *data = "author=John Smith\n language=C\n year=2022\n";
    char *next = NULL;

    metadata_t metadata = { .key = NULL, .value = NULL };
    while ((next = strsep((char**)&data, "\n")) != NULL) {
        metadata = metadata_decode(next);
        metadata_print(&metadata);
        metadata_destroy(&metadata);
    }

    return 0;
}