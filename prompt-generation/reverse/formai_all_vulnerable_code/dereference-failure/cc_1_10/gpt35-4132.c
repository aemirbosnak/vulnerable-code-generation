//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL 255
#define MIN_PIXEL 0

typedef struct Pixel{
    int red;
    int green;
    int blue;
}Pixel;

Pixel** readImage(char* filename, int* width, int* height, int* maxPixelValue){
    FILE* fp=fopen(filename, "r");
    if(fp==NULL){
        printf("Unable to open the file.\n");
        return NULL;
    }
    char header[3];
    fgets(header, sizeof(header), fp);
    if(strcmp(header, "P3\n")!=0){
        printf("Invalid image format.\n");
        return NULL;
    }
    fscanf(fp, "%d %d %d\n", width, height, maxPixelValue);
    Pixel** image=(Pixel**)malloc((*height)*sizeof(Pixel*));
    for(int i=0; i<(*height); i++){
        image[i]=(Pixel*)malloc((*width)*sizeof(Pixel));
        for(int j=0; j<(*width); j++){
            fscanf(fp, "%d %d %d\n", &image[i][j].red, &image[i][j].green, &image[i][j].blue);
        }
    }
    fclose(fp);
    return image;
}

Pixel** flipImage(Pixel** image, int width, int height){
    Pixel** flippedImage=(Pixel**)malloc(height*sizeof(Pixel*));
    for(int i=0; i<height; i++){
        flippedImage[i]=(Pixel*)malloc(width*sizeof(Pixel));
        for(int j=0; j<width; j++){
            flippedImage[i][j].red=image[height-i-1][j].red;
            flippedImage[i][j].green=image[height-i-1][j].green;
            flippedImage[i][j].blue=image[height-i-1][j].blue;
        }
    }
    return flippedImage;
}

Pixel** adjustBrightnessContrast(Pixel** image, int width, int height, float brightness, float contrast){
    Pixel** processedImage=(Pixel**)malloc(height*sizeof(Pixel*));
    float factor=((259*(contrast+255))/255)/((259*(255-contrast))/255);
    for(int i=0; i<height; i++){
        processedImage[i]=(Pixel*)malloc(width*sizeof(Pixel));
        for(int j=0; j<width; j++){
            processedImage[i][j].red=fmin(fmax((int)(factor*(image[i][j].red-128)+128+brightness), MIN_PIXEL), MAX_PIXEL);
            processedImage[i][j].green=fmin(fmax((int)(factor*(image[i][j].green-128)+128+brightness), MIN_PIXEL), MAX_PIXEL);
            processedImage[i][j].blue=fmin(fmax((int)(factor*(image[i][j].blue-128)+128+brightness), MIN_PIXEL), MAX_PIXEL);
        }
    }
    return processedImage;
}

void writeImage(char* filename, Pixel** image, int width, int height, int maxPixelValue){
    FILE* fp=fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n%d\n", width, height, maxPixelValue);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fprintf(fp, "%d %d %d ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main(){
    int width, height, maxPixelValue;
    Pixel** image=readImage("input.ppm", &width, &height, &maxPixelValue);
    if(image==NULL){
        return 1;
    }
    Pixel** flippedImage=flipImage(image, width, height);
    writeImage("flipped.ppm", flippedImage, width, height, maxPixelValue);
    Pixel** processedImage=adjustBrightnessContrast(image, width, height, 50, 50);
    writeImage("processed.ppm", processedImage, width, height, maxPixelValue);
    for(int i=0; i<height; i++){
        free(image[i]);
        free(flippedImage[i]);
        free(processedImage[i]);
    }
    free(image);
    free(flippedImage);
    free(processedImage);
    return 0;
}