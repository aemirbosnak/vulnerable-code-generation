//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
/*
  A paranoid-style C program for Digital Watermarking

  The program takes an input image and embeds a watermark text by altering the least significant bit of the RGB values of the image pixels.
  It also has the ability to detect the watermark in the output image and display the original watermark text if found.

  Author: paranoidbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256
#define MAX_IMAGE_LENGTH 2000000

// function prototypes
void embed_watermark(char *input_filename, char *output_filename, char *watermark);
bool detect_watermark(char *input_filename, char *watermark);

int main(int argc, char const *argv[]) {

  if (argc < 3) {
    printf("Usage: %s <input_image_file> <output_image_file> [watermark_text]\n", argv[0]);
    printf("Example: %s input.png output.png 'This is my watermark'\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char input_filename[100];
  char output_filename[100];
  char *watermark = NULL;

  strncpy(input_filename, argv[1], 100);
  strncpy(output_filename, argv[2], 100);

  if (argc == 4) {
    watermark = argv[3];
    if (strlen(watermark) > MAX_WATERMARK_LENGTH) {
      printf("Error: Watermark text is too long.\n");
      exit(EXIT_FAILURE);
    }
  }

  embed_watermark(input_filename, output_filename, watermark);

  if (detect_watermark(output_filename, watermark)) {
    printf("Watermark has been detected and extracted successfully!\n");
    printf("The original watermark text is: %s\n", watermark);
  }
  else {
    printf("Watermark has not been detected.\n");
  }

  return 0;
}

// function to embed the watermark in the image
void embed_watermark(char *input_filename, char *output_filename, char *watermark) {

  FILE *input_file = NULL;
  FILE *output_file = NULL;
  char *image_buffer = NULL;
  char *watermark_buffer = NULL;
  uint32_t image_length = 0;
  uint32_t watermark_length = 0;
  uint32_t i;

  // open input file
  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    printf("Error: Could not open input image file.\n");
    exit(EXIT_FAILURE);
  }

  // allocate memory for image buffer
  image_buffer = (char*) malloc(MAX_IMAGE_LENGTH);
  if (image_buffer == NULL) {
    printf("Error: Could not allocate memory for image buffer.\n");
    fclose(input_file);
    exit(EXIT_FAILURE);
  }

  // read input file into buffer
  image_length = fread(image_buffer, 1, MAX_IMAGE_LENGTH, input_file);
  if (image_length == 0) {
    printf("Error: Input image file is empty.\n");
    fclose(input_file);
    free(image_buffer);
    exit(EXIT_FAILURE);
  }

  // close input file
  fclose(input_file);

  // if watermark is not provided, exit
  if (watermark == NULL) {
    free(image_buffer);
    return;
  }

  // allocate memory for watermark buffer
  watermark_buffer = (char*) malloc(MAX_WATERMARK_LENGTH);
  if (watermark_buffer == NULL) {
    printf("Error: Could not allocate memory for watermark buffer.\n");
    free(image_buffer);
    exit(EXIT_FAILURE);
  }

  // copy watermark into buffer
  watermark_length = strlen(watermark);
  strncpy(watermark_buffer, watermark, watermark_length);

  // embed watermark in image
  for (i = 0; i < watermark_length; i++) {
    // embed each character of watermark by altering the least significant bit of the blue color channel for each subsequent pixel in the image
    uint32_t pixel_index = (i * 3) + 54;
    char c = watermark_buffer[i];
    for (int j = 0; j < 8; j++) {
      int bit = (c >> j) & 1;
      if (bit == 0) {
        image_buffer[pixel_index + 2] &= 0xFE;  // set LSB to 0
      }
      else {
        image_buffer[pixel_index + 2] |= 0x01;  // set LSB to 1
      }
      pixel_index += (image_length - 54) / watermark_length;
    }
  }

  // open output file
  output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    printf("Error: Could not open output image file.\n");
    free(image_buffer);
    free(watermark_buffer);
    exit(EXIT_FAILURE);
  }

  // write image buffer to output file
  fwrite(image_buffer, 1, image_length, output_file);

  // close output file
  fclose(output_file);

  // free memory
  free(image_buffer);
  free(watermark_buffer);

  printf("Watermark has been successfully embedded in the image.\n");
}

// function to detect watermark in the image
bool detect_watermark(char *input_filename, char *watermark) {

  FILE *input_file = NULL;
  char *image_buffer = NULL;
  uint32_t image_length = 0;
  uint32_t watermark_length = 0;
  uint32_t detected_length = 0;
  char detected_watermark[MAX_WATERMARK_LENGTH];
  uint32_t i;

  // open input file
  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    printf("Error: Could not open input image file.\n");
    exit(EXIT_FAILURE);
  }

  // allocate memory for image buffer
  image_buffer = (char*) malloc(MAX_IMAGE_LENGTH);
  if (image_buffer == NULL) {
    printf("Error: Could not allocate memory for image buffer.\n");
    fclose(input_file);
    exit(EXIT_FAILURE);
  }

  // read input file into buffer
  image_length = fread(image_buffer, 1, MAX_IMAGE_LENGTH, input_file);
  if (image_length == 0) {
    printf("Error: Input image file is empty.\n");
    fclose(input_file);
    free(image_buffer);
    exit(EXIT_FAILURE);
  }

  // close input file
  fclose(input_file);

  // if watermark is not provided, exit
  if (watermark == NULL) {
    free(image_buffer);
    return false;
  }

  // calculate watermark length
  watermark_length = strlen(watermark);

  // detect watermark in image
  for (i = 0; i < watermark_length; i++) {
    // detect each character of watermark by checking the least significant bit of the blue color channel for each subsequent pixel in the image
    uint32_t pixel_index = (i * 3) + 54;
    char c = 0;
    for (int j = 0; j < 8; j++) {
      int bit = image_buffer[pixel_index + 2] & 0x01;
      c |= (bit << j);
      pixel_index += (image_length - 54) / watermark_length;
    }
    detected_watermark[i] = c;
    detected_length++;
    if (detected_length == watermark_length) {
      detected_watermark[detected_length] = '\0';
      break;
    }
  }

  // free memory
  free(image_buffer);

  // compare detected watermark with original watermark
  if (strcmp(detected_watermark, watermark) == 0) {
    return true;
  }
  else {
    return false;
  }
}