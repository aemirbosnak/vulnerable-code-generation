//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef struct {
    u16 width;
    u16 height;
    u8 *data;
} Image;

Image *read_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the file header
    u16 magic;
    fread(&magic, sizeof(u16), 1, f);
    if (magic != 0x4d42) {
        fprintf(stderr, "Error: invalid file format\n");
        fclose(f);
        return NULL;
    }

    u32 filesize;
    fread(&filesize, sizeof(u32), 1, f);
    fread(&filesize, sizeof(u32), 1, f);

    u16 offset;
    fread(&offset, sizeof(u16), 1, f);

    // Read the image header
    u32 header_size;
    fread(&header_size, sizeof(u32), 1, f);
    if (header_size != 40) {
        fprintf(stderr, "Error: invalid image header size\n");
        fclose(f);
        return NULL;
    }

    u32 width;
    fread(&width, sizeof(u32), 1, f);
    u32 height;
    fread(&height, sizeof(u32), 1, f);

    u16 planes;
    fread(&planes, sizeof(u16), 1, f);
    if (planes != 1) {
        fprintf(stderr, "Error: invalid number of planes\n");
        fclose(f);
        return NULL;
    }

    u16 bpp;
    fread(&bpp, sizeof(u16), 1, f);
    if (bpp != 8) {
        fprintf(stderr, "Error: invalid bits per pixel\n");
        fclose(f);
        return NULL;
    }

    u32 compression;
    fread(&compression, sizeof(u32), 1, f);
    if (compression != 0) {
        fprintf(stderr, "Error: invalid compression format\n");
        fclose(f);
        return NULL;
    }

    u32 image_size;
    fread(&image_size, sizeof(u32), 1, f);

    // Read the image data
    u8 *data = malloc(image_size);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(f);
        return NULL;
    }

    fread(data, image_size, 1, f);
    fclose(f);

    // Create the image struct
    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image struct\n");
        free(data);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the file header
    u16 magic = 0x4d42;
    fwrite(&magic, sizeof(u16), 1, f);

    u32 filesize = image->width * image->height + 54;
    fwrite(&filesize, sizeof(u32), 1, f);
    fwrite(&filesize, sizeof(u32), 1, f);

    u16 offset = 54;
    fwrite(&offset, sizeof(u16), 1, f);

    // Write the image header
    u32 header_size = 40;
    fwrite(&header_size, sizeof(u32), 1, f);

    fwrite(&image->width, sizeof(u32), 1, f);
    fwrite(&image->height, sizeof(u32), 1, f);

    u16 planes = 1;
    fwrite(&planes, sizeof(u16), 1, f);

    u16 bpp = 8;
    fwrite(&bpp, sizeof(u16), 1, f);

    u32 compression = 0;
    fwrite(&compression, sizeof(u32), 1, f);

    u32 image_size = image->width * image->height;
    fwrite(&image_size, sizeof(u32), 1, f);

    // Write the image data
    fwrite(image->data, image_size, 1, f);
    fclose(f);
}

void flip_image(Image *image) {
    for (u16 y = 0; y < image->height / 2; y++) {
        for (u16 x = 0; x < image->width; x++) {
            u8 temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (u16 y = 0; y < image->height; y++) {
        for (u16 x = 0; x < image->width; x++) {
            int new_brightness = image->data[y * image->width + x] + brightness;
            if (new_brightness < 0) {
                new_brightness = 0;
            } else if (new_brightness > 255) {
                new_brightness = 255;
            }
            image->data[y * image->width + x] = new_brightness;
        }
    }
}

void change_contrast(Image *image, int contrast) {
    for (u16 y = 0; y < image->height; y++) {
        for (u16 x = 0; x < image->width; x++) {
            int new_contrast = (image->data[y * image->width + x] - 127) * contrast / 100 + 127;
            if (new_contrast < 0) {
                new_contrast = 0;
            } else if (new_contrast > 255) {
                new_contrast = 255;
            }
            image->data[y * image->width + x] = new_contrast;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image
    flip_image(image);

    // Change the brightness
    change_brightness(image, 50);

    // Change the contrast
    change_contrast(image, 150);

    // Write the image to a file
    write_image(image, argv[2]);

    // Free the image memory
    free(image->data);
    free(image);

    return 0;
}