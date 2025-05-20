//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to binary */
int* dec_to_bin(int decimal) {
    static int binary[8];
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    // Padding with zeroes up to 8 bits
    while (index < 8) {
        binary[index] = 0;
        index++;
    }

    return binary;
}

/* Function to convert binary to decimal */
int bin_to_dec(int* binary) {
    int decimal = 0;
    int power = 1;

    for (int i = 0; i < 8; i++) {
        int bit = binary[i];
        decimal += bit * power;
        power *= 2;
    }

    return decimal;
}

/* Function to hide a message in an image */
void hide_message_in_image(char* image_path, char* message) {
    FILE* fp = fopen(image_path, "rb+");

    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    rewind(fp);

    int message_size = strlen(message) + 1; // Adding 1 for null terminator
    int max_message_size = (image_size - 54) / 8; // Maximum number of bytes we can hide in the image

    if (message_size > max_message_size) {
        printf("Error: message is too big to hide in the image.\n");
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Modify the header to indicate the size of the message
    int* message_size_binary = dec_to_bin(message_size);
    for (int i = 0; i < 8; i++) {
        header[32 + i] = message_size_binary[i] * 255;
    }

    // Write the modified header back to the image
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Hide each character of the message in the least significant bit of each color byte in the image
    unsigned char pixel[3];
    int pixel_index = 0; // Keeps track of which pixel we are on
    int bit_index = 0; // Keeps track of which bit of the message byte we are hiding

    while (1) {
        fread(pixel, sizeof(unsigned char), 3, fp);
        if (feof(fp)) {
            break;
        }

        // Hide the next bit of the message byte in the least significant bit of each color byte
        int* message_byte = dec_to_bin((int)message[bit_index]);
        pixel[0] = (pixel[0] & 0b11111110) | message_byte[0];
        pixel[1] = (pixel[1] & 0b11111110) | message_byte[1];
        pixel[2] = (pixel[2] & 0b11111110) | message_byte[2];

        // Write the modified pixel back to the image
        fseek(fp, 54 + pixel_index * 3, SEEK_SET);
        fwrite(pixel, sizeof(unsigned char), 3, fp);

        // Move on to the next bit of the message byte
        bit_index++;
        if (bit_index == message_size * 8) {
            break;
        }

        // Move on to the next pixel
        pixel_index++;
    }

    fclose(fp);

    printf("Message hidden in image.\n");
}

/* Function to extract a message from an image */
void extract_message_from_image(char* image_path) {
    FILE* fp = fopen(image_path, "rb");

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Read the size of the message from the header
    int message_size_binary[8];
    for (int i = 0; i < 8; i++) {
        message_size_binary[i] = header[32 + i] % 2;
    }
    int message_size = bin_to_dec(message_size_binary);

    // Extract the message from the image
    char* message = (char*)malloc(message_size);
    int message_index = 0; // Keeps track of which bit of the message byte we are extracting

    while (1) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, fp);
        if (feof(fp)) {
            break;
        }

        // Extract the least significant bit of each color byte and add it to the message byte
        int message_byte = 0;
        message_byte += pixel[0] % 2;
        message_byte <<= 1;
        message_byte += pixel[1] % 2;
        message_byte <<= 1;
        message_byte += pixel[2] % 2;

        // Write the message byte to the message array
        message[message_index] = (char)message_byte;

        // Move on to the next bit of the message byte
        message_index++;
        if (message_index == message_size * 8) {
            break;
        }
    }

    fclose(fp);

    printf("Message extracted from image: %s\n", message);
}

/* Main function */
int main() {
    char* image_path = "image.bmp";
    char* message = "This is a secret message.";

    hide_message_in_image(image_path, message);
    extract_message_from_image(image_path);

    return 0;
}