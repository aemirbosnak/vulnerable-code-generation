//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define EMBEDDED_MSG_SIZE 1024

typedef struct {
    uint8_t *data;
    size_t size;
} Image;

typedef struct {
    uint8_t *data;
    size_t size;
} Watermark;

Watermark *create_watermark(const char *msg) {
    Watermark *wm = malloc(sizeof(Watermark));
    wm->size = strlen(msg);
    wm->data = malloc(wm->size);
    memcpy(wm->data, msg, wm->size);
    return wm;
}

void free_watermark(Watermark *wm) {
    free(wm->data);
    free(wm);
}

Image *create_image(uint8_t *data, size_t size) {
    Image *img = malloc(sizeof(Image));
    img->data = data;
    img->size = size;
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

uint8_t *embed_watermark(const Image *img, const Watermark *wm) {
    if (img->size < wm->size) {
        return NULL;
    }

    uint8_t *watermarked_data = malloc(img->size);
    memcpy(watermarked_data, img->data, img->size);

    for (int i = 0; i < wm->size; i++) {
        uint8_t bit = wm->data[i] & 0x01;
        watermarked_data[i] &= 0xFE;
        watermarked_data[i] |= bit;
    }

    return watermarked_data;
}

Watermark *extract_watermark(const Image *img) {
    Watermark *wm = create_watermark("");

    for (int i = 0; i < img->size; i++) {
        uint8_t bit = img->data[i] & 0x01;
        wm->data[i] = bit;
    }

    return wm;
}

int main() {
    // Create an image
    uint8_t img_data[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    };
    Image *img = create_image(img_data, sizeof(img_data));

    // Create a watermark
    Watermark *wm = create_watermark("hello world");

    // Embed the watermark in the image
    uint8_t *watermarked_data = embed_watermark(img, wm);

    // Create an image from the watermarked data
    Image *watermarked_img = create_image(watermarked_data, img->size);

    // Extract the watermark from the watermarked image
    Watermark *extracted_wm = extract_watermark(watermarked_img);

    // Compare the extracted watermark with the original watermark
    int is_equal = strcmp((char *)extracted_wm->data, (char *)wm->data) == 0;

    // Print the result
    printf("Watermark is equal to the original watermark: %d\n", is_equal);

    // Free the resources
    free_image(img);
    free_watermark(wm);
    free_image(watermarked_img);
    free_watermark(extracted_wm);

    return 0;
}