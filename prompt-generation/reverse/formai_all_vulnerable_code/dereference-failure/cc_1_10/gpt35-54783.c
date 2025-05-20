//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//Function to flip an image
void flipImage(int *image, int width, int height) {
   for(int i = 0; i < height/2; i++){
      for(int j = 0; j < width; j++){
         int temp = *(image + i*width + j);
         *(image + i*width + j) = *(image + (height-i-1)*width + j);
         *(image + (height-i-1)*width + j) = temp;
      }
   }
}

//Function to adjust brightness of an image
void adjustBrightness(int *image, int width, int height, int brightness) {
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         *(image + i*width + j) += brightness;
         if(*(image + i*width + j) > 255) *(image + i*width + j) = 255;
         else if(*(image + i*width + j) < 0) *(image + i*width + j) = 0;
      }
   }
}

//Function to adjust contrast of an image
void adjustContrast(int *image, int width, int height, float contrast) {
   float factor = (259*(contrast + 255))/(255*(259 - contrast));
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         *(image + i*width + j) = factor*(*(image + i*width + j) - 128) + 128;
         if(*(image + i*width + j) > 255) *(image + i*width + j) = 255;
         else if(*(image + i*width + j) < 0) *(image + i*width + j) = 0;
      }
   }
}

int main() {
   int width = 3;
   int height = 3;
   int *image = (int*)malloc(width*height*sizeof(int));

   //Creating a sample image
   *(image + 0*width + 0) = 0;
   *(image + 0*width + 1) = 128;
   *(image + 0*width + 2) = 255;
   *(image + 1*width + 0) = 64;
   *(image + 1*width + 1) = 192;
   *(image + 1*width + 2) = 32;
   *(image + 2*width + 0) = 128;
   *(image + 2*width + 1) = 64;
   *(image + 2*width + 2) = 128;

   printf("Original Image:\n");
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         printf("%d\t", *(image + i*width + j));
      }
      printf("\n");
   }

   //Flipping the image
   flipImage(image, width, height);
   
   printf("Flipped Image:\n");
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         printf("%d\t", *(image + i*width + j));
      }
      printf("\n");
   }

   //Adjusting brightness of the image
   adjustBrightness(image, width, height, 50);

   printf("Bright Image:\n");
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         printf("%d\t", *(image + i*width + j));
      }
      printf("\n");
   }

   //Adjusting contrast of the image
   adjustContrast(image, width, height, 50);

   printf("Contrasted Image:\n");
   for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
         printf("%d\t", *(image + i*width + j));
      }
      printf("\n");
   }

   free(image);
   return 0;
}