//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensures structure is byte-aligned
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

#pragma pack(pop)

void embed_message(const char* input_bmp, const char* message, const char* output_bmp) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, infile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, infile);
    
    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a valid BMP file.\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }
    
    // Calculate message length and ensure capacity
    size_t message_length = strlen(message);
    if (message_length * 8 + 32 > (bih.biWidth * bih.biHeight * (bih.biBitCount / 8))) {
        fprintf(stderr, "Error: Message is too long to embed in the image.\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    fseek(infile, bfh.bfOffBits, SEEK_SET);

    // Open output file
    FILE *outfile = fopen(output_bmp, "wb");
    if (!outfile) {
        perror("Failed to open output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outfile);

    // Copy pixels and embed the message
    uint8_t pixel[3];
    int bit_index = 0;
    for (size_t i = 0; i < bih.biWidth * bih.biHeight; i++) {
        fread(pixel, sizeof(uint8_t), 3, infile); // Read 3 bytes (RGB)

        // Embed message bits in the least significant bit of the blue channel
        if(bit_index < message_length * 8) {
            pixel[0] = (pixel[0] & 0xFE) | ((message[bit_index / 8] >> (7 - (bit_index % 8))) & 0x01);
            bit_index++;
        }

        fwrite(pixel, sizeof(uint8_t), 3, outfile); // Write modified pixel
    }

    // Append a terminating bit to signify end of the message
    if (bit_index < message_length * 8) {
        pixel[0] = (pixel[0] & 0xFE) | 0x01; // Set last pixel LSB to indicate end
        fwrite(pixel, sizeof(uint8_t), 3, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("Message embedded successfully!\n");
}

void extract_message(const char* input_bmp) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, infile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, infile);
    
    fseek(infile, bfh.bfOffBits, SEEK_SET);

    // Extract message
    char *message = malloc(1024); // Allocate memory for the message (1024 bytes)
    if (!message) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    size_t bit_index = 0;
    for (size_t i = 0; bit_index < 1023 * 8; i++) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, infile); // Read 3 bytes (RGB)

        // Decode the least significant bit
        message[bit_index / 8] <<= 1; // Shift left
        message[bit_index / 8] |= (pixel[0] & 0x01); // Get LSB
        bit_index++;

        // Check for terminating LSB
        if (bit_index >= 8 && (message[(bit_index / 8) - 1] & 0x01) == 1) {
            break;
        }
    }
    message[bit_index / 8] = '\0'; // Null-terminate the string

    printf("Extracted Message: %s\n", message);
    free(message);
    fclose(infile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <bmp_file> <message/output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}