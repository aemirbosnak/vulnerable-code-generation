//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>

/* Function to flip an image horizontally */
void flipHorizontal(int width, int height, int image[width][height]){ 
    int temp;
    for(int i=0; i<height; i++){
        for(int j=0; j<width/2; j++){
            temp = image[j][i];
            image[j][i] = image[width-j-1][i];
            image[width-j-1][i] = temp;
        }
    }
}

/* Function to change brightness of an image */
void changeBrightness(int width, int height, int image[width][height], int brightness){ 
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            image[j][i] += brightness; // Add brightness value to each pixel
            if(image[j][i] > 255){ // Make sure pixel value doesn't exceed 255 (maximum value for a pixel)
                image[j][i] = 255;
            }
            else if(image[j][i] < 0){ // Make sure pixel value doesn't go below 0 (minimum value for a pixel)
                image[j][i] = 0;
            }
        }
    }
}

/* Function to change contrast of an image */
void changeContrast(int width, int height, int image[width][height], float contrast){ 
    int pixel;
    contrast = (100.0 + contrast) / 100.0;
    contrast *= contrast;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            pixel = image[j][i];
            pixel /= 255.0;
            pixel -= 0.5;
            pixel *= contrast;
            pixel += 0.5;
            pixel *= 255.0;
            if(pixel > 255){ // Make sure pixel value doesn't exceed 255 (maximum value for a pixel)
                pixel = 255;
            }
            else if(pixel < 0){ // Make sure pixel value doesn't go below 0 (minimum value for a pixel)
                pixel = 0;
            }
            image[j][i] = pixel;
        }
    }
}

/* Sample usage of the functions */
int main(){
    int width = 4;
    int height = 3;
    int image[4][3] = {{10, 30, 50, 70}, {20, 40, 60, 80}, {30, 50, 70, 90}};
    printf("Original Image\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    flipHorizontal(width, height, image);
    printf("Flipped Image\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    changeBrightness(width, height, image, -20);
    printf("Image with decreased brightness\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    changeContrast(width, height, image, 30);
    printf("Image with increased contrast\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[j][i]);
        }
        printf("\n");
    }

    return 0;
}