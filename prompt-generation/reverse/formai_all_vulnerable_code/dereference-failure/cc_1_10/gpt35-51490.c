//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

void encode(char *image, char *message, char *output_file) {
    int image_size, message_size, i, j, b;
    char *p;
    FILE *fptr1, *fptr2;

    // Open the image and message files in binary mode
    fptr1 = fopen(image, "rb");
    fptr2 = fopen(message, "rb");

    // Check if both files exist and were opened successfully
    if (fptr1 == NULL) {
        printf("Error: Could not open image file %s\n", image);
        exit(1);
    }
    if (fptr2 == NULL) {
        printf("Error: Could not open message file %s\n", message);
        exit(1);
    }

    // Read the image and message file into memory
    char *image_data = (char *) malloc(MAX_FILE_SIZE * sizeof(char));
    image_size = fread(image_data, 1, MAX_FILE_SIZE, fptr1);

    char *message_data = (char *) malloc(MAX_FILE_SIZE * sizeof(char));
    message_size = fread(message_data, 1, MAX_FILE_SIZE, fptr2);

    // Close the files
    fclose(fptr1);
    fclose(fptr2);

    // Loop over each byte of the message data
    p = image_data;
    for (i = 0; i < message_size; i++) {
        b = message_data[i];

        // Loop over each bit of the byte
        for (j = 0; j < 8; j++) {
            if (b & 0x80) {
                // Set the least significant bit of the current pixel to 1
                *p |= 1;
            } else {
                // Set the least significant bit of the current pixel to 0
                *p &= ~1;
            }

            b <<= 1;
            p++;
        }
    }

    // Write the modified image data to a new file
    fptr1 = fopen(output_file, "wb");
    fwrite(image_data, 1, image_size, fptr1);
    fclose(fptr1);

    free(image_data);
    free(message_data);
}

void decode(char *image, char *output_file) {
    int image_size, message_size, i, j;
    char *p, *end, *message_end;
    FILE *fptr1, *fptr2;

    // Open the image file in binary mode
    fptr1 = fopen(image, "rb");

    // Check if the file exists and was opened successfully
    if (fptr1 == NULL) {
        printf("Error: Could not open image file %s\n", image);
        exit(1);
    }

    // Read the image file into memory
    char *image_data = (char *) malloc(MAX_FILE_SIZE * sizeof(char));
    image_size = fread(image_data, 1, MAX_FILE_SIZE, fptr1);

    // Close the file
    fclose(fptr1);

    // Allocate memory for the message data
    char *message_data = (char *) malloc(MAX_FILE_SIZE * sizeof(char));

    // Loop over each byte of the message data
    p = image_data;
    end = image_data + image_size - 1;
    message_end = message_data + MAX_FILE_SIZE;
    for (i = 0; i < MAX_FILE_SIZE; i++) {
        // Loop over each bit of the byte
        for (j = 0; j < 8; j++) {
            // Get the least significant bit of the current pixel
            char bit = *p & 1;

            // Save the bit to the message data
            *message_data <<= 1;
            *message_data |= bit;

            // Increment the message data pointer
            if (message_data < message_end) {
                message_data++;
            }

            // Increment the pixel data pointer
            if (p < end) {
                p++;
            }
        }

        // Stop looping if we have reached the end of the message data
        if (message_data >= message_end) {
            break;
        }
    }

    // Write the decoded message data to a new file
    fptr2 = fopen(output_file, "wb");
    fwrite(message_data, 1, message_size, fptr2);
    fclose(fptr2);

    free(image_data);
    free(message_data);
}

int main() {
    encode("input.jpg", "message.txt", "output.jpg");
    decode("output.jpg", "decoded_message.txt");

    return 0;
}