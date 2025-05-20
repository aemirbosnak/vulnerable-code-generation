//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80 //max width for the output ascii art
#define MAX_HEIGHT 80 //max height for the output ascii art

char* img_ascii(int img[MAX_HEIGHT][MAX_WIDTH], int width, int height){
    char ascii_map[] = " .:-=+*#%@";
    int color_depth = strlen(ascii_map); //number of possible ascii characters
        
    char* ascii_buffer = (char*) malloc(MAX_HEIGHT*MAX_WIDTH); //allocate memory for the ascii output buffer
    
    //convert each pixel of the image to an ascii character
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int pixel = img[y][x]; //get the pixel value
            
            int char_idx = ((float) pixel / (255.0 / (color_depth-1))); //convert pixel value to ascii index in the ascii_map string
            
            ascii_buffer[y*width+x] = ascii_map[char_idx]; //assign the corresponding ascii character to the pixel
        }
    }
    
    return ascii_buffer; //return the ascii output buffer
}

int main(){
    //test image data
    int img_test[MAX_HEIGHT][MAX_WIDTH] = {
        {100, 50, 75,  0, 200},
        { 20, 10, 70, 30,  50},
        {  5,  0, 30, 80, 255},
        { 70, 40, 50, 20, 190},
        {200, 90, 10, 70, 180},
    };
    
    int width = 5; //width of the image
    int height = 5; //height of the image
    
    char* ascii_art = img_ascii(img_test, width, height); //convert the image to ascii art
    
    printf("ASCII Art:\n");
    
    //print the ascii art line by line
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            printf("%c", ascii_art[y*width+x]);
        }
        printf("\n");
    }
    
    free(ascii_art); //free the allocated memory
    
    return 0;
}