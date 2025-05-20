//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to flip an image horizontally
void flip_horizontally(int **image, int width, int height){
    int x, y, temp;
    for(x=0; x<width/2; x++){
        for(y=0; y<height; y++){
            temp = image[x][y];
            image[x][y] = image[width-1-x][y];
            image[width-1-x][y] = temp;
        }
    }
}

//function to change brightness and contrast of an image
void brightness_contrast(int **image, int width, int height, float brightness, float contrast){
    int x, y;
    for(x=0; x<width; x++){
        for(y=0; y<height; y++){
            int pixel = image[x][y];
            float pixel_float = pixel / 255.0;
            pixel_float = (pixel_float - 0.5) * contrast + 0.5 + brightness;
            if(pixel_float < 0){
                pixel_float = 0;
            }
            else if(pixel_float > 1){
                pixel_float = 1;
            }
            image[x][y] = (int)(pixel_float * 255);
        }
    }
}

int main(){
    int width = 5;
    int height = 5;
    int **image;
    image = (int **)malloc(height * sizeof(int *));
    for(int i=0; i<height; i++){
        image[i] = (int *)malloc(width * sizeof(int));
    }
    //initialize the image with random pixel values
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            image[x][y] = rand() % 256;
        }
    }
    //print the original image
    printf("Original Image:\n");
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            printf("%3d ", image[x][y]);
        }
        printf("\n");
    }
    //flip the image horizontally
    flip_horizontally(image, width, height);
    //print the flipped image
    printf("Flipped Image:\n");
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            printf("%3d ", image[x][y]);
        }
        printf("\n");
    }
    //apply brightness and contrast adjustment on the original image
    brightness_contrast(image, width, height, 0.2, 1.5);
    //print the adjusted image
    printf("Adjusted Image:\n");
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            printf("%3d ", image[x][y]);
        }
        printf("\n");
    }
    //free the memory allocated for the image
    for(int i=0; i<height; i++){
        free(image[i]);
    }
    free(image);
    return 0;
}