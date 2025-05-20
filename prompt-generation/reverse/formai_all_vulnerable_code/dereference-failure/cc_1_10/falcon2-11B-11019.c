//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 512
#define PADDING_CHAR 'x'

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image_file> <secret_message>\n", argv[0]);
        return 1;
    }

    char *image_file = argv[1];
    char *secret_message = argv[2];

    // Open image file
    FILE *image_file_ptr = fopen(image_file, "rb");
    if (image_file_ptr == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    // Allocate memory for image buffer
    unsigned char *image_buffer = (unsigned char *)malloc(BLOCK_SIZE);

    // Read image file into buffer
    int bytes_read = fread(image_buffer, 1, BLOCK_SIZE, image_file_ptr);
    if (bytes_read!= BLOCK_SIZE) {
        printf("Error reading image file\n");
        free(image_buffer);
        fclose(image_file_ptr);
        return 1;
    }

    // Create secret message buffer
    char *secret_message_buffer = (char *)malloc(strlen(secret_message) + 1);
    strcpy(secret_message_buffer, secret_message);

    // Find the first free block of bytes in the image buffer
    int block_index = 0;
    while (image_buffer[block_index]!= '\0') {
        block_index++;
    }

    // Add secret message to image buffer
    int bytes_to_add = strlen(secret_message_buffer);
    for (int i = 0; i < bytes_to_add; i++) {
        int secret_index = block_index + i;
        int image_index = secret_index % BLOCK_SIZE;
        image_buffer[image_index] = secret_message_buffer[i];
    }

    // Add padding to make image buffer a multiple of BLOCK_SIZE
    int padding_length = BLOCK_SIZE - (bytes_read % BLOCK_SIZE);
    for (int i = 0; i < padding_length; i++) {
        int image_index = block_index + i;
        int secret_index = block_index + bytes_to_add + i;
        image_buffer[image_index] = PADDING_CHAR;
        secret_message_buffer[secret_index] = PADDING_CHAR;
    }

    // Write modified image buffer back to file
    fwrite(image_buffer, 1, BLOCK_SIZE, image_file_ptr);

    // Free memory
    free(image_buffer);
    free(secret_message_buffer);

    // Close image file
    fclose(image_file_ptr);

    printf("Steganography complete! New image file saved.\n");

    return 0;
}