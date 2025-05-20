//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetbits;
} BMPFileHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void embed_message(const char* input_image, const char* message, const char* output_image) {
    FILE *infile = fopen(input_image, "rb");
    if (!infile) {
        perror("Error opening input image file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;

    fread(&file_header, sizeof(BMPFileHeader), 1, infile);
    fread(&info_header, sizeof(BMPInfoHeader), 1, infile);
    
    if (file_header.type != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    int width = info_header.width;
    int height = info_header.height;
    int pixel_count = width * height;

    // Calculate message length and padding
    size_t message_length = strlen(message);
    if (message_length > pixel_count) {
        fprintf(stderr, "Message too long to embed in the image\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Buffer to hold the image data
    Pixel *pixels = malloc(pixel_count * sizeof(Pixel));
    if (!pixels) {
        perror("Memory allocation failed");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Read pixel data
    fseek(infile, file_header.offsetbits, SEEK_SET);
    fread(pixels, sizeof(Pixel), pixel_count, infile);
    fclose(infile);

    // Embed the message into the least significant bits of the image pixels
    for (size_t i = 0; i < message_length; ++i) {
        pixels[i].blue = (pixels[i].blue & ~1) | (message[i] & 1);
        pixels[i].green = (pixels[i].green & ~1) | ((message[i] >> 1) & 1);
        pixels[i].red = (pixels[i].red & ~1) | ((message[i] >> 2) & 1);
    }

    // Handle padding for message termination
    uint8_t terminator = 0;
    for (size_t i = message_length; i < pixel_count; ++i) {
        pixels[i].blue = (pixels[i].blue & ~1) | (terminator & 1);
        pixels[i].green = (pixels[i].green & ~1) | ((terminator >> 1) & 1);
        pixels[i].red = (pixels[i].red & ~1) | ((terminator >> 2) & 1);
    }

    // Save the modified image with the embedded message
    FILE *outfile = fopen(output_image, "wb");
    if (!outfile) {
        perror("Error opening output image file");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    fwrite(&file_header, sizeof(BMPFileHeader), 1, outfile);
    fwrite(&info_header, sizeof(BMPInfoHeader), 1, outfile);
    fwrite(pixels, sizeof(Pixel), pixel_count, outfile);
    fclose(outfile);
    free(pixels);
}

void extract_message(const char* input_image) {
    FILE *infile = fopen(input_image, "rb");
    if (!infile) {
        perror("Error opening input image file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;

    fread(&file_header, sizeof(BMPFileHeader), 1, infile);
    fread(&info_header, sizeof(BMPInfoHeader), 1, infile);
    
    if (file_header.type != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    int width = info_header.width;
    int height = info_header.height;
    int pixel_count = width * height;

    // Buffer to hold the image data
    Pixel *pixels = malloc(pixel_count * sizeof(Pixel));
    if (!pixels) {
        perror("Memory allocation failed");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Read pixel data
    fseek(infile, file_header.offsetbits, SEEK_SET);
    fread(pixels, sizeof(Pixel), pixel_count, infile);
    fclose(infile);

    // Extract the message from the least significant bits of the pixels
    char *message = malloc(pixel_count);
    if (!message) {
        perror("Memory allocation failed");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    size_t message_length = 0;
    for (size_t i = 0; i < pixel_count; ++i) {
        message[message_length] |= (pixels[i].blue & 1) << 0;
        message[message_length] |= (pixels[i].green & 1) << 1;
        message[message_length] |= (pixels[i].red & 1) << 2;

        if (message[message_length] == 0) {
            break; // End of message 
        }

        message_length++;
    }

    // Output the extracted message
    printf("Extracted Message: ");
    for (size_t i = 0; i < message_length; ++i) {
        putchar(message[i]);
    }
    putchar('\n');

    free(pixels);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s [embed/extract] [input_image] [output_image/message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], "output.bmp");
        printf("Message embedded successfully!\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}