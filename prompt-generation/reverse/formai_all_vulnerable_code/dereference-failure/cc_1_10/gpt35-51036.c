//FormAI DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to hide the bits of the message in the least significant bit of the image data.
void hide_message_in_image(unsigned char* image_data, char* message) {
    int image_index = 0, message_index = 0, bit_index = 0;
    char current_bit = message[message_index] >> bit_index & 1;
    while (current_bit != '\0') {
        // Get the current pixel data
        unsigned char current_pixel = image_data[image_index];
        // Set the least significant bit of the pixel to the current bit of the message
        current_pixel = (current_pixel & 0xFE) | current_bit;
        // Save the updated pixel data back to the image data
        image_data[image_index] = current_pixel;
        // Move to the next bit of the message
        bit_index++;
        if (bit_index == 8) {
            bit_index = 0;
            message_index++;
            current_bit = message[message_index] >> bit_index & 1;
        } else {
            current_bit = message[message_index] >> bit_index & 1;
        }
        // Move to the next pixel in the image data
        image_index++;
    }
}

// Function to extract the message hidden in the least significant bit of the image data.
char* extract_message_from_image(unsigned char* image_data) {
    char* message = (char*) malloc(1024 * sizeof(char));
    int image_index = 0, bit_index = 0, message_index = 0;
    char current_bit = image_data[image_index] & 1;
    while (current_bit != '\0') {
        // Get the current bit from the image data
        current_bit = image_data[image_index] & 1;
        // Add the current bit to the message
        message[message_index] |= current_bit << bit_index;
        // Move to the next bit of the message
        bit_index++;
        if (bit_index == 8) {
            bit_index = 0;
            message_index++;
        }
        // Move to the next pixel in the image data
        image_index++;
    }
    return message;
}

int main() {
    // Open the image file for reading
    FILE* image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Unable to open image file!\n");
        return 1;
    }
    // Read the image data from the file
    unsigned char* image_data = (unsigned char*) malloc(1024 * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), 1024, image_file);
    // Close the image file
    fclose(image_file);

    // Hide the message in the image
    char message[] = "Hello, world!";
    hide_message_in_image(image_data, message);

    // Extract the message from the image
    char* hidden_message = extract_message_from_image(image_data);
    printf("Hidden message: %s\n", hidden_message);

    // Free the image data and the hidden message
    free(image_data);
    free(hidden_message);

    return 0;
}