//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Romeo and Juliet's secret message
char *secret = "But soft, what light through yonder window breaks?";

// Romeo's watermarking function
void romeo_watermark(char *image, char *message) {
    int i, j, index = 0;
    int w = sqrt(strlen(image) / 3);
    int h = sqrt(strlen(image) / 3);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (index < strlen(message)) {
                // Embed the message bit in the least significant bit of the red component
                image[3 * (i * w + j)] |= (message[index] & 1) << 0;
                // Embed the message bit in the least significant bit of the green component
                image[3 * (i * w + j) + 1] |= (message[index] & 1) << 1;
                // Embed the message bit in the least significant bit of the blue component
                image[3 * (i * w + j) + 2] |= (message[index] & 1) << 2;
                index++;
            }
        }
    }
}

// Juliet's watermark detection function
char *juliet_detect_watermark(char *image) {
    int i, j, index = 0;
    int w = sqrt(strlen(image) / 3);
    int h = sqrt(strlen(image) / 3);
    char *message = malloc(strlen(image) / 3);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (index < strlen(secret)) {
                // Extract the message bit from the least significant bit of the red component
                message[index] |= (image[3 * (i * w + j)] & 1) >> 0;
                // Extract the message bit from the least significant bit of the green component
                message[index] |= (image[3 * (i * w + j) + 1] & 1) >> 1;
                // Extract the message bit from the least significant bit of the blue component
                message[index] |= (image[3 * (i * w + j) + 2] & 1) >> 2;
                index++;
            }
        }
    }

    return message;
}

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.jpg", "rb");
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    rewind(fp);
    char *image = malloc(image_size);
    fread(image, 1, image_size, fp);
    fclose(fp);

    // Romeo watermarks the image with his secret message
    romeo_watermark(image, secret);

    // Juliet detects the watermark from the image
    char *message = juliet_detect_watermark(image);

    // Print the detected message
    printf("%s\n", message);

    // Free the allocated memory
    free(image);
    free(message);

    return 0;
}