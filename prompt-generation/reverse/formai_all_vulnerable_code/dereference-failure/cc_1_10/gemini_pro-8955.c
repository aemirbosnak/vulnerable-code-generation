//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} pixel_t;

typedef struct {
  unsigned int width;
  unsigned int height;
  pixel_t *pixels;
} image_t;

image_t *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    return NULL;
  }

  // Read the header
  unsigned char header[14];
  fread(header, sizeof(unsigned char), 14, fp);

  if (header[0] != 'B' || header[1] != 'M') {
    return NULL;
  }

  // Skip the color table
  fseek(fp, 54, SEEK_SET);

  // Read the image data
  image_t *image = malloc(sizeof(image_t));
  image->width = *(unsigned int *)(header + 18);
  image->height = *(unsigned int *)(header + 22);
  image->pixels = malloc(sizeof(pixel_t) * image->width * image->height);
  fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

  fclose(fp);

  return image;
}

void save_image(const char *filename, const image_t *image) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    return;
  }

  // Write the header
  unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
  *(unsigned int *)(header + 2) = image->width * image->height * sizeof(pixel_t) + 54;
  fwrite(header, sizeof(unsigned char), 14, fp);

  // Write the image data
  fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

  fclose(fp);
}

void flip_image_horizontal(image_t *image) {
  for (unsigned int y = 0; y < image->height; y++) {
    for (unsigned int x = 0; x < image->width / 2; x++) {
      pixel_t temp = image->pixels[y * image->width + x];
      image->pixels[y * image->width + x] = image->pixels[y * image->width + image->width - x - 1];
      image->pixels[y * image->width + image->width - x - 1] = temp;
    }
  }
}

void flip_image_vertical(image_t *image) {
  for (unsigned int y = 0; y < image->height / 2; y++) {
    for (unsigned int x = 0; x < image->width; x++) {
      pixel_t temp = image->pixels[y * image->width + x];
      image->pixels[y * image->width + x] = image->pixels[(image->height - y - 1) * image->width + x];
      image->pixels[(image->height - y - 1) * image->width + x] = temp;
    }
  }
}

void change_brightness_contrast(image_t *image, double brightness, double contrast) {
  for (unsigned int y = 0; y < image->height; y++) {
    for (unsigned int x = 0; x < image->width; x++) {
      pixel_t *pixel = &image->pixels[y * image->width + x];

      // Adjust the brightness
      pixel->r = (unsigned char)round(pixel->r * brightness);
      pixel->g = (unsigned char)round(pixel->g * brightness);
      pixel->b = (unsigned char)round(pixel->b * brightness);

      // Adjust the contrast
      pixel->r = (unsigned char)round((pixel->r - 128) * contrast + 128);
      pixel->g = (unsigned char)round((pixel->g - 128) * contrast + 128);
      pixel->b = (unsigned char)round((pixel->b - 128) * contrast + 128);
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <input_image> <output_image>\n", argv[0]);
    return 1;
  }

  // Load the input image
  image_t *image = load_image(argv[1]);
  if (!image) {
    printf("Error: could not load input image '%s'\n", argv[1]);
    return 1;
  }

  // Flip the image horizontally
  flip_image_horizontal(image);

  // Flip the image vertically
  flip_image_vertical(image);

  // Change the brightness and contrast
  change_brightness_contrast(image, 1.2, 1.5);

  // Save the output image
  save_image(argv[2], image);

  // Free the memory
  free(image->pixels);
  free(image);

  return 0;
}