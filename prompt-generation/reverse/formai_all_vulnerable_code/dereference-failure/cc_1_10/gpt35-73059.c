//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include<stdio.h>
#include<stdlib.h>

void flip(int *img, int width, int height){
  int temp;
  for(int i=0; i<height/2; i++){
    for(int j=0; j<width; j++){
      temp = *(img+(i*width)+j);
      *(img+(i*width)+j) = *(img+((height-i-1)*width)+j);
      *(img+((height-i-1)*width)+j) = temp;
    }
  }
}

void changeBrightness(int *img, int width, int height, int value){
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      *(img+(i*width)+j) += value;
      if(*(img+(i*width)+j) > 255){
        *(img+(i*width)+j) = 255;
      }
      else if(*(img+(i*width)+j) < 0){
        *(img+(i*width)+j) = 0;
      }
    }
  }
}

void changeContrast(int *img, int width, int height, float value){
  float factor = (259 * (value + 255)) / (255 * (259 - value));
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      *(img+(i*width)+j) = (int)(factor * (*(img+(i*width)+j) - 128) + 128);
    }
  }
}

int main(){
  int width = 4;
  int height = 3;
  int *img = (int*)malloc(width*height*sizeof(int));
  for(int i=0; i<height; i++){
      for(int j=0; j<width; j++){
          *(img+(i*width)+j) = i+j;
          printf("%d ", *(img+(i*width)+j));
      }
      printf("\n");
  }
  flip(img, width, height);
  printf("\nAfter flip:\n");
  for(int i=0; i<height; i++){
      for(int j=0; j<width; j++){
          printf("%d ", *(img+(i*width)+j));
      }
      printf("\n");
  }
  changeBrightness(img, width, height, 20);
  printf("\nAfter changeBrightness:\n");
  for(int i=0; i<height; i++){
      for(int j=0; j<width; j++){
          printf("%d ", *(img+(i*width)+j));
      }
      printf("\n");
  }
  changeContrast(img, width, height, 1.5);
  printf("\nAfter changeContrast:\n");
  for(int i=0; i<height; i++){
      for(int j=0; j<width; j++){
          printf("%d ", *(img+(i*width)+j));
      }
      printf("\n");
  }
  free(img);
  return 0;
}