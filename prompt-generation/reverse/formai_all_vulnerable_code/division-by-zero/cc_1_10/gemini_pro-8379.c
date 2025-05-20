//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret watermark
#define WATERMARK "I'm a funny watermark!"

// Embed the watermark in an image
void embed_watermark(unsigned char *image, int image_size) {
    // Find a random spot to hide our watermark
    int offset = rand() % (image_size - strlen(WATERMARK));

    // Embed the watermark in the image, one byte at a time
    for (int i = 0; i < strlen(WATERMARK); i++) {
        image[offset + i] ^= WATERMARK[i];
    }
}

// Extract the watermark from an image
char *extract_watermark(unsigned char *image, int image_size) {
    // Find the watermark in the image
    char *watermark = malloc(strlen(WATERMARK) + 1);
    int offset = -1;

    for (int i = 0; i < image_size - strlen(WATERMARK); i++) {
        int mismatch = 0;

        // Check if the current byte matches the watermark
        for (int j = 0; j < strlen(WATERMARK); j++) {
            if (image[i + j] ^ WATERMARK[j]) {
                mismatch = 1;
                break;
            }
        }

        // If we found a match, store the offset
        if (!mismatch) {
            offset = i;
            break;
        }
    }

    // If we didn't find the watermark, return NULL
    if (offset == -1) {
        return NULL;
    }

    // Extract the watermark from the image
    for (int i = 0; i < strlen(WATERMARK); i++) {
        watermark[i] = image[offset + i] ^ WATERMARK[i];
    }

    watermark[strlen(WATERMARK)] = '\0';

    // Return the watermark
    return watermark;
}

// Test our watermarking functions
int main() {
    // Create a test image
    unsigned char image[] = "This is a test image.";
    int image_size = sizeof(image);

    // Embed the watermark in the image
    embed_watermark(image, image_size);

    // Extract the watermark from the image
    char *watermark = extract_watermark(image, image_size);

    // Print the watermark
    printf("The watermark is: %s\n", watermark);

    // Free the watermark
    free(watermark);

    return 0;
}