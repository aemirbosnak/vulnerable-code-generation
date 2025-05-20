//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: systematic
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

void embed_message(const char *input_file, const char *output_file, const char *message) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Could not open input file");
        exit(1);
    }

    BMPHeader bmp_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, infile);

    int msg_length = strlen(message);
    if (msg_length > 255) {
        fprintf(stderr, "Message too long. Limit is 255 characters.\n");
        fclose(infile);
        return;
    }

    fseek(infile, sizeof(BMPHeader), SEEK_SET);
    unsigned char *pixel_data = malloc(bmp_header.width * bmp_header.height * 3);
    fread(pixel_data, sizeof(unsigned char), bmp_header.width * bmp_header.height * 3, infile);
    fclose(infile);

    // Embed message length at the end of the pixel_data
    pixel_data[bmp_header.width * bmp_header.height * 3] = (unsigned char)msg_length;

    // Embed the message into the pixel data
    for (int i = 0; i < msg_length; i++) {
        pixel_data[bmp_header.width * bmp_header.height * 3 + i + 1] = (unsigned char)message[i];
    }

    FILE *outfile = fopen(output_file, "wb");
    if (!outfile) {
        perror("Could not open output file");
        free(pixel_data);
        exit(1);
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, outfile);
    fwrite(pixel_data, sizeof(unsigned char), bmp_header.width * bmp_header.height * 3 + msg_length + 1, outfile);
    fclose(outfile);
    free(pixel_data);
}

void extract_message(const char *input_file) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Could not open input file");
        exit(1);
    }

    BMPHeader bmp_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, infile);

    fseek(infile, sizeof(BMPHeader) + (bmp_header.width * bmp_header.height * 3), SEEK_SET);
    unsigned char msg_length;
    fread(&msg_length, sizeof(unsigned char), 1, infile);
    
    if (msg_length == 0) {
        printf("No message is embedded.\n");
        fclose(infile);
        return;
    }

    char *message = malloc(msg_length + 1);
    fread(message, sizeof(char), msg_length, infile);
    message[msg_length] = '\0';

    printf("Extracted Message: %s\n", message);
    
    fclose(infile);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s embed|extract input.bmp output.bmp message\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], argv[4]);
        printf("Message embedded successfully!\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}