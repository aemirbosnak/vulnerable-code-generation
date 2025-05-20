//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 8

typedef struct {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} pixel_t;

// Embed a watermark into an image.
void embed_watermark(pixel_t *image, const char *watermark) {
  int i = 0;

  // Iterate over the image and embed the watermark.
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Get the pixel at (x, y).
      pixel_t *pixel = &image[y * WIDTH + x];

      // Embed the watermark bit in the least significant bit of the red channel.
      if (watermark[i] == '0') {
        pixel->red &= ~1;
      } else {
        pixel->red |= 1;
      }

      // Move to the next bit in the watermark.
      i++;
    }
  }
}

// Extract the watermark from an image.
char *extract_watermark(pixel_t *image) {
  int i = 0;
  char *watermark = malloc(WIDTH * HEIGHT / 8 + 1);

  // Iterate over the image and extract the watermark.
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Get the pixel at (x, y).
      pixel_t *pixel = &image[y * WIDTH + x];

      // Extract the watermark bit from the least significant bit of the red channel.
      if (pixel->red & 1) {
        watermark[i] = '1';
      } else {
        watermark[i] = '0';
      }

      // Move to the next bit in the watermark.
      i++;
    }
  }

  // Terminate the watermark with a null character.
  watermark[i] = '\0';

  return watermark;
}

// Test the watermarking and extraction functions.
int main() {
  // Create an image.
  pixel_t image[HEIGHT * WIDTH];

  // Embed a watermark into the image.
  embed_watermark(image, "This is a watermark.");

  // Extract the watermark from the image.
  char *watermark = extract_watermark(image);

  // Print the watermark.
  printf("%s\n", watermark);

  // Free the watermark.
  free(watermark);

  return 0;
}