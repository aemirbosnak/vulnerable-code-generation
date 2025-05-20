//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 120 // maximum width of the image
#define MAX_HEIGHT 120 // maximum height of the image
#define MAX_PIXEL_VALUE 255 // maximum pixel value in the image

typedef struct {
    int row; // number of rows in the image
    int col; // number of columns in the image
    int pixels[MAX_HEIGHT][MAX_WIDTH]; // array to store pixel values
} Image;

// Function to read the image file
void readImageFile(char *filename, Image *img){
    FILE *fp;
    char magicNumber[128];
    int i,j;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file %s\n",filename);
        exit(EXIT_FAILURE);
    }

    fgets(magicNumber, sizeof(magicNumber), fp);
    if(magicNumber[0] != 'P' || magicNumber[1] != '2'){
        printf("Invalid image format\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", &img->col, &img->row);
    if(img->col > MAX_WIDTH || img->row > MAX_HEIGHT){
        printf("Image size should be less than %dx%d\n", MAX_WIDTH, MAX_HEIGHT);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", &i);
    if(i != MAX_PIXEL_VALUE){
        printf("Invalid pixel value\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<img->row; i++){
        for(j=0; j<img->col; j++){
            fscanf(fp, "%d", &img->pixels[i][j]);
        }
    }

    fclose(fp);
}

// Function to convert image to ASCII art
void convertToAsciiArt(Image *img, char *asciiArt){
    int i,j;
    int pixelValue;
    int asciiIndex;
    char asciiChars[] = " .,:;i1tfLCG08@";

    asciiIndex = 0;
    for(i=0; i<img->row; i++){
        for(j=0; j<img->col; j++){
            pixelValue = img->pixels[i][j];
            asciiIndex = (pixelValue * strlen(asciiChars)) / (MAX_PIXEL_VALUE + 1);
            asciiArt[i*img->col + j] = asciiChars[asciiIndex];
        }
        asciiArt[i*img->col + j] = '\n';
    }
    asciiArt[i*img->col + j] = '\0';
}

int main(){
    Image img;
    char asciiArt[MAX_WIDTH*MAX_HEIGHT];
    char *filename = "image.pgm";

    readImageFile(filename, &img);
    convertToAsciiArt(&img, asciiArt);

    printf("%s", asciiArt);

    return 0;
}