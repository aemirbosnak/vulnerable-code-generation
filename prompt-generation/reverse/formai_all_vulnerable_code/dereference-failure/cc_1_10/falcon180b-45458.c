//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define HEIGHT 100
#define WIDTH 100

typedef struct{
    int height;
    int width;
    int **data;
}Image;

void createImage(Image* img){
    img->height = HEIGHT;
    img->width = WIDTH;
    img->data = (int**)malloc(img->height*sizeof(int*));
    for(int i=0;i<img->height;i++){
        img->data[i] = (int*)malloc(img->width*sizeof(int));
    }
}

void destroyImage(Image* img){
    for(int i=0;i<img->height;i++){
        free(img->data[i]);
    }
    free(img->data);
}

void flipImage(Image* img){
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width/2;j++){
            int temp = img->data[i][j];
            img->data[i][j] = img->data[i][img->width-1-j];
            img->data[i][img->width-1-j] = temp;
        }
    }
}

void changeBrightness(Image* img,int factor){
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            int temp = img->data[i][j]*factor;
            if(temp>255){
                temp = 255;
            }
            else if(temp<0){
                temp = 0;
            }
            img->data[i][j] = temp;
        }
    }
}

void changeContrast(Image* img,int factor){
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            int temp = (img->data[i][j]+factor*(255-img->data[i][j]))/2;
            if(temp>255){
                temp = 255;
            }
            else if(temp<0){
                temp = 0;
            }
            img->data[i][j] = temp;
        }
    }
}

void displayImage(Image* img){
    for(int i=0;i<img->height;i++){
        for(int j=0;j<img->width;j++){
            printf("%d ",img->data[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Image img;
    createImage(&img);
    for(int i=0;i<img.height;i++){
        for(int j=0;j<img.width;j++){
            img.data[i][j] = i*img.width+j;
        }
    }
    flipImage(&img);
    changeBrightness(&img,2);
    changeContrast(&img,2);
    displayImage(&img);
    destroyImage(&img);
    return 0;
}