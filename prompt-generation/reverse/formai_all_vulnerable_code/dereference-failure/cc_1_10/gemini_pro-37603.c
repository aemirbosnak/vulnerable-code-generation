//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b, a;
} Pixel;

typedef struct {
  int width, height;
  Pixel *data;
} Image;

Image *image_new(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->data = malloc(width * height * sizeof(Pixel));
  return image;
}

void image_free(Image *image) {
  free(image->data);
  free(image);
}

void image_set_pixel(Image *image, int x, int y, Pixel pixel) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->data[y * image->width + x] = pixel;
}

Pixel image_get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return (Pixel){0, 0, 0, 0};
  }
  return image->data[y * image->width + x];
}

void image_save_ppm(Image *image, char *filename) {
  FILE *file = fopen(filename, "w");
  fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = image_get_pixel(image, x, y);
      fprintf(file, "%d %d %d ", pixel.r, pixel.g, pixel.b);
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

int main() {
  // Create a new image.
  Image *image = image_new(256, 256);

  // Generate a gradient from black to white.
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Pixel pixel = {0, 0, 0, 0};
      pixel.r = (unsigned char)((double)x / image->width * 255);
      pixel.g = (unsigned char)((double)x / image->width * 255);
      pixel.b = (unsigned char)((double)x / image->width * 255);
      image_set_pixel(image, x, y, pixel);
    }
  }

  // Draw a circle.
  int radius = 25;
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      if ((x - image->width / 2) * (x - image->width / 2) + (y - image->height / 2) * (y - image->height / 2) <= radius * radius) {
        Pixel pixel = {0, 0, 0, 0};
        pixel.r = 255;
        pixel.g = 255;
        pixel.b = 0;
        image_set_pixel(image, x, y, pixel);
      }
    }
  }

  // Save the image to a file.
  image_save_ppm(image, "output.ppm");

  // Free the image.
  image_free(image);

  return 0;
}