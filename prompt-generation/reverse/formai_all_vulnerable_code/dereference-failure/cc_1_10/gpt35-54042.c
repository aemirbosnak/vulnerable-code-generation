//FormAI DATASET v1.0 Category: Image Steganography ; Style: scientific
/* C Image Steganography Example Program */

#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fIn = fopen("input.bmp", "rb");
   FILE *fOut = fopen("output.bmp", "wb");
   int i, j, width, height;
   unsigned char r, g, b, rNew, gNew, bNew, mask;

   if (fIn == NULL || fOut == NULL) {
      printf("Error: Could not open file(s).\n");
      exit(1);
   }

   // Read header information from input file
   unsigned char header[54];
   fread(header, sizeof(unsigned char), 54, fIn);
   width = *(int*)&header[18];
   height = *(int*)&header[22];

   // Create copy of header
   unsigned char headerCopy[54];
   for (i = 0; i < 54; i++)
      headerCopy[i] = header[i];

   // Get user message to hide in the image
   char message[100];
   printf("Enter the message to hide in the image: ");
   gets(message);

   // Loop through image data and replace LSB of each color channel with message data
   int messageIndex = 0;
   int messageLength = strlen(message);
   mask = 1;
   for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
         // Read in pixel color data
         fread(&b, sizeof(unsigned char), 1, fIn);
         fread(&g, sizeof(unsigned char), 1, fIn);
         fread(&r, sizeof(unsigned char), 1, fIn);

         // Replace LSB of color channels with message data
         if (messageIndex < messageLength) {
            rNew = r & (~mask) | ((message[messageIndex] & mask) << 0);
            gNew = g & (~mask) | ((message[messageIndex] & mask) << 1);
            bNew = b & (~mask) | ((message[messageIndex] & mask) << 2);
            messageIndex++;
         }
         else {
            rNew = r; gNew = g; bNew = b;
         }

         // Write modified pixel color data to output file
         fwrite(&bNew, sizeof(unsigned char), 1, fOut);
         fwrite(&gNew, sizeof(unsigned char), 1, fOut);
         fwrite(&rNew, sizeof(unsigned char), 1, fOut);
      }
   }

   // Copy remaining data from input file to output file
   while (!feof(fIn)) {
      unsigned char buffer[1024];
      size_t bytesRead = fread(buffer, sizeof(unsigned char), 1024, fIn);
      fwrite(buffer, sizeof(unsigned char), bytesRead, fOut);
   }

   // Close files
   fclose(fIn);
   fclose(fOut);

   printf("Message hidden in image.\n");

   return 0;
}