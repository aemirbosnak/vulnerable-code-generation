//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* data;
} Image;

Image load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // Read header
    char header[54];
    fread(header, 1, 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Check if format is valid
    if (*(int*)&header[0] != 0x4D42 || *(int*)&header[28] != 24) {
        fprintf(stderr, "Invalid file format: %s", filename);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for image data
    Pixel* data = (Pixel*) malloc(sizeof(Pixel) * width * height);

    // Read pixel data
    fseek(file, *(int*)&header[10], SEEK_SET);
    for (int i = 0; i < width * height; i++) {
        unsigned char rgb[3];
        fread(rgb, 1, 3, file);
        data[i].r = rgb[2];
        data[i].g = rgb[1];
        data[i].b = rgb[0];
    }

    // Close file and return image
    fclose(file);
    return (Image){ width, height, data };
}

void save_image(const char* filename, const Image* image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // Write header
    char header[54];
    memset(header, 0, sizeof(header));
    header[0] = 0x42;
    header[1] = 0x4D;
    *(int*)&header[2] = 54 + image->width * image->height * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    fwrite(header, 1, 54, file);

    // Write pixel data
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char rgb[3] = { image->data[i].b, image->data[i].g, image->data[i].r };
        fwrite(rgb, 1, 3, file);
    }

    // Close file
    fclose(file);
}

Image invert_colors(Image image) {
    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i].r = 255 - image.data[i].r;
        image.data[i].g = 255 - image.data[i].g;
        image.data[i].b = 255 - image.data[i].b;
    }
    return image;
}

Image grayscale(Image image) {
    for (int i = 0; i < image.width * image.height; i++) {
        unsigned char gray = (30 * image.data[i].r + 59 * image.data[i].g + 11 * image.data[i].b) / 100;
        image.data[i].r = gray;
        image.data[i].g = gray;
        image.data[i].b = gray;
    }
    return image;
}

Image blur(Image image) {
    Pixel* buffer = (Pixel*) malloc(sizeof(Pixel) * image.width * image.height);
    memcpy(buffer, image.data, sizeof(Pixel) * image.width * image.height);

    int kernel[3][3] = {
        { 1, 2, 1 },
        { 2, 4, 2 },
        { 1, 2, 1 }
    };

    for (int y = 1; y < image.height - 1; y++) {
        for (int x = 1; x < image.width - 1; x++) {
            int r = 0, g = 0, b = 0;
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int index = (y + j) * image.width + (x + i);
                    r += buffer[index].r * kernel[j+1][i+1];
                    g += buffer[index].g * kernel[j+1][i+1];
                    b += buffer[index].b * kernel[j+1][i+1];
                }
            }
            int index = y * image.width + x;
            image.data[index].r = r / 16;
            image.data[index].g = g / 16;
            image.data[index].b = b / 16;
        }
    }

    free(buffer);
    return image;
}

int main() {
    Image original = load_image("example.bmp");
    Image inverted = invert_colors(original);
    Image gray = grayscale(original);
    Image blurred = blur(original);
    save_image("inverted.bmp", &inverted);
    save_image("grayscale.bmp", &gray);
    save_image("blurred.bmp", &blurred);
    return 0;
}