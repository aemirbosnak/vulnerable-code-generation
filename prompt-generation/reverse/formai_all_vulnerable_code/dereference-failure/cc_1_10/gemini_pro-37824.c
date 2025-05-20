//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bitmap file header
struct bmp_header {
    char type[2];       // "BM"
    unsigned int size;    // Size of the file in bytes
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;  // Offset to the pixel data
};

// Bitmap info header
struct bmp_info_header {
    unsigned int size;             // Size of the info header in bytes
    int width;                   // Width of the image in pixels
    int height;                  // Height of the image in pixels
    unsigned short planes;        // Number of color planes
    unsigned short bit_count;     // Number of bits per pixel
    unsigned int compression;      // Compression type
    unsigned int image_size;      // Size of the image data in bytes
    int x_resolution;            // Resolution in pixels per meter
    int y_resolution;            // Resolution in pixels per meter
    unsigned int num_colors;      // Number of colors in the palette
    unsigned int important_colors; // Number of important colors
};

// Embed a message in a bitmap image
void embed_message(char *image_file, char *message) {
    // Open the image file
    FILE *image = fopen(image_file, "rb+");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return;
    }

    // Read the bitmap header
    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, image);

    // Read the bitmap info header
    struct bmp_info_header info_header;
    fread(&info_header, sizeof(struct bmp_info_header), 1, image);

    // Check if the image is 24-bit color
    if (info_header.bit_count != 24) {
        fprintf(stderr, "Error: Image must be 24-bit color\n");
        fclose(image);
        return;
    }

    // Get the size of the image data
    unsigned int image_size = info_header.image_size;

    // Allocate memory for the image data
    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(image);
        return;
    }

    // Read the image data
    fread(image_data, image_size, 1, image);

    // Embed the message in the image data
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        // Get the ASCII value of the character
        unsigned char character = message[i];

        // Embed the character in the least significant bits of the pixel data
        for (int j = 0; j < 8; j++) {
            // Get the bitmask for the least significant bit
            unsigned char bitmask = 1 << j;

            // Set the least significant bit to the value of the character
            image_data[i * 3 + j] = (image_data[i * 3 + j] & ~bitmask) | ((character & bitmask) >> j);
        }
    }

    // Write the modified image data to the file
    fseek(image, header.offset, SEEK_SET);
    fwrite(image_data, image_size, 1, image);

    // Free the memory allocated for the image data
    free(image_data);

    // Close the image file
    fclose(image);
}

// Extract a message from a bitmap image
char *extract_message(char *image_file) {
    // Open the image file
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return NULL;
    }

    // Read the bitmap header
    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, image);

    // Read the bitmap info header
    struct bmp_info_header info_header;
    fread(&info_header, sizeof(struct bmp_info_header), 1, image);

    // Check if the image is 24-bit color
    if (info_header.bit_count != 24) {
        fprintf(stderr, "Error: Image must be 24-bit color\n");
        fclose(image);
        return NULL;
    }

    // Get the size of the image data
    unsigned int image_size = info_header.image_size;

    // Allocate memory for the image data
    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(image);
        return NULL;
    }

    // Read the image data
    fread(image_data, image_size, 1, image);

    // Extract the message from the image data
    int message_length = 0;
    for (int i = 0; i < image_size; i += 3) {
        // Get the least significant bits of the pixel data
        unsigned char character = 0;
        for (int j = 0; j < 8; j++) {
            // Get the bitmask for the least significant bit
            unsigned char bitmask = 1 << j;

            // Shift the character left by one bit
            character <<= 1;

            // Set the least significant bit of the character to the value of the pixel data
            character |= (image_data[i + j] & bitmask) >> j;
        }

        // Check if the character is the end of the message
        if (character == '\0') {
            break;
        }

        // Increment the message length
        message_length++;
    }

    // Allocate memory for the message
    char *message = malloc(message_length + 1);
    if (message == NULL) {
        fprintf(stderr, "Error allocating memory for message\n");
        fclose(image);
        free(image_data);
        return NULL;
    }

    // Copy the message from the image data to the buffer
    memcpy(message, image_data, message_length);

    // Terminate the message with a null character
    message[message_length] = '\0';

    // Free the memory allocated for the image data
    free(image_data);

    // Close the image file
    fclose(image);

    // Return the message
    return message;
}

// Main function
int main() {
    // Embed a message in an image file
    embed_message("image.bmp", "Hello, world!");

    // Extract the message from the image file
    char *message = extract_message("image.bmp");

    // Print the message
    printf("Message: %s\n", message);

    // Free the memory allocated for the message
    free(message);

    return 0;
}