//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

//function to convert RGB values to greyscale
int rgb_to_greyscale(int r, int g, int b){
    int grey = round(0.21*r + 0.72*g + 0.07*b);
    return grey;
}

//function to map greyscale value to ascii character
char map_to_ascii(int grey){
    char ascii_char;
    char ascii_chars[] = {' ', '.', ',', ':', '-', '=', '+', '*', '#', '%', '@'};
    int intervals[] = {0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255};
    
    for(int i = 0; i < 11; i++){
        if(grey >= intervals[i] && grey <= intervals[i+1]){
            ascii_char = ascii_chars[i];
            break;
        }
    }
    
    return ascii_char;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Please provide the filename of the image to convert\n");
        return 1;
    }
    
    char *filename = argv[1];
    FILE *fptr = fopen(filename, "rb");
    
    if(fptr == NULL){
        printf("Error opening file\n");
        return 1;
    }
    
    //get dimensions of the image
    fseek(fptr, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, fptr);
    fread(&height, 4, 1, fptr);
    
    //get offset to pixel data
    fseek(fptr, 10, SEEK_SET);
    int offset;
    fread(&offset, 4, 1, fptr);
    
    //move to pixel data
    fseek(fptr, offset, SEEK_SET);
    
    //allocate memory for pixel data
    int *pixels = (int*) malloc(width*height*sizeof(int));
    
    //read pixel data
    for(int i = 0; i < width*height; i++){
        int b = fgetc(fptr);
        int g = fgetc(fptr);
        int r = fgetc(fptr);
        int grey = rgb_to_greyscale(r, g, b);
        pixels[i] = grey;
    }
    
    //close file pointer
    fclose(fptr);
    
    //print ascii art
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int index = i*width + j;
            char ascii_char = map_to_ascii(pixels[index]);
            printf("%c", ascii_char);
            usleep(1000); //add sleep to delay printing for visual effect
        }
        printf("\n");
    }
    
    //free memory
    free(pixels);
    
    return 0;
}