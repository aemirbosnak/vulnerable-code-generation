//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 10

void hideWatermark(char *watermark, FILE *imageFile) {
    unsigned char byte;
    int i = 0, bitPos = 0, wmLength = strlen(watermark);

    while (i <= wmLength) {
        byte = fgetc(imageFile);
        if (byte == EOF) {
            printf("Image file ended before watermark could be hidden.\n");
            exit(EXIT_FAILURE);
        }
        if (bitPos == 8) {  // We have written the watermark, now add a null terminator.
            byte &= 0xFE;  // Set the last bit to 0 to avoid detection.
            watermark[i++] = '\0';
            bitPos = 0;
        } else if (i < wmLength) {
            byte = (byte & 0xFE) | ((watermark[i] >> bitPos++) & 0x1);
        }
        fputc(byte, imageFile);
    }
}

void readWatermark(char *watermark, FILE *imageFile) {
    unsigned char byte;
    int i = 0, bitPos = 0;

    while (i < WATERMARK_SIZE) {
        byte = fgetc(imageFile);
        if (byte == EOF) {
            printf("Image file ended before watermark could be read.\n");
            exit(EXIT_FAILURE);
        }
        if (bitPos == 8) {  // We have read the watermark.
            watermark[i++] = '\0';
            bitPos = 0;
        } else {
            watermark[i] |= (byte & 0x1) << bitPos++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [-h | -r] <watermark> <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *mode = argv[1];
    char *watermark = argv[2];
    FILE *imageFile = fopen(argv[3], "rb+");
    if (!imageFile) {
        printf("Failed to open image file %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "-h") == 0) {
        hideWatermark(watermark, imageFile);
        printf("Watermark successfully hidden in the image.\n");
    } else if (strcmp(mode, "-r") == 0) {
        readWatermark(watermark, imageFile);
        printf("Read watermark: %s\n", watermark);
    } else {
        printf("Invalid mode %s, must be either -h (hide) or -r (read).\n", mode);
        return EXIT_FAILURE;
    }

    fclose(imageFile);
    return EXIT_SUCCESS;
}