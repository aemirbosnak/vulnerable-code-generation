//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to flip image horizontally
void horizontal_flip(int height, int width, int image[height][width]) {
    int temp;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
}

// Function to adjust brightness of image
void adjust_brightness(int height, int width, int image[height][width], int brightness) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] += brightness;
            if(image[i][j] > 255) {
                image[i][j] = 255;
            } else if(image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to adjust contrast of image
void adjust_contrast(int height, int width, int image[height][width], float contrast) {
    contrast = (100.0 + contrast) / 100.0;
    contrast *= contrast;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            float value = ((image[i][j] / 255.0 - 0.5) * contrast + 0.5) * 255.0;
            if(value > 255) {
                image[i][j] = 255;
            } else if(value < 0) {
                image[i][j] = 0;
            } else {
                image[i][j] = (int)value;
            }
        }
    }
}

int main() {
    int height, width;
    printf("Enter height and width of image: ");
    scanf("%d %d", &height, &width);

    int image[height][width];
    printf("Enter image pixel values:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("1. Horizontal Flip\n2. Adjust Brightness\n3. Adjust Contrast\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            horizontal_flip(height, width, image);
            printf("Image flipped horizontally.\n");
            break;
        }
        case 2: {
            int brightness;
            printf("Enter brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            adjust_brightness(height, width, image, brightness);
            printf("Brightness adjusted.\n");
            break;
        }
        case 3: {
            float contrast;
            printf("Enter contrast value (-100 to 100): ");
            scanf("%f", &contrast);
            adjust_contrast(height, width, image, contrast);
            printf("Contrast adjusted.\n");
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }

    printf("Updated Image:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}