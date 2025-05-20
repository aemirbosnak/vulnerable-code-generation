//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAX_TAGS 100
#define MAX_TAGS_LEN 256

typedef struct {
    char *name;
    char *value;
} MetadataEntry;

typedef struct {
    MetadataEntry tags[MAX_TAGS];
    int num_tags;
} Metadata;

Metadata *create_metadata() {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->num_tags = 0;
    return metadata;
}

void add_tag(Metadata *metadata, char *name, char *value) {
    if (metadata->num_tags == MAX_TAGS) {
        return;
    }
    int index = metadata->num_tags++;
    metadata->tags[index].name = strdup(name);
    metadata->tags[index].value = strdup(value);
}

void print_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        free(metadata->tags[i].name);
        free(metadata->tags[i].value);
    }
    free(metadata);
}

int main() {
    Metadata *metadata = create_metadata();
    add_tag(metadata, "author", "Alan Turing");
    add_tag(metadata, "title", "On Computable Numbers, with an Application to the Entscheidungsproblem");
    add_tag(metadata, "year", "1936");
    add_tag(metadata, "journal", "Proceedings of the London Mathematical Society");

    print_metadata(metadata);
    printf("\n");

    free_metadata(metadata);
    return 0;
}