//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed watermark into the image
void embedWatermark(char *imageFile, char *watermark) {
   FILE *image, *wm;
   int byte, bit, wmbit, i;
   char wmbyte, imgbyte;
   
   // Open the image and watermark files
   image = fopen(imageFile, "rb+");
   wm = fopen(watermark, "rb");

   // Embed the watermark bit-by-bit
   for (i = 0; i < strlen(watermark); i++) {
      wmbyte = fgetc(wm);
      for (wmbit = 0; wmbit < 8; wmbit++) {
         byte = ftell(image);
         imgbyte = fgetc(image);
         bit = wmbyte & (1 << (7 - wmbit)) ? 1 : 0;
         if (bit == 1 && (imgbyte & 1) == 0) {
            fseek(image, byte, SEEK_SET);
            fputc(imgbyte | 1, image);
         }
         if (bit == 0 && (imgbyte & 1) == 1) {
            fseek(image, byte, SEEK_SET);
            fputc(imgbyte & ~1, image);
         }
      }
   }

   // Close the image and watermark files
   fclose(wm);
   fclose(image);

   printf("Watermark embedded successfully!\n");
}

// Function to extract watermark from the image
char *extractWatermark(char *imageFile, int watermarkSize) {
   FILE *image;
   int byte, bit, i;
   char imgbyte, wmbyte, *watermark;

   // Allocate memory for the watermark buffer
   watermark = (char *) malloc(watermarkSize * sizeof(char));

   // Open the image file
   image = fopen(imageFile, "rb");

   // Extract the watermark bit-by-bit
   for (i = 0; i < watermarkSize; i++) {
      wmbyte = 0;
      for (bit = 0; bit < 8; bit++) {
         byte = ftell(image);
         imgbyte = fgetc(image);
         wmbyte |= (imgbyte & 1) << (7 - bit);
      }
      watermark[i] = wmbyte;
   }

   // Close the image file
   fclose(image);

   // Return the watermark
   return watermark;
}

// Main function
int main() {
   char *imageFile = "image.bmp";
   char *watermark = "watermark.txt";
   char *extractedWatermark;
   int watermarkSize = strlen(watermark);
   
   printf("Embedding watermark '%s' into image '%s'...\n", watermark, imageFile);

   embedWatermark(imageFile, watermark);

   printf("Watermark extraction:\n");

   extractedWatermark = extractWatermark(imageFile, watermarkSize);

   printf("Extracted watermark: %s\n", extractedWatermark);

   free(extractedWatermark);

   return 0;
}