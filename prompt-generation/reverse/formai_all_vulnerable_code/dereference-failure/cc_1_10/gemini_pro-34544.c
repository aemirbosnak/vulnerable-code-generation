//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define WIDTH 512
#define HEIGHT 512

// Image data type
typedef unsigned char pixel_t;

// Image flipping function
void flip_image(pixel_t *image) {
  // Flipping the image horizontally
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH / 2; x++) {
      pixel_t temp = image[y * WIDTH + x];
      image[y * WIDTH + x] = image[y * WIDTH + WIDTH - x - 1];
      image[y * WIDTH + WIDTH - x - 1] = temp;
    }
  }

  // Flipping the image vertically
  for (int y = 0; y < HEIGHT / 2; y++) {
    for (int x = 0; x < WIDTH; x++) {
      pixel_t temp = image[y * WIDTH + x];
      image[y * WIDTH + x] = image[(HEIGHT - y - 1) * WIDTH + x];
      image[(HEIGHT - y - 1) * WIDTH + x] = temp;
    }
  }
}

// Image brightness and contrast adjustment function
void adjust_brightness_contrast(pixel_t *image, int brightness, float contrast) {
  // Adjust brightness
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      image[y * WIDTH + x] = image[y * WIDTH + x] + brightness;
    }
  }

  // Adjust contrast
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      image[y * WIDTH + x] = (image[y * WIDTH + x] - 128) * contrast + 128;
    }
  }
}

// Image saving function
void save_image(pixel_t *image, char *filename) {
  // Open a file for writing
  FILE *fp = fopen(filename, "wb");

  // Write the image header
  fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);

  // Write the image data
  fwrite(image, sizeof(pixel_t), WIDTH * HEIGHT, fp);

  // Close the file
  fclose(fp);
}

int main() {
  // Allocate memory for the image
  pixel_t *image = malloc(WIDTH * HEIGHT * sizeof(pixel_t));

  // Load the image from a file
  FILE *fp = fopen("image.pgm", "rb");
  fread(image, sizeof(pixel_t), WIDTH * HEIGHT, fp);
  fclose(fp);

  // Flip the image
  flip_image(image);

  // Adjust the image brightness and contrast
  adjust_brightness_contrast(image, 50, 1.2);

  // Save the image to a file
  save_image(image, "flipped_brightened_contrasted.pgm");

  // Free the memory allocated for the image
  free(image);

  return 0;
}