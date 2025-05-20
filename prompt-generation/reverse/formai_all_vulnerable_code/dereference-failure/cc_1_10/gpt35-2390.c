//FormAI DATASET v1.0 Category: Image Steganography ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define BMP_HEADER_SIZE 54

void print_bmp_header(char *header) {
    printf("Printing BMP Header..\n");
    for(int i=0;i<BMP_HEADER_SIZE;i++) {
        printf("%d ", header[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {

    if(argc < 4) {
        printf("Usage: ./image_stegano [INPUT IMAGE] [OUTPUT IMAGE] [SECRET MESSAGE]\n");
        return 1;
    }

    char const *input_image = argv[1];
    char const *output_image = argv[2];
    char const *secret_message = argv[3];

    FILE *input_fp, *output_fp;
    input_fp = fopen(input_image, "rb");
    output_fp = fopen(output_image, "wb");

    if(input_fp == NULL || output_fp == NULL) {
        printf("Error opening file(s)!\n");
        exit(1);
    }

    // read BMP header of input file
    char header[BMP_HEADER_SIZE];
    fread(header, sizeof(char), BMP_HEADER_SIZE, input_fp);
    print_bmp_header(header);

    // write BMP header to output file
    fwrite(header, sizeof(char), BMP_HEADER_SIZE, output_fp);

    // calculate message size and check if it can fit in image
    int message_size = strlen(secret_message);
    int max_capacity = ((BMP_HEADER_SIZE * 8) / 3) - 1;
    if(message_size > max_capacity) {
        printf("Error: Secret message is too big to fit in the input image!\n");
        exit(1);
    }

    // allocate buffer to store pixel data
    int image_size = (header[2] & 0xFF) | ((header[3] & 0xFF) << 8) | ((header[4] & 0xFF) << 16) | ((header[5] & 0xFF) << 24);
    int padding = (4 - ((header[2] * 3) % 4)) % 4;
    uint8_t *image_data = (uint8_t*) malloc(image_size * sizeof(uint8_t));
    fread(image_data, sizeof(uint8_t), image_size, input_fp);

    // embed secret message in pixel data
    int message_index = 0;
    for(int i=0;i<image_size;i+=3) {
        if(message_index < message_size) {
            image_data[i+2] = (image_data[i+2] & 0xFC) | ((secret_message[message_index] & 0xC0) >> 6);
            image_data[i+1] = (image_data[i+1] & 0xFC) | ((secret_message[message_index] & 0x30) >> 4);
            image_data[i] = (image_data[i] & 0xFC) | ((secret_message[message_index] & 0x0C) >> 2);
            message_index++;
        } else {
            image_data[i+2] &= 0xFC;
            image_data[i+1] &= 0xFC;
            image_data[i] &= 0xFC;
        }
    }

    // write modified pixel data to output file
    fseek(output_fp, BMP_HEADER_SIZE, SEEK_SET);
    fwrite(image_data, sizeof(uint8_t), image_size, output_fp);

    // free memory
    free(image_data);
    fclose(input_fp);
    fclose(output_fp);

    printf("Secret message embedded successfully in input image!\n");
    printf("Output file: %s\n", output_image);

    return 0;
}