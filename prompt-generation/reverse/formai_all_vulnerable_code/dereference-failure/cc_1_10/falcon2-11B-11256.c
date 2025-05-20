//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    unsigned char *image, *message;
    int width, height, i, j, k;

    fp = fopen("input.bmp", "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    width = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    image = (unsigned char*) malloc(width*height*3);
    if (!image) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    fread(image, width*height*3, 1, fp);
    fclose(fp);

    message = (unsigned char*) malloc(strlen(message) + 1);
    if (!message) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if ((image[i*width*3+j*3+2] & 1) == 0) {
                image[i*width*3+j*3+2] |= 1 << (strlen(message) - 1);
                image[i*width*3+j*3+2] &= ~(1 << (strlen(message) - 1));
                message[strlen(message) - 1] = '0';
                message[strlen(message)] = '\0';
            }
        }
    }

    fp = fopen("output.bmp", "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    fwrite(image, width*height*3, 1, fp);
    fclose(fp);

    printf("Image steganography: %s\n", message);

    free(image);
    free(message);

    return 0;
}