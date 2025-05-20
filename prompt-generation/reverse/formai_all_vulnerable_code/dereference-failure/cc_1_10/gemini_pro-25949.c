//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGB;

typedef struct {
    uint64_t color;
    uint8_t alpha;
} Pixel;

RGB toRGB(Pixel pixel) {
    return (RGB) {
        .red = (pixel.color >> 16) & 0xFF,
        .green = (pixel.color >> 8) & 0xFF,
        .blue = pixel.color & 0xFF
    };
}

Pixel toPixel(RGB rgb) {
    return (Pixel) {
        .color = (uint64_t)rgb.red << 16 | rgb.green << 8 | rgb.blue,
        .alpha = 0xFF
    };
}

int main() {
    // Define the image dimensions.
    int width = 640;
    int height = 480;

    // Allocate memory for the image.
    Pixel* image = malloc(width * height * sizeof(Pixel));

    // Read the image from a file.
    FILE* file = fopen("image.png", "rb");
    fread(image, sizeof(Pixel), width * height, file);
    fclose(file);

    // Get the secret message from the user.
    char* message = "Hello world!";

    // Convert the secret message to a bit array.
    int messageLength = strlen(message);
    uint8_t* messageBits = malloc(messageLength * 8);
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            messageBits[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Hide the secret message in the image.
    for (int i = 0; i < messageLength * 8; i++) {
        int index = i / 8;
        int bit = i % 8;

        RGB rgb = toRGB(image[index]);
        rgb.red = (rgb.red & ~1) | messageBits[i];
        image[index] = toPixel(rgb);
    }

    // Write the modified image to a file.
    file = fopen("image_with_message.png", "wb");
    fwrite(image, sizeof(Pixel), width * height, file);
    fclose(file);

    // Free the allocated memory.
    free(image);
    free(messageBits);

    return 0;
}