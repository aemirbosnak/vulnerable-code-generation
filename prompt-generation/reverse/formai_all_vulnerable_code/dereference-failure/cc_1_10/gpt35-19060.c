//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

void hide_data(char *input_file_name, char *output_file_name, char *message)
{
    // Open input & output files
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    // Copy header from input_file to output_file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file); // read 54 bytes of header
    fwrite(header, sizeof(unsigned char), 54, output_file); // write the same header to the output file

    // Extract pixel data from input_file
    unsigned char pixel_data[3];
    while (fread(pixel_data, sizeof(unsigned char), 3, input_file) == 3) {
        // Get least significant bit from message and hide it in the pixel_data
        for (int i = 0; i < 3; i++) {
            if (*message != '\0') {
                unsigned char mask = BIT0;
                for (int j = 0; j < 8; j++) {
                    if (*message & mask)
                        pixel_data[i] |= (pixel_data[i] & BIT0) ? 0 : BIT0;
                    else
                        pixel_data[i] &= (pixel_data[i] & BIT0) ? ~BIT0 : ~0;
                    mask <<= 1;
                }
                *message++;
            } else {
                break;
            }
        }
        fwrite(pixel_data, sizeof(unsigned char), 3, output_file);
    }

    // Close input & output files
    fclose(input_file);
    fclose(output_file);
}

void extract_data(char *input_file_name)
{
    // Open input file
    FILE *input_file = fopen(input_file_name, "rb");

    // Extract header from input_file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file); // read 54 bytes of header

    // Extract pixel data from input_file and extract hidden message
    unsigned char pixel_data[3];
    unsigned char message_buffer[256];
    int message_index = 0;
    memset(message_buffer, 0, sizeof(message_buffer));
    while (fread(pixel_data, sizeof(unsigned char), 3, input_file) == 3 && message_index < 256) {
        unsigned char message_char = 0;
        for (int i = 0; i < 8; i++) {
            if (pixel_data[i%3] & (1 << (i % 8)))
                message_char |= (1 << (i % 8));
        }
        if (message_char == '\0')
            break;
        message_buffer[message_index++] = message_char;
    }

    // Close input file
    fclose(input_file);

    // Print extracted hidden message
    printf("%s\n", message_buffer);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;
    if (strcmp(argv[1], "-e") == 0 && argc == 5) {
        hide_data(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "-x") == 0 && argc == 3) {
        extract_data(argv[2]);
    } else {
        printf("Usage:\n\t%s -e input_file output_file message\n\t%s -x input_file\n", argv[0], argv[0]);
    }
    return 0;
}