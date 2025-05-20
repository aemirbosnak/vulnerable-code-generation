//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80    // Maximum width of ASCII art
#define HEIGHT 60   // Maximum height of ASCII art

// Function to convert RGB color to grayscale color
int rgbToGray(int r, int g, int b) {
   return (0.2989 * r) + (0.5870 * g) + (0.1140 * b);
}

// Function to convert 2D pixel array to ASCII art
void convertToAscii(int **image, int width, int height) {
   // Array of ASCII characters of different intensities
   char intensity[] = " .:-=+*#%@";
   int range = strlen(intensity) - 1;
   
   // Iterate over each pixel in the image
   for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
         // Convert RGB color to grayscale color
         int gray = rgbToGray(image[i][j], image[i][j+1], image[i][j+2]);
         j+=2;
         
         // Determine the ASCII character based on the grayscale value
         int index = (int)(gray / 255.0 * range);
         printf("%c", intensity[index]);
      }
      printf("\n");
   }
}

int main() {
   // Open the image file
   FILE *fp = fopen("image.bmp", "rb");
   if(fp == NULL) {
      printf("Error opening image file");
      return 1;
   }
   
   // Read the first 54 bytes of the BMP file (header information)
   unsigned char header[54];
   fread(header, sizeof(unsigned char), 54, fp);
   
   // Get image width and height from header
   int width = *(int*)&header[18];
   int height = *(int*)&header[22];
   
   // Calculate padding (bytes needed to align each row to a 4-byte boundary)
   int padding = 4 - ((width * 3) % 4);
   if(padding == 4) padding = 0;
   
   // Allocate memory for the image buffer
   int **image = calloc(height, sizeof(int*));
   for(int i=0; i<height; i++) {
      image[i] = calloc(width*3, sizeof(int));
   }
   
   // Read image data from file
   for(int i=0; i<height; i++) {
      for(int j=0; j<width*3; j+=3) {
         // Read RGB color from file and store in image buffer
         int b = fgetc(fp);
         int g = fgetc(fp);
         int r = fgetc(fp);
         
         image[i][j] = r;
         image[i][j+1] = g;
         image[i][j+2] = b;
      }
      // Skip over padding bytes
      for(int j=0; j<padding; j++) {
         fgetc(fp);
      }
   }
   
   // Convert 2D pixel array to ASCII art and print to console
   convertToAscii(image, width, height);
   
   // Free memory
   for(int i=0; i<height; i++) {
      free(image[i]);
   }
   free(image);
   fclose(fp);
   
   return 0;
}