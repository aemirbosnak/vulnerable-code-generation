//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for holding the image's header data
typedef struct header_t {
    unsigned int width;
    unsigned int height;
    unsigned short int bits_per_pixel;
} header_t;

// Define a function for extracting the image's header data
header_t extract_header(FILE* file) {
    header_t header;
    fseek(file, 18, SEEK_SET);
    fread(&(header.width), sizeof(header.width), 1, file);
    fread(&(header.height), sizeof(header.height), 1, file);
    fseek(file, 28, SEEK_SET);
    fread(&(header.bits_per_pixel), sizeof(header.bits_per_pixel), 1, file);
    fseek(file, 0, SEEK_SET);
    return header;
}

// Define a function for hiding a message in an image
int hide_message(FILE* image_file, const char* message) {
    // Extract the header data
    header_t header = extract_header(image_file);

    // Calculate the number of bits of data that can be hidden in the image
    int max_bits = header.width * header.height * (header.bits_per_pixel / 8);
    int message_length = strlen(message);
    if (message_length * 8 > max_bits) {
        printf("Error: Message is too long to fit in the image.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the image data and read it into memory
    char* image_data = malloc(max_bits);
    if (image_data == NULL) {
        printf("Error: Failed to allocate memory for image data.\n");
        return EXIT_FAILURE;
    }
    fread(image_data, 1, max_bits, image_file);

    // Encode the message in the image data
    for (int i = 0; i < message_length; i++) {
        char byte = message[i];
        for (int j = 0; j < 8; j++) {
            int bit_value = (byte >> j) & 1;
            int index = i * 8 + j;
            image_data[index] &= ~1;
            image_data[index] |= bit_value;
        }
    }

    // Write the encoded image data to a new file
    FILE* output_file = fopen("encoded_image.bmp", "wb");
    if (output_file == NULL) {
        printf("Error: Failed to create output file.\n");
        return EXIT_FAILURE;
    }
    fwrite(image_data, 1, max_bits, output_file);
    fclose(output_file);

    printf("Message has been encoded in image.\n");
    free(image_data);
    return EXIT_SUCCESS;
}

// Define a function for extracting a message from an image
int extract_message(FILE* image_file) {
    // Extract the header data
    header_t header = extract_header(image_file);

    // Allocate memory for the image data and read it into memory
    int max_bits = header.width * header.height * (header.bits_per_pixel / 8);
    char* image_data = malloc(max_bits);
    if (image_data == NULL) {
        printf("Error: Failed to allocate memory for image data.\n");
        return EXIT_FAILURE;
    }
    fread(image_data, 1, max_bits, image_file);

    // Extract the message from the image data
    char* message = malloc(max_bits / 8);
    int message_length = 0;
    for (int i = 0; i < max_bits; i += 8) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= ((image_data[i + j] & 1) << j);
        }
        message[message_length++] = byte;
    }
    message[message_length] = '\0';

    // Print the extracted message
    printf("The message hidden in the image is:\n%s\n", message);

    free(image_data);
    free(message);
    return EXIT_SUCCESS;
}

// Define the main function
int main(int argc, char** argv) {
    // Print usage if command-line arguments are invalid
    if (argc != 4) {
        printf("Usage: %s <command> <image_file> <message>\n", argv[0]);
        printf("Commands:\n");
        printf("    hide   - Hide a message in an image\n");
        printf("    extract - Extract a message from an image\n");
        return EXIT_FAILURE;
    }

    // Open the image file
    FILE* image_file = fopen(argv[2], "rb");
    if (image_file == NULL) {
        printf("Error: Failed to open image file.\n");
        return EXIT_FAILURE;
    }

    // Perform the requested operation
    int result = EXIT_SUCCESS;
    if (strcmp(argv[1], "hide") == 0) {
        result = hide_message(image_file, argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        result = extract_message(image_file);
    } else {
        printf("Error: Invalid command.\n");
        result = EXIT_FAILURE;
    }
    fclose(image_file);

    return result;
}