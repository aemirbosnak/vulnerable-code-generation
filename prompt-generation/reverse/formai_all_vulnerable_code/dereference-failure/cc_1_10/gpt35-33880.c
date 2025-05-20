//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Decentralized Metadata Extractor
// Extracts metadata from various file formats

typedef struct {
    uint8_t tag[4];
    uint8_t size[4];
    uint8_t *value;
} metadata_t;

// Function to extract metadata from ID3 tags
void id3_metadata_extractor(FILE *fp, int size, metadata_t *metadata) {
    int count = 0;
    while (count < size) {
        metadata_t m;
        fread(&m.tag, 1, 4, fp);
        fread(&m.size, 1, 4, fp);
        m.value = (uint8_t*)malloc(sizeof(uint8_t)*(*(uint32_t*)m.size));
        fread(m.value, 1, *(uint32_t*)m.size, fp);
        metadata[count] = m;
        count++;
    }
}

// Function to extract metadata from EXIF tags
void exif_metadata_extractor(FILE *fp, int size, metadata_t *metadata) {
    int count = 0;
    while (count < size) {
        metadata_t m;
        fread(&m.tag, 1, 2, fp);
        fread(&m.size, 1, 2, fp);
        m.value = (uint8_t*)malloc(sizeof(uint8_t)*(*(uint16_t*)m.size));
        fread(m.value, 1, *(uint16_t*)m.size, fp);
        metadata[count] = m;
        count++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("%s could not be opened.\n", argv[1]);
        return 1;
    }

    char ext[5];
    strncpy(ext, &argv[1][strlen(argv[1])-4], 4);

    // Check file extension to determine metadata format
    metadata_t *metadata = (metadata_t*)malloc(sizeof(metadata_t)*10);
    int count = 0;
    if (strcmp(ext, ".mp3") == 0) {
        // Extract metadata from ID3 tags
        fseek(fp, 10, SEEK_SET);
        uint8_t size[4];
        fread(&size, 1, 4, fp);
        int total_size = 10 + *(uint32_t*)size;
        fseek(fp, -4, SEEK_CUR);
        id3_metadata_extractor(fp, total_size, metadata);
        count++;
    }
    else if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
        // Extract metadata from EXIF tags
        uint8_t header[4];
        fread(&header, 1, 4, fp);
        fseek(fp, -4, SEEK_CUR);
        if (memcmp(header, "Exif", 4) == 0) {
            fseek(fp, 6, SEEK_CUR);
            uint16_t size[2];
            fread(&size, 1, 2, fp);
            int total_size = *(uint16_t*)size - 8;
            exif_metadata_extractor(fp, total_size, metadata);
            count++;
        }
    }

    fclose(fp);

    // Print extracted metadata
    for (int i = 0; i < count; i++) {
        printf("Metadata %d\n", i+1);
        printf("Tag: %c%c%c%c\n", metadata[i].tag[0], metadata[i].tag[1], metadata[i].tag[2], metadata[i].tag[3]);
        printf("Size: %d\n", *(uint32_t*)metadata[i].size);
        printf("Value: %s\n\n", metadata[i].value);
    }

    return 0;
}