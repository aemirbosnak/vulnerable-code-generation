//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to generate and embed a digital watermark into the image
void embed_watermark(unsigned char *image, int width, int height, char *watermark) {

    // Allocate memory for digital watermark of size width * height (image size)
    unsigned char *digital_watermark = (unsigned char*)malloc(width*height*sizeof(unsigned char));

    // Adding digital watermark to the image using bitwise XOR operation
    for(int i=0; i<width*height; i++) {
        digital_watermark[i] = image[i] ^ watermark[i % strlen(watermark)];
    }

    // Storing the digital watermark back to the image
    memcpy(image, digital_watermark, width*height*sizeof(unsigned char));

    free(digital_watermark);
}

// Function to extract and decode digital watermark from the image
char* decode_watermark(unsigned char *image, int width, int height, int watermark_size) {

    // Allocate memory for digital watermark extracted from image
    char *digital_watermark = (char*)malloc(watermark_size*sizeof(char));

    // Extracting digital watermark from the image using bitwise XOR operation
    for(int i=0; i<watermark_size; i++) {
        digital_watermark[i] = image[i] ^ image[width*height-i-1];
    }

    // Null terminating the digital watermark
    digital_watermark[watermark_size] = '\0';

    return digital_watermark;
}

int main() {

    int width = 256, height = 256;
    unsigned char *image = (unsigned char*)malloc(width*height*sizeof(unsigned char));
    char *watermark = "Hello World! This is an example of digital watermarking using C language!";
    int watermark_size = strlen(watermark);

    // Populating image with random values between 0 to 255
    for(int i=0; i<width*height; i++) {
        image[i] = rand() % 256;
    }

    // Embedding the digital watermark into the image
    embed_watermark(image, width, height, watermark);

    // Extracting and decoding the digital watermark from the image
    char *digital_watermark = decode_watermark(image, width, height, watermark_size);

    printf("Original Watermark: %s\nDecoded Watermark: %s\n", watermark, digital_watermark);

    free(image);
    free(digital_watermark);

    return 0;
}