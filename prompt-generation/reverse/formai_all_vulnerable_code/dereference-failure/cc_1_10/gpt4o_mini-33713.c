//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: intelligent
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
} BMPFileHeader;

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
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void embed_message(const char *message, const char *input_image, const char *output_image) {
    FILE *input = fopen(input_image, "rb");
    if (!input) {
        perror("Error opening input image");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader bmpFileHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input);

    if (bmpFileHeader.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    long img_data_size = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    fseek(input, bmpFileHeader.bfOffBits, SEEK_SET);
    Pixel *pixels = (Pixel *)malloc(img_data_size);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.biWidth * abs(bmpInfoHeader.biHeight), input);
    fclose(input);

    int msg_length = strlen(message);
    if (msg_length * 8 > img_data_size) {
        fprintf(stderr, "Message is too long to embed in the image\n");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    // Embed message length
    for (int i = 0; i < 32; i++) {
        pixels[i / 8].blue = (pixels[i / 8].blue & 0xFE) | ((msg_length >> i) & 0x1);
    }

    // Embed the message
    for (int i = 0; i < msg_length; i++) {
        for (int j = 0; j < 8; j++) {
            pixels[(i * 8) + j + 32].blue = (pixels[(i * 8) + j + 32].blue & 0xFE) | ((message[i] >> j) & 0x1);
        }
    }

    FILE *output = fopen(output_image, "wb");
    if (!output) {
        perror("Error creating output image");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpFileHeader, sizeof(BMPFileHeader), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, output);
    fwrite(pixels, sizeof(Pixel), bmpInfoHeader.biWidth * abs(bmpInfoHeader.biHeight), output);

    fclose(output);
    free(pixels);
    printf("Message embedded successfully!\n");
}

void extract_message(const char *input_image) {
    FILE *input = fopen(input_image, "rb");
    if (!input) {
        perror("Error opening input image");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader bmpFileHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input);

    Pixel *pixels = (Pixel *)malloc(bmpInfoHeader.biWidth * abs(bmpInfoHeader.biHeight) * sizeof(Pixel));
    fseek(input, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.biWidth * abs(bmpInfoHeader.biHeight), input);
    fclose(input);

    int msg_length = 0;
    for (int i = 0; i < 32; i++) {
        msg_length |= (pixels[i / 8].blue & 0x1) << i;
    }

    char *message = (char *)malloc(msg_length + 1);
    for (int i = 0; i < msg_length; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= (pixels[(i * 8) + j + 32].blue & 0x1) << j;
        }
    }
    message[msg_length] = '\0';

    printf("Extracted message: %s\n", message);
    free(message);
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input_image> <output_image/message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[3], argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid action. Use 'embed' or 'extract'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}