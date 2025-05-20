//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

/* Function to create a new image */
Image* createImage(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    if(img == NULL) {
        return NULL;
    }
    img->width = width;
    img->height = height;
    img->data = (unsigned char*)malloc(width * height * 3);
    if(img->data == NULL) {
        free(img);
        return NULL;
    }
    memset(img->data, 0, width * height * 3);
    return img;
}

/* Function to load an image from file */
Image* loadImage(char* path) {
    FILE* f = fopen(path, "rb");
    if(f == NULL) {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char* buffer = (unsigned char*)malloc(size);
    if(buffer == NULL) {
        fclose(f);
        return NULL;
    }
    fread(buffer, size, 1, f);
    fclose(f);
    int width = *(int*)&buffer[18];
    int height = *(int*)&buffer[22];
    Image* img = createImage(width, height);
    if(img == NULL) {
        free(buffer);
        return NULL;
    }
    memcpy(img->data, &buffer[54], width * height * 3);
    free(buffer);
    return img;
}

/* Function to save an image to file */
int saveImage(char* path, Image* img) {
    FILE* f = fopen(path, "wb");
    if(f == NULL) {
        return 0;
    }
    unsigned char fileHeader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
    unsigned char infoHeader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, img->width, 0, 0, 0, img->height, 0, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int fileSize = img->width * img->height * 3 + 54;
    fileHeader[2] = (unsigned char)(fileSize);
    fileHeader[3] = (unsigned char)(fileSize >> 8);
    fileHeader[4] = (unsigned char)(fileSize >> 16);
    fileHeader[5] = (unsigned char)(fileSize >> 24);
    fwrite(fileHeader, sizeof(unsigned char), 14, f);
    fwrite(infoHeader, sizeof(unsigned char), 40, f);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, f);
    fclose(f);
    return 1;
}

/* Function to get a pixel from an image */
unsigned char* getPixel(Image* img, int x, int y) {
    if(x >= 0 && x < img->width && y >= 0 && y < img->height) {
        return &img->data[(y * img->width + x) * 3];
    }
    return NULL;
}

/* Function to set a pixel in an image */
void setPixel(Image* img, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    unsigned char* pixel = getPixel(img, x, y);
    if(pixel != NULL) {
        pixel[0] = b;
        pixel[1] = g;
        pixel[2] = r;
    }
}

/* Function to convert an image to grayscale */
void grayscale(Image* img) {
    int x, y;
    unsigned char* pixel;
    for(y = 0; y < img->height; y++) {
        for(x = 0; x < img->width; x++) {
            pixel = getPixel(img, x, y);
            if(pixel != NULL) {
                unsigned char gray = (unsigned char)(0.299 * (float)pixel[2] + 0.587 * (float)pixel[1] + 0.114 * (float)pixel[0]);
                pixel[0] = gray;
                pixel[1] = gray;
                pixel[2] = gray;
            }
        }
    }
}

/* Main function */
int main() {
    // Load an image from file
    Image* img = loadImage("example.bmp");
    if(img == NULL) {
        printf("Failed to load image!\n");
        return 1;
    }
    // Convert the image to grayscale
    grayscale(img);
    // Save the modified image to file
    if(saveImage("modified.bmp", img) == 0) {
        printf("Failed to save image!\n");
        return 1;
    }
    free(img->data);
    free(img);
    printf("Image processing completed.\n");
    return 0;
}