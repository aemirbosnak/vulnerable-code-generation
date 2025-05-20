//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VAL 255

typedef struct {
    uint8_t pixels[HEIGHT][WIDTH];
} Image;

void load_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fread(img->pixels, sizeof(uint8_t), HEIGHT * WIDTH, file);
    fclose(file);
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(img->pixels, sizeof(uint8_t), HEIGHT * WIDTH, file);
    fclose(file);
}

void embed_watermark(Image *img, const char *watermark, int offset) {
    size_t wm_len = strlen(watermark);
    for (size_t i = 0; i < wm_len; ++i) {
        for (int j = 0; j < 8; ++j) {
            int bit = (watermark[i] >> (7 - j)) & 1;
            int x = (i + offset) % HEIGHT;
            int y = (i + offset) % WIDTH;

            img->pixels[x][y] = (img->pixels[x][y] & ~1) | bit;
        }
    }
}

void extract_watermark(Image *img, char *buffer, int offset, size_t wm_len) {
    for (size_t i = 0; i < wm_len; ++i) {
        buffer[i] = 0;
        for (int j = 0; j < 8; ++j) {
            int x = (i + offset) % HEIGHT;
            int y = (i + offset) % WIDTH;

            int bit = img->pixels[x][y] & 1;
            buffer[i] = (buffer[i] << 1) | bit;
        }
    }
}

void display_image(Image *img) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", img->pixels[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark_text> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *watermark = argv[2];
    const char *output_file = argv[3];
    int offset = 0; // Can be modified based on user requirement

    Image img;
    load_image(input_file, &img);

    printf("Original Image Loaded, Dimensions: %dx%d\n", WIDTH, HEIGHT);
    
    embed_watermark(&img, watermark, offset);
    printf("Watermark Embedded: \"%s\"\n", watermark);
    
    save_image(output_file, &img);
    printf("Output Image Saved: %s\n", output_file);

    // Extract watermark for verification
    char extracted_watermark[256] = {0}; // make sure it's big enough
    extract_watermark(&img, extracted_watermark, offset, strlen(watermark));
    
    printf("Extracted Watermark: \"%s\"\n", extracted_watermark);

    return EXIT_SUCCESS;
}