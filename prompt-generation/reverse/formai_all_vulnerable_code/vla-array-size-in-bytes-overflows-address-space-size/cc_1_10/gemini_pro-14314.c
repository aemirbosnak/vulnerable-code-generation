//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read header
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if it's a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP file\n");
        exit(1);
    }

    // Get image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    // Read image data
    fread(image->data, 1, width * height * 3, fp);

    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Write header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image->width * image->height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = image->width * image->height * 3;
    *(int *)&header[38] = 0;
    *(int *)&header[42] = 0;
    *(int *)&header[46] = 0;
    *(int *)&header[50] = 0;

    fwrite(header, 1, 54, fp);

    // Write image data
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    fclose(fp);
}

void embed_watermark(Image *image, char *message) {
    int i, j, k;

    // Convert message to binary
    int binary_message[strlen(message) * 8];
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Embed watermark in image
    k = 0;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            // Embed one bit in each pixel
            image->data[i * image->width * 3 + j * 3] = (image->data[i * image->width * 3 + j * 3] & 0xFE) | binary_message[k++];

            // Embed one bit in each pixel
            image->data[i * image->width * 3 + j * 3 + 1] = (image->data[i * image->width * 3 + j * 3 + 1] & 0xFE) | binary_message[k++];

            // Embed one bit in each pixel
            image->data[i * image->width * 3 + j * 3 + 2] = (image->data[i * image->width * 3 + j * 3 + 2] & 0xFE) | binary_message[k++];
        }
    }
}

char *extract_watermark(Image *image) {
    int i, j, k;

    // Extract watermark from image
    int binary_message[image->width * image->height * 3 * 8];
    k = 0;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            // Extract one bit from each pixel
            binary_message[k++] = image->data[i * image->width * 3 + j * 3] & 1;

            // Extract one bit from each pixel
            binary_message[k++] = image->data[i * image->width * 3 + j * 3 + 1] & 1;

            // Extract one bit from each pixel
            binary_message[k++] = image->data[i * image->width * 3 + j * 3 + 2] & 1;
        }
    }

    // Convert binary watermark to string
    char *message = malloc(strlen(binary_message) / 8 + 1);
    k = 0;
    for (i = 0; i < strlen(binary_message) / 8; i++) {
        for (j = 0; j < 8; j++) {
            message[i] |= binary_message[k++] << j;
        }
    }

    message[strlen(binary_message) / 8] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark_message> <output_image>\n", argv[0]);
        exit(1);
    }

    // Read input image
    Image *image = read_image(argv[1]);

    // Embed watermark in image
    embed_watermark(image, argv[2]);

    // Write watermarked image
    write_image(image, argv[3]);

    // Extract watermark from image
    char *watermark = extract_watermark(image);

    // Print watermark
    printf("Watermark: %s\n", watermark);

    // Free memory
    free(image->data);
    free(image);
    free(watermark);

    return 0;
}