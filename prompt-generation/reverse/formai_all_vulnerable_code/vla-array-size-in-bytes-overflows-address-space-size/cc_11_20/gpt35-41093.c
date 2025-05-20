//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>

int main(){

    int height, width, brightness, contrast, i, j, k;
    char flip;

    printf("Enter the height and width of the image: ");
    scanf("%d %d", &height, &width);

    int pixels[height][width];

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            printf("Enter pixel value for (%d, %d): ", i+1, j+1);
            scanf("%d", &pixels[i][j]);
        }
    }

    printf("\nEnter the brightness level (positive or negative integer): ");
    scanf("%d", &brightness);

    printf("\nEnter the contrast level (positive integer): ");
    scanf("%d", &contrast);

    printf("\nDo you want to flip the image? (y/n): ");
    scanf(" %c", &flip);

    // flip image if required
    if(flip == 'y'){
        int temp[height][width];
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                temp[i][j] = pixels[i][width-1-j];
            }
        }
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                pixels[i][j] = temp[i][j];
            }
        }
    }

    // adjust brightness
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixels[i][j] += brightness;
            if(pixels[i][j] < 0){
                pixels[i][j] = 0;
            }
        }
    }

    // adjust contrast
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            pixels[i][j] = pixels[i][j] * contrast;
        }
    }

    // print the new image
    printf("\nNew Image:\n");
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}