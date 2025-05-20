//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Convert binary to grayscale pixel
unsigned char gray_pixel(unsigned char *src, int n, int bit) {
    unsigned char dst[n];
    int i;

    for (i = 0; i < n; i++) {
        dst[i] = (src[i] & (1 << bit))? 0xff : 0x00;
    }

    return dst;
}

// Convert grayscale pixel to binary
unsigned char binary_pixel(unsigned char *src, int n, int bit) {
    unsigned char dst[n];
    int i;

    for (i = 0; i < n; i++) {
        dst[i] = (src[i] & 0xff) == 0xff? 1 : 0;
    }

    return dst;
}

// Read an image file in grayscale
unsigned char *read_image(const char *filename) {
    unsigned char *data = NULL;
    int width, height, bytes_per_line;
    FILE *fp = fopen(filename, "rb");

    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    data = (unsigned char*)malloc(filesize);
    if (!data) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    width = height = 0;
    bytes_per_line = 0;

    for (int i = 0; i < filesize; i++) {
        if (data[i] == 0x00) {
            width++;
        } else if (data[i] == 0xff) {
            height++;
        } else if (data[i] == 0xda) {
            bytes_per_line = (data[i+1] << 8) | data[i+2];
            break;
        }
    }

    unsigned char *image = (unsigned char*)malloc(width * height * bytes_per_line);
    if (!image) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (data[index++] << 8) | data[index++];
            image[y * width + x] = gray_pixel(image, bytes_per_line, 8);
        }
    }

    return image;
}

// Hide data in an image file
void hide_data(unsigned char *image, unsigned char *data, int size) {
    int width, height, bytes_per_line;
    unsigned char *hidden_image = NULL;

    width = height = 0;
    bytes_per_line = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] == 0x00) {
            width++;
        } else if (data[i] == 0xff) {
            height++;
        } else if (data[i] == 0xda) {
            bytes_per_line = (data[i+1] << 8) | data[i+2];
            break;
        }
    }

    hidden_image = (unsigned char*)malloc(width * height * bytes_per_line);
    if (!hidden_image) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (data[index++] << 8) | data[index++];
            hidden_image[y * width + x] = binary_pixel(image, bytes_per_line, 8);
        }
    }

    FILE *fp = fopen("output.png", "wb");
    if (!fp) {
        printf("Error opening file %s\n", "output.png");
        exit(EXIT_FAILURE);
    }

    fwrite(hidden_image, width * height * bytes_per_line, 1, fp);
    fclose(fp);

    free(image);
    free(hidden_image);
}

int main() {
    const char *filename = "image.png";
    unsigned char *image = read_image(filename);
    if (!image) {
        return 1;
    }

    unsigned char *data = "Hello, World!";
    hide_data(image, data, strlen(data));

    free(image);
    return 0;
}