//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

//function to flip image horizontally
void flipHorizontal(int img_height, int img_width, int img_pixels[img_height][img_width]) {
    int temp;
    for(int i=0; i<img_height; i++) {
        for(int j=0; j<img_width/2; j++) {
            temp = img_pixels[i][j];
            img_pixels[i][j] = img_pixels[i][img_width-1-j];
            img_pixels[i][img_width-1-j] = temp;
        }
    }
}

//function to change brightness and contrast of image
void brightnessContrast(int img_height, int img_width, int img_pixels[img_height][img_width], int brightness, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0; i<img_height; i++) {
        for(int j=0; j<img_width; j++) {
            img_pixels[i][j] = (int)(factor * (img_pixels[i][j] - 128) + 128 + brightness);
            if(img_pixels[i][j] < 0)
                img_pixels[i][j] = 0;
            if(img_pixels[i][j] > 255)
                img_pixels[i][j] = 255;
        }
    }
}

int main() {
    int img_height, img_width;

    //read image file
    FILE *fptr;
    fptr = fopen("C:\\images\\input.txt", "r");
    if(fptr == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }
    fscanf(fptr, "%d %d", &img_height, &img_width);
    int img_pixels[img_height][img_width];
    for(int i=0; i<img_height; i++) {
        for(int j=0; j<img_width; j++) {
            fscanf(fptr, "%d", &img_pixels[i][j]);
        }
    }
    fclose(fptr);

    //flip image horizontally
    flipHorizontal(img_height, img_width, img_pixels);

    //change brightness and contrast
    int brightness = -50;
    float contrast = 50.0;
    brightnessContrast(img_height, img_width, img_pixels, brightness, contrast);

    //write image file
    fptr = fopen("C:\\images\\output.txt", "w");
    fprintf(fptr, "%d %d\n", img_height, img_width);
    for(int i=0; i<img_height; i++) {
        for(int j=0; j<img_width; j++) {
            fprintf(fptr, "%d ", img_pixels[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);

    return 0;
}