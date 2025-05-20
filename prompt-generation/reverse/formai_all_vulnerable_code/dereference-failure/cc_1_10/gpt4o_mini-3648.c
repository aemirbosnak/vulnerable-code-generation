//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IMAGE_SIZE 640*480  // A small resolution for simplicity
#define MAGIC_NUMBER "APOC"

/* Basic structure to store image meta data */
typedef struct {
    char magic[4];  // Magic number to identify the file type
    uint32_t width;
    uint32_t height;
    uint32_t dataSize;
} ImageHeader;

/* Structure for representing a pixel */
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

/* RGB image data */
Pixel image[MAX_IMAGE_SIZE];

/* Function to load the image */
int loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open the image file: %s\n", filename);
        return -1;
    }
    
    ImageHeader header;
    fread(&header, sizeof(ImageHeader), 1, file);

    if (strncmp(header.magic, MAGIC_NUMBER, 4) != 0) {
        fprintf(stderr, "Invalid image format\n");
        fclose(file);
        return -1;
    }

    header.dataSize = header.width * header.height;
    fread(image, sizeof(Pixel), header.dataSize, file);
    fclose(file);

    return header.dataSize;
}

/* Function to save the image */
void saveImage(const char *filename, uint32_t width, uint32_t height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot open the file to save image: %s\n", filename);
        return;
    }
    
    ImageHeader header;
    strncpy(header.magic, MAGIC_NUMBER, 4);
    header.width = width;
    header.height = height;
    header.dataSize = width * height;

    fwrite(&header, sizeof(ImageHeader), 1, file);
    fwrite(image, sizeof(Pixel), header.dataSize, file);
    fclose(file);
}

/* Function for basic steganography - hiding text in least significant bits */
void hideText(const char *secret, int position, int textLength) {
    for (int i = 0; i < textLength && position + i < MAX_IMAGE_SIZE; i++) {
        // Take each character of the secret message
        uint8_t character = secret[i];
        // Modify the least significant bit of the pixel's red component
        image[position + i].r = (image[position + i].r & 0xFE) | (character & 0x01);
        character >>= 1; // Shift right to get the next bit
    }
}

/* Function to extract hidden text from the image */
void extractText(char *output, int position, int textLength) {
    for (int i = 0; i < textLength && position + i < MAX_IMAGE_SIZE; i++) {
        // Read the least significant bit from the pixel's red component
        output[i] = (image[position + i].r & 0x01) + 0x30; // Convert to ASCII (cm)
        output[i] = (output[i] == '0') ? 0 : 1; // Convert to a boolean
    }
    output[textLength] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <secret_message>\n", argv[0]);
        return EXIT_FAILURE;
    }
  
    int position = 0; // Position to start hiding the secret message
   
    // Load the image file
    int dataSize = loadImage(argv[1]);
    if (dataSize <= 0) return EXIT_FAILURE;

    // Hide the secret message in the image
    hideText(argv[2], position, strlen(argv[2]));

    // Save the new image with the hidden message
    saveImage("output_image.apoc", 640, 480);

    // Prepare to extract the hidden text for verification
    char extractedText[100] = {0};
    extractText(extractedText, position, strlen(argv[2]));

    printf("Hidden Message Extracted: %s\n", extractedText);
    return EXIT_SUCCESS;
}