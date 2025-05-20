//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned char *image;
    unsigned int width;
    unsigned int height;
    unsigned int stride;
    unsigned int numBytes;
    unsigned int payloadSize;
    unsigned char *payload;
} Image;

Image createImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    unsigned char *image = (unsigned char *)malloc(size);
    if (image == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    unsigned int numBytes = fread(image, 1, size, file);
    if (numBytes!= size) {
        perror("Error reading file");
        exit(1);
    }

    fclose(file);

    Image imageInfo;
    imageInfo.image = image;
    imageInfo.width = 0;
    imageInfo.height = 0;
    imageInfo.stride = 0;
    imageInfo.numBytes = size;

    return imageInfo;
}

void printImage(const Image *image) {
    unsigned int numPixels = image->width * image->height;
    printf("%d x %d image with %d pixels\n", image->width, image->height, numPixels);
}

void destroyImage(Image *image) {
    free(image->image);
    free(image);
}

bool hideMessage(Image *image, unsigned int payloadSize, const unsigned char *payload) {
    if (payloadSize > image->numBytes) {
        fprintf(stderr, "Payload size exceeds image size\n");
        return false;
    }

    unsigned char *message = (unsigned char *)malloc(payloadSize);
    if (message == NULL) {
        perror("Error allocating memory");
        return false;
    }

    unsigned int numBytes = 0;
    unsigned int offset = 0;
    unsigned int bits = 0;
    unsigned int numPixels = image->width * image->height;

    while (numBytes < payloadSize) {
        unsigned char bit = payload[numBytes];
        if (bit == 0) {
            bit = 1;
            offset += numPixels;
        } else {
            bit = 0;
            offset -= numPixels;
        }

        bits = (bits << 1) | bit;
        numBytes++;
    }

    unsigned char *result = (unsigned char *)malloc(numPixels + 1);
    if (result == NULL) {
        perror("Error allocating memory");
        return false;
    }

    for (unsigned int i = 0; i < image->width; i++) {
        for (unsigned int j = 0; j < image->height; j++) {
            unsigned int pixel = image->image[offset];
            result[offset] = pixel ^ (bits % 2);
            bits /= 2;
            offset += image->stride;
        }
    }

    result[numPixels] = 0;

    free(image->image);
    image->image = result;
    image->payload = payload;
    image->payloadSize = payloadSize;

    return true;
}

unsigned int extractMessage(const Image *image) {
    unsigned int payloadSize = image->payloadSize;
    unsigned int numPixels = image->width * image->height;
    unsigned int numBytes = numPixels + 1;

    unsigned int bits = 0;
    unsigned int numBytesRead = 0;

    for (unsigned int i = 0; i < numPixels; i++) {
        unsigned int pixel = image->image[i];
        if (pixel!= 0) {
            bits |= 1;
            numBytesRead++;
        }
        numBytes -= 1;
    }

    unsigned char *payload = (unsigned char *)malloc(payloadSize);
    if (payload == NULL) {
        perror("Error allocating memory");
        return 0;
    }

    for (unsigned int i = 0; i < numBytes; i++) {
        if (bits & 1) {
            payload[numBytesRead++] = image->image[i];
        } else {
            payload[numBytesRead++] = 0;
        }
        bits = 1;
    }

    return numBytesRead;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <image> <payload>\n", argv[0]);
        exit(1);
    }

    Image image = createImage(argv[1]);
    if (image.image == NULL) {
        return 1;
    }

    unsigned int payloadSize = atoi(argv[2]);

    unsigned char *payload = (unsigned char *)malloc(payloadSize);
    if (payload == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    sscanf(argv[2], "%hhu", payload);

    if (!hideMessage(&image, payloadSize, payload)) {
        fprintf(stderr, "Error hiding payload\n");
        return 1;
    }

    printImage(&image);

    unsigned int numBytes = extractMessage(&image);
    printf("Extracted payload of size %d bytes\n", numBytes);

    destroyImage(&image);

    return 0;
}