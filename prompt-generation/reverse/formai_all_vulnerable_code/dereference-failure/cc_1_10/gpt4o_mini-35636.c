//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void hide_message_in_image(const char *bmp_filename, const char *message_filename, const char *output_filename) {
    FILE *bmp_file = fopen(bmp_filename, "rb");
    if (!bmp_file) {
        perror("Could not open BMP file");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmp_file);

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    int width = bih.biWidth;
    int height = bih.biHeight;
    int pixel_array_offset = bfh.bfOffBits;

    // Move to the pixel array in the BMP file
    fseek(bmp_file, pixel_array_offset, SEEK_SET);

    // Read the entire BMP file into memory
    unsigned char *image_data = (unsigned char *)malloc(bfh.bfSize);
    fread(image_data, 1, bfh.bfSize, bmp_file);

    fclose(bmp_file);

    // Read the message from the file
    FILE *message_file = fopen(message_filename, "r");
    if (!message_file) {
        perror("Could not open message file");
        free(image_data);
        return;
    }

    char message[256];
    fgets(message, sizeof(message), message_file);
    fclose(message_file);

    // Add a termination character for the message
    strcat(message, "!");  // Mark end of the message with '!'
    int message_length = strlen(message);

    // Hide the message in the least significant bit of the image data
    int index = 0;
    for (int i = 0; i < message_length * 8; i++) {
        int byte_index = (i / 8) + pixel_array_offset;  // Find the byte in the image
        int bit_index = i % 8;                            // Find the bit position
        unsigned char bit = (message[i / 8] >> (7 - bit_index)) & 1;

        // Clear least significant bit
        image_data[byte_index] &= 0xFE; // Set the LSB to 0
        
        // Set the LSB to the bit of the message
        image_data[byte_index] |= bit;  
    }

    // Save the new image with the hidden message
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Could not create output file");
        free(image_data);
        return;
    }

    fwrite(image_data, 1, bfh.bfSize, output_file);
    fclose(output_file);
    free(image_data);

    printf("Message hidden successfully!\n");
}

int main() {
    const char *bmp_filename = "input.bmp";         // Input BMP file
    const char *message_filename = "message.txt";   // Text file containing the message
    const char *output_filename = "output.bmp";     // Output BMP file

    hide_message_in_image(bmp_filename, message_filename, output_filename);
    
    return 0;
}