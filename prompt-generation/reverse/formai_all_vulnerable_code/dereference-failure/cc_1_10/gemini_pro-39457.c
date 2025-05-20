//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

#define LSB_MASK 1
#define MAX_MESSAGE_LENGTH 1024 * 1024

void embed_message(FILE *image, FILE *message) {
    u32 image_size;
    u32 message_size;

    // Read the image size from the first 4 bytes of the file
    fseek(image, 0, SEEK_END);
    image_size = ftell(image);
    rewind(image);

    // Read the message size from the first 4 bytes of the file
    fseek(message, 0, SEEK_END);
    message_size = ftell(message);
    rewind(message);

    // Check if the image is big enough to hold the message
    if (message_size > image_size) {
        fprintf(stderr, "Error: Image is too small to hold the message\n");
        exit(1);
    }

    // Read the message into a buffer
    char *message_buffer = malloc(message_size);
    fread(message_buffer, 1, message_size, message);

    // Embed the message in the image
    for (u32 i = 0; i < message_size; i++) {
        // Get the next byte from the message
        char byte = message_buffer[i];

        // Embed the LSB of the byte in the LSB of the current pixel
        u32 pixel;
        fread(&pixel, 1, sizeof(u32), image);
        pixel &= ~LSB_MASK;
        pixel |= byte & LSB_MASK;
        fseek(image, -sizeof(u32), SEEK_CUR);
        fwrite(&pixel, 1, sizeof(u32), image);
    }
   
    printf("Message embedded successfully!\n");
}

void extract_message(FILE *image, FILE *message) {
    u32 image_size;

    // Read the image size from the first 4 bytes of the file
    fseek(image, 0, SEEK_END);
    image_size = ftell(image);
    rewind(image);

    // Create a buffer to hold the extracted message
    char *message_buffer = malloc(image_size);

    // Extract the message from the image
    for (u32 i = 0; i < image_size; i++) {
        // Get the current pixel
        u32 pixel;
        fread(&pixel, 1, sizeof(u32), image);

        // Extract the LSB of the pixel
        char byte = pixel & LSB_MASK;

        // Append the LSB to the message buffer
        message_buffer[i] = byte;
    }

    // Write the extracted message to the file
    fwrite(message_buffer, 1, image_size, message);
    printf("Message extracted successfully!\n");
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image> <message> <encode|decode>\n", argv[0]);
        exit(1);
    }

    // Open the image and message files
    FILE *image = fopen(argv[1], "rb+");
    if (image == NULL) {
        fprintf(stderr, "Error: Could not open image file\n");
        exit(1);
    }

    FILE *message = fopen(argv[2], "rb");
    if (message == NULL) {
        fprintf(stderr, "Error: Could not open message file\n");
        exit(1);
    }

    // Embed or extract the message, depending on the third argument
    if (strcmp(argv[3], "encode") == 0) {
        embed_message(image, message);
    } else if (strcmp(argv[3], "decode") == 0) {
        extract_message(image, message);
    } else {
        fprintf(stderr, "Error: Invalid operation\n");
        exit(1);
    }

    // Close the files
    fclose(image);
    fclose(message);

    return 0;
}