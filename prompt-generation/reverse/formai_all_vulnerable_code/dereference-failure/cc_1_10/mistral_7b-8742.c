//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define SECRET_MESSAGE "Hello World!"
#define IMAGE_WIDTH 3
#define IMAGE_HEIGHT 3
#define MAX_PIXEL_VALUE 255
#define BITS_PER_PIXEL 8
#define BYTES_PER_PIXEL (BITS_PER_PIXEL / 8)
#define NUM_PIXELS IMAGE_WIDTH * IMAGE_HEIGHT

void print_usage(void) {
    printf("Usage: %s <image_file>\n", __FILE__);
}

void hide_message(unsigned char *image, const char *message) {
    int i = 0;
    int j = 0;
    int pixel_index = 0;
    int message_len = strlen(message);
    int remaining_bits = 0;

    for (i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        for (j = 0; j < BYTES_PER_PIXEL; j++) {
            if (remaining_bits < BITS_PER_PIXEL) {
                unsigned char bit_mask = 1 << (BITS_PER_PIXEL - remaining_bits - 1);

                // Hide next bit
                if (i >= NUM_PIXELS || (message_len > 0 && (message[j / 8] >> (j % 8) & bit_mask) != (SECRET_MESSAGE[i / NUM_PIXELS] >> (i % NUM_PIXELS) % 8 & bit_mask))) {
                    image[pixel_index] = image[pixel_index] | bit_mask;
                    message_len--;
                }

                remaining_bits += 1;
            }

            pixel_index++;
        }

        remaining_bits = 0;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    unsigned char *image = malloc(NUM_PIXELS * BYTES_PER_PIXEL);

    FILE *image_file = fopen(argv[1], "rb");

    if (image_file == NULL) {
        perror("Error opening image file.\n");
        free(image);
        return EXIT_FAILURE;
    }

    fread(image, sizeof(unsigned char), NUM_PIXELS * BYTES_PER_PIXEL, image_file);
    fclose(image_file);

    hide_message(image, SECRET_MESSAGE);

    image_file = fopen(argv[1], "wb");

    if (image_file == NULL) {
        perror("Error opening image file for writing.\n");
        free(image);
        return EXIT_FAILURE;
    }

    fwrite(image, sizeof(unsigned char), NUM_PIXELS * BYTES_PER_PIXEL, image_file);
    fclose(image_file);

    free(image);

    printf("Message hidden successfully.\n");

    return EXIT_SUCCESS;
}