//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    unsigned char header[54];
    uint32_t width;
    uint32_t height;
    uint32_t size;
    unsigned char *data;
} BMPImage;

BMPImage *loadBMP(const char *filename);
void saveBMP(const char *filename, BMPImage *image);
void embedMessage(BMPImage *image, const char *message);
char *extractMessage(BMPImage *image);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image.bmp> <message/output.bmp>\n", argv[0]);
        return 1;
    }

    BMPImage *image = loadBMP(argv[2]);
    if (!image) {
        fprintf(stderr, "Failed to load image %s\n", argv[2]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(image, argv[3]);
        saveBMP("output.bmp", image);
        printf("Message embedded successfully in output.bmp\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        char *message = extractMessage(image);
        if (message) {
            printf("Extracted message: %s\n", message);
            free(message);
        } else {
            printf("No message found in the image\n");
        }
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
    }

    free(image->data);
    free(image);
    return 0;
}

BMPImage *loadBMP(const char *filename) {
    BMPImage *image = malloc(sizeof(BMPImage));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        free(image);
        return NULL;
    }

    fread(image->header, sizeof(unsigned char), 54, file);
    image->width = *(int*)&image->header[18];
    image->height = *(int*)&image->header[22];
    image->size = image->width * image->height * 3; // Assuming 24 bit BMP

    image->data = malloc(image->size);
    if (!image->data) {
        fprintf(stderr, "Memory allocation for image data failed\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->size, file);
    fclose(file);
    return image;
}

void saveBMP(const char *filename, BMPImage *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    fwrite(image->header, sizeof(unsigned char), 54, file);
    fwrite(image->data, sizeof(unsigned char), image->size, file);
    fclose(file);
}

void embedMessage(BMPImage *image, const char *message) {
    size_t messageLength = strlen(message);
    if (messageLength > (image->size / 8)) {
        fprintf(stderr, "Message is too long to embed in the image\n");
        return;
    }

    // Embed length of message in the first byte of the last pixel
    image->data[image->size - 1] = messageLength;

    for (size_t i = 0; i < messageLength; i++) {
        // Embed message into the least significant bit of each color component
        for (int j = 0; j < 3; j++) {
            image->data[(image->size - 2 - i) * 3 + j] =
                (image->data[(image->size - 2 - i) * 3 + j] & ~1) | ((message[i] >> j) & 1);
        }
    }
}

char *extractMessage(BMPImage *image) {
    size_t messageLength = image->data[image->size - 1];
    char *message = malloc(messageLength + 1);
    if (!message) {
        fprintf(stderr, "Memory allocation for message extraction failed\n");
        return NULL;
    }

    for (size_t i = 0; i < messageLength; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            // Extract message from the least significant bit of each color component
            int colorIndex = (image->size - 2 - i) * 3 + j / 3;
            message[i] |= ((image->data[colorIndex] & 1) << j);
        }
    }
    message[messageLength] = '\0';
    return message;
}