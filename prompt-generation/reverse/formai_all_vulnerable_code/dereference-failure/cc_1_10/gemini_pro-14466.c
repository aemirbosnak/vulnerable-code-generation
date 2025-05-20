//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the header information
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    fread(&image->channels, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    // Write the header information
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(&image->channels, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);
}

void watermark_image(Image *image, char *watermark) {
    int i, j, k;

    // Convert the watermark to lowercase
    for (i = 0; watermark[i] != '\0'; i++) {
        watermark[i] = tolower(watermark[i]);
    }

    // Embed the watermark in the image data
    for (i = 0; i < image->width; i++) {
        for (j = 0; j < image->height; j++) {
            for (k = 0; k < image->channels; k++) {
                // Get the least significant bit of the pixel
                int lsb = image->data[i * image->width * image->channels + j * image->channels + k] & 1;

                // Embed the watermark bit in the pixel
                if (watermark[i] == '\0') {
                    image->data[i * image->width * image->channels + j * image->channels + k] &= ~1;
                } else {
                    image->data[i * image->width * image->channels + j * image->channels + k] |= watermark[i] & 1;
                    watermark++;
                }
            }
        }
    }
}

char *extract_watermark(Image *image) {
    int i, j, k;
    char *watermark = malloc(image->width + 1);
    if (!watermark) {
        perror("malloc");
        return NULL;
    }

    // Extract the watermark from the image data
    for (i = 0, k = 0; i < image->width; i++) {
        for (j = 0; j < image->height; j++) {
            for (k = 0; k < image->channels; k++) {
                // Get the least significant bit of the pixel
                int lsb = image->data[i * image->width * image->channels + j * image->channels + k] & 1;

                // Add the watermark bit to the watermark string
                watermark[i] |= lsb << k;
            }
        }
    }

    // Null-terminate the watermark string
    watermark[i] = '\0';

    // Convert the watermark string to uppercase
    for (i = 0; watermark[i] != '\0'; i++) {
        watermark[i] = toupper(watermark[i]);
    }

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <watermark>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Embed the watermark in the image
    watermark_image(image, argv[2]);

    // Write the watermarked image to a file
    write_image(image, "watermarked.bmp");

    // Extract the watermark from the image
    char *watermark = extract_watermark(image);
    if (!watermark) {
        return 1;
    }

    // Print the watermark
    printf("Watermark: %s\n", watermark);

    // Free the allocated memory
    free(image->data);
    free(image);
    free(watermark);

    return 0;
}