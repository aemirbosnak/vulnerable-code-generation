//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef unsigned char pixel;

pixel image[MAX_WIDTH][MAX_HEIGHT];

void read_image(char filename[]){
    FILE *fp;
    char ch;
    int w,h,bits;

    fp = fopen(filename,"rb");
    if (fp == NULL){
        printf("Error Opening File!");
        exit(1);
    }

    //read P5
    ch = fgetc(fp);
    if (ch != 'P' ){
        printf("Error: Not a PGM file");
        exit(1);
    }

    ch = fgetc(fp);
    if (ch != '5'){
        printf("Error: Not a PGM file");
        exit(1);
    }

    //read dimensions
    fscanf(fp,"%d",&w);
    fscanf(fp,"%d",&h);
    fscanf(fp,"%d",&bits);

    //check image dimensions
    if (w > MAX_WIDTH || h > MAX_HEIGHT){
        printf("Error: Image Dimensions Greater Than Maximum");
        exit(1);
    }

    //read pixel values
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            image[i][j] = fgetc(fp);
        }
    }

    fclose(fp);
}

void write_image(char filename[]){
    FILE *fp;

    fp = fopen(filename,"wb");
    if (fp == NULL){
        printf("Error Opening File!");
        exit(1);
    }

    //write P5
    fprintf(fp,"P5\n");

    //write dimensions
    fprintf(fp,"%d %d\n",MAX_WIDTH,MAX_HEIGHT);

    //write bit depth
    fprintf(fp,"%d\n",255);

    //write pixel values
    for (int i=0; i<MAX_HEIGHT; i++){
        for (int j=0; j<MAX_WIDTH; j++){
            fputc(image[i][j],fp);
        }
    } 

    fclose(fp);
}

void flip_image(int direction){
    if (direction == 0){
        //flip horizontal
        for (int i=0; i<MAX_HEIGHT; i++){
            for (int j=0; j<MAX_WIDTH/2; j++){
                pixel tmp = image[i][j];
                image[i][j] = image[i][MAX_WIDTH-1-j];
                image[i][MAX_WIDTH-1-j] = tmp;
            }
        }
    }
    else if (direction == 1){
        //flip vertical
        for (int i=0; i<MAX_HEIGHT/2; i++){
            for (int j=0; j<MAX_WIDTH; j++){
                pixel tmp = image[i][j];
                image[i][j] = image[MAX_HEIGHT-1-i][j];
                image[MAX_HEIGHT-1-i][j] = tmp;
            }
        }   
    }
    else{
        printf("Invalid direction!");
    }
}

void change_brightness(int amount){
    for (int i=0; i<MAX_HEIGHT; i++){
        for (int j=0; j<MAX_WIDTH; j++){
            int val = (int)image[i][j] + amount;
            if (val < 0){
                val = 0;
            }
            else if (val > 255){
                val = 255;
            }
            image[i][j] = (pixel)val;
        }
    }
}

void change_contrast(int amount){
    double factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));

    for (int i=0; i<MAX_HEIGHT; i++){
        for (int j=0; j<MAX_WIDTH; j++){
            int val = (int)image[i][j];

            val = (int)((factor * (val - 128)) + 128);

            if (val < 0){
                val = 0;
            }
            else if (val > 255){
                val = 255;
            }

            image[i][j] = (pixel)val;
        }
    }
}

int main(){
    read_image("input.pgm");

    flip_image(0); //horizontal flip
    change_brightness(50); //increase brightness
    change_contrast(50); //increase contrast
    flip_image(1); //vertical flip

    write_image("output.pgm");

    return 0;
}