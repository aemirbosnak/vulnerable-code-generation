//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

// Function to embed the message into the image
void embed_message(unsigned char *image, unsigned char *message, int image_size, int message_size) {
    int i, j, k, l;
    unsigned char temp;

    // Loop through each pixel of the image
    for (i = 0; i < image_size; i++) {
        // Convert the pixel value to binary
        temp = image[i];
        for (j = 7; j >= 0; j--) {
            // Get the least significant bit of the message
            l = message[k] & 1;
            // Set the least significant bit of the pixel to the message bit
            temp = (temp & ~(1 << j)) | (l << j);
            // Shift the message right by one bit
            message[k] = message[k] >> 1;
            // Increment the message index if all bits of the current message byte have been embedded
            if (j == 0) {
                k++;
            }
        }
        // Update the pixel value in the image
        image[i] = temp;
    }
}

// Function to extract the message from the image
void extract_message(unsigned char *image, unsigned char *message, int image_size, int message_size) {
    int i, j, k, l;
    unsigned char temp;

    // Loop through each pixel of the image
    for (i = 0; i < image_size; i++) {
        // Convert the pixel value to binary
        temp = image[i];
        for (j = 7; j >= 0; j--) {
            // Get the least significant bit of the pixel
            l = temp & 1;
            // Set the least significant bit of the message to the pixel bit
            message[k] = (message[k] << 1) | l;
            // Increment the message index if all bits of the current message byte have been extracted
            if (j == 0) {
                k++;
            }
        }
    }
}

// Main function
int main() {
    // Declare an array to store the image
    unsigned char image[MAX_IMAGE_SIZE];
    // Declare an array to store the message
    unsigned char message[MAX_MESSAGE_SIZE];
    // Declare variables to store the image size and message size
    int image_size, message_size;
    // Get the image size and message size from the user
    printf("Enter the image size (in bytes): ");
    scanf("%d", &image_size);
    printf("Enter the message size (in bytes): ");
    scanf("%d", &message_size);

    // Get the image data from the user
    printf("Enter the image data: ");
    fread(image, image_size, 1, stdin);

    // Get the message data from the user
    printf("Enter the message data: ");
    fread(message, message_size, 1, stdin);

    // Embed the message into the image
    embed_message(image, message, image_size, message_size);

    // Output the steganographed image
    printf("Steganographed image: ");
    fwrite(image, image_size, 1, stdout);

    // Extract the message from the steganographed image
    extract_message(image, message, image_size, message_size);

    // Output the extracted message
    printf("Extracted message: %s\n", message);

    return 0;
}