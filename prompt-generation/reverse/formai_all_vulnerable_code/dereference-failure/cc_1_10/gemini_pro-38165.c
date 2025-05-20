//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Embed a watermark into an image.
//
// watermark: the watermark to embed
// watermark_len: the length of the watermark in bytes
// image: the image to embed the watermark into
// image_len: the length of the image in bytes
// output: the output image with the watermark embedded
// output_len: the length of the output image in bytes
void embed_watermark(const uint8_t *watermark, size_t watermark_len,
                     const uint8_t *image, size_t image_len,
                     uint8_t **output, size_t *output_len) {
  // Check that the watermark is not longer than the image.
  if (watermark_len > image_len) {
    fprintf(stderr, "Watermark is too long.\n");
    exit(1);
  }

  // Allocate memory for the output image.
  *output = malloc(image_len);
  if (*output == NULL) {
    fprintf(stderr, "Failed to allocate memory for output image.\n");
    exit(1);
  }

  // Copy the image to the output image.
  memcpy(*output, image, image_len);

  // Embed the watermark into the output image.
  for (size_t i = 0; i < watermark_len; i++) {
    (*output)[i] = (*output)[i] ^ watermark[i];
  }

  // Set the output image length.
  *output_len = image_len;
}

// Extract a watermark from an image.
//
// image: the image to extract the watermark from
// image_len: the length of the image in bytes
// watermark: the extracted watermark
// watermark_len: the length of the watermark in bytes
void extract_watermark(const uint8_t *image, size_t image_len,
                      uint8_t **watermark, size_t *watermark_len) {
  // Allocate memory for the watermark.
  *watermark = malloc(image_len);
  if (*watermark == NULL) {
    fprintf(stderr, "Failed to allocate memory for watermark.\n");
    exit(1);
  }

  // Extract the watermark from the image.
  for (size_t i = 0; i < image_len; i++) {
    (*watermark)[i] = (*watermark)[i] ^ image[i];
  }

  // Set the watermark length.
  *watermark_len = image_len;
}

int main(int argc, char **argv) {
  // Check that the command line arguments are valid.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s watermark image output\n", argv[0]);
    exit(1);
  }

  // Read the watermark from the input file.
  FILE *watermark_fp = fopen(argv[1], "rb");
  if (watermark_fp == NULL) {
    fprintf(stderr, "Failed to open watermark file.\n");
    exit(1);
  }
  fseek(watermark_fp, 0, SEEK_END);
  size_t watermark_len = ftell(watermark_fp);
  rewind(watermark_fp);
  uint8_t *watermark = malloc(watermark_len);
  if (watermark == NULL) {
    fprintf(stderr, "Failed to allocate memory for watermark.\n");
    exit(1);
  }
  fread(watermark, 1, watermark_len, watermark_fp);
  fclose(watermark_fp);

  // Read the image from the input file.
  FILE *image_fp = fopen(argv[2], "rb");
  if (image_fp == NULL) {
    fprintf(stderr, "Failed to open image file.\n");
    exit(1);
  }
  fseek(image_fp, 0, SEEK_END);
  size_t image_len = ftell(image_fp);
  rewind(image_fp);
  uint8_t *image = malloc(image_len);
  if (image == NULL) {
    fprintf(stderr, "Failed to allocate memory for image.\n");
    exit(1);
  }
  fread(image, 1, image_len, image_fp);
  fclose(image_fp);

  // Embed the watermark into the image.
  uint8_t *output;
  size_t output_len;
  embed_watermark(watermark, watermark_len, image, image_len, &output, &output_len);

  // Write the output image to the output file.
  FILE *output_fp = fopen(argv[3], "wb");
  if (output_fp == NULL) {
    fprintf(stderr, "Failed to open output file.\n");
    exit(1);
  }
  fwrite(output, 1, output_len, output_fp);
  fclose(output_fp);

  // Free the allocated memory.
  free(watermark);
  free(image);
  free(output);

  return 0;
}