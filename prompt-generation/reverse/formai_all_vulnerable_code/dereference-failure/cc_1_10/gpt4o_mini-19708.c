//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char magic[2];
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bpp;
    unsigned int compression;
    unsigned int imagesize;
    unsigned int xresolution;
    unsigned int yresolution;
    unsigned int ncolors;
    unsigned int importantcolors;
} BMPInfoHeader;
#pragma pack(pop)

void embed_message(const char *input_bmp, const char *output_bmp, const char *message) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Error opening input BMP file");
        return;
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, infile);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, infile);

    int image_size = bmp_info_header.width * bmp_info_header.height * (bmp_info_header.bpp / 8);
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    fseek(infile, bmp_header.offset, SEEK_SET);
    fread(image_data, image_size, 1, infile);
    fclose(infile);

    // Embed the message
    size_t message_len = strlen(message);
    if (message_len * 8 > image_size) {
        printf("Message is too long to fit in the image!\n");
        free(image_data);
        return;
    }

    for (size_t i = 0; i < message_len; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int img_index = (i * 8 + bit);
            int byte_index = img_index / 8;
            int bit_index = img_index % 8;

            unsigned char byte = image_data[byte_index];
            byte = (byte & 0xFE) | ((message[i] >> (7 - bit)) & 0x01);
            image_data[byte_index] = byte;
        }
    }

    // Save output BMP file
    FILE *outfile = fopen(output_bmp, "wb");
    if (!outfile) {
        perror("Error opening output BMP file");
        free(image_data);
        return;
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, outfile);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, outfile);
    fseek(outfile, bmp_header.offset, SEEK_SET);
    fwrite(image_data, image_size, 1, outfile);

    free(image_data);
    fclose(outfile);
    printf("Message embedded successfully in %s\n", output_bmp);
}

void extract_message(const char *input_bmp, size_t message_length) {
    FILE *infile = fopen(input_bmp, "rb");
    if (!infile) {
        perror("Error opening BMP file");
        return;
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, infile);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, infile);

    int image_size = bmp_info_header.width * bmp_info_header.height * (bmp_info_header.bpp / 8);
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    fseek(infile, bmp_header.offset, SEEK_SET);
    fread(image_data, image_size, 1, infile);
    fclose(infile);

    char *extracted_message = (char *)malloc(message_length + 1);
    for (size_t i = 0; i < message_length; i++) {
        extracted_message[i] = 0;
        for (int bit = 0; bit < 8; bit++) {
            int img_index = (i * 8 + bit);
            int byte_index = img_index / 8;
            int bit_index = img_index % 8;

            unsigned char byte = image_data[byte_index];
            extracted_message[i] |= ((byte & 0x01) << (7 - bit));
        }
    }
    extracted_message[message_length] = '\0';

    free(image_data);
    printf("Extracted Message: %s\n", extracted_message);
    free(extracted_message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed|extract> <input_bmp> <output_bmp/message_length> [message]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 5) {
            printf("Error: Please provide a message to embed.\n");
            return 1;
        }
        embed_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        size_t message_length = (size_t)atoi(argv[3]);
        extract_message(argv[2], message_length);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}