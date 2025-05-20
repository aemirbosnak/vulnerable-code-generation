//FormAI DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the bits of a character
void getBits(char ch, int* bits) {
    int i = 0;
    while(ch > 0) {
        bits[i++] = ch % 2;
        ch /= 2;
    }
    while(i < 8) {
        bits[i++] = 0;
    }
}

// Function to convert the bits into a character
char getChar(int* bits) {
    int ch = 0, i;
    for(i = 7; i >= 0; i--) {
        ch = ch*2 + bits[i];
    }
    return ch;
}

// Function to hide the message in the image
void hideMessage(char* message, char* image) {
    int len = strlen(message);
    int pos = 0, i, j, bits[8];
    for(i = 0; i < len; i++) {
        getBits(message[i], bits);
        for(j = 0; j < 8; j++) {
            if(bits[j] == 1) {
                image[pos] |= 1 << j;
            } else {
                image[pos] &= ~(1 << j);
            }
            pos++;
        }
    }
}

// Function to extract the message from the image
char* extractMessage(char* image, int messageLen) {
    char* message = (char*)malloc((messageLen+1)*sizeof(char));
    int pos = 0, i, j, bits[8];
    for(i = 0; i < messageLen; i++) {
        for(j = 0; j < 8; j++) {
            bits[j] = (image[pos] >> j) & 1;
        }
        message[i] = getChar(bits);
        pos++;
    }
    message[i] = '\0';
    return message;
}

int main() {
    char* message = "Hello, this is a secret message!";
    char* image = (char*)malloc(100*sizeof(char));
    strcpy(image, "This is an image");

    printf("Original message: %s\nOriginal image: %s\n", message, image);

    hideMessage(message, image);

    printf("Image with hidden message: %s\n", image);

    char* extractedMessage = extractMessage(image, strlen(message));
    printf("Extracted message: %s\n", extractedMessage);

    free(image);
    free(extractedMessage);

    return 0;
}