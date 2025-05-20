//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t rol32(uint32_t n, unsigned int c) {
    return (n >> (32 - c)) | (n << c);
}

uint32_t ror32(uint32_t n, unsigned int c) {
    return (n << (32 - c)) | (n >> c);
}

typedef struct {
    char *name;
    size_t size;
    unsigned char *data;
} image;

image *load_image(char *file) {
    FILE *f = fopen(file, "rb");
    if (!f) return NULL;

    image *img = malloc(sizeof(image));
    fseek(f, 0, SEEK_END);
    img->size = ftell(f);
    rewind(f);
    img->data = malloc(img->size);
    fread(img->data, 1, img->size, f);
    fclose(f);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void embed_watermark(image *img, char *watermark) {
    uint32_t key = 0x12345678;
    size_t i = 0;

    for (; i < img->size && watermark[i]; i++) {
        img->data[i] ^= rol32(key, 1) & 0xff;
        key = ror32(key, 3);
        key ^= watermark[i];
    }
}

char *extract_watermark(image *img, char *watermark) {
    uint32_t key = 0x12345678;
    size_t i = 0;

    for (; i < img->size && watermark[i]; i++) {
        watermark[i] = img->data[i] ^ rol32(key, 1) & 0xff;
        key = ror32(key, 3);
        key ^= watermark[i];
    }

    return watermark;
}

int main() {
    char watermark[] = "Hidden message";
    image *img = load_image("image.jpg");
    if (!img) return 1;

    embed_watermark(img, watermark);
    char *extracted = extract_watermark(img, watermark);

    printf("Watermark: %s\n", extracted);
    free(extracted);
    free_image(img);
    return 0;
}