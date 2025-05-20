//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef struct {
    uint32_t offset;
    uint32_t length;
    char *data;
} MetadataItem;

typedef struct {
    uint32_t count;
    MetadataItem *items;
} MetadataList;

MetadataList *extractMetadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *data = malloc(filesize);
    if (data == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    fread(data, 1, filesize, file);
    fclose(file);

    MetadataList *metadata = malloc(sizeof(MetadataList));
    if (metadata == NULL) {
        perror("malloc");
        free(data);
        return NULL;
    }

    metadata->count = 0;
    metadata->items = NULL;

    uint32_t offset = 0;
    while (offset < filesize) {
        uint32_t length = *(uint32_t *)(data + offset);
        if (length > filesize - offset) {
            break;
        }

        MetadataItem *item = malloc(sizeof(MetadataItem));
        if (item == NULL) {
            perror("malloc");
            free(metadata);
            free(data);
            return NULL;
        }

        item->offset = offset;
        item->length = length;
        item->data = malloc(length + 1);
        if (item->data == NULL) {
            perror("malloc");
            free(metadata);
            free(data);
            free(item);
            return NULL;
        }

        memcpy(item->data, data + offset + 4, length);
        item->data[length] = '\0';

        metadata->count++;
        metadata->items = realloc(metadata->items, metadata->count * sizeof(MetadataItem));
        if (metadata->items == NULL) {
            perror("realloc");
            free(metadata);
            free(data);
            free(item);
            free(item->data);
            return NULL;
        }

        metadata->items[metadata->count - 1] = *item;

        offset += length + 4;
    }

    free(data);
    return metadata;
}

void printMetadata(const MetadataList *metadata) {
    for (uint32_t i = 0; i < metadata->count; i++) {
        printf("Offset: 0x%08X\n", metadata->items[i].offset);
        printf("Length: 0x%08X\n", metadata->items[i].length);
        printf("Data: %s\n", metadata->items[i].data);
        printf("\n");
    }
}

void freeMetadata(MetadataList *metadata) {
    for (uint32_t i = 0; i < metadata->count; i++) {
        free(metadata->items[i].data);
    }

    free(metadata->items);
    free(metadata);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    MetadataList *metadata = extractMetadata(argv[1]);
    if (metadata == NULL) {
        fprintf(stderr, "Could not extract metadata from file.\n");
        return 1;
    }

    printMetadata(metadata);

    freeMetadata(metadata);

    return 0;
}