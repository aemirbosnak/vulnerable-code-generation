//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define DATA "secret.txt"
#define IMG "image.bmp"

// Extract pixel from image
unsigned char get_pixel(unsigned char *img, int i, int j, int c) {
    return img[(i * 3 + j) * 3 + c];
}

// Set pixel in image
void set_pixel(unsigned char *img, int i, int j, int c, unsigned char p) {
    img[(i * 3 + j) * 3 + c] = p;
}

// Embed data in image
void embed_data(unsigned char *img, unsigned char *data, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 3; k++) {
                unsigned char p = get_pixel(img, i / 8, j / 3, k);
                unsigned char bit = (data[i] >> (7 - j)) & 1;
                p = (p & 0xFE) | bit;
                set_pixel(img, i / 8, j / 3, k, p);
            }
        }
    }
}

// Extract data from image
unsigned char *extract_data(unsigned char *img, int n) {
    int i, j, k;
    unsigned char *data = (unsigned char *)malloc(n);
    for (i = 0; i < n; i++) {
        data[i] = 0;
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 3; k++) {
                unsigned char p = get_pixel(img, i / 8, j / 3, k);
                unsigned char bit = p & 1;
                data[i] |= (bit << (7 - j));
            }
        }
    }
    return data;
}

// Main function
int main() {
    unsigned char *img = NULL;
    unsigned char *data = NULL;
    FILE *fp;
    int size, n;

    // Open image file
    if ((fp = fopen(IMG, "rb")) == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Read image file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    img = (unsigned char *)malloc(size);
    fread(img, 1, size, fp);
    fclose(fp);

    // Get data from file
    if ((fp = fopen(DATA, "rb")) == NULL) {
        perror("Error opening data file");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    rewind(fp);
    data = (unsigned char *)malloc(n);
    fread(data, 1, n, fp);
    fclose(fp);

    // Embed data in image
    embed_data(img, data, n);

    // Save image file
    if ((fp = fopen(IMG, "wb")) == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }
    fwrite(img, 1, size, fp);
    fclose(fp);

    // Free memory
    free(img);
    free(data);

    return EXIT_SUCCESS;
}