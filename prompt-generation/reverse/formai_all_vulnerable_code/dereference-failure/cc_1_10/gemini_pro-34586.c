//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      unsigned char temp = image[i * width + j];
      image[i * width + j] = image[i * width + width - j - 1];
      image[i * width + width - j - 1] = temp;
    }
  }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char temp = image[i * width + j];
      image[i * width + j] = image[(height - i - 1) * width + j];
      image[(height - i - 1) * width + j] = temp;
    }
  }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = image[i * width + j] + brightness;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[i * width + j] = new_value;
    }
  }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = (image[i * width + j] - 128) * contrast + 128;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[i * width + j] = new_value;
    }
  }
}

int main() {
  // Read the image from a file
  FILE *file = fopen("image.bmp", "rb");
  if (file == NULL) {
    printf("Error: could not open file\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  // Allocate memory for the image data
  unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
  if (image == NULL) {
    printf("Error: could not allocate memory for image\n");
    return 1;
  }

  // Read the image data
  fread(image, sizeof(unsigned char), width * height, file);

  // Close the file
  fclose(file);

  // Flip the image horizontally
  flip_horizontal(image, width, height);

  // Flip the image vertically
  flip_vertical(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 1.5);

  // Write the modified image to a file
  file = fopen("modified_image.bmp", "wb");
  if (file == NULL) {
    printf("Error: could not open file\n");
    return 1;
  }

  // Write the image dimensions
  fwrite(&width, sizeof(int), 1, file);
  fwrite(&height, sizeof(int), 1, file);

  // Write the image data
  fwrite(image, sizeof(unsigned char), width * height, file);

  // Close the file
  fclose(file);

  // Free the memory allocated for the image data
  free(image);

  return 0;
}