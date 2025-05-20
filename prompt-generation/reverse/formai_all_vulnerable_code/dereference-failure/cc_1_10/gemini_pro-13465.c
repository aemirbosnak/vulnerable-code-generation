//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <cover image> <secret message> <output image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *cover_image = fopen(argv[1], "rb");
    if (cover_image == NULL) {
        perror("Error opening cover image");
        return EXIT_FAILURE;
    }

    FILE *secret_message = fopen(argv[2], "rb");
    if (secret_message == NULL) {
        perror("Error opening secret message");
        return EXIT_FAILURE;
    }

    FILE *output_image = fopen(argv[3], "wb");
    if (output_image == NULL) {
        perror("Error opening output image");
        return EXIT_FAILURE;
    }

    fseek(cover_image, 0, SEEK_END);
    long cover_image_size = ftell(cover_image);
    rewind(cover_image);

    fseek(secret_message, 0, SEEK_END);
    long secret_message_size = ftell(secret_message);
    rewind(secret_message);

    if (secret_message_size > cover_image_size) {
        printf("Error: secret message is too large\n");
        return EXIT_FAILURE;
    }

    byte *cover_image_data = malloc(cover_image_size);
    if (cover_image_data == NULL) {
        perror("Error allocating memory for cover image data");
        return EXIT_FAILURE;
    }

    byte *secret_message_data = malloc(secret_message_size);
    if (secret_message_data == NULL) {
        perror("Error allocating memory for secret message data");
        return EXIT_FAILURE;
    }

    fread(cover_image_data, cover_image_size, 1, cover_image);
    fread(secret_message_data, secret_message_size, 1, secret_message);

    for (long i = 0; i < secret_message_size; i++) {
        cover_image_data[i] = (cover_image_data[i] & 0xF0) | (secret_message_data[i] & 0x0F);
    }

    fwrite(cover_image_data, cover_image_size, 1, output_image);

    free(cover_image_data);
    free(secret_message_data);

    fclose(cover_image);
    fclose(secret_message);
    fclose(output_image);

    return EXIT_SUCCESS;
}