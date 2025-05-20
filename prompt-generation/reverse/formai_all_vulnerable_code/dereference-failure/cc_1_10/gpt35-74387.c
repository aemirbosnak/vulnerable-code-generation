//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to flip the image
void flipImage(int *image, int height, int width) {

    int *tempImage = malloc(height * width * sizeof(int));

    // Creating a flipped image using a temporary array
    for(int i=0;i<height;i++){
       for(int j=0;j<width;j++){
            tempImage[i*width + (width-j-1)] = image[i*width + j];
       }
    }

    // Copying the flipped image into the original array
    for(int i=0;i<height*width;i++){
        image[i] = tempImage[i];
    }

    free(tempImage); // Freeing up the memory after the operation

}

// Function to change the brightness of the image
void changeBrightness(int *image, int height, int width, int brightness) {

    // Changing the brightness of each pixel by the specified value
    for(int i=0;i<height*width;i++){
        if(image[i]+brightness < 0){
            image[i] = 0;
        } else if(image[i]+brightness > 255){
            image[i] = 255;
        } else {
            image[i] += brightness;
        }
    }

}

// Function to change the contrast of the image
void changeContrast(int *image, int height, int width, float contrast) {

    // Changing the contrast of each pixel by the specified value
    for(int i=0;i<height*width;i++){
        float tempPixel = contrast*(image[i] - 128) + 128;
        if(tempPixel < 0){
            image[i] = 0;
        } else if(tempPixel > 255){
            image[i] = 255;
        } else {
            image[i] = (int)round(tempPixel);
        }
    }

}

int main(){

    // Initializing the image
    int height = 5;
    int width = 5;
    int image[25] = {128, 64, 32, 96, 192, 
                     64, 32, 96, 192, 128, 
                     32, 96, 192, 128, 64, 
                     96, 192, 128, 64, 32, 
                     192, 128, 64, 32, 96};

    printf("\nOriginal image:\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    // Flipping the image horizontally
    flipImage(image, height, width);
    printf("\nImage after flipping horizontally:\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    // Changing the brightness of the image by 20
    changeBrightness(image, height, width, 20);
    printf("\nImage after increasing brightness by 20:\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    // Changing the contrast of the image by a factor of 1.5
    changeContrast(image, height, width, 1.5);
    printf("\nImage after increasing contrast by a factor of 1.5:\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    return 0;
}