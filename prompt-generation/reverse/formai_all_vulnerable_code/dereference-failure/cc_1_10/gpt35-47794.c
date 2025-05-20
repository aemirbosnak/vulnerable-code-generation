//FormAI DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store a pixel's RGB values
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// structure to store the image file data
typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// function to load an image file into memory
Image *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // read the header data
    char magic[2];
    fread(magic, sizeof(char), 2, fp);
    int width, height, maxval;
    fscanf(fp, "%d %d %d\n", &width, &height, &maxval);

    // allocate memory for the pixel data
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);

    // read the pixel data
    fread(pixels, sizeof(Pixel), width * height, fp);

    // close the file
    fclose(fp);

    // create an Image struct and store the data in it
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    return image;
}

// function to save an image file from memory
void saveImage(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file '%s' for writing\n", filename);
        return;
    }

    // write the header data
    char magic[2] = {'P','6'};
    fwrite(magic, sizeof(char), 2, fp);
    fprintf(fp, "%d %d\n255\n", image->width, image->height);

    // write the pixel data
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    // close the file
    fclose(fp);
}

// function to encode a secret message into an image
void encodeMessage(Image *image, char *message) {
    // create a copy of the pixel data to modify
    Pixel *pixels = malloc(sizeof(Pixel) * image->width * image->height);
    memcpy(pixels, image->pixels, sizeof(Pixel) * image->width * image->height);

    // loop over each pixel and encode the message bit by bit
    int messageIndex = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        // get the RGB values of the current pixel
        Pixel pixel = pixels[i];

        // encode the message bit into the least significant bit of the red channel
        if (message[messageIndex] == '0') {
            pixel.red &= 0xFE;
        } else {
            pixel.red |= 0x01;
        }

        // move to the next message bit
        messageIndex = (messageIndex + 1) % strlen(message);

        // update the modified pixel back into the copy of the pixel data
        pixels[i] = pixel;
    }

    // overwrite the original pixel data with the modified copy
    free(image->pixels);
    image->pixels = pixels;
}

// function to decode a secret message from an image
char *decodeMessage(Image *image) {
    // allocate memory for the decoded message
    char *message = malloc(sizeof(char) * (image->width * image->height) / 8 + 1);

    // loop over each pixel and extract the message bit by bit
    int messageIndex = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        // get the RGB values of the current pixel
        Pixel pixel = image->pixels[i];

        // extract the message bit from the least significant bit of the red channel
        if ((pixel.red & 0x01) == 0) {
            message[messageIndex] = '0';
        } else {
            message[messageIndex] = '1';
        }

        // move to the next message bit
        messageIndex++;

        // check if the entire message has been extracted
        if (messageIndex == (image->width * image->height) / 8) {
            break;
        }
    }

    // add the string terminator
    message[messageIndex] = '\0';

    return message;
}

int main() {
    // load the image file
    Image *image = loadImage("image.ppm");
    if (!image) {
        return 1;
    }

    // encode a message into the image
    char *message = "This is a secret message!";
    encodeMessage(image, message);

    // save the modified image file
    saveImage(image, "encoded.ppm");

    // decode the message from the image
    char *decodedMessage = decodeMessage(image);
    printf("Decoded message: %s\n", decodedMessage);

    // free the memory used by the image data
    free(image->pixels);
    free(image);
    free(decodedMessage);

    return 0;
}