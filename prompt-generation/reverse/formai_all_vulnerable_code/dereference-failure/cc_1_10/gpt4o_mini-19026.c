//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)

typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_bits;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned int compression;
    unsigned int size_image;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} DIBHeader;

#pragma pack(pop)

void embed_message(BMPHeader *bmp_header, DIBHeader *dib_header, const char *message, const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    // Write headers to output file
    fwrite(bmp_header, sizeof(BMPHeader), 1, output);
    fwrite(dib_header, sizeof(DIBHeader), 1, output);
  
    // Calculate the position to start embedding the message
    int pixel_start = bmp_header->offset_bits;
    fseek(input, pixel_start, SEEK_SET);
    fwrite((void *)((char *)bmp_header + pixel_start), 1, sizeof(BMPHeader) + sizeof(DIBHeader), output);

    // Embed the message into the pixel data
    int message_length = strlen(message);
    char *pixel_data = malloc(dib_header->size_image);
    
    fread(pixel_data, 1, dib_header->size_image, input);

    // Embed length of the message at the last pixel (least significant bit)
    for (int i = 0; i < message_length; ++i) {
        pixel_data[i * 8] = (pixel_data[i * 8] & ~1) | ((message[i] >> 7) & 1);
        for (int j = 6; j >= 0; --j) {
            pixel_data[i * 8 + 1 + j] = (pixel_data[i * 8 + 1 + j] & ~1) | ((message[i] >> j) & 1);
        }
    }

    // Write modified pixel data to output file
    fwrite(pixel_data, 1, dib_header->size_image, output);

    free(pixel_data);
    fclose(input);
    fclose(output);
}

void extract_message(BMPHeader *bmp_header, DIBHeader *dib_header, const char *output_file) {
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file for extraction");
        return;
    }
  
    // Buffer for pixel data
    char *pixel_data = malloc(dib_header->size_image);
    fread(pixel_data, 1, dib_header->size_image, stdin);

    // Extract the message from the pixel data
    char message[256] = {0};
    int length = 0;

    while (length < 256 && (pixel_data[length * 8] & 1) == 0) {
        char c = 0;
        for (int j = 0; j < 8; ++j) {
            c <<= 1;
            c |= (pixel_data[length * 8 + j] & 1);
        }
        message[length++] = c;
    }

    fwrite(message, sizeof(char), length, output);
    fclose(output);
    free(pixel_data);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <embed/extract> <input bmp> <output bmp> <message/extracted output>\n", argv[0]);
        return 1;
    }

    BMPHeader bmp_header;
    DIBHeader dib_header;

    FILE *file = fopen(argv[2], "rb");
    fread(&bmp_header, sizeof(BMPHeader), 1, file);
    fread(&dib_header, sizeof(DIBHeader), 1, file);
    fclose(file);

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(&bmp_header, &dib_header, argv[4], argv[2], argv[3]);
        printf("Message embedded successfully.\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        printf("Extracted message:\n");
        extract_message(&bmp_header, &dib_header, argv[4]);
        printf("Message extracted successfully.\n");
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}