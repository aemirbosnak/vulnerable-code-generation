//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned char r, g, b;
}Pixel;

typedef struct{
    int width, height;
    Pixel* data;
}Image;

Image* createImage(int width, int height){
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = calloc(width * height, sizeof(Pixel));
    return img;
}

void freeImage(Image* img){
    free(img->data);
    free(img);
}

void setPixel(Image* img, int x, int y, unsigned char r, unsigned char g, unsigned char b){
    int index = y * img->width + x;
    img->data[index].r = r;
    img->data[index].g = g;
    img->data[index].b = b;
}

void drawRectangle(Image* img, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            setPixel(img, x, y, r, g, b);
        }
    }
}

void drawCircle(Image* img, int cx, int cy, int r, unsigned char r_, unsigned char g_, unsigned char b_){
    int x, y, ix, iy;
    float d;
    for (x=-r;x<=r;x++) {
        d=sqrt(r*r-x*x);
        for (y=-d;y<=d;y++) {
            ix=cx+x;
            iy=cy+y;
            if(ix >= 0 && ix < img->width && iy >= 0 && iy < img->height)
                setPixel(img, ix, iy, r_, g_, b_);
        }
    }
}

void loadImage(Image* img, char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file: %s\n", filename);
        return;
    }    
    char format[3];
    fgets(format, 3, file);
    if(strcmp(format, "P6") != 0){
        printf("Invalid file format: %s\n", format);
        fclose(file);
        return;
    }    
    fscanf(file, "%d %d\n", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d\n", &maxval);
    img->data = calloc(img->width * img->height, sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void saveImage(Image* img, char* filename){
    FILE* file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file: %s\n", filename);
        return;
    }    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void medievalEditor(){
    Image* img = createImage(640, 480);
    drawRectangle(img, 50, 50, 590, 430, 255, 255, 255);
    drawCircle(img, 320, 240, 100, 255, 0, 0);
    drawCircle(img, 290, 210, 10, 0, 0, 0);
    drawCircle(img, 350, 210, 10, 0, 0, 0);
    drawRectangle(img, 305, 250, 335, 400, 0, 0, 0);
    drawCircle(img, 320, 430, 50, 0, 0, 0);
    saveImage(img, "medieval_image.ppm");
    freeImage(img);
}

int main(){
    medievalEditor();
    return 0;
}