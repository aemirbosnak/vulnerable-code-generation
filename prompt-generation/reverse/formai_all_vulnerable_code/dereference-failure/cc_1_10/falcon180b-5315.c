//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 1024
#define HEIGHT 768

// Function to hide message in image
void hide(char* message, char* cover, char* stego) {
    FILE* fp_cover = fopen(cover, "rb");
    FILE* fp_stego = fopen(stego, "wb");

    if (fp_cover == NULL || fp_stego == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    int bytes_read = 0;
    char buffer[1024];

    // Read cover image into buffer
    while ((bytes_read = fread(buffer, 1, 1024, fp_cover)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_stego);
    }

    // Hide message in least significant bits of image
    int message_length = strlen(message);
    int bits_per_pixel = 24; // Assume RGB image
    int message_capacity = WIDTH * HEIGHT * bits_per_pixel;
    int message_index = 0;

    for (int i = 0; i < message_capacity; i++) {
        int bit = message[message_index] - '0';
        message_index++;

        // Check if message is fully hidden
        if (message_index >= message_length) {
            break;
        }

        // Hide bit in least significant bit of pixel
        fwrite(&buffer[i * 3], 1, 1, fp_stego);
    }

    fclose(fp_cover);
    fclose(fp_stego);
}

// Function to extract hidden message from image
void extract(char* stego, char* message) {
    FILE* fp_stego = fopen(stego, "rb");

    if (fp_stego == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int bytes_read = 0;
    char buffer[1024];

    // Read stego image into buffer
    while ((bytes_read = fread(buffer, 1, 1024, fp_stego)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(fp_stego);
}

int main() {
    char cover[] = "cover.jpg";
    char stego[] = "stego.jpg";
    char message[] = "Hello, world!";

    hide(message, cover, stego);
    extract(stego, message);

    return 0;
}