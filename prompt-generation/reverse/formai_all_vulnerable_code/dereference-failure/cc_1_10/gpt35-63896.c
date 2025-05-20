//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAXSIZE = 100000;

void error(const char* message) {
    printf("Error: %s", message);
    exit(1);
}

void hide(const char* imagepath, const char* message, const char* outputpath) {

    FILE* image = fopen(imagepath, "rb");
    if (!image) {
        error("Failed to open image file");
    }

    // Read the image header
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, image) != 54) {
        error("Failed to read image header");
    }

    // Get the image size
    int width = *(int*)& header[18];
    int height = *(int*)& header[22];

    // Calculate the size of the pixel array
    int size = width * height * 3;

    // Check if the message fits in the image
    if (strlen(message) * 8 + 32 > size) {
        error("Message is too long to be hidden in the image");
    }

    // Allocate memory for the pixel array
    unsigned char* pixels = (unsigned char*)malloc(size);
    if (!pixels) {
        error("Failed to allocate memory");
    }

    // Read the pixel array
    if (fread(pixels, sizeof(unsigned char), size, image) != size) {
        error("Failed to read pixel array");
    }

    // Close the image file
    fclose(image);

    // Get the length of the message
    int length = strlen(message);

    // Write the first 4 bytes of the pixel array with the length of the message
    pixels[0] = length >> 24;
    pixels[1] = length >> 16;
    pixels[2] = length >> 8;
    pixels[3] = length;

    // Convert the message to binary
    unsigned char binary[MAXSIZE];
    int index = 0;
    for (int i = 0; i < length; i++) {
        int c = message[i];
        for (int j = 7; j >= 0; j--) {
            binary[index++] = (c & (1 << j)) ? '1' : '0';
        }
    }

    // Hide the message in the pixel array
    index = 0;
    for (int i = 4; i < size; i += 3) {
        if (index < length * 8) {
            pixels[i] = (pixels[i] & 0xfe) | (binary[index++] == '1');
        }
        if (index < length * 8) {
            pixels[i + 1] = (pixels[i + 1] & 0xfe) | (binary[index++] == '1');
        }
        if (index < length * 8) {
            pixels[i + 2] = (pixels[i + 2] & 0xfe) | (binary[index++] == '1');
        }
    }

    // Write the modified pixel array to a new file
    FILE* output = fopen(outputpath, "wb");
    if (!output) {
        error("Failed to create output file");
    }

    // Write the header and pixel array to the output file
    if (fwrite(header, sizeof(unsigned char), 54, output) != 54) {
        error("Failed to write image header");
    }
    if (fwrite(pixels, sizeof(unsigned char), size, output) != size) {
        error("Failed to write pixel array");
    }

    // Close the output file
    fclose(output);

    // Free the allocated memory
    free(pixels);
}

char* reveal(const char* imagepath) {

    FILE* image = fopen(imagepath, "rb");
    if (!image) {
        error("Failed to open image file");
    }

    // Read the image header
    unsigned char header[54];
    if (fread(header, sizeof(unsigned char), 54, image) != 54) {
        error("Failed to read image header");
    }

    // Get the image size
    int width = *(int*)& header[18];
    int height = *(int*)& header[22];

    // Calculate the size of the pixel array
    int size = width * height * 3;

    // Allocate memory for the pixel array
    unsigned char* pixels = (unsigned char*)malloc(size);
    if (!pixels) {
        error("Failed to allocate memory");
    }

    // Read the pixel array
    if (fread(pixels, sizeof(unsigned char), size, image) != size) {
        error("Failed to read pixel array");
    }

    // Close the image file
    fclose(image);

    // Get the length of the message
    int length = pixels[0] << 24 | pixels[1] << 16 | pixels[2] << 8 | pixels[3];

    // Convert the message to binary
    unsigned char binary[MAXSIZE];
    int index = 0;
    for (int i = 4; i < size; i += 3) {
        if (index < length * 8) {
            binary[index++] = (pixels[i] & 1) ? '1' : '0';
        }
        if (index < length * 8) {
            binary[index++] = (pixels[i + 1] & 1) ? '1' : '0';
        }
        if (index < length * 8) {
            binary[index++] = (pixels[i + 2] & 1) ? '1' : '0';
        }
    }
    // Convert the binary message to ASCII
    char* message = (char*)malloc(length + 1);
    if (!message) {
        error("Failed to allocate memory");
    }
    index = 0;
    for (int i = 0; i < length * 8; i += 8) {
        int c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (binary[i + j] == '1') << (7 - j);
        }
        message[index++] = c;
    }
    message[index] = '\0';

    // Free the allocated memory
    free(pixels);

    // Return the decrypted message
    return message;
}

int main() {

    char imagepath[100], message[1000], outputpath[100];
    printf("Enter path of the cover image: ");
    fgets(imagepath,sizeof(imagepath),stdin);
    printf("Enter the message to be hidden in the image: ");
    fgets(message,sizeof(message),stdin);
    printf("Enter the output path of the stegno image: ");
    fgets(outputpath,sizeof(outputpath),stdin);

    // Remove newline characters from input
    imagepath[strcspn(imagepath, "\n")] = 0;
    message[strcspn(message, "\n")] = 0;
    outputpath[strcspn(outputpath, "\n")] = 0;

    // Encrypt the message in the image
    hide(imagepath, message, outputpath);

    printf("\nThe message has been successfully hidden in the image!\n\n");

    // Decrypt the hidden message from the image
    char* decrypted = reveal(outputpath);

    printf("The hidden message is:\n%s\n", decrypted);

    free(decrypted);

    return 0;
}