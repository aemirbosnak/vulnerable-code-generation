//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image width and height
#define WIDTH    256
#define HEIGHT   256

// Define contrast range
#define MIN_CONTRAST -255
#define MAX_CONTRAST  255

// Define brightness range
#define MIN_BRIGHTNESS -127
#define MAX_BRIGHTNESS  127

// Function to flip image horizontally 
void flipHorizontally(unsigned char *image) {
   int i, j;
   unsigned char temp;

   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < WIDTH / 2; j++) {
         temp = image[i*WIDTH+j];
         image[i*WIDTH+j] = image[i*WIDTH+WIDTH-j-1];
         image[i*WIDTH+WIDTH-j-1] = temp;
      }
   }
}

// Function to change image contrast
void changeContrast(unsigned char *image, int contrast) {
   int i, j, k;

   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < WIDTH; j++) {
         k = i*WIDTH+j;

         if (contrast > 0) {
            image[k] = (image[k] * (MAX_CONTRAST - contrast)) + (contrast * MIN_CONTRAST) / MAX_CONTRAST;
         }
         else {
            image[k] = (image[k] * (MAX_CONTRAST + contrast)) - (-contrast * MIN_CONTRAST) / MAX_CONTRAST;
         }
      }
   }
}

// Function to change image brightness
void changeBrightness(unsigned char *image, int brightness) {
   int i, j, k;

   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < WIDTH; j++) {
         k = i*WIDTH+j;

         if (brightness > 0) {
            if (image[k] + brightness > MAX_BRIGHTNESS) {
               image[k] = MAX_BRIGHTNESS;
            }
            else {
               image[k] = image[k] + brightness;
            }
         }
         else {
            if (image[k] + brightness < MIN_BRIGHTNESS) {
               image[k] = MIN_BRIGHTNESS;
            }
            else {
               image[k] = image[k] + brightness;
            }
         }
      }
   }
}

int main() {
   // Allocate memory for input and output images
   unsigned char *image = (unsigned char*) malloc(sizeof(unsigned char) * WIDTH * HEIGHT);

   // Read the image from file
   FILE *file = fopen("input.raw", "rb");
   fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
   fclose(file);

   // Perform image processing tasks
   printf("Performing image processing tasks...\n");
   printf("Flipping the image horizontally...\n");
   flipHorizontally(image);

   printf("Increasing contrast by 50%%...\n");
   changeContrast(image, 50);

   printf("Decreasing brightness by 50 units...\n");
   changeBrightness(image, -50);

   // Write the image to file
   file = fopen("output.raw", "wb");
   fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
   fclose(file);

   // Deallocate memory
   free(image);

   printf("Image processing completed successfully!\n");

   return 0;
}