//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_METADATA_SIZE 1024
#define MAX_TAG_NAME_SIZE 64
#define MAX_TAG_VALUE_SIZE 512

typedef struct {
    char name[MAX_TAG_NAME_SIZE];
    char value[MAX_TAG_VALUE_SIZE];
} MetadataTag;

typedef struct {
    int num_tags;
    MetadataTag tags[MAX_METADATA_SIZE];
} Metadata;

Metadata* extract_metadata(char* input) {
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->num_tags = 0;

    char* token = strtok(input, ";");
    while (token != NULL) {
        char* name = strtok(token, "=");
        char* value = strtok(NULL, "=");

        MetadataTag tag;
        strcpy(tag.name, name);
        strcpy(tag.value, value);

        metadata->tags[metadata->num_tags++] = tag;

        token = strtok(NULL, ";");
    }

    return metadata;
}

void print_metadata(Metadata* metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main() {
    char* input = "title=The Beatles;artist=John Lennon, Paul McCartney, George Harrison, Ringo Starr;album=Sgt. Pepper's Lonely Hearts Club Band;year=1967";

    Metadata* metadata = extract_metadata(input);

    print_metadata(metadata);

    free(metadata);

    return 0;
}