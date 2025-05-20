//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB limit
#define MAX_BPP 255 // Maximum bits per pixel

// Function to encode a secret message into an image
void encode_image(char* image_file, char* secret_message) {
    // Open image file
    FILE* file = fopen(image_file, "rb");
    if (file == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    // Read image data
    unsigned char* image_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    fread(image_data, sizeof(unsigned char), MAX_FILE_SIZE, file);
    fclose(file);

    // Split image data into RGB components
    unsigned char* red_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    unsigned char* green_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    unsigned char* blue_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        unsigned char r = image_data[i];
        unsigned char g = image_data[i + MAX_FILE_SIZE / 2];
        unsigned char b = image_data[i + MAX_FILE_SIZE / 2 * 2];
        red_data[i] = r;
        green_data[i] = g;
        blue_data[i] = b;
    }

    // Modify red component to hide secret message
    unsigned char* secret_data = (unsigned char*)malloc(strlen(secret_message) * sizeof(unsigned char));
    for (int i = 0; i < strlen(secret_message); i++) {
        int index = (int)secret_message[i] * MAX_BPP / 8;
        if (index >= MAX_FILE_SIZE) {
            printf("Error: secret message exceeds maximum bits per pixel.\n");
            free(image_data);
            free(red_data);
            free(green_data);
            free(blue_data);
            free(secret_data);
            return;
        }
        red_data[index] = (unsigned char)(secret_data[i] + red_data[index]);
    }

    // Write modified image data to new file
    FILE* outfile = fopen(image_file, "wb");
    if (outfile == NULL) {
        printf("Error opening output file.\n");
        free(image_data);
        free(red_data);
        free(green_data);
        free(blue_data);
        free(secret_data);
        return;
    }
    fwrite(red_data, sizeof(unsigned char), MAX_FILE_SIZE, outfile);
    fwrite(green_data, sizeof(unsigned char), MAX_FILE_SIZE, outfile);
    fwrite(blue_data, sizeof(unsigned char), MAX_FILE_SIZE, outfile);
    fclose(outfile);

    printf("Successfully encoded secret message into image file.\n");

    // Free memory
    free(image_data);
    free(red_data);
    free(green_data);
    free(blue_data);
    free(secret_data);
}

// Function to decode a hidden message from an image
char* decode_image(char* image_file, char* secret_message) {
    // Open image file
    FILE* file = fopen(image_file, "rb");
    if (file == NULL) {
        printf("Error opening image file.\n");
        return NULL;
    }

    // Read image data
    unsigned char* image_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    fread(image_data, sizeof(unsigned char), MAX_FILE_SIZE, file);
    fclose(file);

    // Split image data into RGB components
    unsigned char* red_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    unsigned char* green_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    unsigned char* blue_data = (unsigned char*)malloc(MAX_FILE_SIZE);
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        unsigned char r = image_data[i];
        unsigned char g = image_data[i + MAX_FILE_SIZE / 2];
        unsigned char b = image_data[i + MAX_FILE_SIZE / 2 * 2];
        red_data[i] = r;
        green_data[i] = g;
        blue_data[i] = b;
    }

    // Decode hidden message from red component
    char* secret_data = (char*)malloc(strlen(secret_message) * sizeof(char));
    for (int i = 0; i < strlen(secret_message); i++) {
        int index = (int)secret_message[i] * MAX_BPP / 8;
        if (index >= MAX_FILE_SIZE) {
            printf("Error: secret message exceeds maximum bits per pixel.\n");
            free(image_data);
            free(red_data);
            free(green_data);
            free(blue_data);
            free(secret_data);
            return NULL;
        }
        int r = red_data[index];
        int g = red_data[index + MAX_FILE_SIZE / 2];
        int b = red_data[index + MAX_FILE_SIZE / 2 * 2];
        if ((r ^ (1 << (7 - (int)secret_message[i])))!= (1 << (7 - (int)secret_message[i]))) {
            secret_data[i] = (char)(r ^ (1 << (7 - (int)secret_message[i])) + 1);
        } else {
            secret_data[i] = (char)(r ^ (1 << (7 - (int)secret_message[i])) - 1);
        }
    }

    // Free memory
    free(image_data);
    free(red_data);
    free(green_data);
    free(blue_data);
    return secret_data;
}

int main() {
    char* secret_message = "HELLO WORLD";
    char* image_file = "image.png";

    // Encode secret message into image
    encode_image(image_file, secret_message);

    // Decode hidden message from image
    char* hidden_message = decode_image(image_file, secret_message);
    printf("Hidden message: %s\n", hidden_message);

    // Free memory
    free(hidden_message);
    return 0;
}