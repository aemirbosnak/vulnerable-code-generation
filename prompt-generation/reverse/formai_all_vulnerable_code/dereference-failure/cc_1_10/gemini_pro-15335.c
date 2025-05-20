//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COVER_IMAGE_FILE "cover.bmp"
#define WATERMARK_IMAGE_FILE "watermark.bmp"
#define OUTPUT_IMAGE_FILE "watermarked.bmp"

// Structure to hold the pixel data of an image
typedef struct {
  unsigned char b;
  unsigned char g;
  unsigned char r;
} pixel;

// Structure to hold the image data
typedef struct {
  int width;
  int height;
  pixel *data;
} image;

// Function to read an image from a file
image *read_image(char *filename) {
  FILE *fp;
  image *img;

  // Open the file
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the header information
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, fp);

  // Get the width and height of the image
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  img = malloc(sizeof(image));
  img->width = width;
  img->height = height;
  img->data = malloc(width * height * sizeof(pixel));

  // Read the pixel data
  fread(img->data, sizeof(pixel), width * height, fp);

  // Close the file
  fclose(fp);

  return img;
}

// Function to write an image to a file
void write_image(image *img, char *filename) {
  FILE *fp;

  // Open the file
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  // Write the header information
  unsigned char header[54];
  memcpy(header, "BM", 2);
  *(int *)&header[2] = sizeof(header) + img->width * img->height * sizeof(pixel);
  *(int *)&header[10] = sizeof(header);
  *(int *)&header[18] = img->width;
  *(int *)&header[22] = img->height;
  *(short *)&header[28] = 1;
  *(short *)&header[30] = 8;
  *(int *)&header[38] = 0;
  *(int *)&header[46] = 0;
  *(int *)&header[54] = img->width * img->height * sizeof(pixel);
  fwrite(header, sizeof(unsigned char), 54, fp);

  // Write the pixel data
  fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

  // Close the file
  fclose(fp);
}

// Function to embed a watermark into an image
void embed_watermark(image *cover_img, image *watermark_img) {
  // Check if the cover image is large enough to hold the watermark
  if (cover_img->width < watermark_img->width || cover_img->height < watermark_img->height) {
    fprintf(stderr, "Error: Cover image is too small to hold the watermark\n");
    return;
  }

  // Embed the watermark into the cover image
  for (int y = 0; y < watermark_img->height; y++) {
    for (int x = 0; x < watermark_img->width; x++) {
      // Get the pixel values from the cover and watermark images
      pixel cover_pixel = cover_img->data[y * cover_img->width + x];
      pixel watermark_pixel = watermark_img->data[y * watermark_img->width + x];

      // Embed the watermark pixel into the cover pixel
      cover_pixel.b = (cover_pixel.b & 0xF0) | (watermark_pixel.b >> 4);
      cover_pixel.g = (cover_pixel.g & 0xF0) | (watermark_pixel.g >> 4);
      cover_pixel.r = (cover_pixel.r & 0xF0) | (watermark_pixel.r >> 4);

      // Update the cover image with the watermarked pixel
      cover_img->data[y * cover_img->width + x] = cover_pixel;
    }
  }
}

// Function to extract a watermark from an image
image *extract_watermark(image *cover_img, image *watermark_img) {
  // Check if the cover image is large enough to hold the watermark
  if (cover_img->width < watermark_img->width || cover_img->height < watermark_img->height) {
    fprintf(stderr, "Error: Cover image is too small to hold the watermark\n");
    return NULL;
  }

  // Extract the watermark from the cover image
  image *watermark_img_extracted = malloc(sizeof(image));
  watermark_img_extracted->width = watermark_img->width;
  watermark_img_extracted->height = watermark_img->height;
  watermark_img_extracted->data = malloc(watermark_img->width * watermark_img->height * sizeof(pixel));

  for (int y = 0; y < watermark_img->height; y++) {
    for (int x = 0; x < watermark_img->width; x++) {
      // Get the pixel values from the cover image
      pixel cover_pixel = cover_img->data[y * cover_img->width + x];

      // Extract the watermark pixel from the cover pixel
      pixel watermark_pixel;
      watermark_pixel.b = (cover_pixel.b & 0x0F) << 4;
      watermark_pixel.g = (cover_pixel.g & 0x0F) << 4;
      watermark_pixel.r = (cover_pixel.r & 0x0F) << 4;

      // Update the extracted watermark image with the watermark pixel
      watermark_img_extracted->data[y * watermark_img->width + x] = watermark_pixel;
    }
  }

  return watermark_img_extracted;
}

int main() {
  // Read the cover image
  image *cover_img = read_image(COVER_IMAGE_FILE);
  if (cover_img == NULL) {
    return EXIT_FAILURE;
  }

  // Read the watermark image
  image *watermark_img = read_image(WATERMARK_IMAGE_FILE);
  if (watermark_img == NULL) {
    return EXIT_FAILURE;
  }

  // Embed the watermark into the cover image
  embed_watermark(cover_img, watermark_img);

  // Write the watermarked image to a file
  write_image(cover_img, OUTPUT_IMAGE_FILE);

  // Extract the watermark from the cover image
  image *watermark_img_extracted = extract_watermark(cover_img, watermark_img);

  // Write the extracted watermark image to a file
  write_image(watermark_img_extracted, "extracted_watermark.bmp");

  // Free the memory allocated for the images
  free(cover_img->data);
  free(cover_img);
  free(watermark_img->data);
  free(watermark_img);
  free(watermark_img_extracted->data);
  free(watermark_img_extracted);

  return EXIT_SUCCESS;
}