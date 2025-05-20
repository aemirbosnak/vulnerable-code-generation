//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to read an Image and convert it to grayscale
void readImage(char* filename, int** image, int* height, int* width){
     // Image Reading Code
     // Grayscale Conversion Code
}

// Function to generate binary string of length 8
char* generateWatermark(){
     char* watermark = (char*)malloc(sizeof(char)*9);
     for(int i=0; i<8; i++){
          watermark[i] = rand()%2;
     }
     watermark[8] = '\0';
     return watermark;
}

// Function to convert decimal number to binary
void decToBin(int num, int* bin){
     // Binary Conversion Code
}

// Function to convert binary to decimal
int binToDec(int* bin){
     // Decimal Conversion Code
}

// Function to implement Digital Watermarking on Image
void implementWatermark(int** image, int height, int width){
     // Watermark Generation Code
     char* watermark = generateWatermark();
     // Pixel Selection Code
     int i = rand()%height;
     int j = rand()%width;
     int pixel[8];
     decToBin(image[i][j], pixel);
     // Watermark Embedding Code
     for(int k=0; k<8; k++){
          pixel[k] = (pixel[k]/2)*2 + watermark[k];
     }
     // Saving Watermarked Image Code
     image[i][j] = binToDec(pixel);
     // Image Writing Code
}

// Function to extract watermark from watermarked image
char* extractWatermark(int** image, int height, int width){
     // Watermark Extraction Code
     char* watermark = (char*)malloc(sizeof(char)*9);
     // Pixel Selection Code
     int i = rand()%height;
     int j = rand()%width;
     int pixel[8];
     decToBin(image[i][j], pixel);
     // Watermark Extraction Code
     for(int k=0; k<8; k++){
          watermark[k] = pixel[k]%2;
     }
     watermark[8] = '\0';
     return watermark;
}

int main(){
     int** image;
     int height, width;
     char* filename = "image.bmp";
     readImage(filename, &image, &height, &width);
     implementWatermark(image, height, width);
     char* extractedWatermark = extractWatermark(image, height, width);
     printf("Extracted Watermark: %s", extractedWatermark);
     return 0;
}