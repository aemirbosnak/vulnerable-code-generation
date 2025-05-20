//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Declare the secret key
uint32_t secret_key = 0xdeadbeef;

// Pack the secret key into a bitmask
uint32_t bitmask = 0x01010101;

// Embed the watermark into the image data
void embed_watermark(uint8_t *image_data, size_t image_size) {
  for (size_t i = 0; i < image_size; i++) {
    image_data[i] ^= (bitmask & (secret_key >> (i % 32))) >> i % 32;
  }
}

// Extract the watermark from the image data
uint32_t extract_watermark(uint8_t *image_data, size_t image_size) {
  uint32_t watermark = 0;
  for (size_t i = 0; i < image_size; i++) {
    watermark |= ((image_data[i] ^ (bitmask & (secret_key >> (i % 32)))) << (i % 32)) & bitmask;
  }
  return watermark;
}

int main() {

  // Create a random array of image data.
  uint8_t *image_data = malloc(1024);
  for (int i = 0; i < 1024; i++) {
    image_data[i] = rand() % 256;
  }

  // Embed the watermark into the image data.
  embed_watermark(image_data, 1024);

  // Verify the watermark.
  uint32_t extracted_watermark = extract_watermark(image_data, 1024);
  if (extracted_watermark == secret_key) {
    printf("Watermark verification successful.\n");
  } else {
    printf("Watermark verification failed.\n");
  }

  // Free the allocated memory.
  free(image_data);

  return 0;
}