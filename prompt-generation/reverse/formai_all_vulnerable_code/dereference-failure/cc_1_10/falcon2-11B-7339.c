//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include<stdio.h>
#include<stdlib.h>

void flipImage(int** image, int rows, int cols){
    // create a copy of the image for flipping
    int** flippedImage = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        flippedImage[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // flip each row
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            flippedImage[i][j] = image[rows-1-i][j]; // flip row
        }
    }
    
    // free memory
    for(int i=0; i<rows; i++){
        free(image[i]);
    }
    free(image);
    image = flippedImage;
}

int main(){
    // create a 2x2 image
    int** image = (int**)malloc(2 * sizeof(int*));
    for(int i=0; i<2; i++){
        image[i] = (int*)malloc(2 * sizeof(int));
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            image[i][j] = i*2 + j; // fill the image
        }
    }
    
    // flip the image
    flipImage(image, 2, 2);
    
    // print the flipped image
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    // free memory
    for(int i=0; i<2; i++){
        free(image[i]);
    }
    free(image);
    return 0;
}