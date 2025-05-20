//FormAI DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

//define the image data structure
typedef struct Image {
    unsigned char red[IMG_HEIGHT][IMG_WIDTH];
    unsigned char green[IMG_HEIGHT][IMG_WIDTH];
    unsigned char blue[IMG_HEIGHT][IMG_WIDTH];
} Image;

//function to write image data to a file
void writeImageToFile(Image img, const char* filename) {
    FILE* f = fopen(filename, "wb");
    fprintf(f, "P6 %d %d 255\n", IMG_WIDTH, IMG_HEIGHT);
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            fputc(img.red[i][j], f);
            fputc(img.green[i][j], f);
            fputc(img.blue[i][j], f);
        }
    }
    fclose(f);
}

//function to add noise to the image
void addNoise(Image* img, float intensity) {
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            img->red[i][j] += (rand()%256)*intensity;
            img->green[i][j] += (rand()%256)*intensity;
            img->blue[i][j] += (rand()%256)*intensity;
        }
    }
}

//function to flip the image horizontally
void flipHorizontal(Image* img) {
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH/2; j++) {
            unsigned char tmp = img->red[i][j];
            img->red[i][j] = img->red[i][IMG_WIDTH-j-1];
            img->red[i][IMG_WIDTH-j-1] = tmp;
            tmp = img->green[i][j];
            img->green[i][j] = img->green[i][IMG_WIDTH-j-1];
            img->green[i][IMG_WIDTH-j-1] = tmp;
            tmp = img->blue[i][j];
            img->blue[i][j] = img->blue[i][IMG_WIDTH-j-1];
            img->blue[i][IMG_WIDTH-j-1] = tmp;
        }
    }
}

//function to rotate the image 90 degrees clockwise
void rotateClockwise(Image* img) {
    Image rotated = *img;
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            img->red[i][j] = rotated.red[IMG_WIDTH-j-1][i];
            img->green[i][j] = rotated.green[IMG_WIDTH-j-1][i];
            img->blue[i][j] = rotated.blue[IMG_WIDTH-j-1][i];
        }
    }
}

//function to apply an intensity map to the image
void applyIntensityMap(Image* img, float (*intensityMap)(float)) {
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            img->red[i][j] = (unsigned char)round(intensityMap((float)img->red[i][j]/255.0)*255);
            img->green[i][j] = (unsigned char)round(intensityMap((float)img->green[i][j]/255.0)*255);
            img->blue[i][j] = (unsigned char)round(intensityMap((float)img->blue[i][j]/255.0)*255);
        }
    }
}

//function to brighten the image
float brighten(float intensity) {
    return intensity + 0.2;
}

//function to darken the image
float darken(float intensity) {
    return intensity - 0.2;
}

int main() {
    //allocate memory for the image
    Image* img = malloc(sizeof(Image));
    
    //initialize the image with random values
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            img->red[i][j] = rand()%256;
            img->green[i][j] = rand()%256;
            img->blue[i][j] = rand()%256;
        }
    }
    
    //add noise
    addNoise(img, 0.1);
    
    //flip horizontally
    flipHorizontal(img);
    
    //rotate 90 degrees clockwise
    rotateClockwise(img);
    
    //apply intensity map to brighten the image
    applyIntensityMap(img, brighten);
    
    //write image to file
    writeImageToFile(*img, "output.ppm");
    
    //free memory
    free(img);
    
    return 0;
}