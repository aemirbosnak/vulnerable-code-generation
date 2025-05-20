//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

char chars[] = {' ','.',':','-','=','+','*','#','%','@'};

char* to_ascii(unsigned char* img, int img_width, int img_height){

    char* ascii_img = malloc(sizeof(char)*img_width*img_height);
    int char_pixels = 256/(strlen(chars)-1);

    for(int y=0; y<img_height; y++){
        for(int x=0; x<img_width; x++){
            int pixel = img[y*img_width + x];
            int c = pixel/char_pixels;
            ascii_img[y*img_width + x] = chars[c];
        }   
    }

    return ascii_img;
}

int main(int argc, char const *argv[]){

    if(argc != 3){
        printf("Usage: ./ascii_img_converter <input_image_file> <output_ascii_file>\n");
        exit(EXIT_FAILURE);
    }

    FILE* input_img = fopen(argv[1], "rb");

    fseek(input_img,0,SEEK_END);
    int file_size = ftell(input_img);
    fseek(input_img,0,SEEK_SET);

    unsigned char* img = malloc(file_size);
    fread(img, sizeof(unsigned char), file_size, input_img);

    fclose(input_img);

    int img_width = *(int*)(img+18);
    int img_height = *(int*)(img+22);

    char* ascii_img = to_ascii(img+54, img_width, img_height);

    FILE* output_file = fopen(argv[2], "w");

    for (int y = 0; y < img_height; y++){
        for (int x = 0; x < img_width; x++){
            fprintf(output_file, "%c", ascii_img[y*img_width+x]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);
    free(ascii_img);
    free(img);

    return 0;

}