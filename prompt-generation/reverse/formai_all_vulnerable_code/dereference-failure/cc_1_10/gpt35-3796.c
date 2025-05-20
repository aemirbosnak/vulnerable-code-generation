//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the message to hide
#define MAX_MSG_LEN 100

// Define the size of the image to use
#define IMG_HEIGHT 10
#define IMG_WIDTH 10

// Define function to hide the message in the image
void hideMessageInImage(char *image, char *message) {
    int imgSize = IMG_HEIGHT * IMG_WIDTH;
    int msgLen = strlen(message);
    int msgChar = 0;

    // Loop through each pixel in the image
    for (int i = 0; i < imgSize; i++) {
        // Check if there are still characters to hide in the message
        if (msgChar < msgLen) {
            // Get the ASCII value of the next character in the message
            int charVal = (int)message[msgChar];

            // Get the binary value of the character and store it in an array
            int bits[8];
            int j = 0;
            while (charVal != 0) {
                int bit = charVal % 2;
                bits[j] = bit;
                charVal /= 2;
                j++;
            }

            // Loop through each bit and replace the LSB of the image pixel with the bit
            for (int k = 0; k < 8; k++) {
                if (bits[k] == 1) {
                    image[i] |= 1 << k;
                } else {
                    image[i] &= ~(1 << k);
                }
            }

            // Increment the message character counter
            msgChar++;
        } else {
            break;
        }
    }
}

int main() {
    printf("Welcome to the image steganography program!\n");

    // Allocate memory for the image and initialize to all zeros
    char *image = (char *)calloc(IMG_HEIGHT * IMG_WIDTH, sizeof(char));

    // Get user input for the message to hide and check if it's within the max length
    char message[MAX_MSG_LEN];
    printf("Please enter the message you want to hide in the image (max length: %d): ", MAX_MSG_LEN);
    fgets(message, MAX_MSG_LEN, stdin);
    if (strlen(message) >= MAX_MSG_LEN) {
        printf("The message is too long. Please try again.\n");
        return 0;
    }

    // Hide the message in the image
    hideMessageInImage(image, message);

    // Print out the image with the hidden message
    printf("Here is the image with the hidden message:\n");
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            printf("%d ", (int)image[i*IMG_WIDTH + j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image
    free(image);

    printf("Thank you for using the image steganography program!\n");

    return 0;
}