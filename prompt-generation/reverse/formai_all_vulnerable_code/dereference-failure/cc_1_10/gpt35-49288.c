//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
/* Linus Torvalds-style Steganography Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        printf("You need to specify both the input image and the image to hide in it!\n");
        return 1;
    }

    FILE *input, *secret, *output;
    input = fopen(argv[1], "rb");
    secret = fopen(argv[2], "rb");
    output = fopen("output.bmp", "wb");

    if (input == NULL || secret == NULL || output == NULL) {
        printf("Failed to open one or more of the input files.\n");
        return 1;
    }

    // Check to make sure that the inputs are BMP files
    char input_header[54], secret_header[54];
    fread(input_header, sizeof(char), 54, input);
    fread(secret_header, sizeof(char), 54, secret);
    if (memcmp(input_header, secret_header, 54) != 0) {
        printf("The input files are not compatible.\n");
        return 1;
    }

    // Do the actual steganography encoding.
    char input_data, secret_data;
    int data_count = 0;
    while (fread(&input_data, sizeof(char), 1, input) == 1) {
        if (fread(&secret_data, sizeof(char), 1, secret) == 1) {
            // Get the least significant bit of the input data
            int lsb = input_data & 0x01;
            // Replace it with the corresponding bit from the secret data
            input_data = (input_data & 0xFE) | ((secret_data >> data_count) & 0x01);
            fwrite(&input_data, sizeof(char), 1, output);
            data_count++;
            // Once we've written 8 bits, move on to the next 8 bits of the secret
            if (data_count == 8) {
                data_count = 0;
                if (fread(&secret_data, sizeof(char), 1, secret) == 1) {
                    fwrite(&secret_data, sizeof(char), 1, output);
                } else {
                    break; // We've run out of secret data
                }
            }
        } else {
            fwrite(&input_data, sizeof(char), 1, output);
        }
    }

    // Clean up and exit.
    fclose(input);
    fclose(secret);
    fclose(output);
    return 0;
}