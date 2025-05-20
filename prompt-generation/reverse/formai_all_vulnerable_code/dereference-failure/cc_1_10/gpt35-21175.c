//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to load image
void load_image(char* file_path, int* image_data, int* w, int* h) {
    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error loading image %s\n", file_path);
        exit(1);
    }

    // read in headers
    char buffer[54];
    fread(buffer, 1, 54, fp);

    // extract width and height
    *w = *(int*)&buffer[18];
    *h = *(int*)&buffer[22];

    // calculate size of image data
    int size = (*w) * (*h) * 3;

    // allocate memory for image data
    *image_data = (int*)malloc(size);

    // read in image data
    fread(*image_data, 1, size, fp);

    // close file
    fclose(fp);
}

// function to save image
void save_image(char* file_path, int* image_data, int w, int h) {
    FILE* fp = fopen(file_path, "wb");
    if (fp == NULL) {
        printf("Error saving image %s\n", file_path);
        exit(1);
    }

    // create header
    char header[54] = {
        0x42, 0x4D,       // bitmap identifier
        0x00, 0x00, 0x00, 0x00, // size of bitmap file
        0x00, 0x00,       // reserved
        0x00, 0x00,       // reserved
        0x36, 0x00, 0x00, 0x00, // offset to start of image data
        0x28, 0x00, 0x00, 0x00, // size of bitmap info header
        0x00, 0x00, 0x00, 0x00, // width of bitmap
        0x00, 0x00, 0x00, 0x00, // height of bitmap
        0x01, 0x00,       // number of color planes
        0x18, 0x00,       // bits per pixel (24-bit)
        0x00, 0x00, 0x00, 0x00, // compression mode (none)
        0x00, 0x00, 0x00, 0x00, // size of image data (set later)
        0x13, 0x0B, 0x00, 0x00, // horizontal resolution (2835 pixels/meter)
        0x13, 0x0B, 0x00, 0x00, // vertical resolution (2835 pixels/meter)
        0x00, 0x00, 0x00, 0x00, // number of colors in color palette (not used)
        0x00, 0x00, 0x00, 0x00  // number of important colors (not used)
    };

    // populate header
    int size = w * h * 3;
    *(int*)&header[2] = 54 + size;
    *(int*)&header[18] = w;
    *(int*)&header[22] = h;
    *(int*)&header[34] = size;

    // write header
    fwrite(header, 1, 54, fp);

    // write image data
    fwrite(image_data, 1, size, fp);

    // close file
    fclose(fp);
}

// function to flip image vertically
void flip_vertically(int* image_data, int w, int h) {
    int temp[w * 3];
    for (int i = 0; i < h / 2; i++) {
        memcpy(temp, &image_data[i * w * 3], w * 3);
        memcpy(&image_data[i * w * 3], &image_data[(h - i - 1) * w * 3], w * 3);
        memcpy(&image_data[(h - i - 1) * w * 3], temp, w * 3);
    }
}

// function to desaturate image
void desaturate(int* image_data, int w, int h) {
    for (int i = 0; i < w * h * 3; i += 3) {
        int r = image_data[i];
        int g = image_data[i + 1];
        int b = image_data[i + 2];

        int gray = (r + g + b) / 3;

        image_data[i] = gray;
        image_data[i + 1] = gray;
        image_data[i + 2] = gray;
    }
}

int main(int argc, char** argv) {
    // check command line arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // load input image
    int* image_data;
    int w, h;
    load_image(argv[1], &image_data, &w, &h);

    // flip image vertically
    flip_vertically(image_data, w, h);

    // desaturate image
    desaturate(image_data, w, h);

    // save output image
    save_image(argv[2], image_data, w, h);

    // free memory
    free(image_data);

    printf("Image processing complete!\n");

    return 0;
}