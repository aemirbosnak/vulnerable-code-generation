//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <carrier> <watermark> <output>\n", argv[0]);
        return 1;
    }

    // read carrier image
    FILE *carrier_file = fopen(argv[1], "rb");
    if (carrier_file == NULL) {
        fprintf(stderr, "Error opening carrier image\n");
        return 1;
    }
    fseek(carrier_file, 0, SEEK_END);
    size_t carrier_size = ftell(carrier_file);
    fseek(carrier_file, 0, SEEK_SET);
    uint8_t *carrier = malloc(carrier_size);
    fread(carrier, 1, carrier_size, carrier_file);
    fclose(carrier_file);

    // read watermark image
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        fprintf(stderr, "Error opening watermark image\n");
        return 1;
    }
    fseek(watermark_file, 0, SEEK_END);
    size_t watermark_size = ftell(watermark_file);
    fseek(watermark_file, 0, SEEK_SET);
    uint8_t *watermark = malloc(watermark_size);
    fread(watermark, 1, watermark_size, watermark_file);
    fclose(watermark_file);

    // embed watermark into carrier image
    int watermark_width = watermark_size / 3;
    int watermark_height = 3;
    int carrier_width = carrier_size / 3;
    int carrier_height = carrier_size / 3;
    for (int y = 0; y < watermark_height; y++) {
        for (int x = 0; x < watermark_width; x++) {
            uint8_t *carrier_pixel = &carrier[(y * carrier_width + x) * 3];
            uint8_t *watermark_pixel = &watermark[(y * watermark_width + x) * 3];
            for (int i = 0; i < 3; i++) {
                carrier_pixel[i] = (carrier_pixel[i] & 0xf0) | (watermark_pixel[i] >> 4);
            }
        }
    }

    // write watermarked image to file
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }
    fwrite(carrier, 1, carrier_size, output_file);
    fclose(output_file);

    free(carrier);
    free(watermark);

    return 0;
}