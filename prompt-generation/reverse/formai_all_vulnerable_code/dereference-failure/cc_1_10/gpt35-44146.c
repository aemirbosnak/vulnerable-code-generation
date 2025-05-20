//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

//Function to flip an image
void flipImage(int width, int height, unsigned char* imagePixels){
    unsigned char temp;
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width/2; j++){
            temp = imagePixels[i*width*3 + j*3];
            imagePixels[i*width*3 + j*3] = imagePixels[i*width*3 + (width-j-1)*3];
            imagePixels[i*width*3 + (width-j-1)*3] = temp;
            
            temp = imagePixels[i*width*3 + j*3 + 1];
            imagePixels[i*width*3 + j*3 + 1] = imagePixels[i*width*3 + (width-j-1)*3 + 1];
            imagePixels[i*width*3 + (width-j-1)*3 + 1] = temp;
            
            temp = imagePixels[i*width*3 + j*3 + 2];
            imagePixels[i*width*3 + j*3 + 2] = imagePixels[i*width*3 + (width-j-1)*3 + 2];
            imagePixels[i*width*3 + (width-j-1)*3 + 2] = temp;
        }
    }
}

//Function to adjust brightness and contrast of an image
void adjustImage(int width, int height, unsigned char* imagePixels, int brightness, float contrast){
    int i, j;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            int index = i*width*3 + j*3;
            int red = imagePixels[index];
            int green = imagePixels[index + 1];
            int blue = imagePixels[index + 2];
            
            //Adjust brightness
            red = red + brightness;
            green = green + brightness;
            blue = blue + brightness;
            
            //Adjust contrast
            red = factor * (red - 128) + 128;
            green = factor * (green - 128) + 128;
            blue = factor * (blue - 128) + 128;
            
            //Clamp pixel values to the range 0-255
            red = red > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : red < MIN_PIXEL_VALUE ? MIN_PIXEL_VALUE : red;
            green = green > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : green < MIN_PIXEL_VALUE ? MIN_PIXEL_VALUE : green;
            blue = blue > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : blue < MIN_PIXEL_VALUE ? MIN_PIXEL_VALUE : blue;
            
            imagePixels[index] = red;
            imagePixels[index + 1] = green;
            imagePixels[index + 2] = blue;
        }
    }
}

int main(){
    //Read image data from file
    FILE* file;
    char* filename = "myimage.rgb";
    int width = 640;
    int height = 480;
    unsigned char* imagePixels = (unsigned char*) malloc(width*height*3);
    file = fopen(filename, "rb");  
    fread(imagePixels, sizeof(unsigned char), width*height*3, file);
    fclose(file);
    
    //Flip image horizontally
    flipImage(width, height, imagePixels);
    
    //Adjust image brightness and contrast
    int brightness = 50;
    float contrast = 50.0;
    adjustImage(width, height, imagePixels, brightness, contrast);
    
    //Write processed image data to file
    char* newFilename = "mynewimage.rgb";
    file = fopen(newFilename, "wb");  
    fwrite(imagePixels, sizeof(unsigned char), width*height*3, file);
    fclose(file);
    
    free(imagePixels);
    
    return 0;
}