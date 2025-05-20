//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed a watermark in an image.
int embed_watermark(const char *image_file, const char *watermark_file) {
  // Read the image.
  FILE *image_fp = fopen(image_file, "rb");
  if (image_fp == NULL) {
    perror("fopen");
    return 1;
  }
  fseek(image_fp, 0, SEEK_END);
  long image_size = ftell(image_fp);
  fseek(image_fp, 0, SEEK_SET);
  unsigned char *image_data = malloc(image_size);
  if (image_data == NULL) {
    perror("malloc");
    fclose(image_fp);
    return 1;
  }
  fread(image_data, 1, image_size, image_fp);
  fclose(image_fp);

  // Read the watermark.
  FILE *watermark_fp = fopen(watermark_file, "rb");
  if (watermark_fp == NULL) {
    perror("fopen");
    free(image_data);
    return 1;
  }
  fseek(watermark_fp, 0, SEEK_END);
  long watermark_size = ftell(watermark_fp);
  fseek(watermark_fp, 0, SEEK_SET);
  unsigned char *watermark_data = malloc(watermark_size);
  if (watermark_data == NULL) {
    perror("malloc");
    fclose(watermark_fp);
    free(image_data);
    return 1;
  }
  fread(watermark_data, 1, watermark_size, watermark_fp);
  fclose(watermark_fp);

  // Embed the watermark in the image.
  for (int i = 0; i < image_size; i++) {
    image_data[i] ^= watermark_data[i % watermark_size];
  }

  // Write the watermarked image.
  FILE *watermarked_image_fp = fopen("watermarked.jpg", "wb");
  if (watermarked_image_fp == NULL) {
    perror("fopen");
    free(image_data);
    free(watermark_data);
    return 1;
  }
  fwrite(image_data, 1, image_size, watermarked_image_fp);
  fclose(watermarked_image_fp);

  // Free the memory.
  free(image_data);
  free(watermark_data);

  return 0;
}

// Extract a watermark from an image.
int extract_watermark(const char *watermarked_image_file) {
  // Read the watermarked image.
  FILE *watermarked_image_fp = fopen(watermarked_image_file, "rb");
  if (watermarked_image_fp == NULL) {
    perror("fopen");
    return 1;
  }
  fseek(watermarked_image_fp, 0, SEEK_END);
  long watermarked_image_size = ftell(watermarked_image_fp);
  fseek(watermarked_image_fp, 0, SEEK_SET);
  unsigned char *watermarked_image_data = malloc(watermarked_image_size);
  if (watermarked_image_data == NULL) {
    perror("malloc");
    fclose(watermarked_image_fp);
    return 1;
  }
  fread(watermarked_image_data, 1, watermarked_image_size, watermarked_image_fp);
  fclose(watermarked_image_fp);

  // Read the watermark.
  FILE *watermark_fp = fopen("watermark.jpg", "wb");
  if (watermark_fp == NULL) {
    perror("fopen");
    free(watermarked_image_data);
    return 1;
  }

  // Extract the watermark from the image.
  for (int i = 0; i < watermarked_image_size; i++) {
    unsigned char pixel = watermarked_image_data[i];
    unsigned char original_pixel = pixel;
    for (int j = 0;; j++) {
      if (j < 8 && !(pixel & 1)) {
        break;
      } else if (j >= 8 && (pixel & 1)) {
        break;
      }
      pixel >>= 1;
    }
    fputc(original_pixel ^ pixel, watermark_fp);
  }

  // Free the memory.
  free(watermarked_image_data);

  return 0;
}

int main() {
  // Embed a watermark in an image.
  if (embed_watermark("image.jpg", "watermark.jpg")) {
    return 1;
  }

  // Extract the watermark from the watermarked image.
  if (extract_watermark("watermarked.jpg")) {
    return 1;
  }

  return 0;
}