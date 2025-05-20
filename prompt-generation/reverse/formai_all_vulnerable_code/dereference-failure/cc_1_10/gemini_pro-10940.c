//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: scalable
// Scalable Image Steganography in C
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Pixel data structure
typedef struct {
    uint8_t r, g, b;
} Pixel;

// Image array type
typedef Pixel** Image;

// Image header
typedef struct {
    uint32_t width, height;
} ImageHeader;

// Load image from file
Image loadImage(const char* filename, ImageHeader* header) {
    // Open file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Read header
    fread(header, sizeof(ImageHeader), 1, file);

    // Allocate image array
    Image image = malloc(header->height * sizeof(Pixel*));
    for (int i = 0; i < header->height; i++) {
        image[i] = malloc(header->width * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < header->height; i++) {
        for (int j = 0; j < header->width; j++) {
            fread(&image[i][j], sizeof(Pixel), 1, file);
        }
    }

    // Close file
    fclose(file);

    return image;
}

// Save image to file
void saveImage(const char* filename, Image image, ImageHeader header) {
    // Open file
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write header
    fwrite(&header, sizeof(ImageHeader), 1, file);

    // Write pixel data
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            fwrite(&image[i][j], sizeof(Pixel), 1, file);
        }
    }

    // Close file
    fclose(file);
}

// Hide message in image
void hideMessage(Image image, ImageHeader header, const char* message) {
    // Convert message to bits
    uint8_t* bits = malloc(strlen(message) * 8);
    for (int i = 0; i < strlen(message); i++) {
        for (int j = 0; j < 8; j++) {
            bits[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Hide bits in pixels
    int bitIndex = 0;
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            // Modify red channel to hide 2 bits
            image[i][j].r &= 0xFC;
            image[i][j].r |= bits[bitIndex++];

            // Modify green channel to hide 3 bits
            image[i][j].g &= 0xE7;
            image[i][j].g |= (bits[bitIndex++] << 3);

            // Modify blue channel to hide 3 bits
            image[i][j].b &= 0xE7;
            image[i][j].b |= (bits[bitIndex++] << 3);

            // Check if all bits are hidden
            if (bitIndex == strlen(message) * 8) {
                return;
            }
        }
    }
}

// Extract message from image
char* extractMessage(Image image, ImageHeader header) {
    // Allocate memory for message
    char* message = malloc(header.width * header.height / 8);

    // Extract bits from pixels
    int bitIndex = 0;
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            // Extract 2 bits from red channel
            message[bitIndex / 8] |= (image[i][j].r & 3) << (bitIndex % 8);
            bitIndex++;

            // Extract 3 bits from green channel
            message[bitIndex / 8] |= ((image[i][j].g >> 3) & 7) << (bitIndex % 8);
            bitIndex++;

            // Extract 3 bits from blue channel
            message[bitIndex / 8] |= ((image[i][j].b >> 3) & 7) << (bitIndex % 8);
            bitIndex++;

            // Check if all bits are extracted
            if (bitIndex == strlen(message) * 8) {
                return message;
            }
        }
    }

    return NULL;
}

// Main function
int main() {
    // Load image
    ImageHeader header;
    Image image = loadImage("image.bmp", &header);
    if (!image) {
        return 1;
    }

    // Hide message in image
    hideMessage(image, header, "Hello world!");

    // Save stego image
    saveImage("stego.bmp", image, header);

    // Extract message from image
    char* message = extractMessage(image, header);
    if (!message) {
        printf("Could not extract message.\n");
        return 1;
    }

    printf("Extracted message: %s\n", message);

    // Free allocated memory
    free(image);
    free(message);

    return 0;
}