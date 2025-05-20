//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

typedef struct {
  unsigned char r, g, b, a;
} pixel_t;

typedef struct {
  unsigned int width, height;
  pixel_t *pixels;
} image_t;

image_t *image_new(unsigned int width, unsigned int height) {
  image_t *image = malloc(sizeof(image_t));
  if (!image) return NULL;

  image->width = width;
  image->height = height;
  image->pixels = malloc(width * height * sizeof(pixel_t));
  if (!image->pixels) {
    free(image);
    return NULL;
  }

  return image;
}

void image_free(image_t *image) {
  if (!image) return;

  free(image->pixels);
  free(image);
}

int image_save(image_t *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) return -1;

  fprintf(fp, "P3\n%u %u\n255\n", image->width, image->height);

  for (unsigned int y = 0; y < image->height; y++) {
    for (unsigned int x = 0; x < image->width; x++) {
      pixel_t pixel = image->pixels[y * image->width + x];
      fprintf(fp, "%u %u %u ", pixel.r, pixel.g, pixel.b);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);

  return 0;
}

int main(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr, "Usage: %s <width> <height> <input.txt> <output.ppm>\n", argv[0]);
    return 1;
  }

  unsigned int width = atoi(argv[1]);
  unsigned int height = atoi(argv[2]);
  const char *input_filename = argv[3];
  const char *output_filename = argv[4];

  FILE *fp = fopen(input_filename, "r");
  if (!fp) {
    fprintf(stderr, "Error opening input file: %s\n", input_filename);
    return 1;
  }

  image_t *image = image_new(width, height);
  if (!image) {
    fprintf(stderr, "Error creating image\n");
    return 1;
  }

  char line[256];
  unsigned int y = 0;
  while (fgets(line, sizeof(line), fp)) {
    char *token;

    token = strtok(line, " ");
    for (unsigned int x = 0; x < width && token; x++) {
      unsigned int r = atoi(token);
      token = strtok(NULL, " ");
      unsigned int g = atoi(token);
      token = strtok(NULL, " ");
      unsigned int b = atoi(token);
      token = strtok(NULL, " ");

      image->pixels[y * width + x] = (pixel_t){r, g, b, 255};
    }

    y++;

    if (y >= height) break;
  }

  fclose(fp);

  int result = image_save(image, output_filename);
  if (result != 0) {
    fprintf(stderr, "Error saving image: %s\n", output_filename);
  }

  image_free(image);

  return result;
}