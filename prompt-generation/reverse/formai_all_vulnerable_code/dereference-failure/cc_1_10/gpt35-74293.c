//FormAI DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This program demonstrates a unique implementation of LSB steganography on an image

//Function to get image data
unsigned char* getImage(char *filename) {
    FILE *in;
    unsigned char *data;

    in = fopen(filename,"rb");

    if (in == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    data = (unsigned char*) malloc(sizeof(unsigned char));

    fread(data,1,sizeof(unsigned char),in);

    fclose(in);

    return data;
}

//Function to write image data
void writeImage(char *filename, unsigned char *data) {
    FILE *out;

    out = fopen(filename,"wb");

    if (out == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(data,1,sizeof(unsigned char),out);

    fclose(out);

}

//Function to hide message in the least significant bits of the image data
void hideMessage(char *message, unsigned char *imageData) {
    int messageLength = strlen(message);
    int bitCount = 0;

    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (message[i] >> j) & 1;
            if (bit) {
                imageData[bitCount] |= 1;
            } else {
                imageData[bitCount] &= 0xFE;
            }
            bitCount++;
        }
    }
}

//Function to get hidden message from the least significant bits of the image data
char* getMessage(unsigned char *imageData) {
    char *message = (char*) malloc(sizeof(char));
    int messageLength = 0;
    int bitCount = 0;

    while (1) {
        char ch = 0;
        for (int i = 0; i < 8; i++) {
            char bit = imageData[bitCount] & 1;
            ch |= bit << i;
            bitCount++;
        }
        if (ch == '\0') break;
        message[messageLength] = ch;
        messageLength++;
        message = (char*) realloc(message,sizeof(char) * (messageLength + 1));
    }
    message[messageLength] = '\0';

    return message;
}

int main() {

    printf("LSB Steganography Implementation on Images\n\n");

    char *message = "Hidden message!";
    unsigned char *imageData;

    //Get the image data
    imageData = getImage("image.bmp");

    //Hide the message in the image data
    hideMessage(message,imageData);

    //Write the new image data to a file
    writeImage("hidden.bmp",imageData);

    //Get the hidden message from the image data
    char *hiddenMessage = getMessage(imageData);

    printf("Message hidden in image: %s\n",hiddenMessage);

    //Free memory
    free(imageData);
    free(hiddenMessage);

    return 0;
}