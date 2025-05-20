//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char header[54];
    unsigned int width;
    unsigned int height;
    unsigned short bits_per_pixel;
} BMPHeader;
#pragma pack(pop)

void embed_message(const char *input_bmp, const char *output_bmp, const char *message) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Unable to open input image");
        return;
    }

    BMPHeader bmp_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, infile);

    FILE *outfile = fopen(output_bmp, "wb");
    if (!outfile) {
        perror("Unable to open output image");
        fclose(infile);
        return;
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, outfile);

    // Calculate the position to start embedding
    long message_length = strlen(message) + 1; // +1 for null terminator
    if (message_length > (bmp_header.width * bmp_header.height * 3 / 8)) {
        fprintf(stderr, "Error: Message is too long to embed in this image.\n");
        fclose(infile);
        fclose(outfile);
        return;
    }

    // Embed the message into the least significant bits of the pixel data
    unsigned char pixel[3];
    for (long i = 0; i < message_length; i++) {
        fread(pixel, sizeof(unsigned char), 3, infile);
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 5) & 0x01);
        fwrite(pixel, sizeof(unsigned char), 3, outfile);
    }

    // Write the remaining pixel data unchanged
    while (fread(pixel, sizeof(unsigned char), 3, infile) == 3) {
        fwrite(pixel, sizeof(unsigned char), 3, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("Message successfully embedded in %s as %s.\n", input_bmp, output_bmp);
}

void extract_message(const char *input_bmp) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Unable to open input image");
        return;
    }

    BMPHeader bmp_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, infile);

    // Read message from the least significant bits
    unsigned char pixel[3];
    char message[256];
    memset(message, 0, sizeof(message));
    
    for (int i = 0; i < sizeof(message) - 1; i++) {
        fread(pixel, sizeof(unsigned char), 3, infile);
        message[i] = (0x00 << 7) | ((pixel[0] & 0x01) << 6) | 
                     ((pixel[1] & 0x01) << 5) | ((pixel[2] & 0x01) << 4);
        
        if (message[i] == 0) {
            break; // End of message (null terminator)
        }
    }

    fclose(infile);
    printf("Extracted message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <input.bmp> [output.bmp] <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Usage for embedding: %s embed <input.bmp> <output.bmp> <message>\n", argv[0]);
            return 1;
        }
        embed_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Usage for extracting: %s extract <input.bmp>\n", argv[0]);
            return 1;
        }
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        return 1;
    }

    return 0;
}