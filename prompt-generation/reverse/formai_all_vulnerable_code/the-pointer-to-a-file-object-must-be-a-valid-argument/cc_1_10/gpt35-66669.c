//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WIDTH 500
#define MAX_HEIGHT 500

unsigned char ASCII_CHARS[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

char imageToASCII(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int height, int width, char output[MAX_HEIGHT][MAX_WIDTH]){
    if(height > MAX_HEIGHT || width > MAX_WIDTH){
        return 1;
    }

    int range = 255 / 10;
    int ASCII_CHARS_LENGTH = sizeof(ASCII_CHARS)/sizeof(unsigned char);
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int brightness = image[i][j]/range;
            if(brightness >= ASCII_CHARS_LENGTH){
                brightness = ASCII_CHARS_LENGTH - 1;
            }
            output[i][j] = ASCII_CHARS[brightness];
        }
    }

    return 0;
}

int main(){
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    char ASCII_art[MAX_HEIGHT][MAX_WIDTH];

    int height, width;

    // Parse the image into a 2D unsigned char array
    FILE* fp = fopen("image.pgm", "rb");

    char buffer[1000];
    int buffer_index = 0;
    
    bool started_parsing_image = false;
    
    while(fgets(buffer, 1000, fp)){
        if(buffer[0] == '#'){
            continue;
        }
        else if(!started_parsing_image){
            started_parsing_image = true;
            sscanf(buffer, "%d %d\n", &width, &height);
        }
        else{
            char* pixel_str = "";
            int pixel_str_index = 0;
            for(int i=0;i<strlen(buffer);i++){
                if(buffer[i] >= '0' && buffer[i] <= '9'){
                    pixel_str[pixel_str_index] = buffer[i];
                    pixel_str_index++;
                }
            }
            unsigned char pixel_value = atoi(pixel_str);
            image[(buffer_index-1)/(width+1)][(buffer_index-1)%(width+1)] = pixel_value;
            buffer_index+=strlen(pixel_str)+1;
        }
    }

    imageToASCII(image, height, width, ASCII_art);

    // Print the ASCII art
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%c", ASCII_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}