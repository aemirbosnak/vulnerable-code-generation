//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void encode_message_to_image(const char *image_path, const char *message, const char *output_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        perror("Error opening image file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image);

    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(image);
        return;
    }

    uint32_t pixelDataOffset = bfh.bfOffBits;
    fseek(image, pixelDataOffset, SEEK_SET);
    
    // Prepare to read pixels
    uint32_t width = bih.biWidth;
    uint32_t height = bih.biHeight;
    uint32_t pixels_count = width * height;
    RGB *pixels = (RGB *)malloc(pixels_count * sizeof(RGB));
    fread(pixels, sizeof(RGB), pixels_count, image);
    fclose(image);

    // Embed the message length in the first pixel
    uint32_t message_length = strlen(message);
    for (int i = 0; i < 32; ++i) {
        if (i < 8) {
            pixels[0].blue = (pixels[0].blue & 0xFE) | ((message_length >> (7 - i)) & 0x01);
        } else if (i < 16) {
            pixels[0].green = (pixels[0].green & 0xFE) | ((message_length >> (15 - i)) & 0x01);
        } else {
            pixels[0].red = (pixels[0].red & 0xFE) | ((message_length >> (23 - i)) & 0x01);
        }
    }

    // Embed the message
    for (size_t i = 0; i < message_length; ++i) {
        for (int j = 0; j < 8; ++j) {
            RGB *pixel = &pixels[(i * 8 + j + 1)];
            if (i * 8 + j + 1 >= pixels_count) break; // Check for overflow
            pixel->blue = (pixel->blue & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

    // Write the modified image to the output file
    FILE *output = fopen(output_path, "wb");
    if (!output) {
        perror("Error opening output file");
        free(pixels);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output);
    fwrite(pixels, sizeof(RGB), pixels_count, output);
    
    fclose(output);
    free(pixels);
    printf("Message encoded successfully!\n");
}

void decode_message_from_image(const char *image_path) {
    FILE *image = fopen(image_path, "rb");
    if (!image) {
        perror("Error opening image file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image);

    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(image);
        return;
    }

    uint32_t pixelDataOffset = bfh.bfOffBits;
    fseek(image, pixelDataOffset, SEEK_SET);
    
    uint32_t width = bih.biWidth;
    uint32_t height = bih.biHeight;
    uint32_t pixels_count = width * height;
    RGB *pixels = (RGB *)malloc(pixels_count * sizeof(RGB));
    fread(pixels, sizeof(RGB), pixels_count, image);
    fclose(image);

    // Decode message length
    uint32_t message_length = 0;
    for (int i = 0; i < 32; ++i) {
        if (i < 8) {
            message_length |= (pixels[0].blue & 0x01) << (7 - i);
        } else if (i < 16) {
            message_length |= (pixels[0].green & 0x01) << (15 - i);
        } else {
            message_length |= (pixels[0].red & 0x01) << (23 - i);
        }
    }

    // Extract the message
    char *message = (char *)malloc(message_length + 1);
    for (size_t i = 0; i < message_length; ++i) {
        message[i] = 0;
        for (int j = 0; j < 8; ++j) {
            RGB *pixel = &pixels[(i * 8 + j + 1)];
            if (i * 8 + j + 1 >= pixels_count) break; // Check for overflow
            message[i] |= (pixel->blue & 0x01) << (7 - j);
        }
    }
    message[message_length] = '\0';
    
    printf("Decoded Message: %s\n", message);
    free(message);
    free(pixels);
}

int main() {
    const char *image_path = "input.bmp";
    const char *output_path = "output.bmp";
    const char *secret_message = "Hello, this is a secret message!";
    
    encode_message_to_image(image_path, secret_message, output_path);
    decode_message_from_image(output_path);
    
    return 0;
}