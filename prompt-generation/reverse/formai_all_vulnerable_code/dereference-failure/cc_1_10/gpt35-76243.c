//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

//function to flip the image
void flip_image(int rows, int columns, int image[rows][columns]){
    for(int i=0; i<rows/2; i++){
        for(int j=0; j<columns; j++){
            int temp = image[i][j];
            image[i][j] = image[rows-i-1][j];
            image[rows-i-1][j] = temp;
        }
    }
}

//function to change the brightness of the image
void change_brightness(int rows, int columns, int image[rows][columns], int brightness){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            int new_value = image[i][j] + brightness;
            if(new_value > 255){
                image[i][j] = 255;
            } else if (new_value < 0){
                image[i][j] = 0;
            } else {
                image[i][j] = new_value;
            }
        }
    }
}

//function to change the contrast of the image
void change_contrast(int rows, int columns, int image[rows][columns], float contrast){
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            int new_value = factor * (image[i][j] - 128) + 128;
            if(new_value > 255){
                image[i][j] = 255;
            } else if (new_value < 0){
                image[i][j] = 0;
            } else {
                image[i][j] = new_value;
            }
        }
    }
}

int main(){
    //example image
    int image[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};

    //printing the original image
    printf("Original Image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }

    //flipping the image
    flip_image(3, 3, image);

    //printing the flipped image
    printf("Flipped Image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }

    //changing the brightness of the image by adding 40
    change_brightness(3, 3, image, 40);

    //printing the image after changing brightness
    printf("Brightness changed Image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }

    //changing the contrast of the image by multiplying with a factor of 1.5
    change_contrast(3, 3, image, 1.5);

    //printing the image after changing contrast
    printf("Contrast changed Image:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}