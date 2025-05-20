//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Define constants for image dimensions
#define WIDTH 640
#define HEIGHT 480

// Define functions for image processing tasks
void flipImage(unsigned char *buffer, int width, int height);
void adjustBrightnessContrast(unsigned char *buffer, int width, int height, int bright, float contrast);

int main(){
    // Load image data into buffer
    unsigned char *imageBuffer = (unsigned char*)malloc(WIDTH*HEIGHT*sizeof(unsigned char));
    // ... code to load image data from file ...

    // Flip image horizontally
    flipImage(imageBuffer, WIDTH, HEIGHT);

    // Adjust brightness and contrast
    int brightness = 50; // Increase brightness by 50
    float contrast = 1.5f; // Increase contrast by 50%
    adjustBrightnessContrast(imageBuffer, WIDTH, HEIGHT, brightness, contrast);

    // Save processed image data to file
    // ... code to save image data to file ...

    // Free image buffer memory
    free(imageBuffer);

    return 0;
}

void flipImage(unsigned char *buffer, int width, int height){
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width/2; x++){
            int i = y*width + x;
            int j = y*width + (width-x-1);
            // Swap pixel values for horizontal flip
            unsigned char temp = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp;
        }
    }
}

void adjustBrightnessContrast(unsigned char *buffer, int width, int height, int bright, float contrast){
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            int i = y*width + x;
            // Adjust pixel value
            int newValue = (int)(factor * (buffer[i] - 128) + 128 + bright);
            if(newValue < 0){
                newValue = 0;
            }
            else if(newValue > 255){
                newValue = 255;
            }
            buffer[i] = (unsigned char)newValue;
        }
    }
}