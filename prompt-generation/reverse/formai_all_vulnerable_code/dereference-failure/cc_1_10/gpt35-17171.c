//FormAI DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void hide_msg_in_pixels(byte *pixels, char *msg) {
    int i = 0, j = 0, k = 0, byte_index = 0;
    byte mask = 1;

    // loop through each pixel
    for(i = 0; pixels[i+2] != '\0'; i+=3) {
        // loop through each color in the pixel (RGB)
        for(j=0; j<3; j++) {
            // check if there is a bit to hide the message in
            if(k<8) {
                // set the lsb to the current bit in the message
                pixels[i+j] = (pixels[i+j] & ~mask) | ((msg[byte_index] >> k) & mask);
                k++;
            } else {
                byte_index++;
                k = 0;
            }
        }
    }
}

void read_msg_from_pixels(byte *pixels, char *msg) {
    int i = 0, j = 0, k = 0, byte_index = 0;
    byte mask = 1, temp = 0;

    // loop through each pixel
    for(i = 0; pixels[i+2] != '\0'; i+=3) {
        // loop through each color in the pixel (RGB)
        for(j=0; j<3; j++) {
            // get the lsb from the color and add it to the message
            temp = pixels[i+j] & mask;
            msg[byte_index] |= (temp << k);

            if(k == 7) {
                byte_index++;
                msg[byte_index] = '\0';
            } else {
                k++;
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[] = "test.bmp";
    byte *pixels;
    char message[] = "This is a secret message hidden in an image";

    // open the image file
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // read in the pixels from the image
    fseek(fp, 54, SEEK_SET);  // start reading at the pixel data
    pixels = (byte*)malloc(3*sizeof(byte));
    while(fread(pixels, sizeof(byte), 3, fp)) {
        // do something with the pixels
    }

    // hide the message in the pixels and save the new image
    hide_msg_in_pixels(pixels, message);
    // ...

    // read the message from the pixels
    char message_out[100];
    read_msg_from_pixels(pixels, message_out);
    printf("The message hidden in the image is: %s\n", message_out);

    // clean up
    free(pixels);
    fclose(fp);

    return 0;
}