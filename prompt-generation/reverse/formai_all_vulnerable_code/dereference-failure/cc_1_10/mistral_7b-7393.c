//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint16_t signature;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} bmp_header;

typedef struct {
    uint32_t signature;
    uint32_t size;
} bmp_metadata_header;

typedef struct {
    uint32_t id;
    uint32_t size;
    uint32_t offset;
} bmp_metadata_entry;

typedef struct {
    uint32_t type;
    uint32_t size;
    uint32_t offset;
    uint32_t data_size;
} bmp_custom_metadata;

void parse_bmp_metadata(FILE *fp, bmp_metadata_entry *entry, bmp_custom_metadata *custom_metadata) {
    fseek(fp, entry->offset, SEEK_SET);

    bmp_metadata_header metadata_header;
    fread(&metadata_header, sizeof(metadata_header), 1, fp);

    if (metadata_header.signature != 0x424D) {
        printf("Invalid metadata header\n");
        return;
    }

    uint32_t num_entries = metadata_header.size / sizeof(bmp_metadata_entry);
    for (uint32_t i = 0; i < num_entries; i++) {
        fread(entry, sizeof(bmp_metadata_entry), 1, fp);

        if (entry->id == 0x270E) { // Custom metadata tag
            fseek(fp, entry->offset, SEEK_SET);
            fread(custom_metadata, sizeof(bmp_custom_metadata), 1, fp);
            printf("Custom metadata:\n");
            printf("\tType: %s\n", custom_metadata->type > 0 ? "XMP" : "ICM");
            printf("\tSize: %d bytes\n", custom_metadata->size);
            printf("\tOffset: %d bytes\n", custom_metadata->offset);
            printf("\tData size: %d bytes\n", custom_metadata->data_size);
            break;
        }

        entry++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <BMP file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    bmp_header bmp_header;
    fread(&bmp_header, sizeof(bmp_header), 1, fp);

    if (bmp_header.signature != 0x4D42) {
        printf("Invalid BMP header\n");
        fclose(fp);
        return 1;
    }

    bmp_metadata_entry metadata_entry;
    bmp_custom_metadata custom_metadata;

    parse_bmp_metadata(fp, &metadata_entry, &custom_metadata);

    fclose(fp);

    return 0;
}