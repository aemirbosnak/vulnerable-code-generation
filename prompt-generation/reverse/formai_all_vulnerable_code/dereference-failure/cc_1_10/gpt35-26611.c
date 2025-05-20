//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8

void hide_message(char *img_path, char *msg_path, char *output_path);
void extract_message(char *img_path);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <img_path> <msg_path>\n", argv[0]);
        return 1;
    }

    char *img_path = argv[1];
    char *msg_path = argv[2];

    hide_message(img_path, msg_path, "output.bmp");
    extract_message("output.bmp");

    return 0;
}

void hide_message(char *img_path, char *msg_path, char *output_path) {
    FILE *img_file = fopen(img_path, "rb");
    FILE *msg_file = fopen(msg_path, "rb");
    FILE *output_file = fopen(output_path, "wb");

    if (!img_file || !msg_file || !output_file) {
        printf("Error opening file(s)!\n");
        return;
    }

    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, img_file);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int img_size = *(int*)&header[34];

    // Allocate memory for image and message
    unsigned char *img_data = (unsigned char*)malloc(img_size);
    unsigned char *msg_data = (unsigned char*)malloc(img_size / BYTES_PER_PIXEL);

    // Read image and message data into memory
    fread(img_data, sizeof(unsigned char), img_size, img_file);
    fread(msg_data, sizeof(unsigned char), img_size / BYTES_PER_PIXEL - 1, msg_file);

    // Add null byte at end of message
    msg_data[img_size / BYTES_PER_PIXEL - 1] = '\0';

    // Write BMP header to output file
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // Loop through image data and replace least significant bit of each byte with message data
    int i, j;
    for (i = 0, j = 0; i < img_size; i += BYTES_PER_PIXEL, j++) {
        if (j >= strlen(msg_data)) {
            break;
        }

        img_data[i + 2] = (img_data[i + 2] & 0xFE) | ((msg_data[j] >> 7) & 0x01);
        img_data[i + 1] = (img_data[i + 1] & 0xFE) | ((msg_data[j] >> 6) & 0x01);
        img_data[i] = (img_data[i] & 0xFE) | ((msg_data[j] >> 5) & 0x01);
        img_data[i + 2] = (img_data[i + 2] & 0xFD) | ((msg_data[j] >> 4) & 0x01);
        img_data[i + 1] = (img_data[i + 1] & 0xFD) | ((msg_data[j] >> 3) & 0x01);
        img_data[i] = (img_data[i] & 0xFD) | ((msg_data[j] >> 2) & 0x01);
        img_data[i + 2] = (img_data[i + 2] & 0xFB) | ((msg_data[j] >> 1) & 0x01);
        img_data[i + 1] = (img_data[i + 1] & 0xFB) | (msg_data[j] & 0x01);
    }

    // Write image data to output file
    fwrite(img_data, sizeof(unsigned char), img_size, output_file);

    // Free memory and close files
    free(img_data);
    free(msg_data);
    fclose(img_file);
    fclose(msg_file);
    fclose(output_file);

    printf("Message hidden successfully!\n");
}

void extract_message(char *img_path) {
    FILE *img_file = fopen(img_path, "rb");
    if (!img_file) {
        printf("Error opening file!\n");
        return;
    }

    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, img_file);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int img_size = *(int*)&header[34];

    // Allocate memory for image and message data
    unsigned char *img_data = (unsigned char*)malloc(img_size);
    unsigned char *msg_data = (unsigned char*)malloc(img_size / BYTES_PER_PIXEL);

    // Read image data into memory
    fread(img_data, sizeof(unsigned char), img_size, img_file);

    // Loop through image data and extract least significant bit of each byte
    int i, j;
    for (i = 0, j = 0; i < img_size; i += BYTES_PER_PIXEL, j++) {
        if (j >= img_size / BYTES_PER_PIXEL) {
            break;
        }

        msg_data[j] = (img_data[i + 2] & 0x01) << 7;
        msg_data[j] |= (img_data[i + 1] & 0x01) << 6;
        msg_data[j] |= (img_data[i] & 0x01) << 5;
        msg_data[j] |= (img_data[i + 2] & 0x02) << 3;
        msg_data[j] |= (img_data[i + 1] & 0x02) << 2;
        msg_data[j] |= (img_data[i] & 0x02) << 1;
        msg_data[j] |= (img_data[i + 2] & 0x04) >> 1;
        msg_data[j] |= img_data[i + 1] & 0x04;
    }

    // Print extracted message
    printf("Extracted message: %s\n", msg_data);

    // Free memory and close files
    free(img_data);
    free(msg_data);
    fclose(img_file);
}