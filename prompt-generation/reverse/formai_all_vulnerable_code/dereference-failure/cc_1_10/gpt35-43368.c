//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

char image_ascii[HEIGHT][WIDTH+1];

int convert_pixel_to_char(int pixel){
    if(pixel < 64){
        return ' ';
    }
    else if(pixel >= 64 && pixel < 128){
        return '.';
    }
    else if(pixel >= 128 && pixel < 192){
        return 'x';
    }
    else{
        return '#';
    }
}

void convert_image(unsigned char* image_data){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            int pixel_index = (i * WIDTH) + j;
            int pixel = image_data[pixel_index];
            image_ascii[i][j] = convert_pixel_to_char(pixel);
        }
        image_ascii[i][WIDTH] = '\0';
    }
}

int main(){
    //initialize image data
    unsigned char* image_data = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    for(int i = 0; i< WIDTH*HEIGHT; i++){
        image_data[i] = rand() % 255;
    }

    //convert image data to ascii
    convert_image(image_data);

    //print ascii art
    for(int i = 0; i < HEIGHT; i++){
        printf("%s\n", image_ascii[i]);
    }

    free(image_data);
    return 0;
}