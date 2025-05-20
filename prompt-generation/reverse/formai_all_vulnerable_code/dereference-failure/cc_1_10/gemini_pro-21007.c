//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
  uint8_t r, g, b;
} pixel_t;

typedef struct {
  size_t width, height;
  pixel_t *data;
} image_t;

image_t *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  image_t *image = malloc(sizeof(image_t));
  if (!image) {
    fclose(fp);
    return NULL;
  }

  fread(&image->width, sizeof(size_t), 1, fp);
  fread(&image->height, sizeof(size_t), 1, fp);

  image->data = malloc(image->width * image->height * sizeof(pixel_t));
  if (!image->data) {
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->data, sizeof(pixel_t), image->width * image->height, fp);
  fclose(fp);

  return image;
}

void save_image(const image_t *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) return;

  fwrite(&image->width, sizeof(size_t), 1, fp);
  fwrite(&image->height, sizeof(size_t), 1, fp);

  fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp);
  fclose(fp);
}

void flip_image(image_t *image) {
  for (size_t y = 0; y < image->height / 2; y++) {
    for (size_t x = 0; x < image->width; x++) {
      pixel_t temp = image->data[y * image->width + x];
      image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
      image->data[(image->height - 1 - y) * image->width + x] = temp;
    }
  }
}

void change_brightness(image_t *image, double brightness) {
  for (size_t y = 0; y < image->height; y++) {
    for (size_t x = 0; x < image->width; x++) {
      image->data[y * image->width + x].r = (uint8_t)fmin(255, image->data[y * image->width + x].r * brightness);
      image->data[y * image->width + x].g = (uint8_t)fmin(255, image->data[y * image->width + x].g * brightness);
      image->data[y * image->width + x].b = (uint8_t)fmin(255, image->data[y * image->width + x].b * brightness);
    }
  }
}

void change_contrast(image_t *image, double contrast) {
  double factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
  for (size_t y = 0; y < image->height; y++) {
    for (size_t x = 0; x < image->width; x++) {
      image->data[y * image->width + x].r = (uint8_t)fmin(255, factor * (image->data[y * image->width + x].r - 128) + 128);
      image->data[y * image->width + x].g = (uint8_t)fmin(255, factor * (image->data[y * image->width + x].g - 128) + 128);
      image->data[y * image->width + x].b = (uint8_t)fmin(255, factor * (image->data[y * image->width + x].b - 128) + 128);
    }
  }
}

void rotate_image(image_t *image, double angle) {
  double radian = angle * PI / 180;
  double sine = sin(radian);
  double cosine = cos(radian);
  image_t *rotated_image = malloc(sizeof(image_t));
  rotated_image->width = image->width * fabs(cosine) + image->height * fabs(sine);
  rotated_image->height = image->width * fabs(sine) + image->height * fabs(cosine);
  rotated_image->data = malloc(rotated_image->width * rotated_image->height * sizeof(pixel_t));

  for (size_t y = 0; y < rotated_image->height; y++) {
    for (size_t x = 0; x < rotated_image->width; x++) {
      double x_prime = x * cosine - y * sine;
      double y_prime = x * sine + y * cosine;
      if (x_prime < 0 || x_prime >= image->width || y_prime < 0 || y_prime >= image->height) {
        rotated_image->data[y * rotated_image->width + x] = (pixel_t){0, 0, 0};
      } else {
        rotated_image->data[y * rotated_image->width + x] = image->data[(size_t)y_prime * image->width + (size_t)x_prime];
      }
    }
  }

  free(image->data);
  *image = *rotated_image;
  free(rotated_image);
}

int main(int argc, char **argv) {
  if (argc < 5) {
    printf("Usage: %s <input image> <output image> <operation> <parameters>\n", argv[0]);
    printf("Operations:\n");
    printf("  flip\n");
    printf("  brightness <value>\n");
    printf("  contrast <value>\n");
    printf("  rotate <angle>\n");
    return 1;
  }

  image_t *image = load_image(argv[1]);
  if (!image) {
    printf("Error loading image: %s\n", argv[1]);
    return 1;
  }

  if (strcmp(argv[3], "flip") == 0) {
    flip_image(image);
  } else if (strcmp(argv[3], "brightness") == 0) {
    double brightness = atof(argv[4]);
    change_brightness(image, brightness);
  } else if (strcmp(argv[3], "contrast") == 0) {
    double contrast = atof(argv[4]);
    change_contrast(image, contrast);
  } else if (strcmp(argv[3], "rotate") == 0) {
    double angle = atof(argv[4]);
    rotate_image(image, angle);
  } else {
    printf("Invalid operation: %s\n", argv[3]);
    free(image->data);
    free(image);
    return 1;
  }

  save_image(image, argv[2]);
  free(image->data);
  free(image);

  return 0;
}