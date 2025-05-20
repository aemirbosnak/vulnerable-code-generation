//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure structure is packed
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t important_colors;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void encode_message(const char *filename, const char *message) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    if (bmp_header.type != 0x4D42) {
        printf("Not a BMP file\n");
        fclose(file);
        return;
    }

    fseek(file, bmp_header.offset_data, SEEK_SET);
    
    size_t message_length = strlen(message);
    size_t total_pixels = bmp_info_header.width * bmp_info_header.height;
    size_t bit_count = message_length * 8;

    if (bit_count > total_pixels) {
        printf("Message is too long to encode in the image\n");
        fclose(file);
        return;
    }

    for (size_t i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            Pixel pixel;
            fread(&pixel, sizeof(Pixel), 1, file);
            pixel.red = (pixel.red & ~1) | ((message[i] >> (7 - j)) & 1);
            fwrite(&pixel, sizeof(Pixel), 1, file);
        }
    }
    
    fclose(file);
    printf("Message encoded successfully\n");
}

void decode_message(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    if (bmp_header.type != 0x4D42) {
        printf("Not a BMP file\n");
        fclose(file);
        return;
    }

    fseek(file, bmp_header.offset_data, SEEK_SET);
    
    char message[256];
    size_t message_length = 0;

    while (message_length < 255) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            Pixel pixel;
            fread(&pixel, sizeof(Pixel), 1, file);
            byte |= ((pixel.red & 1) << (7 - j));
        }
        if (byte == 0) break; // null-terminated
        message[message_length++] = byte;
    }
    
    message[message_length] = '\0';
    fclose(file);
    printf("Decoded message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <filename> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode_message(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode_message(argv[2]);
    } else {
        printf("Invalid command. Use 'encode' or 'decode'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}