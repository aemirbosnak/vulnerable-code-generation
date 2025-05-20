//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

// Function to flip an image horizontally
void horizontal_flip(unsigned char* image) {
    unsigned char temp;
    for(int y=0;y<HEIGHT;y++) {
        for(int x=0;x<WIDTH/2;x++) {
            temp = image[y*WIDTH+x];
            image[y*WIDTH+x] = image[y*WIDTH+(WIDTH-x-1)];
            image[y*WIDTH+(WIDTH-x-1)] = temp;
        }
    }
}

// Function to change the brightness of an image
void brightness(unsigned char* image, int level) {
    for(int i=0;i<WIDTH*HEIGHT;i++) {
        int pixel = (int)image[i] + level; // Add or subtract the level from each pixel value
        if(pixel > 255) {
            image[i] = 255; // Clamp the pixel value if it exceeds 255
        } else if(pixel < 0) {
            image[i] = 0; // Clamp the pixel value if it falls below 0
        } else {
            image[i] = (unsigned char)pixel;
        }
    }
}

// Function to change the contrast of an image
void contrast(unsigned char* image, float level) {
    float factor = (259.0f * (level + 255.0f)) / (255.0f * (259.0f - level));
    for(int i=0;i<WIDTH*HEIGHT;i++) {
        float pixel = ((float)image[i] - 128.0f) * factor + 128.0f; // Apply the contrast formula to each pixel value
        if(pixel > 255.0f) {
            image[i] = 255;
        } else if(pixel < 0.0f) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)pixel;
        }
    }
}

int main() {
    // Create a grayscale image with random pixel values
    unsigned char* image = (unsigned char*)malloc(WIDTH*HEIGHT*sizeof(unsigned char));
    for(int i=0;i<WIDTH*HEIGHT;i++) {
        image[i] = rand()%256;
    }
    
    // Flip the image horizontally
    horizontal_flip(image);
    
    // Change the brightness of the image by -50
    brightness(image, -50);
    
    // Change the contrast of the image by factor of 1.5
    contrast(image, 1.5f);

    // Output the resulting image to file
    FILE* fp = fopen("processed_image.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH*HEIGHT, fp);
    fclose(fp);

    free(image);
    return 0;
}