//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
void encode(char *image_name, char *secret_file_name, char *output_image_name);
void decode(char *image_name);

/* Main function */
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <encode/decode> <image_file> <secret_file>(optional) <output_image_file>(optional)\n", argv[0]);
        return -1;
    }
    else if(strcmp(argv[1], "encode") == 0) {
        if(argc < 4) {
            printf("Usage: %s <encode> <image_file> <secret_file> <output_image_file>\n", argv[0]);
            return -1;
        }
        else {
            encode(argv[2], argv[3], argv[4]);
        }
    }
    else if(strcmp(argv[1], "decode") == 0) {
        if(argc < 3) {
            printf("Usage: %s <decode> <image_file>\n", argv[0]);
            return -1;
        }
        else {
            decode(argv[2]);
        }
    }
    else {
        printf("Invalid option\n");
        printf("Usage: %s <encode/decode> <image_file> <secret_file>(optional) <output_image_file>(optional)\n", argv[0]);
        return -1;
    }
    return 0;
}

/* Function to encode a secret file into an image */
void encode(char *image_name, char *secret_file_name, char *output_image_name) {
    FILE *image_file = fopen(image_name, "rb");
    FILE *secret_file = fopen(secret_file_name, "rb");
    FILE *output_image_file = fopen(output_image_name, "wb");

    if(!image_file || !secret_file || !output_image_file) {
        printf("Error: file not found\n");
        return;
    }

    unsigned char image_header[54];
    fread(image_header, sizeof(unsigned char), 54, image_file);
    fwrite(image_header, sizeof(unsigned char), 54, output_image_file);

    unsigned int image_size = *(unsigned int*)&image_header[2];
    unsigned int image_width = *(unsigned int*)&image_header[18];
    unsigned int image_height = *(unsigned int*)&image_header[22];

    unsigned int secret_file_size = 0;
    fseek(secret_file, 0, SEEK_END);
    secret_file_size = ftell(secret_file);
    rewind(secret_file);

    if(secret_file_size > (image_size - 54) / 8) {
        printf("Error: secret file too large\n");
        return;
    }

    unsigned char *image_data = (unsigned char*)malloc(image_size - 54);
    fread(image_data, sizeof(unsigned char), image_size - 54, image_file);

    unsigned char *secret_data = (unsigned char*)malloc(secret_file_size + 1);
    fread(secret_data, sizeof(unsigned char), secret_file_size, secret_file);

    unsigned int secret_bit_index = 0;
    for(unsigned int i = 0; i < image_size - 54; i += 4) {
        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        unsigned char red = image_data[i];
        unsigned char green = image_data[i + 1];
        unsigned char blue = image_data[i + 2];
        unsigned char alpha = image_data[i + 3];

        red = (red & ~0x01) | ((secret_data[secret_bit_index / 8] >> (secret_bit_index % 8)) & 0x01);
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        green = (green & ~0x01) | ((secret_data[secret_bit_index / 8] >> (secret_bit_index % 8)) & 0x01);
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        blue = (blue & ~0x01) | ((secret_data[secret_bit_index / 8] >> (secret_bit_index % 8)) & 0x01);
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        alpha = (alpha & ~0x01) | ((secret_data[secret_bit_index / 8] >> (secret_bit_index % 8)) & 0x01);
        secret_bit_index++;

        image_data[i] = red;
        image_data[i + 1] = green;
        image_data[i + 2] = blue;
        image_data[i + 3] = alpha;
    }

    fwrite(image_data, sizeof(unsigned char), image_size - 54, output_image_file);

    free(image_data);
    free(secret_data);

    fclose(image_file);
    fclose(secret_file);
    fclose(output_image_file);

    printf("Secret file encoded successfully\n");
}

/* Function to decode a secret file from an image */
void decode(char *image_name) {
    FILE *image_file = fopen(image_name, "rb");

    if(!image_file) {
        printf("Error: file not found\n");
        return;
    }

    unsigned char image_header[54];
    fread(image_header, sizeof(unsigned char), 54, image_file);

    unsigned int image_size = *(unsigned int*)&image_header[2];
    unsigned int image_width = *(unsigned int*)&image_header[18];
    unsigned int image_height = *(unsigned int*)&image_header[22];

    unsigned char *image_data = (unsigned char*)malloc(image_size - 54);
    fread(image_data, sizeof(unsigned char), image_size - 54, image_file);

    unsigned int secret_file_size = (image_size - 54) / 8;
    unsigned char *secret_data = (unsigned char*)malloc(secret_file_size + 1);

    unsigned int secret_bit_index = 0;
    for(unsigned int i = 0; i < image_size - 54; i += 4) {
        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        unsigned char red = image_data[i];
        unsigned char green = image_data[i + 1];
        unsigned char blue = image_data[i + 2];
        unsigned char alpha = image_data[i + 3];

        secret_data[secret_bit_index / 8] |= ((red & 0x01) << (secret_bit_index % 8));
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        secret_data[secret_bit_index / 8] |= ((green & 0x01) << (secret_bit_index % 8));
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        secret_data[secret_bit_index / 8] |= ((blue & 0x01) << (secret_bit_index % 8));
        secret_bit_index++;

        if(secret_bit_index / 8 >= secret_file_size) {
            break;
        }

        secret_data[secret_bit_index / 8] |= ((alpha & 0x01) << (secret_bit_index % 8));
        secret_bit_index++;
    }

    secret_data[secret_file_size] = '\0';

    FILE *output_file = fopen("secret.txt", "wb");
    fwrite(secret_data, sizeof(unsigned char), secret_file_size, output_file);
    fclose(output_file);

    free(image_data);
    free(secret_data);

    fclose(image_file);

    printf("Secret file decoded successfully\n");
}