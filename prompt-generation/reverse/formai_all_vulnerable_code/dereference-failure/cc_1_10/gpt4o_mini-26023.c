//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)  // Ensure we don't have any padding bytes in our structs
typedef struct {
    unsigned char header[54];
    unsigned int data_offset;
} BMPHeader;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

void encode_message(const char *message, Pixel *pixel_data, unsigned int pixel_count) {
    for (int i = 0; message[i] != '\0' && i < pixel_count; i++) {
        // Modify the least significant bit of the blue value of the pixel
        pixel_data[i].blue = (pixel_data[i].blue & 0xFE) | (message[i] & 0x01);
    }
}

void decode_message(char *message, Pixel *pixel_data, unsigned int max_length) {
    for (int i = 0; i < max_length; i++) {
        // Extract the least significant bit of the blue value of the pixel
        message[i] = 0; // Initialize the character
        message[i] |= (pixel_data[i].blue & 0x01) << 0; // Extract blue bit
        if (message[i] == '\0') break; // End of message reached
    }
}

void read_bmp_image(const char *filename, BMPHeader *bmp_header, Pixel **pixel_data, unsigned int *pixel_count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    fread(bmp_header->header, sizeof(unsigned char), 54, file);
    bmp_header->data_offset = *(unsigned int*)&bmp_header->header[0x0A];

    unsigned int width = *(unsigned int*)&bmp_header->header[0x12];
    unsigned int height = *(unsigned int*)&bmp_header->header[0x16];
    *pixel_count = width * height;

    // Allocate memory for pixel data
    *pixel_data = (Pixel *)malloc(*pixel_count * sizeof(Pixel));
    fseek(file, bmp_header->data_offset, SEEK_SET);
    fread(*pixel_data, sizeof(Pixel), *pixel_count, file);
    
    fclose(file);
}

void write_bmp_image(const char *filename, BMPHeader *bmp_header, Pixel *pixel_data, unsigned int pixel_count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fwrite(bmp_header->header, sizeof(unsigned char), 54, file);
    fseek(file, bmp_header->data_offset, SEEK_SET);
    fwrite(pixel_data, sizeof(Pixel), pixel_count, file);
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input.bmp output.bmp \"secret message\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPHeader bmp_header;
    Pixel *pixel_data = NULL;
    unsigned int pixel_count = 0;

    // Load BMP image
    read_bmp_image(argv[1], &bmp_header, &pixel_data, &pixel_count);

    // Encode the message into the pixel data
    encode_message(argv[3], pixel_data, pixel_count);

    // Write the modified image with the encoded message
    write_bmp_image(argv[2], &bmp_header, pixel_data, pixel_count);

    // Cleanup
    free(pixel_data);
    printf("Message encoded successfully!\n");
    return EXIT_SUCCESS;
}