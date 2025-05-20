//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <dlfcn.h>

typedef struct Metadata {
    char *name;
    char *value;
} Metadata;

typedef struct MetadataExtractor {
    void *handle;
    void (*init)(void);
    void (*extract)(const char *fname, Metadata **metadata, size_t *count);
    void (*free)(Metadata **metadata, size_t count);
} MetadataExtractor;

MetadataExtractor *create_metadata_extractor(const char *libname) {
    MetadataExtractor *extractor = malloc(sizeof(MetadataExtractor));
    if (!extractor) {
        return NULL;
    }

    extractor->handle = dlopen(libname, RTLD_LAZY);
    if (!extractor->handle) {
        free(extractor);
        return NULL;
    }

    extractor->init = dlsym(extractor->handle, "init");
    if (!extractor->init) {
        dlclose(extractor->handle);
        free(extractor);
        return NULL;
    }

    extractor->extract = dlsym(extractor->handle, "extract");
    if (!extractor->extract) {
        dlclose(extractor->handle);
        free(extractor);
        return NULL;
    }

    extractor->free = dlsym(extractor->handle, "free");
    if (!extractor->free) {
        dlclose(extractor->handle);
        free(extractor);
        return NULL;
    }

    extractor->init();

    return extractor;
}

void destroy_metadata_extractor(MetadataExtractor *extractor) {
    if (!extractor) {
        return;
    }

    if (extractor->handle) {
        dlclose(extractor->handle);
    }

    free(extractor);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <libname>\n", argv[0]);
        return 1;
    }

    MetadataExtractor *extractor = create_metadata_extractor(argv[1]);
    if (!extractor) {
        printf("Failed to create metadata extractor\n");
        return 1;
    }

    Metadata *metadata = NULL;
    size_t count = 0;
    extractor->extract("test.txt", &metadata, &count);

    for (size_t i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    extractor->free(&metadata, count);
    destroy_metadata_extractor(extractor);

    return 0;
}