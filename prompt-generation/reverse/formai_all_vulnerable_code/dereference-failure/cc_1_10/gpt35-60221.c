//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hide the message in the red component of the image pixels
void hideMessage(unsigned char *image, char *message, int size) {
    int i, j, k = 0;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            int pixel = (i * size + j) * 3;
            if (k < strlen(message)) {
                image[pixel] = (image[pixel] & 0xFE) | ((message[k] >> 7) & 0x01);
                image[pixel+1] = (image[pixel+1] & 0xFE) | ((message[k] >> 6) & 0x01);
                image[pixel+2] = (image[pixel+2] & 0xFE) | ((message[k] >> 5) & 0x01);
                k++;
            }
        }
    }
}

// Retrieve the message from the red component of the image pixels
void retrieveMessage(unsigned char *image, char *message, int size) {
    int i, j, k = 0;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            int pixel = (i * size + j) * 3;
            if (k < strlen(message)) {
                message[k] = ((image[pixel] & 0x01) << 7) | ((image[pixel+1] & 0x01) << 6) | ((image[pixel+2] & 0x01) << 5);
                k++;
            }
        }
    }
}

int main() {
    char message[] = "Hello world!";
    int size = 10;
    int imageSize = size * size * 3;
    unsigned char *image = (unsigned char*)malloc(imageSize);

    // Fill in some sample image data
    int i, j, k = 0;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            int pixel = (i * size + j) * 3;
            image[pixel] = 255;
            image[pixel+1] = 0;
            image[pixel+2] = 0;
        }
    }

    // Hide the message in the image
    hideMessage(image, message, size);

    // Retrieve the message from the image
    char *retrievedMessage = (char*)malloc(strlen(message));
    retrieveMessage(image, retrievedMessage, size);
    retrievedMessage[strlen(message)] = '\0';

    printf("Original message: %s\n", message);
    printf("Retrieved message: %s\n", retrievedMessage);

    free(image);
    free(retrievedMessage);
    
    return 0;
}