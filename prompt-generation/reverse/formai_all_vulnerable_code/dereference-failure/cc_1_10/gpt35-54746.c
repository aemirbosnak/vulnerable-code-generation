//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>

/* Function to flip an image */
void flipImage(int *image, int width, int height){
    int temp;
    for(int i=0; i<height/2; i++){
        for(int j=0; j<width; j++){
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + (height-i-1)*width + j);
            *(image + (height-i-1)*width + j) = temp;
        }
    }
}

/* Function to change brightness */
void changeBrightness(int *image, int width, int height, int brightness){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            *(image + i*width + j) += brightness;
            if(*(image + i*width + j) > 255){
                *(image + i*width + j) = 255;
            }
            else if(*(image + i*width + j) < 0){
                *(image + i*width + j) = 0;
            }
        }
    }
}

/* Function to change contrast */
void changeContrast(int *image, int width, int height, int contrast){
    double factor = (double)(259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            *(image + i*width + j) = (int)(factor * (*(image + i*width + j) - 128) + 128);
            if(*(image + i*width + j) > 255){
                *(image + i*width + j) = 255;
            }
            else if(*(image + i*width + j) < 0){
                *(image + i*width + j) = 0;
            }
        }
    }
}

int main(){
    int width = 4;
    int height = 3;
    int brightness = 50;
    int contrast = 50;

    /* Allocate memory for image */
    int *image = (int*)malloc(width*height*sizeof(int));

    /* Fill image with random values */
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            *(image + i*width + j) = rand()%256;
        }
    }

    printf("Original Image:\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d\t", *(image + i*width + j));
        }
        printf("\n");
    }

    /* Flip image */
    flipImage(image, width, height);
    printf("\nFlipped Image:\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d\t", *(image + i*width + j));
        }
        printf("\n");
    }

    /* Change brightness */
    changeBrightness(image, width, height, brightness);
    printf("\nBrightness changed image:\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d\t", *(image + i*width + j));
        }
        printf("\n");
    }

    /* Change contrast */
    changeContrast(image, width, height, contrast);
    printf("\nContrast changed image:\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d\t", *(image + i*width + j));
        }
        printf("\n");
    }

    /* Free allocated memory */
    free(image);

    return 0;
}