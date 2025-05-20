//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: brave
// Embark on an audacious watermarking odyssey, where pixels dance to the rhythm of hidden data!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Behold, the canvas upon which our watery tale unfolds!
typedef struct {
    uint8_t *data;
    int width, height;
} Image;

// Extract the image's essence, pixel by pixel
Image load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) { perror("Failed to open image"); exit(1); }

    Image img;
    fread(&img.width, sizeof(int), 1, f);
    fread(&img.height, sizeof(int), 1, f);
    img.data = malloc(img.width * img.height * 3);
    fread(img.data, img.width * img.height * 3, 1, f);
    fclose(f);

    return img;
}

// Encode a secret in the depths of the image's pixels
void encode_watermark(Image *img, const char *message) {
    int i = 0, j = 0, k = 0;
    int bit = 0;

    while (message[k]) {
        // Sneak a bit of data into the least significant bit of each pixel's blue component
        img->data[i * img->width * 3 + j * 3 + 2] &= ~1;
        img->data[i * img->width * 3 + j * 3 + 2] |= (message[k] >> bit) & 1;

        // Advance through the message and the pixel array
        bit++;
        j++;
        if (j == img->width) { j = 0; i++; }
        if (bit == 8) { bit = 0; k++; }
    }
}

// Disembark the shipwrecked bits from the watery depths of the image
char *decode_watermark(const Image *img) {
    int i = 0, j = 0, k = 0;
    int bit = 0;
    char *message = malloc(img->width * img->height / 3);

    while (i < img->height && j < img->width) {
        // Rescue a bit of data from the least significant bit of each pixel's blue component
        message[k] |= (img->data[i * img->width * 3 + j * 3 + 2] & 1) << bit;
        bit++;

        // Advance through the pixel array and the message
        j++;
        if (j == img->width) { j = 0; i++; }
        if (bit == 8) { bit = 0; k++; }
    }

    return message;
}

int main() {
    // Load the image, a canvas for our watery tale
    Image img = load_image("image.bmp");

    // Encode a secret message in the watery depths of the pixels
    char *message = "Ahoy there, matey! This be a secret message hidden in the pixels.";
    encode_watermark(&img, message);

    // Save the watermarked image
    FILE *f = fopen("watermarked-image.bmp", "wb");
    if (!f) { perror("Failed to save watermarked image"); exit(1); }
    fwrite(&img.width, sizeof(int), 1, f);
    fwrite(&img.height, sizeof(int), 1, f);
    fwrite(img.data, img.width * img.height * 3, 1, f);
    fclose(f);

    // Disembark the hidden message from the watery depths
    char *decoded_message = decode_watermark(&img);
    printf("Disembarking message...\n");
    printf("%s\n", decoded_message);

    return 0;
}