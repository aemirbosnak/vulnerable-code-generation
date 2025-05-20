//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

typedef struct Pixel{
        int r;
        int g;
        int b;
    } Pixel ;

Pixel **imageData;
Pixel **copyOfImageData;

int max_color_value;
int height,width;


void allocateMemory(int height, int width){
    int i;
    imageData = (Pixel**) malloc(sizeof(Pixel*)*height);
    for(i=0;i<height;i++) imageData[i] = (Pixel*) malloc(sizeof(Pixel)*width);
     
    copyOfImageData = (Pixel**) malloc(sizeof(Pixel*)*height);
    for(i=0;i<height;i++) copyOfImageData[i] = (Pixel*) malloc(sizeof(Pixel)*width);
}

void readImage(char *filename){

    int i,j;
    FILE *fp = fopen(filename,"r");
    char ch;
    char comment[1000];
    fgets(comment,1000,fp);
    if(comment[0]!='P' || comment[1]!='3'){
        printf("Invalid file format\n");
        exit(0);
    }
    
    ch = fgetc(fp);
    while(ch=='#'){
    fgets(comment,1000,fp);
    ch = fgetc(fp);
    }
    ungetc(ch,fp);

    fscanf(fp,"%d %d\n",&width,&height);
    allocateMemory(height,width);

    fscanf(fp,"%d\n",&max_color_value);

    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            fscanf(fp,"%d %d %d",&imageData[i][j].r,&imageData[i][j].g,&imageData[i][j].b);
         }
    }

    fclose(fp);

}


void writeImage(char *filename){

    int i,j;
    FILE *fp = fopen(filename,"w");
    fprintf(fp,"P3\n");
    fprintf(fp,"#Created by CSC 131 - C Basic Image Processing\n");
    fprintf(fp,"%d %d\n",width,height);
    fprintf(fp,"%d\n",max_color_value);
    
    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            fprintf(fp,"%d %d %d ",imageData[i][j].r,imageData[i][j].g,imageData[i][j].b);
         }
         fprintf(fp,"\n");
    }

    fclose(fp);

}


void copyImageData(){
    int i,j;
    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            copyOfImageData[i][j].r = imageData[i][j].r;
            copyOfImageData[i][j].g = imageData[i][j].g;
            copyOfImageData[i][j].b = imageData[i][j].b;
         }
    }

}


void flipImage(){

    int i,j;
    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            imageData[i][j].r = copyOfImageData[height-i-1][j].r;
            imageData[i][j].g = copyOfImageData[height-i-1][j].g;
            imageData[i][j].b = copyOfImageData[height-i-1][j].b;
         }
    }

}


void changeBrightness(int brightness){

    int i,j;
    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            imageData[i][j].r = imageData[i][j].r + brightness;
            imageData[i][j].g = imageData[i][j].g + brightness;
            imageData[i][j].b = imageData[i][j].b + brightness;
         }
    }

}


void changeContrast(float contrast){

    int i,j;
    for(i=0;i<height;i++){
         for(j=0;j<width;j++){
            imageData[i][j].r = contrast*(imageData[i][j].r - 128) + 128;
            imageData[i][j].g = contrast*(imageData[i][j].g - 128) + 128;
            imageData[i][j].b = contrast*(imageData[i][j].b - 128) + 128;
         }
    }

}


int main(){
    readImage("example.ppm");
    copyImageData();
    
    flipImage();
    changeBrightness(50);
    changeContrast(1.5);
    
    writeImage("new_example.ppm");
    return 0;
}