//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
// Welcome to the desolate wasteland of post-apocalyptic image processing!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our pixel survivor, ready to traverse the image landscape
typedef struct Pixel {
  int red;
  int green;
  int blue;
} Pixel;

// A relentless horde of pixels, representing our image
typedef struct Image {
  int width;
  int height;
  Pixel *data;
} Image;

// Initialize an image, preparing it for the horrors to come
Image *new_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->data = malloc(sizeof(Pixel) * width * height);
  return image;
}

// Load an image from a file, like a scavenger scavenging for supplies
Image *load_image(char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Failed to open file: %s\n", filename);
    exit(1);
  }

  // Read header information
  char header[5];
  fread(header, sizeof(char), 5, file);
  if (strcmp(header, "P3") != 0) {
    fprintf(stderr, "Invalid file format: %s\n", filename);
    exit(1);
  }

  int width, height, max_value;
  fscanf(file, "%d %d %d\n", &width, &height, &max_value);

  // Create a new image and populate it with pixel survivors
  Image *image = new_image(width, height);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int red, green, blue;
      fscanf(file, "%d %d %d\n", &red, &green, &blue);
      image->data[i * width + j].red = red;
      image->data[i * width + j].green = green;
      image->data[i * width + j].blue = blue;
    }
  }

  fclose(file);
  return image;
}

// Our intrepid pixel traveler, ready to explore the image's depths
void explore_image(Image *image) {
  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      // Each pixel tells its tale of survival and resilience
      printf("Pixel [%d, %d]: %d, %d, %d\n", i, j, image->data[i * image->width + j].red,
             image->data[i * image->width + j].green, image->data[i * image->width + j].blue);
    }
  }
}

// Flip the image vertically, a testament to the world turned upside down
void flip_vertical(Image *image) {
  for (int i = 0; i < image->height / 2; i++) {
    for (int j = 0; j < image->width; j++) {
      // Pixels swap places, like survivors trading resources
      Pixel temp = image->data[i * image->width + j];
      image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
      image->data[(image->height - i - 1) * image->width + j] = temp;
    }
  }
}

// Adjust the image's brightness and contrast, like a beacon in the darkness
void adjust_brightness_contrast(Image *image, int brightness, float contrast) {
  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      // Pixels emerge from the shadows, their intensity transformed
      image->data[i * image->width + j].red = (image->data[i * image->width + j].red + brightness) * contrast;
      image->data[i * image->width + j].green = (image->data[i * image->width + j].green + brightness) * contrast;
      image->data[i * image->width + j].blue = (image->data[i * image->width + j].blue + brightness) * contrast;
    }
  }
}

// Save the image, preserving the memories of a desolate world
void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    fprintf(stderr, "Failed to open file: %s\n", filename);
    exit(1);
  }

  // Write header information
  fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);

  // Pixels march out, their journey recorded for all time
  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fprintf(file, "%d %d %d\n", image->data[i * image->width + j].red, image->data[i * image->width + j].green,
              image->data[i * image->width + j].blue);
    }
  }

  fclose(file);
}

// Our weary travelers embark on their journey through the desolate wasteland of image processing
int main() {
  // Load the image, a tattered relic of a forgotten civilization
  Image *image = load_image("apocalyptic_landscape.ppm");

  // Explore the image, uncovering its secrets and horrors
  printf("Exploring the image:\n");
  explore_image(image);

  // Flip the image vertically, as if gravity has forsaken the world
  printf("Flipping the image vertically:\n");
  flip_vertical(image);

  // Adjust the image's brightness and contrast, revealing hidden truths
  printf("Adjusting brightness and contrast:\n");
  adjust_brightness_contrast(image, -50, 1.5);

  // Save the image, etching our mark on this desolate world
  printf("Saving the image:\n");
  save_image(image, "apocalyptic_landscape_processed.ppm");

  // Our journey ends, but the image remains, a testament to the resilience of pixels in the face of despair
  free(image->data);
  free(image);
  return 0;
}