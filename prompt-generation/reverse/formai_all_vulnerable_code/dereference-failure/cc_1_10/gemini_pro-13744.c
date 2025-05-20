//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TAG_SIZE 4

typedef struct Image {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

typedef struct ExifData {
    uint32_t ifd0_offset;
    uint16_t num_tags;
    uint32_t *tags;
} ExifData;

Image read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    Image image;
    fseek(fp, 10, SEEK_SET);
    fread(&image.width, sizeof(uint32_t), 1, fp);
    fread(&image.height, sizeof(uint32_t), 1, fp);
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image.data = malloc(size);
    fread(image.data, size, 1, fp);
    fclose(fp);

    return image;
}

ExifData read_exif_data(const uint8_t *data) {
    ExifData exif;
    memcpy(&exif.ifd0_offset, data + 6, TAG_SIZE);
    memcpy(&exif.num_tags, data + exif.ifd0_offset, TAG_SIZE);
    exif.tags = malloc(exif.num_tags * TAG_SIZE);
    memcpy(exif.tags, data + exif.ifd0_offset + TAG_SIZE, exif.num_tags * TAG_SIZE);

    return exif;
}

void print_exif_data(const ExifData *exif) {
    printf("Number of tags: %u\n", exif->num_tags);
    for (int i = 0; i < exif->num_tags; i++) {
        uint32_t tag = exif->tags[i];
        printf("Tag %u: %08x\n", i, tag);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Image image = read_image(argv[1]);
    ExifData exif = read_exif_data(image.data);
    print_exif_data(&exif);

    free(image.data);
    free(exif.tags);

    return EXIT_SUCCESS;
}