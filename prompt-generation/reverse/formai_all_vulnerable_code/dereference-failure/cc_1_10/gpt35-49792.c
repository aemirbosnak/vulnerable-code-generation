//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8
#define MAX_MESSAGE_SIZE 256

/**
 * Structure representing a block of pixels
 */
typedef struct {
    unsigned char values[BLOCK_SIZE][BLOCK_SIZE];
} Block;

/**
 * Structure representing the digital watermark containing the message
 */
typedef struct {
    int size;
    char message[MAX_MESSAGE_SIZE];
} Watermark;

/**
 * Function to embed a digital watermark into an image
 * @param image Input image
 * @param watermark Digital watermark to be embedded
 * @return Embedded image
 */
Block** embed_watermark(Block** image, Watermark watermark) {
    // Calculate the number of blocks in the image
    int rows = sizeof(image) / sizeof(image[0]);
    int cols = sizeof(image[0]) / sizeof(Block);
    
    // Verify that the message can fit into the image
    if (watermark.size > rows * cols * BLOCK_SIZE * BLOCK_SIZE) {
        printf("Error: The message is too large to be embedded into the image.\n");
        exit(1);
    }
    
    // Convert watermark message to binary
    char message_bits[watermark.size * 8];
    for (int i = 0; i < watermark.size; i++) {
        for (int j = 0; j < 8; j++) {
            message_bits[i * 8 + j] = (watermark.message[i] >> j) & 0x01;
        }
    }
    
    // Embed each bit of the message into each block of pixels in the image
    int bit_index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    if (bit_index < watermark.size * 8) {
                        image[i][j].values[k][l] &= 0xFE; // Clear least significant bit
                        image[i][j].values[k][l] |= message_bits[bit_index];
                        bit_index++;
                    }
                }
            }
        }
    }
    
    return image;
}

/**
 * Function to extract a digital watermark from an image
 * @param image Input image containing the watermark
 * @param size Size of the watermark message
 * @return Extracted watermark
 */
Watermark extract_watermark(Block** image, int size) {
    // Calculate the number of blocks in the image
    int rows = sizeof(image) / sizeof(image[0]);
    int cols = sizeof(image[0]) / sizeof(Block);
    
    // Extract each bit of the message from each block of pixels in the image
    char message_bytes[size];
    int bit_index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    if (bit_index < size * 8) {
                        message_bytes[bit_index / 8] |= (image[i][j].values[k][l] & 0x01) << (bit_index % 8);
                        bit_index++;
                    }
                }
            }
        }
    }
    
    // Create the extracted watermark
    Watermark watermark = {size, ""};
    memcpy(watermark.message, message_bytes, size);
    
    return watermark;
}

int main() {
    // Create a test image
    Block** image = (Block**) malloc(sizeof(Block*) * 4);
    for (int i = 0; i < 4; i++) {
        image[i] = (Block*) malloc(sizeof(Block) * 4);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    image[i][j].values[k][l] = (i + j + k + l) % 256;
                }
            }
        }
    }
    
    // Embed a watermark into the image
    Watermark watermark = {15, "Hello World!"};
    image = embed_watermark(image, watermark);
    
    // Extract the watermark from the image
    Watermark extracted_watermark = extract_watermark(image, watermark.size);
    
    // Display the extracted watermark message
    printf("Extracted message: %s\n", extracted_watermark.message);
    
    return 0;
}