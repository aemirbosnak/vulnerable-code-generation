//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN 512
#define WATERMARK "LoveIsEternal" // The text we will hide in the image's pixel values.

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void embed_watermark(Image *img, const char *watermark);
void extract_watermark(Image *img, char *extracted_watermark, int length);
void free_image(Image *img);

int main() {
    char filename[MAX_LEN];
    char extracted_watermark[MAX_LEN];

    printf("The sun sets, casting shadows upon your gentle heart. \n");
    printf("Whisper in my ear, your favorite image filename: ");
    scanf("%s", filename);

    // Load the image where we will plant our seeds of love.
    Image *img = load_image(filename);
    if (!img) {
        printf("Alas, dear heart, I could not find that image!\n");
        return 1;
    }

    printf("Stealthily, like a love letter carried by the wind, we embed a watermark...\n");
    embed_watermark(img, WATERMARK);
    
    // Save our beloved image with the hidden message.
    char watermarked_filename[MAX_LEN];
    snprintf(watermarked_filename, MAX_LEN, "watermarked_%s", filename);
    save_image(watermarked_filename, img);
    printf("Our beloved has been saved as: %s\n", watermarked_filename);
    
    // Now, let’s retrieve our sweet message.
    extract_watermark(img, extracted_watermark, strlen(WATERMARK));
    printf("The hidden message is: %s\n", extracted_watermark);

    free_image(img);
    return 0;
}

Image* load_image(const char *filename) {
    // This function will simulate an image loading
    // For a real scenario, we would parse an image file format like PPM, BMP, etc.
    // Here, we create a dummy image for demonstration.

    int width = 10; // We'll have a small image for simplicity.
    int height = 10;

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(Pixel) * width * height);

    for (int i = 0; i < width * height; ++i) {
        img->pixels[i].r = rand() % 256;
        img->pixels[i].g = rand() % 256;
        img->pixels[i].b = rand() % 256;
    }

    return img;
}

void save_image(const char *filename, Image *img) {
    // This function would normally save an image.
    // Here we will only print a message to simulate saving.
    printf("Saving the romantic image to %s...\n", filename);
}

void embed_watermark(Image *img, const char *watermark) {
    size_t len = strlen(watermark);
    for (size_t i = 0; i < len; ++i) {
        // We use the red channel of each pixel to embed our watermark
        img->pixels[i].r = (img->pixels[i].r & 0xFE) | ((watermark[i] >> 7) & 0x01);
    }
}

void extract_watermark(Image *img, char *extracted_watermark, int length) {
    for (int i = 0; i < length; ++i) {
        // Extracting the watermark from the red channel
        extracted_watermark[i] = (img->pixels[i].r & 0x01) << 7; // Get the last bit
        for (int j = 6; j >= 0; --j) {
            extracted_watermark[i] |= ((img->pixels[i + 1].r & (1 << j)) >> j);
        }
    }
    extracted_watermark[length] = '\0'; // Null terminate the string
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}