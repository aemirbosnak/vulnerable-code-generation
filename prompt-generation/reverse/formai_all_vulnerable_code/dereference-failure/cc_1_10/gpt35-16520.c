//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
// C Image Steganography Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide the message in the image
void embed_message(unsigned char *image_data, char *message)
{
    int message_len = strlen(message);
    int image_size = strlen(image_data);
    int message_index = 0;

    // Loop through each pixel in the image
    for (int i = 0; i < image_size; i += 3) {
        // If we have reached the end of the message, stop
        if (message_index >= message_len) {
            break;
        }

        // Get the current RGB values of the pixel
        unsigned char r = image_data[i];
        unsigned char g = image_data[i + 1];
        unsigned char b = image_data[i + 2];

        // Get the current bit of the message
        char bit = message[message_index];

        // Embed the bit in the least significant bit of each color value
        image_data[i] = (r & 0xFE) | (bit & 0x01);
        image_data[i + 1] = (g & 0xFE) | (bit & 0x01);
        image_data[i + 2] = (b & 0xFE) | (bit & 0x01);

        // Move on to the next bit in the message
        message_index++;
    }
}

// Function to extract the message from the image
char *extract_message(unsigned char *image_data)
{
    int image_size = strlen(image_data);
    char *message = malloc(image_size / 8 + 1);

    int message_index = 0;
    char current_byte = 0;
    int bit_counter = 0;

    // Loop through each pixel in the image
    for (int i = 0; i < image_size; i += 3) {
        // If we have extracted 8 bits, add the byte to the message
        if (bit_counter == 8) {
            message[message_index] = current_byte;
            message_index++;
            bit_counter = 0;
            current_byte = 0;
        }

        // Get the least significant bit of each color value
        unsigned char r = image_data[i] & 0x01;
        unsigned char g = image_data[i + 1] & 0x01;
        unsigned char b = image_data[i + 2] & 0x01;

        // Concatenate the 3 bits into a single byte
        current_byte = (current_byte << 1) | r;
        current_byte = (current_byte << 1) | g;
        current_byte = (current_byte << 1) | b;

        // Move on to the next bit
        bit_counter++;
    }

    message[message_index] = '\0';

    return message;
}

int main(int argc, char **argv)
{
    // Check that the user provided an image and a message
    if (argc < 3) {
        printf("Usage: %s [image file] [message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the image file
    FILE *fp = fopen(argv[1], "rb");

    if (!fp) {
        printf("Failed to open image file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Get the size of the image file
    fseek(fp, 0L, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Read the image data into memory
    unsigned char *image_data = malloc(image_size);

    if (!image_data) {
        printf("Failed to allocate memory\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fread(image_data, sizeof(unsigned char), image_size, fp);
    fclose(fp);

    // Embed the message in the image
    char *message = argv[2];
    embed_message(image_data, message);

    // Write the modified image data to a new file
    fp = fopen("output.bmp", "wb");

    if (!fp) {
        printf("Failed to write output file\n");
        free(image_data);
        return EXIT_FAILURE;
    }

    fwrite(image_data, sizeof(unsigned char), image_size, fp);
    fclose(fp);

    printf("Message embedded successfully\n");

    // Extract the message from the image
    fp = fopen("output.bmp", "rb");

    if (!fp) {
        printf("Failed to open output file\n");
        free(image_data);
        return EXIT_FAILURE;
    }

    fseek(fp, 0L, SEEK_END);
    image_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    unsigned char *output_data = malloc(image_size);

    if (!output_data) {
        printf("Failed to allocate memory\n");
        fclose(fp);
        free(image_data);
        return EXIT_FAILURE;
    }

    fread(output_data, sizeof(unsigned char), image_size, fp);
    fclose(fp);

    char *extracted_message = extract_message(output_data);

    printf("Extracted message: %s\n", extracted_message);

    free(image_data);
    free(output_data);
    free(extracted_message);

    return EXIT_SUCCESS;
}