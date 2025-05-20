//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define SRC_FILE "input.png"
#define WATERMARK_FILE "watermark.png"
#define WATERMARK_FOLDER "watermark"

int main(int argc, char *argv[]) {
  // Load the source image
  printf("Loading source image...\n");
  unsigned char *src_data = (unsigned char*)malloc(WIDTH*HEIGHT*3);
  FILE *src_file = fopen(SRC_FILE, "rb");
  fread(src_data, 1, WIDTH*HEIGHT*3, src_file);
  fclose(src_file);

  // Load the watermark image
  printf("Loading watermark image...\n");
  unsigned char *watermark_data = (unsigned char*)malloc(WIDTH*HEIGHT*3);
  FILE *watermark_file = fopen(WATERMARK_FILE, "rb");
  fread(watermark_data, 1, WIDTH*HEIGHT*3, watermark_file);
  fclose(watermark_file);

  // Convert the images to grayscale
  printf("Converting to grayscale...\n");
  unsigned char *src_gray = (unsigned char*)malloc(WIDTH*HEIGHT);
  unsigned char *watermark_gray = (unsigned char*)malloc(WIDTH*HEIGHT);
  for(int y=0; y<HEIGHT; y++) {
    for(int x=0; x<WIDTH; x++) {
      int index = (y*WIDTH + x)*3;
      src_gray[y*WIDTH + x] = 0.2126*src_data[index] + 0.7152*src_data[index+1] + 0.0722*src_data[index+2];
      watermark_gray[y*WIDTH + x] = 0.2126*watermark_data[index] + 0.7152*watermark_data[index+1] + 0.0722*watermark_data[index+2];
    }
  }

  // Perform the digital watermarking operation
  printf("Performing digital watermarking...\n");
  for(int y=0; y<HEIGHT; y++) {
    for(int x=0; x<WIDTH; x++) {
      int index = (y*WIDTH + x)*3;
      int watermark_value = watermark_gray[y*WIDTH + x];
      src_gray[y*WIDTH + x] += watermark_value;
      if(src_gray[y*WIDTH + x] > 255) {
        src_gray[y*WIDTH + x] = 255;
      }
      if(src_gray[y*WIDTH + x] < 0) {
        src_gray[y*WIDTH + x] = 0;
      }
    }
  }

  // Save the watermarked image
  printf("Saving watermarked image...\n");
  FILE *output_file = fopen(WATERMARK_FOLDER ".png", "wb");
  fwrite(src_data, 1, WIDTH*HEIGHT*3, output_file);
  fclose(output_file);

  // Free the memory
  free(src_data);
  free(watermark_data);
  free(src_gray);
  free(watermark_gray);

  return 0;
}