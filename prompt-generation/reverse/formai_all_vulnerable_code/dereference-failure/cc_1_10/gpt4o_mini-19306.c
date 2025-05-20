//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: genius
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
} BMPHeader;

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
} BMPInfoHeader;
#pragma pack(pop)

void embed_message(const char *image_path, const char *message, const char *output_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        fprintf(stderr, "Error: Could not open image file.\n");
        return;
    }
    
    // Read BMP headers
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(bmpHeader), 1, image);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, image);
    
    // Check if the file is a 24-bit BMP
    if (bmpHeader.bfType != 0x4D42 || bmpInfoHeader.biBitCount != 24) {
        fprintf(stderr, "Error: Not a valid 24-bit BMP file.\n");
        fclose(image);
        return;
    }

    // Prepare to embed the message
    fseek(image, bmpHeader.bfOffBits, SEEK_SET);
    
    // Make sure the message fits
    int message_length = strlen(message);
    if (message_length * 8 > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3)) {
        fprintf(stderr, "Error: Message is too long to embed in this image.\n");
        fclose(image);
        return;
    }

    // Embed message length
    for (int i = 0; i < message_length; i++) {
        char byte = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, image);  // Read one pixel (3 bytes)
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> (7 - j)) & 0x01);
            fwrite(pixel, sizeof(unsigned char), 3, image);  // Write modified pixel
        }
    }
    
    // Write back the rest of the image
    unsigned char buffer[3];
    while (fread(buffer, sizeof(buffer), 1, image)) {
        fwrite(buffer, sizeof(buffer), 1, image);
    }
    
    fclose(image);

    // Save modified image
    FILE *output_image = fopen(output_path, "wb");
    if (!output_image) {
        fprintf(stderr, "Error: Could not open output file for writing.\n");
        return;
    }
    
    // Write BMP headers back to the new image
    fwrite(&bmpHeader, sizeof(bmpHeader), 1, output_image);
    fwrite(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, output_image);
    
    // Copy the modified data to the new image
    fseek(image, bmpHeader.bfOffBits, SEEK_SET);
    fseek(output_image, bmpHeader.bfOffBits, SEEK_SET);
    fseek(image, 0, SEEK_SET);
    while (fread(buffer, sizeof(buffer), 1, image)) {
        fwrite(buffer, sizeof(buffer), 1, output_image);
    }
    
    fclose(output_image);
    printf("Message embedded successfully into %s!\n", output_path);
}

void extract_message(const char *image_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        fprintf(stderr, "Error: Could not open image file.\n");
        return;
    }

    // Read BMP headers
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(bmpHeader), 1, image);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, image);
    
    // Check if the file is a 24-bit BMP
    if (bmpHeader.bfType != 0x4D42 || bmpInfoHeader.biBitCount != 24) {
        fprintf(stderr, "Error: Not a valid 24-bit BMP file.\n");
        fclose(image);
        return;
    }

    char message[256] = {0};
    fseek(image, bmpHeader.bfOffBits, SEEK_SET);

    // Read embedded message
    int message_length = 0;
    while (message_length < 255) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, image);
            byte |= ((pixel[0] & 0x01) << (7 - j));
        }
        if (byte == '\0') break;  // End of message
        message[message_length++] = byte;
    }

    fclose(image);
    printf("Extracted message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <image_path> <message/output_path>\n", argv[0]);
        return 1;
    }
    
    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Unknown command. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}