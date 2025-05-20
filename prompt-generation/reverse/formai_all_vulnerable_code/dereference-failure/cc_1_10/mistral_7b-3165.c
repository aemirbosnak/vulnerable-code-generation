//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define SURPRISE_ME_MAGIC 0xDEADBEEF
#define SURPRISE_ME_VERSION 1

typedef struct {
    uint32_t magic;
    uint32_t version;
    uint32_t size;
    char name[64];
} SurpriseMeMetadata;

void surprise_me_extract(const uint8_t* data, size_t size) {
    SurpriseMeMetadata metadata;

    if (size < sizeof(metadata)) {
        fprintf(stderr, "Data too small\n");
        return;
    }

    memcpy(&metadata, data, sizeof(metadata));

    if (metadata.magic != SURPRISE_ME_MAGIC || metadata.version != SURPRISE_ME_VERSION) {
        fprintf(stderr, "Invalid metadata\n");
        return;
    }

    size_t name_len = metadata.size - sizeof(metadata);

    if (name_len > 64) {
        fprintf(stderr, "Name too long\n");
        return;
    }

    printf("Found SurpriseMe metadata:\n");
    printf("  Name: %s\n", metadata.name);
    printf("  Size: %zu bytes\n", metadata.size);

    // Surprise the user with a random message!
    char* surprise = malloc(100);
    for (size_t i = 0; i < 100; i++) {
        surprise[i] = (char)rand() % 26 + 'A';
    }
    surprise[99] = '\0';
    printf("  Surprise: %s\n", surprise);

    free(surprise);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return 1;
    }

    size_t data_size = strlen(argv[1]) + 1;
    uint8_t* data = malloc(data_size);

    memcpy(data, argv[1], data_size);

    surprise_me_extract(data, data_size);

    free(data);
    return 0;
}