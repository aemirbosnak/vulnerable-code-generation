//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>

//Function to add watermark to given image
void addWatermark(unsigned char* image, unsigned char* watermark, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight){

    int startX = (imageWidth/2)-(watermarkWidth/2);
    int startY = (imageHeight/2)-(watermarkHeight/2);

    for(int i=0; i<watermarkHeight; i++){
        for(int j=0; j<watermarkWidth; j++){
            int imageIndex = ((startY+i)*imageWidth)+(startX+j);
            int watermarkIndex = (i*watermarkWidth)+j;
            image[imageIndex] = image[imageIndex] | watermark[watermarkIndex];
        }
    }
}

//Function to extract and print watermark from given image
void extractWatermark(unsigned char* image, int imageWidth, int imageHeight, int watermarkWidth, int watermarkHeight){

    int startX = (imageWidth/2)-(watermarkWidth/2);
    int startY = (imageHeight/2)-(watermarkHeight/2);

    for(int i=0; i<watermarkHeight; i++){
        for(int j=0; j<watermarkWidth; j++){
            int imageIndex = ((startY+i)*imageWidth)+(startX+j);
            unsigned char bit = image[imageIndex] & 1;
            printf("%d ", bit);
        }
        printf("\n");
    }
}

//Main function to test the watermarking process
int main(){

    //Assuming we have a 4096x2160 image and a 256x256 watermark
    int imageWidth = 4096;
    int imageHeight = 2160;
    int watermarkWidth = 256;
    int watermarkHeight = 256;

    //Allocate memory for image and watermark arrays
    unsigned char* image = (unsigned char*)malloc(imageWidth*imageHeight*sizeof(unsigned char));
    unsigned char* watermark = (unsigned char*)malloc(watermarkWidth*watermarkHeight*sizeof(unsigned char));

    //Fill image and watermark arrays with random bits (0 or 1)
    for(int i=0; i<imageHeight; i++){
        for(int j=0; j<imageWidth; j++){
            int index = (i*imageWidth)+j;
            image[index] = rand()%2;
        }
    }
    for(int i=0; i<watermarkHeight; i++){
        for(int j=0; j<watermarkWidth; j++){
            int index = (i*watermarkWidth)+j;
            watermark[index] = rand()%2;
        }
    }

    //Print original image and watermark (for testing purposes)
    printf("Original Image:\n");
    for(int i=0; i<imageHeight; i++){
        for(int j=0; j<imageWidth; j++){
            int index = (i*imageWidth)+j;
            printf("%d ", image[index]);
        }
        printf("\n");
    }
    printf("\nOriginal Watermark:\n");
    for(int i=0; i<watermarkHeight; i++){
        for(int j=0; j<watermarkWidth; j++){
            int index = (i*watermarkWidth)+j;
            printf("%d ", watermark[index]);
        }
        printf("\n");
    }

    //Add watermark to image
    addWatermark(image, watermark, imageWidth, imageHeight, watermarkWidth, watermarkHeight);

    //Print watermarked image (for testing purposes)
    printf("\nWatermarked Image:\n");
    for(int i=0; i<imageHeight; i++){
        for(int j=0; j<imageWidth; j++){
            int index = (i*imageWidth)+j;
            printf("%d ", image[index]);
        }
        printf("\n");
    }

    //Extract and print watermark from watermarked image
    printf("\nExtracted Watermark:\n");
    extractWatermark(image, imageWidth, imageHeight, watermarkWidth, watermarkHeight);

    //Free memory
    free(image);
    free(watermark);

    return 0;
}