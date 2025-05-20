//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SECTOR_SIZE 512

typedef struct {
    uint32_t lba;
    uint16_t sector_count;
    uint8_t data[SECTOR_SIZE];
} sector_t;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);

    long sector_count = image_size / SECTOR_SIZE;
    sector_t *sectors = malloc(sector_count * sizeof(sector_t));
    if (sectors == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (long i = 0; i < sector_count; i++) {
        sectors[i].lba = i;
        sectors[i].sector_count = 1;
        fread(sectors[i].data, SECTOR_SIZE, 1, image_file);
    }

    for (long i = 0; i < sector_count; i++) {
        if (memcmp(sectors[i].data, "\x55\xAA", 2) == 0) {
            long start_lba = sectors[i].lba;
            long end_lba = start_lba + sectors[i].sector_count - 1;

            for (long j = start_lba; j <= end_lba; j++) {
                fwrite(sectors[j].data, SECTOR_SIZE, 1, output_file);
            }
            break;
        }
    }

    free(sectors);
    fclose(image_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}