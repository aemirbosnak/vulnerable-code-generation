//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This function flips an image horizontally
void flip_horizontally(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[y * width + (width - 1 - x)];
      image[y * width + (width - 1 - x)] = temp;
    }
  }
}

// This function flips an image vertically
void flip_vertically(unsigned char *image, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[(height - 1 - y) * width + x];
      image[(height - 1 - y) * width + x] = temp;
    }
  }
}

// This function changes the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int new_value = image[y * width + x] + brightness;
      if (new_value < 0) {
        new_value = 0;
      } else if (new_value > 255) {
        new_value = 255;
      }
      image[y * width + x] = new_value;
    }
  }
}

// This function changes the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int new_value = (image[y * width + x] - 127.5) * contrast + 127.5;
      if (new_value < 0) {
        new_value = 0;
      } else if (new_value > 255) {
        new_value = 255;
      }
      image[y * width + x] = new_value;
    }
  }
}

int main() {
  // Load the image from a file
  unsigned char *image = (unsigned char *)malloc(sizeof(unsigned char) * 640 * 480 * 3);
  FILE *file = fopen("image.jpg", "rb");
  fread(image, sizeof(unsigned char), 640 * 480 * 3, file);
  fclose(file);

  // Flip the image horizontally
  flip_horizontally(image, 640, 480);

  // Flip the image vertically
  flip_vertically(image, 640, 480);

  // Change the brightness of the image
  change_brightness(image, 640, 480, 50);

  // Change the contrast of the image
  change_contrast(image, 640, 480, 1.2);

  // Save the image to a file
  file = fopen("new_image.jpg", "wb");
  fwrite(image, sizeof(unsigned char), 640 * 480 * 3, file);
  fclose(file);

  // Free the memory allocated for the image
  free(image);

  return 0;
}