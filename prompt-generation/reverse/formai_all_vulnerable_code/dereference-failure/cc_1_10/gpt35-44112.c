//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HIDDEN_MESSAGE "SECRET MESSAGE HIDDEN IN IMAGE"
#define MESSAGE_SIZE 30

void hide_message_in_image(char* image_path, char* secret_message, int message_size) {
    /* open the image file */
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Failed to open the image file\n");
        return;
    }

    /* read the first 54 bytes of the image file */
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, image_file);

    /* get the width and height of the image */
    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];

    /* calculate the size of the pixel array */
    int pixel_array_size = image_width * image_height * 3;

    /* allocate memory for the pixel array and read it from the file */
    uint8_t* pixel_array = (uint8_t*)malloc(pixel_array_size);
    fread(pixel_array, sizeof(uint8_t), pixel_array_size, image_file);

    /* close the image file */
    fclose(image_file);

    /* hide the message in the least significant bit of each color channel */
    int i, j, k;
    for (i = 0, j = 0; i < message_size; i++, j += 8) {
        uint8_t character = secret_message[i];
        for (k = 0; k < 8; k++) {
            uint8_t bit = (character >> (7 - k)) & 0x01;
            pixel_array[j * 3 + k * 3] = (pixel_array[j * 3 + k * 3] & 0xFE) | bit;
            pixel_array[j * 3 + k * 3 + 1] = (pixel_array[j * 3 + k * 3 + 1] & 0xFE) | bit;
            pixel_array[j * 3 + k * 3 + 2] = (pixel_array[j * 3 + k * 3 + 2] & 0xFE) | bit;
        }
    }

    /* open the output image file */
    FILE* output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Failed to create the output image file\n");
        return;
    }

    /* write the header and pixel array to the output file */
    fwrite(header, sizeof(uint8_t), 54, output_file);
    fwrite(pixel_array, sizeof(uint8_t), pixel_array_size, output_file);

    /* close the output file */
    fclose(output_file);

    /* free the allocated memory */
    free(pixel_array);
}

void extract_message_from_image(char* image_path, char* extracted_message, int message_size) {
    /* open the image file */
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Failed to open the image file\n");
        return;
    }

    /* read the first 54 bytes of the image file */
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, image_file);

    /* get the width and height of the image */
    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];

    /* calculate the size of the pixel array */
    int pixel_array_size = image_width * image_height * 3;

    /* allocate memory for the pixel array and read it from the file */
    uint8_t* pixel_array = (uint8_t*)malloc(pixel_array_size);
    fread(pixel_array, sizeof(uint8_t), pixel_array_size, image_file);

    /* close the image file */
    fclose(image_file);

    /* extract the message from the least significant bit of each color channel */
    int i, j, k;
    for (i = 0, j = 0; i < message_size; i++, j += 8) {
        uint8_t character = 0;
        for (k = 0; k < 8; k++) {
            character = (character << 1) | (pixel_array[j * 3 + k * 3] & 0x01);
        }
        extracted_message[i] = character;
    }

    /* free the allocated memory */
    free(pixel_array);
}

int main() {
    char* image_path = "image.bmp";
    char extracted_message[MESSAGE_SIZE];

    /* hide the message in the image */
    hide_message_in_image(image_path, HIDDEN_MESSAGE, MESSAGE_SIZE);

    /* extract the message from the image */
    extract_message_from_image("output.bmp", extracted_message, MESSAGE_SIZE);

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}