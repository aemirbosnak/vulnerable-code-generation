//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL 255

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

/* Function to create a new image */
Image* createImage(int width, int height) {
    Image* newImage = (Image*)malloc(sizeof(Image));
    newImage->width = width;
    newImage->height = height;
    newImage->data = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    memset(newImage->data, 0, width*height);
    return newImage;
}

/* Function to free an image */
void freeImage(Image* image) {
    free(image->data);
    free(image);
}

/* Function to read an image from a file */
Image* readImage(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("Error reading image file '%s'\n", fileName);
        return NULL;
    }
    char type[3];
    int width, height, maxPixel;
    fscanf(file, "%s%d%d%d", type, &width, &height, &maxPixel);

    Image* image = createImage(width, height);
    fread(image->data, sizeof(unsigned char), width*height, file);

    fclose(file);
    return image;
}

/* Function to write an image to a file */
int writeImage(char* fileName, Image* image) {
    FILE* file = fopen(fileName, "wb");
    if (!file) {
        printf("Error writing image file '%s'\n", fileName);
        return 0;
    }
    fprintf(file, "P5\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL);
    fwrite(image->data, sizeof(unsigned char), image->width*image->height, file);

    fclose(file);
    return 1;
}

/* Function to apply Gaussian blur to the image */
void gaussianBlur(Image* image, float sigma) {
    int kSize = ceil(3 * sigma) * 2 + 1;
    int kRadius = (kSize - 1) / 2;
    float* kernel = (float*)malloc(sizeof(float) * kSize * kSize);
    float sum = 0.0f;
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            int x = i - kRadius;
            int y = j - kRadius;
            kernel[i*kSize+j] = exp(-(float)(x*x + y*y) / (2.0f*sigma*sigma));
            sum += kernel[i*kSize+j];
        }
    }
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            kernel[i*kSize+j] /= sum;
        }
    }

    Image* tempImage = createImage(image->width, image->height);
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            float pixel = 0.0f;
            for (int k = 0; k < kSize; k++) {
                for (int l = 0; l < kSize; l++) {
                    int x = i + k - kRadius;
                    int y = j + l - kRadius;
                    if (x < 0) x = 0;
                    if (x >= image->width) x = image->width - 1;
                    if (y < 0) y = 0;
                    if (y >= image->height) y = image->height - 1;
                    pixel += kernel[k*kSize+l] * (float)(image->data[x*image->width+y]);
                }
            }
            tempImage->data[i*tempImage->width+j] = (unsigned char)pixel;
        }
    }
    memcpy(image->data, tempImage->data, image->width*image->height);
    freeImage(tempImage);
    free(kernel);
}

/* Main function */
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    Image* image = readImage(argv[1]);
    if (!image) {
        return 1;
    }

    gaussianBlur(image, 2.0f);

    if (!writeImage(argv[2], image)) {
        freeImage(image);
        return 1;
    }
    freeImage(image);
    return 0;
}