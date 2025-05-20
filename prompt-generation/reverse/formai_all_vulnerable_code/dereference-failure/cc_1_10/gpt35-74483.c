//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char pixel; // pixel data type
typedef struct{
    int width; // image width
    int height; // image height
    pixel *data; // pixel array (row-major order)
}Image;

/*
 * Function to flip the image vertically
 */
void flipVertical(Image *img){
    int halfHeight = img->height / 2;
    int rowSize = img->width * sizeof(pixel);
    pixel *tmpRow = (pixel*)malloc(rowSize); // allocate temporary row buffer
    for(int i=0; i<halfHeight; i++){
        // swap rows i and height-i-1
        int srcRow = i * img->width;
        int dstRow = (img->height - i - 1) * img->width;
        memcpy(tmpRow, img->data + srcRow, rowSize);
        memcpy(img->data + srcRow, img->data + dstRow, rowSize);
        memcpy(img->data + dstRow, tmpRow, rowSize);
    }
    free(tmpRow);
}

/*
 * Function to adjust the brightness of the image
 * The adjustment value should be between -255 and 255
 */
void adjustBrightness(Image *img, int value){
    for(int i=0; i<img->width*img->height; i++){
        int newPixel = (int)img->data[i] + value;
        if(newPixel < 0){
            img->data[i] = 0;
        } else if(newPixel > 255){
            img->data[i] = 255;
        } else {
            img->data[i] = (pixel)newPixel;
        }
    }
}

/*
 * Function to adjust the contrast of the image
 * The adjustment value should be between -100 and 100
 */
void adjustContrast(Image *img, int value){
    double factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for(int i=0; i<img->width*img->height; i++){
        int newPixel = (int)(factor * (img->data[i] - 128) + 128);
        if(newPixel < 0){
            img->data[i] = 0;
        } else if(newPixel > 255){
            img->data[i] = 255;
        } else {
            img->data[i] = (pixel)newPixel;
        }
    }
}

/*
 * Main function
 */
int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // read image file
    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL){
        printf("Failed to open image file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    Image img;
    fread(&img.width, sizeof(int), 1, fp);
    fread(&img.height, sizeof(int), 1, fp);
    img.data = (pixel*)malloc(img.width * img.height * sizeof(pixel));
    fread(img.data, sizeof(pixel), img.width * img.height, fp);
    fclose(fp);
    // perform image processing
    flipVertical(&img);
    adjustBrightness(&img, 50);
    adjustContrast(&img, 25);
    // write processed image file
    char *outFileName = strdup(argv[1]);
    char *dotPtr = strrchr(outFileName, '.');
    if(dotPtr != NULL){
        *dotPtr = '\0';
    }
    strcat(outFileName, "_out.bin");
    fp = fopen(outFileName, "wb");
    fwrite(&img.width, sizeof(int), 1, fp);
    fwrite(&img.height, sizeof(int), 1, fp);
    fwrite(img.data, sizeof(pixel), img.width * img.height, fp);
    fclose(fp);
    free(outFileName);
    free(img.data);
    return EXIT_SUCCESS;
}