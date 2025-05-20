//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel{
    int r;
    int g;
    int b;
} Pixel;

typedef struct image{
    int height;
    int width;
    Pixel* pixels;
} Image;

// Function to flip an image horizontally
Image flip_image(Image img){
    Image flipped_img = img;

    for(int i = 0; i < img.height; i++){
        for(int j = 0; j < img.width/2; j++){
            Pixel temp = img.pixels[i*img.width + j];
            flipped_img.pixels[i*img.width + j] = img.pixels[i*img.width + img.width - j - 1];
            flipped_img.pixels[i*img.width + img.width - j - 1] = temp;
        }
    }

    return flipped_img;
}

// Function to adjust brightness of an image
Image adjust_brightness(Image img, int value){
    for(int i = 0; i < img.height; i++){
        for(int j = 0; j < img.width; j++){
            img.pixels[i*img.width + j].r += value;
            img.pixels[i*img.width + j].g += value;
            img.pixels[i*img.width + j].b += value;

            // Keep pixel values in range [0, 255]
            if(img.pixels[i*img.width + j].r > 255) img.pixels[i*img.width + j].r = 255;
            if(img.pixels[i*img.width + j].g > 255) img.pixels[i*img.width + j].g = 255;
            if(img.pixels[i*img.width + j].b > 255) img.pixels[i*img.width + j].b = 255;

            if(img.pixels[i*img.width + j].r < 0) img.pixels[i*img.width + j].r = 0;
            if(img.pixels[i*img.width + j].g < 0) img.pixels[i*img.width + j].g = 0;
            if(img.pixels[i*img.width + j].b < 0) img.pixels[i*img.width + j].b = 0;
        }
    }

    return img;
}

// Function to adjust contrast of an image
Image adjust_contrast(Image img, float value){
    for(int i = 0; i < img.height; i++){
        for(int j = 0; j < img.width; j++){
            img.pixels[i*img.width + j].r = (img.pixels[i*img.width + j].r - 128) * value + 128;
            img.pixels[i*img.width + j].g = (img.pixels[i*img.width + j].g - 128) * value + 128;
            img.pixels[i*img.width + j].b = (img.pixels[i*img.width + j].b - 128) * value + 128;

            // Keep pixel values in range [0, 255]
            if(img.pixels[i*img.width + j].r > 255) img.pixels[i*img.width + j].r = 255;
            if(img.pixels[i*img.width + j].g > 255) img.pixels[i*img.width + j].g = 255;
            if(img.pixels[i*img.width + j].b > 255) img.pixels[i*img.width + j].b = 255;

            if(img.pixels[i*img.width + j].r < 0) img.pixels[i*img.width + j].r = 0;
            if(img.pixels[i*img.width + j].g < 0) img.pixels[i*img.width + j].g = 0;
            if(img.pixels[i*img.width + j].b < 0) img.pixels[i*img.width + j].b = 0;
        }
    }

    return img;
}

int main(){
    // Create a test image
    Image test_img;
    test_img.height = 4;
    test_img.width = 4;
    test_img.pixels = (Pixel*) malloc(sizeof(Pixel) * test_img.height * test_img.width);

    test_img.pixels[0].r = 100;
    test_img.pixels[0].g = 150;
    test_img.pixels[0].b = 200;

    test_img.pixels[1].r = 150;
    test_img.pixels[1].g = 200;
    test_img.pixels[1].b = 100;

    test_img.pixels[2].r = 200;
    test_img.pixels[2].g = 100;
    test_img.pixels[2].b = 150;

    test_img.pixels[3].r = 50;
    test_img.pixels[3].g = 50;
    test_img.pixels[3].b = 50;

    test_img.pixels[4].r = 200;
    test_img.pixels[4].g = 150;
    test_img.pixels[4].b = 100;

    test_img.pixels[5].r = 100;
    test_img.pixels[5].g = 100;
    test_img.pixels[5].b = 200;

    test_img.pixels[6].r = 50;
    test_img.pixels[6].g = 200;
    test_img.pixels[6].b = 150;

    test_img.pixels[7].r = 150;
    test_img.pixels[7].g = 50;
    test_img.pixels[7].b = 100;

    test_img.pixels[8].r = 100;
    test_img.pixels[8].g = 200;
    test_img.pixels[8].b = 150;

    test_img.pixels[9].r = 150;
    test_img.pixels[9].g = 50;
    test_img.pixels[9].b = 200;

    test_img.pixels[10].r = 50;
    test_img.pixels[10].g = 150;
    test_img.pixels[10].b = 100;

    test_img.pixels[11].r = 200;
    test_img.pixels[11].g = 100;
    test_img.pixels[11].b = 50;

    test_img.pixels[12].r = 50;
    test_img.pixels[12].g = 100;
    test_img.pixels[12].b = 150;

    test_img.pixels[13].r = 150;
    test_img.pixels[13].g = 200;
    test_img.pixels[13].b = 50;

    test_img.pixels[14].r = 200;
    test_img.pixels[14].g = 50;
    test_img.pixels[14].b = 150;

    test_img.pixels[15].r = 100;
    test_img.pixels[15].g = 150;
    test_img.pixels[15].b = 50;

    // Flip the test image horizontally
    Image flipped_img = flip_image(test_img);

    // Adjust the brightness and contrast of the test image
    Image bright_img = adjust_brightness(test_img, 50);
    Image contrast_img = adjust_contrast(test_img, 1.5);

    // Print the original image
    printf("Original Image:\n");
    for(int i = 0; i < test_img.height; i++){
        for(int j = 0; j < test_img.width; j++){
            printf("(%d, %d, %d)\t", test_img.pixels[i*test_img.width + j].r, test_img.pixels[i*test_img.width + j].g, test_img.pixels[i*test_img.width + j].b);
        }
        printf("\n");
    }
    printf("\n");

    // Print the flipped image
    printf("Flipped Image:\n");
    for(int i = 0; i < flipped_img.height; i++){
        for(int j = 0; j < flipped_img.width; j++){
            printf("(%d, %d, %d)\t", flipped_img.pixels[i*flipped_img.width + j].r, flipped_img.pixels[i*flipped_img.width + j].g, flipped_img.pixels[i*flipped_img.width + j].b);
        }
        printf("\n");
    }
    printf("\n");

    // Print the brightness adjusted image
    printf("Brightness Adjusted Image:\n");
    for(int i = 0; i < bright_img.height; i++){
        for(int j = 0; j < bright_img.width; j++){
            printf("(%d, %d, %d)\t", bright_img.pixels[i*bright_img.width + j].r, bright_img.pixels[i*bright_img.width + j].g, bright_img.pixels[i*bright_img.width + j].b);
        }
        printf("\n");
    }
    printf("\n");

    // Print the contrast adjusted image
    printf("Contrast Adjusted Image:\n");
    for(int i = 0; i < contrast_img.height; i++){
        for(int j = 0; j < contrast_img.width; j++){
            printf("(%d, %d, %d)\t", contrast_img.pixels[i*contrast_img.width + j].r, contrast_img.pixels[i*contrast_img.width + j].g, contrast_img.pixels[i*contrast_img.width + j].b);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}