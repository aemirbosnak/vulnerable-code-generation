//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_SCALE_FACTOR 10
#define MAX_IMAGE_SIZE 1000
#define MAX_ASCII_SIZE 200000

unsigned char image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
unsigned char ascii_art[MAX_ASCII_SIZE];

void print_ascii_art() {
    printf("%s\n", ascii_art);
}

void generate_ascii_art(int height, int width) {

    int ascii_index = 0;

    for(int i = 0 ; i < height ; i++) {
        for(int j = 0 ; j < width ; j++) {
            int index = ((int)image[i][j] / ASCII_SCALE_FACTOR);
            if(index > 0 && index < 25){
                ascii_art[ascii_index] = "abcdefghijklmnopqrstuvwxyz"[index - 1];
            }
            else {
                ascii_art[ascii_index] = ' ';
            }
            ascii_index++;
        }
        ascii_art[ascii_index] = '\n';
        ascii_index++;
    }
    ascii_art[ascii_index] = '\0';
}

void read_image_file(char* file_path, int* height, int* width) {

    FILE *fp;
    fp = fopen(file_path , "rb");

    if(fp==NULL){
        printf("\nCannot open image file\n");
        return;
    }

    fseek(fp,0x0012,SEEK_SET);
    fread(width,sizeof(int),1,fp);
    fread(height,sizeof(int),1,fp);

    if (*height > MAX_IMAGE_SIZE || *width > MAX_IMAGE_SIZE) {
        printf("\nImage size exceeds the maximum limit. Please choose a smaller image.\n");
        return;
    }

    fseek(fp, 54, SEEK_SET);

    for(int i = 0 ; i < *height ; i++) {
        for(int j = 0 ; j < *width ; j++) {
            fread(&image[i][j], 3*sizeof(unsigned char), 1, fp);
        }
    }
}

int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("\nPlease provide input image file path\n");
        return 0;
    }

    int height, width;
    char* image_file_path = argv[1];

    read_image_file(image_file_path, &height, &width);
    generate_ascii_art(height, width);

    print_ascii_art();

    return 0;
}