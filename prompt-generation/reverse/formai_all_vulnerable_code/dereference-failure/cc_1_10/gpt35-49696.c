//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function prototypes
Image* loadImage(char *filename);
int saveImage(Image *image, char *filename);
void freeImage(Image *image);
void flipHorizontal(Image *image);
void brightness(Image *image, int level);
void contrast(Image *image, float level);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_filename> <output_filename> <operation>\n", argv[0]);
        printf("Operation: fh (flip horizontal), br (brightness), ct (contrast)\n");
        return 1;
    }

    // Load image from input file
    Image *image = loadImage(argv[1]);

    if (image == NULL) {
        printf("Error loading image from file %s\n", argv[1]);
        return 1;
    }

    // Apply operation to image
    if (strcmp(argv[3], "fh") == 0) {
        flipHorizontal(image);
    }
    else if (strcmp(argv[3], "br") == 0) {
        int level = atoi(argv[4]);
        brightness(image, level);
    }
    else if (strcmp(argv[3], "ct") == 0) {
        float level = atof(argv[4]);
        contrast(image, level);
    }
    else {
        printf("Invalid operation: %s\n", argv[3]);
        return 1;
    }

    // Save image to output file
    if (!saveImage(image, argv[2])) {
        printf("Error saving image to file %s\n", argv[2]);
        return 1;
    }

    // Free memory allocated for image
    freeImage(image);

    return 0;
}

Image* loadImage(char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        return NULL;
    }

    char header[54];
    fread(header, sizeof(char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int dataSize = width * height * 3;
    Pixel *data = (Pixel*) malloc(dataSize);

    fread(data, sizeof(Pixel), dataSize, file);
    fclose(file);

    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

int saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        return 0;
    }

    unsigned char header[54] = {
        0x42,0x4D,0x36,0x69,0x06,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
        0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
        0x00,0x00,0x24,0x69,0x06,0x00,0x00,0x12,0x0B,0x00,0x00,0x12,0x0B,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    };

    int width = image->width;
    int height = image->height;
    int dataSize = width * height * 3;

    *(int*)&header[2] = 54 + dataSize;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;

    fwrite(header, sizeof(char), 54, file);
    fwrite(image->data, sizeof(Pixel), dataSize, file);

    fclose(file);

    return 1;
}

void freeImage(Image *image) {
    free(image->data);
    free(image);
}

void flipHorizontal(Image *image) {
    int width = image->width;
    int height = image->height;
    Pixel *data = image->data;
    Pixel temp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            temp = data[i*width+j];
            data[i*width+j] = data[i*width+width-j-1];
            data[i*width+width-j-1] = temp;
        }
    }
}

void brightness(Image *image, int level) {
    int width = image->width;
    int height = image->height;
    Pixel *data = image->data;
    int r, g, b;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            r = data[i*width+j].red + level;
            g = data[i*width+j].green + level;
            b = data[i*width+j].blue + level;

            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            data[i*width+j].red = (unsigned char)r;
            data[i*width+j].green = (unsigned char)g;
            data[i*width+j].blue = (unsigned char)b;
        }
    }
}

void contrast(Image *image, float level) {
    int width = image->width;
    int height = image->height;
    Pixel *data = image->data;
    int r, g, b;
    float factor = (259.0 * (level + 255.0)) / (255.0 * (259.0 - level));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            r = data[i*width+j].red;
            g = data[i*width+j].green;
            b = data[i*width+j].blue;

            r = (int)(factor * (r - 128) + 128);
            g = (int)(factor * (g - 128) + 128);
            b = (int)(factor * (b - 128) + 128);

            if (r < 0) r = 0;
            if (g < 0) g = 0;
            if (b < 0) b = 0;
            if (r > 255) r = 255;
            if (g > 255) g = 255;
            if (b > 255) b = 255;

            data[i*width+j].red = (unsigned char)r;
            data[i*width+j].green = (unsigned char)g;
            data[i*width+j].blue = (unsigned char)b;
        }
    }
}