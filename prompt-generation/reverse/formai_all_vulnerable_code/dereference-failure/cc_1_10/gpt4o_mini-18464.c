//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 640
#define HEIGHT 480
#define WATERMARK_SIZE 64

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

void load_image(const char *filename, Pixel image[HEIGHT][WIDTH]);
void save_image(const char *filename, Pixel image[HEIGHT][WIDTH]);
void embed_watermark(Pixel image[HEIGHT][WIDTH], const char *watermark, const size_t size);
void extract_watermark(Pixel image[HEIGHT][WIDTH], char *watermark, size_t *size);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
        return 1;
    }
    
    const char *input_image = argv[1];
    const char *output_image = argv[2];
    const char *watermark_text = argv[3];
    const char action = argv[4][0];

    Pixel image[HEIGHT][WIDTH];
    
    load_image(input_image, image);

    if (action == 'e') {
        embed_watermark(image, watermark_text, strlen(watermark_text));
        save_image(output_image, image);
        printf("Watermark embedded and saved to %s\n", output_image);
    } else if (action == 'x') {
        char extracted_watermark[WATERMARK_SIZE + 1] = {0};
        size_t size = 0;
        
        extract_watermark(image, extracted_watermark, &size);
        printf("Extracted Watermark: %s\n", extracted_watermark);
    } else {
        print_usage();
        return 1;
    }
    
    return 0;
}

void load_image(const char *filename, Pixel image[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fread(image, sizeof(Pixel), HEIGHT * WIDTH, file);
    fclose(file);
}

void save_image(const char *filename, Pixel image[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(image, sizeof(Pixel), HEIGHT * WIDTH, file);
    fclose(file);
}

void embed_watermark(Pixel image[HEIGHT][WIDTH], const char *watermark, const size_t size) {
    for (size_t i = 0; i < size && i < WATERMARK_SIZE; i++) {
        int x = (i % WIDTH);
        int y = (i / WIDTH) % HEIGHT;
        
        image[y][x].r = (image[y][x].r & 0xFE) | ((watermark[i] & 0x80) >> 7);
        image[y][x].g = (image[y][x].g & 0xFE) | ((watermark[i] & 0x40) >> 6);
        image[y][x].b = (image[y][x].b & 0xFE) | ((watermark[i] & 0x20) >> 5);
    }
}

void extract_watermark(Pixel image[HEIGHT][WIDTH], char *watermark, size_t *size) {
    for (size_t i = 0; i < WATERMARK_SIZE; i++) {
        int x = (i % WIDTH);
        int y = (i / WIDTH) % HEIGHT;
        
        watermark[i] = 0;
        watermark[i] |= (image[y][x].r & 0x01) << 7;
        watermark[i] |= (image[y][x].g & 0x01) << 6;
        watermark[i] |= (image[y][x].b & 0x01) << 5;
    }
    watermark[WATERMARK_SIZE] = '\0';
    *size = WATERMARK_SIZE;
}

void print_usage() {
    printf("Usage:\n");
    printf("  To embed watermark: ./watermark input_image.raw output_image.raw 'watermark_text' e\n");
    printf("  To extract watermark: ./watermark input_image.raw output_image.raw '' x\n");
}