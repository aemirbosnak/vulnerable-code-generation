//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int *data;
    unsigned int size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Read the image header
    unsigned int width, height;
    if (fread(&width, sizeof(unsigned int), 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        return NULL;
    }
    if (fread(&height, sizeof(unsigned int), 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }
    image->data = malloc(width * height * sizeof(unsigned int));
    if (image->data == NULL) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, sizeof(unsigned int), width * height, fp) != width * height) {
        perror("fread");
        free(image->data);
        free(image);
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    // Return the image
    image->size = width * height;
    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    // Write the image header
    unsigned int width = image->size / image->size;
    unsigned int height = image->size / width;
    if (fwrite(&width, sizeof(unsigned int), 1, fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return;
    }
    if (fwrite(&height, sizeof(unsigned int), 1, fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return;
    }

    // Write the image data
    if (fwrite(image->data, sizeof(unsigned int), image->size, fp) != image->size) {
        perror("fwrite");
        fclose(fp);
        return;
    }

    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    for (unsigned int i = 0; i < image->size; i++) {
        // Extract the least significant bit of the image data
        unsigned int lsb = image->data[i] & 1;

        // Embed the watermark bit into the LSB of the image data
        image->data[i] = (image->data[i] & ~1) | (watermark[i % strlen(watermark)] & 1);

        // Increment the watermark index
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host image> <watermark> <watermarked image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the host image
    Image *host_image = read_image(argv[1]);
    if (host_image == NULL) {
        return EXIT_FAILURE;
    }

    // Embed the watermark into the host image
    embed_watermark(host_image, argv[2]);

    // Write the watermarked image
    write_image(argv[3], host_image);

    // Free the host image
    free(host_image->data);
    free(host_image);

    return EXIT_SUCCESS;
}