//FormAI DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

void encrypt(FILE* input_file, FILE* output_file, char* message);
char* decrypt(FILE* input_file);

int main() {
    char message[] = "Hello, world! This is an example of image steganography using C.";
    FILE* input_file = fopen("input_image.bmp", "rb");
    FILE* output_file = fopen("output_image.bmp", "wb");

    if (!input_file || !output_file) {
        printf("Error opening files.\n");
        return 1;
    }

    encrypt(input_file, output_file, message);
    printf("Message successfully encrypted.\n");
    fclose(input_file);
    fclose(output_file);

    input_file = fopen("output_image.bmp", "rb");

    if (!input_file) {
        printf("Error opening file.\n");
        return 1;
    }

    char* decrypted_message = decrypt(input_file);
    printf("Decrypted Message: %s\n", decrypted_message);
    free(decrypted_message);
    fclose(input_file);

    return 0;
}

void encrypt(FILE* input_file, FILE* output_file, char* message) {
    // Read header info
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate pixel array size
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    int pixel_array_size = height * (width * 3 + padding);

    // Read pixel array
    Pixel* pixel_array = malloc(pixel_array_size);
    fread(pixel_array, sizeof(unsigned char), pixel_array_size, input_file);

    // Encode message length in first 32 pixels
    int message_length = strlen(message);
    for (int i = 0; i < 32; i++) {
        Pixel pixel = pixel_array[i];
        if (message_length & (1 << i)) {
            pixel.red |= 1;
        } else {
            pixel.red &= ~1;
        }
        pixel_array[i] = pixel;
    }

    // Encode message in remaining pixels
    for (int i = 0; i < message_length; i++) {
        Pixel pixel = pixel_array[i + 32];
        for (int j = 0; j < 8; j++) {
            if (message[i] & (1 << j)) {
                pixel.red |= 1 << j;
            } else {
                pixel.red &= ~(1 << j);
            }
        }
        pixel_array[i + 32] = pixel;
    }

    // Write header and pixel array to output file
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(pixel_array, sizeof(unsigned char), pixel_array_size, output_file);
    free(pixel_array);
}

char* decrypt(FILE* input_file) {
    // Read header info
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate pixel array size
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    int pixel_array_size = height * (width * 3 + padding);

    // Read pixel array
    Pixel* pixel_array = malloc(pixel_array_size);
    fread(pixel_array, sizeof(unsigned char), pixel_array_size, input_file);

    // Decode message length from first 32 pixels
    int message_length = 0;
    for (int i = 0; i < 32; i++) {
        Pixel pixel = pixel_array[i];
        if (pixel.red & 1) {
            message_length |= 1 << i;
        }
    }

    // Decode message from remaining pixels
    char* message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        Pixel pixel = pixel_array[i + 32];
        char c = 0;
        for (int j = 0; j < 8; j++) {
            if (pixel.red & (1 << j)) {
                c |= 1 << j;
            }
        }
        message[i] = c;
    }
    message[message_length] = '\0';

    free(pixel_array);
    return message;
}