//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char pixel;

//Function prototypes
pixel** readImage(char* filename, int* rows, int* cols);
void saveImage(char* filename, pixel** image, int rows, int cols);
void flipH(pixel** image, int rows, int cols);
void flipV(pixel** image, int rows, int cols);
void adjustBrightness(pixel** image, int rows, int cols, int value);
void adjustContrast(pixel** image, int rows, int cols, int contrast);

int main(){
    int rows, cols;
    pixel** image = readImage("image.raw", &rows, &cols);
    
    flipH(image, rows, cols);
    saveImage("flippedH.raw", image, rows, cols);
    
    flipV(image, rows, cols);
    saveImage("flippedV.raw", image, rows, cols);
    
    adjustBrightness(image, rows, cols, 50);
    saveImage("brightened.raw", image, rows, cols);
    
    adjustContrast(image, rows, cols, 2);
    saveImage("highContrast.raw", image, rows, cols);
    
    return 0;
}

//Function to read image from a raw file
pixel** readImage(char* filename, int* rows, int* cols){
    FILE* file;
    if((file = fopen(filename, "rb")) == NULL){
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    
    //Read the dimensions of the image
    fscanf(file, "%d %d\n", rows, cols);
    
    //Allocate memory for the image array
    pixel** image = (pixel**)malloc((*rows)*sizeof(pixel*));
    for(int i = 0; i < (*rows); i++){
        image[i] = (pixel*)malloc((*cols)*sizeof(pixel));
    }
    
    //Read the pixel values from the file
    for(int i = 0; i < (*rows); i++){
        for(int j = 0; j < (*cols); j++){
            fread(&image[i][j], sizeof(pixel), 1, file);
        }
    }
    
    fclose(file);
    return image;
}

//Function to save the image to a raw file
void saveImage(char* filename, pixel** image, int rows, int cols){
    FILE* file;
    if((file = fopen(filename, "wb")) == NULL){
        printf("Error: could not create file %s\n", filename);
        exit(1);
    }
    
    //Write the dimensions of the image to the file
    fprintf(file, "%d %d\n", rows, cols);
    
    //Write the pixel values to the file
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fwrite(&image[i][j], sizeof(pixel), 1, file);
        }
    }
    
    fclose(file);
}

//Function to flip the image horizontally
void flipH(pixel** image, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols/2; j++){
            pixel temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

//Function to flip the image vertically
void flipV(pixel** image, int rows, int cols){
    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows/2; i++){
            pixel temp = image[i][j];
            image[i][j] = image[rows-i-1][j];
            image[rows-i-1][j] = temp;
        }
    }
}

//Function to adjust the brightness of the image
void adjustBrightness(pixel** image, int rows, int cols, int value){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int result = (int)image[i][j] + value;
            if(result > 255) result = 255;
            if(result < 0) result = 0;
            image[i][j] = (pixel)result;
        }
    }
}

//Function to adjust the contrast of the image
void adjustContrast(pixel** image, int rows, int cols, int contrast){
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int result = (int)(factor * (image[i][j] - 128.0) + 128.0);
            if(result > 255) result = 255;
            if(result < 0) result = 0;
            image[i][j] = (pixel)result;
        }
    }
}