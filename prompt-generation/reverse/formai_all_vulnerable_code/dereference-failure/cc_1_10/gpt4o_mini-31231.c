//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message(const char *input_image, const char *output_image, const char *message) {
    FILE *fin = fopen(input_image, "rb");
    if (!fin) {
        perror("Error opening input file");
        return;
    }

    FILE *fout = fopen(output_image, "wb");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, fin);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, fin);

    fwrite(&bfHeader, sizeof(BITMAPFILEHEADER), 1, fout);
    fwrite(&biHeader, sizeof(BITMAPINFOHEADER), 1, fout);

    // Calculate the offset to pixel data
    fseek(fin, bfHeader.bfOffBits, SEEK_SET);
    fseek(fout, bfHeader.bfOffBits, SEEK_SET);

    // Store the message length
    size_t message_length = strlen(message);
    fwrite(&message_length, sizeof(size_t), 1, fout);
    
    // Embed the message in the least significant bits of the image pixels
    uint8_t pixel[3];  // For RGB
    for (size_t i = 0; i < message_length; i++) {
        fread(pixel, sizeof(uint8_t), 3, fin);

        // Change the least significant bit of the blue channel to embed the message
        pixel[0] = (pixel[0] & ~1) | ((message[i] >> 0) & 1);
        pixel[1] = (pixel[1] & ~1) | ((message[i] >> 1) & 1);
        pixel[2] = (pixel[2] & ~1) | ((message[i] >> 2) & 1);
        
        fwrite(pixel, sizeof(uint8_t), 3, fout);
    }

    // Copy the remaining pixels
    while (fread(pixel, sizeof(uint8_t), 3, fin)) {
        fwrite(pixel, sizeof(uint8_t), 3, fout);
    }

    fclose(fin);
    fclose(fout);
}

void extract_message(const char *input_image) {
    FILE *fin = fopen(input_image, "rb");
    if (!fin) {
        perror("Error opening input file");
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, fin);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, fin);

    fseek(fin, bfHeader.bfOffBits, SEEK_SET);
    
    // Read the length of the embedded message
    size_t message_length;
    fread(&message_length, sizeof(size_t), 1, fin);
    
    char *message = (char *)malloc(message_length + 1); 
    if (!message) {
        perror("Error allocating memory");
        fclose(fin);
        return;
    }
    
    for (size_t i = 0; i < message_length; i++) {
        uint8_t pixel[3];

        // Read the pixel data
        fread(pixel, sizeof(uint8_t), 3, fin);
        
        // Extract the message bit from the least significant bits
        message[i] = 0;
        message[i] |= (pixel[0] & 1) << 0;
        message[i] |= (pixel[1] & 1) << 1;
        message[i] |= (pixel[2] & 1) << 2;
    }

    message[message_length] = '\0'; // Null-terminate the string
    printf("Extracted Message: %s\n", message);
    free(message);
    fclose(fin);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <mode> <input_image> <output_image_or_message>\n", argv[0]);
        printf("Mode: 1 for embedding message, 2 for extracting message\n");
        return 1;
    }

    int mode = atoi(argv[1]);
    if (mode == 1) {
        const char *input_image = argv[2];
        const char *output_image = argv[3];
        char message[256];

        printf("Enter the message to embed (max 255 characters): ");
        fgets(message, 256, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        embed_message(input_image, output_image, message);
        printf("Message embedded successfully!\n");
        
    } else if (mode == 2) {
        const char *input_image = argv[2];
        extract_message(input_image);
    } else {
        printf("Invalid mode. Please use 1 or 2.\n");
    }

    return 0;
}