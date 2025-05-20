//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void embed_message(char *message, pixel *image, int image_width, int image_height) {
    int message_length = strlen(message);
    int message_index = 0;
    int bit_index = 0;

    for (int i = 0; i < image_width * image_height; i++) {
        if (bit_index == 8) {
            bit_index = 0;
            message_index++;
        }

        if (message_index == message_length) {
            break;
        }

        unsigned char bit = (message[message_index] >> (7 - bit_index)) & 1;
        image[i].red = (image[i].red & 0xFE) | bit;
        bit_index++;
    }
}

void extract_message(pixel *image, int image_width, int image_height) {
    int message_length = 0;
    int bit_index = 0;
    unsigned char message = 0;

    for (int i = 0; i < image_width * image_height; i++) {
        unsigned char bit = image[i].red & 1;
        message = (message << 1) | bit;
        bit_index++;

        if (bit_index == 8) {
            bit_index = 0;
            message_length++;

            if (message == '\0') {
                break;
            }
        }
    }

    printf("Extracted message: %s\n", message);
}

int main() {
    int image_width = 512;
    int image_height = 512;
    pixel *image = malloc(image_width * image_height * sizeof(pixel));

    // Load the image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    fread(image, sizeof(pixel), image_width * image_height, image_file);
    fclose(image_file);

    // Embed the message in the image
    char *message = "Hello, world!";
    embed_message(message, image, image_width, image_height);

    // Save the modified image to a file
    FILE *output_file = fopen("output.bmp", "wb");
    fwrite(image, sizeof(pixel), image_width * image_height, output_file);
    fclose(output_file);

    // Extract the message from the image
    extract_message(image, image_width, image_height);

    free(image);
    return 0;
}