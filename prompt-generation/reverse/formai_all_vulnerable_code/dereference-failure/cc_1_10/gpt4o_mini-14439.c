//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure to represent a Bitmap Header
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // File type
    uint32_t bfSize;      // Size of the file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap
    int32_t  biHeight;        // Height of the bitmap
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the image
    int32_t  biXPelsPerMeter;   // Pixels per meter in X
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors used
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function to write a message into the least significant bits of the pixel
void embedMessage(uint8_t *pixel, char message_char) {
    pixel[0] = (pixel[0] & 0xFE) | ((message_char >> 0) & 0x01); // Red
    pixel[1] = (pixel[1] & 0xFE) | ((message_char >> 1) & 0x01); // Green
    pixel[2] = (pixel[2] & 0xFE) | ((message_char >> 2) & 0x01); // Blue
}

// Function to embed a secret message in an image
void embedSecretMessage(const char *message, const char *input_image_filename, const char *output_image_filename) {
    FILE *input = fopen(input_image_filename, "rb");
    if (!input) {
        printf("Alas! The image file could not be opened.\n");
        return;
    }

    BITMAPFILEHEADER bmpHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, input);
  
    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;
    int padding = (4 - (width * 3) % 4) % 4;

    fseek(input, bmpHeader.bfOffBits, SEEK_SET);
  
    uint8_t *image_data = (uint8_t *)malloc(3 * width * height + height * padding);
    if (!image_data) {
        printf("Oh dear! Memory allocation failed.\n");
        fclose(input);
        return;
    }
    fread(image_data, 3, width * height, input);
    fseek(input, padding, SEEK_CUR); // Skip the padding

    // Embed the message
    size_t message_length = strlen(message);
    for (size_t i = 0; i < message_length; i++) {
        if (i >= (width * height)) break; // Avoid exceeding image bounds
        embedMessage(&image_data[i * 3], message[i]);
    }

    FILE *output = fopen(output_image_filename, "wb");
    if (!output) {
        printf("Hark! The output file could not be created.\n");
        free(image_data);
        fclose(input);
        return;
    }

    fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, output);
    fwrite(image_data, 3, width * height, output);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < padding; j++) {
            fputc(0, output);
        }
    }

    printf("The secret message hath been embedded within the image!\n");

    // Cleanup
    free(image_data);
    fclose(input);
    fclose(output);
}

// Main function to demonstrate the art of Steganography in a medieval manner
int main() {
    printf("Welcome to the Art of Hidden Messages!\n");
    
    // Specify your image and message here
    const char *input_image = "noble_picture.bmp"; 
    const char *output_image = "noble_picture_steg.bmp";
    const char *secret_message = "A secret in the realm!";

    printf("Behold! The image hath been chosen: %s\n", input_image);
    printf("And the message to be hidden: %s\n", secret_message);
    
    embedSecretMessage(secret_message, input_image, output_image);

    printf("Farewell, good seeker! The task is complete.\n");
    return 0;
}