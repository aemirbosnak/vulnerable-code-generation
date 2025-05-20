//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a pixel value to its hexadecimal representation
char* convertToHex(int pixel) {
    char* hex = (char*) malloc(3 * sizeof(char));
    sprintf(hex, "%02x", pixel);
    return hex;
}

// Function to convert a hexadecimal string to an integer
int convertToInt(char* hex) {
    return strtol(hex, NULL, 16);
}

// Function to embed a secret message in an image file
void embedMessage(const char* input, const char* secret) {
    // Open the input image file
    FILE* fp = fopen(input, "rb");
    if (fp == NULL) {
        printf("Error opening input image file\n");
        return;
    }

    // Open the output image file
    FILE* fpOut = fopen(input, "rb");
    if (fpOut == NULL) {
        printf("Error opening output image file\n");
        return;
    }

    // Read the header of the image file
    int magic;
    fread(&magic, sizeof(int), 1, fp);

    // Check if the input image is a JPEG
    if (magic!= 0xffd8ffd8) {
        printf("Error: input image is not a JPEG\n");
        return;
    }

    // Read the rest of the image data
    fread(secret, 1, strlen(secret), fp);

    // Replace the original image data with the secret message
    fseek(fp, 0, SEEK_SET);
    fwrite(secret, 1, strlen(secret), fp);
    fclose(fp);

    // Rewrite the image data to the output file
    fseek(fpOut, 0, SEEK_SET);
    fwrite(secret, 1, strlen(secret), fpOut);
    fclose(fpOut);

    // Clean up
    free(secret);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    embedMessage(argv[1], argv[2]);

    return 0;
}