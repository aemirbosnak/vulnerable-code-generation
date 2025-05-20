//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void digital_watermarking(char *image, char *key) {
    int watermark_size = strlen(key);
    int width = strlen(image);
    int height = 1;

    char *watermarked_image = (char*) malloc(sizeof(char) * (width * height));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int index = (i * height + j) * 3;
            unsigned char red = (unsigned char) image[index];
            unsigned char green = (unsigned char) image[index + 1];
            unsigned char blue = (unsigned char) image[index + 2];

            int key_index = (i * height + j) * 3;
            unsigned char key_red = (unsigned char) key[key_index];
            unsigned char key_green = (unsigned char) key[key_index + 1];
            unsigned char key_blue = (unsigned char) key[key_index + 2];

            if (key_red == red && key_green == green && key_blue == blue) {
                watermarked_image[index] = 255;
                watermarked_image[index + 1] = 0;
                watermarked_image[index + 2] = 0;
            } else {
                watermarked_image[index] = red;
                watermarked_image[index + 1] = green;
                watermarked_image[index + 2] = blue;
            }
        }
    }

    printf("Watermarked image:\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", watermarked_image[i * height + j]);
        }
        printf("\n");
    }

    free(watermarked_image);
}

int main() {
    char *image = "R0lGODlhAQABAIAAAAAAAP///ywAAAAAAQABAAACAUwAOw==";
    char *key = "Hello World";
    digital_watermarking(image, key);
    return 0;
}