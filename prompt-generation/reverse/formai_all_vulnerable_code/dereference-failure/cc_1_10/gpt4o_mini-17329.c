//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide a message in the least significant bits of an image
void hide_message(const char* input_image, const char* output_image, const char* message) {
    FILE *inFile = fopen(input_image, "rb");
    FILE *outFile = fopen(output_image, "wb");
    
    if (!inFile || !outFile) {
        printf("Error opening files!\n");
        exit(1);
    }

    // Find the message length
    int msg_length = strlen(message);
    // Write the message length to the output file
    fwrite(&msg_length, sizeof(int), 1, outFile);

    // Read the image file and hide the message
    unsigned char pixel[3];
    int i = 0, bit;

    while (fread(pixel, sizeof(unsigned char), 3, inFile) == 3 && i < msg_length * 8) {
        for (int j = 0; j < 3 && i < msg_length * 8; j++) {
            bit = (message[i / 8] >> (7 - (i % 8))) & 1; // Get the next bit of the message
            pixel[j] = (pixel[j] & 0xFE) | bit; // Embed it into the LSB of the pixel
            i++;
        }
        fwrite(pixel, sizeof(unsigned char), 3, outFile);
    }

    // Write the remaining pixels unchanged
    while (fread(pixel, sizeof(unsigned char), 3, inFile) == 3) {
        fwrite(pixel, sizeof(unsigned char), 3, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Message hidden successfully!\n");
}

// Function to extract a hidden message from an image
void extract_message(const char* input_image) {
    FILE *inFile = fopen(input_image, "rb");
    
    if (!inFile) {
        printf("Error opening file!\n");
        exit(1);
    }

    int msg_length = 0;
    // Read the message length from the image
    fread(&msg_length, sizeof(int), 1, inFile);

    unsigned char pixel[3];
    char *message = (char*)malloc(msg_length + 1);
    memset(message, 0, msg_length + 1); // Null-terminate the string

    int i = 0, bit;

    while (fread(pixel, sizeof(unsigned char), 3, inFile) == 3 && i < msg_length * 8) {
        for (int j = 0; j < 3 && i < msg_length * 8; j++) {
            bit = pixel[j] & 1; // Get the least significant bit of the pixel
            message[i / 8] |= (bit << (7 - (i % 8))); // Rebuild the message byte by byte
            i++;
        }
    }

    fclose(inFile);
    printf("Extracted message: %s\n", message);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <mode> <input_image> <output_image> <message>\n", argv[0]);
        printf("Modes: hide, extract\n");
        return 1;
    }

    const char *mode = argv[1];
    const char *input_image = argv[2];
    const char *output_image = argv[3];
    const char *message = argv[4];

    if (strcmp(mode, "hide") == 0) {
        hide_message(input_image, output_image, message);
    } else if (strcmp(mode, "extract") == 0) {
        extract_message(input_image);
    } else {
        printf("Invalid mode! Use 'hide' or 'extract'.\n");
    }

    return 0;
}