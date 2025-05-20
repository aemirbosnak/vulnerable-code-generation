//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    uint32_t width;
    uint32_t height;
    Pixel *data;
} Image;

Image *load_bmp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    uint32_t width, height;
    fread(&width, sizeof(uint32_t), 1, file);
    fread(&height, sizeof(uint32_t), 1, file);

    fseek(file, 54, SEEK_SET);
    Pixel *data = (Pixel *)malloc(sizeof(Pixel) * width * height);
    fread(data, sizeof(Pixel), width * height, file);
    fclose(file);

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;
    return img;
}

void save_bmp(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return;
    }

    uint32_t fileSize = 54 + 3 * img->width * img->height;
    uint32_t reserved = 0;
    uint32_t dataOffset = 54;
    uint32_t dibHeaderSize = 40;
    uint16_t planes = 1;
    uint16_t bpp = 24;
    uint32_t compression = 0;
    uint32_t dataSize = 0;
    uint32_t pixelsPerMeter = 2835;
    uint32_t colorsInPalette = 0;

    fwrite("BM", 2, 1, file);
    fwrite(&fileSize, sizeof(uint32_t), 1, file);
    fwrite(&reserved, sizeof(uint32_t), 1, file);
    fwrite(&dataOffset, sizeof(uint32_t), 1, file);
    fwrite(&dibHeaderSize, sizeof(uint32_t), 1, file);
    fwrite(&img->width, sizeof(uint32_t), 1, file);
    fwrite(&img->height, sizeof(uint32_t), 1, file);
    fwrite(&planes, sizeof(uint16_t), 1, file);
    fwrite(&bpp, sizeof(uint16_t), 1, file);
    fwrite(&compression, sizeof(uint32_t), 1, file);
    fwrite(&dataSize, sizeof(uint32_t), 1, file);
    fwrite(&pixelsPerMeter, sizeof(uint32_t), 1, file);
    fwrite(&pixelsPerMeter, sizeof(uint32_t), 1, file);
    fwrite(&colorsInPalette, sizeof(uint32_t), 1, file);
    fwrite(&colorsInPalette, sizeof(uint32_t), 1, file);

    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void embed_message(Image *img, const char *message) {
    size_t msg_len = strlen(message);
    size_t total_bits = img->width * img->height * 3; // 3 channels (RGB)
    
    if (msg_len * 8 > total_bits) {
        fprintf(stderr, "Message is too large to embed in the image.\n");
        return;
    }

    for (size_t i = 0; i < msg_len; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> (7 - j)) & 1;
            size_t pixel_index = (i * 8 + j) % total_bits;
            size_t pixel_pos = pixel_index / 3;
            int channel = pixel_index % 3;

            if (channel == 0) img->data[pixel_pos].r = (img->data[pixel_pos].r & 0xFE) | bit;
            if (channel == 1) img->data[pixel_pos].g = (img->data[pixel_pos].g & 0xFE) | bit;
            if (channel == 2) img->data[pixel_pos].b = (img->data[pixel_pos].b & 0xFE) | bit;
        }
    }
}

void extract_message(Image *img, char *buffer, size_t buffer_size) {
    size_t msg_len = 0;
    for (size_t i = 0; i < buffer_size; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            size_t pixel_index = (i * 8 + j) % (img->width * img->height * 3);
            size_t pixel_pos = pixel_index / 3;
            int channel = pixel_index % 3;

            int bit;
            if (channel == 0) bit = img->data[pixel_pos].r & 1;
            if (channel == 1) bit = img->data[pixel_pos].g & 1;
            if (channel == 2) bit = img->data[pixel_pos].b & 1;

            c = (c << 1) | bit;
        }
        if (c == '\0') break;
        buffer[msg_len++] = c;
    }
    buffer[msg_len] = '\0';
}

int main() {
    const char *input_image = "input.bmp";
    const char *output_image = "output.bmp";
    const char *secret_message = "Hello World!";

    Image *img = load_bmp(input_image);
    if (img == NULL) return 1;

    embed_message(img, secret_message);
    save_bmp(output_image, img);

    char extracted_message[256];
    extract_message(img, extracted_message, sizeof(extracted_message));
    printf("Extracted message: %s\n", extracted_message);

    free(img->data);
    free(img);
    return 0;
}