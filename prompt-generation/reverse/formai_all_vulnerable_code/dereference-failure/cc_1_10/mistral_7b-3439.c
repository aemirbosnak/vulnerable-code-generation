//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#pragma pack(push, 1)
typedef struct __tagMETADATA {
    char magic[4];
    uint32_t version;
    uint32_t dataSize;
    char name[32];
    uint32_t flags;
} METADATA;
#pragma pack(pop)

int main(int argc, char **argv) {
    FILE *fp;
    METADATA metadata;
    char fileName[64];
    int result;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <metadata file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(fileName, argv[1]);
    fp = fopen(fileName, "rb");

    if (!fp) {
        fprintf(stderr, "Could not open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fread(&metadata, sizeof(METADATA), 1, fp);

    if (memcmp(metadata.magic, "META", 4) != 0) {
        fprintf(stderr, "File %s is not a valid metadata file\n", fileName);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    printf("File %s metadata:\n", fileName);
    printf("Version: %u\n", metadata.version);
    printf("Data size: %u bytes\n", metadata.dataSize);
    printf("Name: %s\n", metadata.name);
    printf("Flags: 0x%08X\n", metadata.flags);

    fclose(fp);
    return EXIT_SUCCESS;
}