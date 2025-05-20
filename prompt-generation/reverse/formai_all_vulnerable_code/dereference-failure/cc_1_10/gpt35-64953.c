//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
// Welcome to my C Image Steganography program!
// In this program, we use steganography techniques to hide a secret message within an image.
// First, we read in the image and load it into our program.
// Then, we encode our secret message into the image by modifying the color values of each pixel.
// Finally, we save the new image with the hidden message encoded within it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants for image processing
#define HEADER_SIZE 54
#define MAX_MESSAGE_LENGTH 1000

// Function to read in an image file
unsigned char* read_image_file(char* filename, int* width, int* height) {
    FILE* img_file = fopen(filename, "rb");
    if (!img_file) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    // Read header information from file
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, img_file);

    // Get width and height from header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Calculate padding for each row
    int padding = 4 - ((*width)*3) % 4;
    padding = padding == 4 ? 0 : padding;

    // Allocate space for image data
    unsigned char* img_data = (unsigned char*)malloc(sizeof(unsigned char)*(*width)*(*height)*3);

    // Read image data from file
    for (int i = 0; i < *height; i++) {
        fread(&img_data[(*width)*3*i], sizeof(unsigned char), (*width)*3, img_file);
        fseek(img_file, padding, SEEK_CUR);
    }

    fclose(img_file);
    return img_data;
}

// Function to save an image file
void save_image_file(char* filename, unsigned char* img_data, int width, int height) {
    FILE* img_file = fopen(filename, "wb");
    if (!img_file) {
        printf("Error: could not create image file.\n");
        exit(1);
    }

    // Write header information to file
    unsigned char header[HEADER_SIZE];
    memset(header, 0, HEADER_SIZE);

    // BMP signature
    header[0] = 'B';
    header[1] = 'M';

    // File size
    *(int*)&header[2] = HEADER_SIZE + (width*height*3);

    // Data offset
    *(int*)&header[10] = HEADER_SIZE;

    // Width and height
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;

    // Bits per pixel
    *(short*)&header[28] = 24;

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, img_file);

    // Calculate padding for each row
    int padding = 4 - (width*3) % 4;
    padding = padding == 4 ? 0 : padding;

    // Write image data to file
    for (int i = 0; i < height; i++) {
        fwrite(&img_data[width*3*i], sizeof(unsigned char), width*3, img_file);
        if (padding > 0) {
            unsigned char padding_byte = 0;
            fwrite(&padding_byte, sizeof(unsigned char), padding, img_file);
        }
    }

    fclose(img_file);
}

// Function to encode a message into an image
void encode_message(unsigned char* img_data, int width, int height, char* message) {
    int message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message too long.\n");
        exit(1);
    }

    // Loop through all pixels in image and modify color values to encode message
    int pixel_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixel_index < message_length) {
                // Encode message character into pixel
                img_data[pixel_index*3] = (img_data[pixel_index*3] & 0xFC) | ((message[pixel_index] >> 6) & 0x03);
                img_data[pixel_index*3+1] = (img_data[pixel_index*3+1] & 0xFC) | ((message[pixel_index] >> 4) & 0x03);
                img_data[pixel_index*3+2] = (img_data[pixel_index*3+2] & 0xFC) | ((message[pixel_index] >> 2) & 0x03);
            }
            else {
                // If message is over, encode null character into pixel
                img_data[pixel_index*3] = (img_data[pixel_index*3] & 0xFC) | 0x00;
                img_data[pixel_index*3+1] = (img_data[pixel_index*3+1] & 0xFC) | 0x00;
                img_data[pixel_index*3+2] = (img_data[pixel_index*3+2] & 0xFC) | 0x00;
            }
            pixel_index++;
        }
    }
}

// Function to decode a message from an image
char* decode_message(unsigned char* img_data, int width, int height) {
    char* message = (char*)malloc(sizeof(char)*MAX_MESSAGE_LENGTH);
    memset(message, 0, sizeof(char)*MAX_MESSAGE_LENGTH);

    // Loop through all pixels in image and extract message characters
    int pixel_index = 0;
    char message_char = 0;
    int bit_index = 0;
    while (bit_index < 8*MAX_MESSAGE_LENGTH) {
        if (pixel_index >= width*height) {
            printf("Error: message not found.\n");
            exit(1);
        }

        // Extract two bits of the message character from each color channel of pixel
        message_char = (message_char << 2) | ((img_data[pixel_index*3] & 0x03) << 6);
        message_char = (message_char << 2) | ((img_data[pixel_index*3+1] & 0x03) << 4);
        message_char = (message_char << 2) | ((img_data[pixel_index*3+2] & 0x03) << 2);

        if ((bit_index % 8) == 7) {
            message[bit_index/8] = message_char;
            if (message_char == 0) {
                break;
            }
            message_char = 0;
        }

        pixel_index++;
        bit_index += 2;
    }

    return message;
}

int main() {
    int width = 0;
    int height = 0;

    // Read in image file
    char* filename = "image.bmp";
    unsigned char* img_data = read_image_file(filename, &width, &height);
    printf("Read in image file %s.\n", filename);

    // Encode a message into the image
    char* message = "Hello, world!";
    encode_message(img_data, width, height, message);
    printf("Encoded message into image.\n");

    // Save the modified image to a new file
    char* new_filename = "encoded_image.bmp";
    save_image_file(new_filename, img_data, width, height);
    printf("Saved encoded image to file %s.\n", new_filename);

    // Decode the message from the modified image
    char* decoded_message = decode_message(img_data, width, height);
    printf("Decoded message from image: %s\n", decoded_message);

    // Free memory 
    free(img_data);
    free(decoded_message);

    return 0;
}