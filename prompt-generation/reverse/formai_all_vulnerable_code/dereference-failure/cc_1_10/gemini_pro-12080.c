//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

void encode(char *input_filename, char *output_filename, char *secret_message) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the header from the input file
    byte header[54];
    if (fread(header, 1, 54, input_file) != 54) {
        perror("Error reading header from input file");
        exit(1);
    }

    // Write the header to the output file
    if (fwrite(header, 1, 54, output_file) != 54) {
        perror("Error writing header to output file");
        exit(1);
    }

    // Get the size of the secret message
    int secret_message_length = strlen(secret_message);

    // Encode the secret message into the image data
    int pixel_index = 54;
    for (int i = 0; i < secret_message_length; i++) {
        // Get the next byte of the secret message
        byte secret_byte = secret_message[i];

        // Get the least significant bit of the pixel
        byte pixel_lsb = header[pixel_index] & 1;

        // Set the least significant bit of the pixel to the secret byte
        header[pixel_index] = (header[pixel_index] & ~1) | (secret_byte & 1);

        // Move to the next pixel
        pixel_index++;

        // If we have reached the end of the image data, wrap around to the beginning
        if (pixel_index == 54 + header[18] * header[22] * 3) {
            pixel_index = 54;
        }
    }

    // Write the encoded image data to the output file
    if (fwrite(header, 1, header[18] * header[22] * 3, output_file) != header[18] * header[22] * 3) {
        perror("Error writing encoded image data to output file");
        exit(1);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}

void decode(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the header from the input file
    byte header[54];
    if (fread(header, 1, 54, input_file) != 54) {
        perror("Error reading header from input file");
        exit(1);
    }

    // Get the size of the secret message
    int secret_message_length = 0;
    int pixel_index = 54;
    while (header[pixel_index] & 1) {
        secret_message_length++;
        pixel_index++;

        // If we have reached the end of the image data, wrap around to the beginning
        if (pixel_index == 54 + header[18] * header[22] * 3) {
            pixel_index = 54;
        }
    }

    // Decode the secret message from the image data
    char secret_message[secret_message_length + 1];
    pixel_index = 54;
    for (int i = 0; i < secret_message_length; i++) {
        // Get the least significant bit of the pixel
        byte pixel_lsb = header[pixel_index] & 1;

        // Append the least significant bit to the secret message
        secret_message[i] = pixel_lsb;

        // Move to the next pixel
        pixel_index++;

        // If we have reached the end of the image data, wrap around to the beginning
        if (pixel_index == 54 + header[18] * header[22] * 3) {
            pixel_index = 54;
        }
    }
    secret_message[secret_message_length] = '\0';

    // Write the secret message to the output file
    fprintf(output_file, "%s", secret_message);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <secret_message>\n", argv[0]);
        return 1;
    }

    encode(argv[1], argv[2], argv[3]);
    decode(argv[2], "secret_message.txt");

    return 0;
}