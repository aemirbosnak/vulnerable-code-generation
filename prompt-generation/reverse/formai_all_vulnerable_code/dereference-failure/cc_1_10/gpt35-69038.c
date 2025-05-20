//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 95
#define BLOCK_SIZE 10

char ASCII_CHARS[ASCII_SIZE] = {' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~'};

//Function to read in the image file
char* read_image(char *file_path){
    FILE *image_file = fopen(file_path, "r");
    fseek(image_file, 0, SEEK_END);
    long int file_size = ftell(image_file);
    rewind(image_file);
    char *buffer = (char*)malloc(sizeof(char) * file_size);
    fread(buffer, sizeof(char), file_size, image_file);
    fclose(image_file);
    return buffer;
}

//Function to resize the image to a block_size by block_size pixel image
char* resize_image(char *image, int width, int height){

    int new_width = width / BLOCK_SIZE;
    int new_height = height / BLOCK_SIZE;
    int block_size = BLOCK_SIZE * BLOCK_SIZE;
    
    char* image_resized = (char*)malloc(sizeof(char) * new_width * new_height);

    for(int i=0;i<new_height;i++){
        for(int j=0;j<new_width;j++){
            int index = (i*new_width)+j;
            int start_row = i*BLOCK_SIZE*width;
            int start_col = j*BLOCK_SIZE;

            double average_brightness = 0;
            for(int k=0;k<BLOCK_SIZE;k++){
                for(int l=0;l<BLOCK_SIZE;l++){
                    average_brightness += (unsigned char) image[start_row + start_col + k*width + l];
                }
            }
            average_brightness /= block_size;

            int ascii_val = (int)(average_brightness / 255 * ASCII_SIZE);
            image_resized[index] = ASCII_CHARS[ascii_val];
        }
    }
    return image_resized;
}

//Function to write the ASCII art to a file
void write_ascii_art(char* ascii_art, char* file_path, int width, int height){
    FILE *output_file = fopen(file_path, "w");
    int index = 0;
    for(int i=0;i<height/BLOCK_SIZE;i++){
        for(int j=0;j<width/BLOCK_SIZE;j++){
            index = (i*(width/BLOCK_SIZE))+j;
            fprintf(output_file, "%c", ascii_art[index]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
}

int main(){
    char image_path[] = "./image.raw";
    char ascii_art_path[] = "./ascii_art.txt";

    char* image = read_image(image_path);
    char* ascii_art =  resize_image(image, 128, 128);
    write_ascii_art(ascii_art, ascii_art_path, 128, 128);

    free(image);
    free(ascii_art);

    return 0;
}