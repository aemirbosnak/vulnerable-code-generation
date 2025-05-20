//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct _color {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} color_t;

typedef struct _canvas {
  int width;
  int height;
  color_t **pixels;
} canvas_t;

canvas_t *create_canvas(int width, int height) {
  canvas_t *canvas = malloc(sizeof(canvas_t));
  if (!canvas) return NULL;
  canvas->width = width;
  canvas->height = height;
  canvas->pixels = malloc(sizeof(color_t *) * height);
  if (!canvas->pixels) return NULL;
  for (int y = 0; y < height; y++) {
    canvas->pixels[y] = malloc(sizeof(color_t) * width);
    if (!canvas->pixels[y]) return NULL;
  }
  return canvas;
}

void destroy_canvas(canvas_t *canvas) {
  if (!canvas) return;
  for (int y = 0; y < canvas->height; y++) {
    free(canvas->pixels[y]);
  }
  free(canvas->pixels);
  free(canvas);
}

int main() {
  canvas_t *canvas = create_canvas(1000, 1000);
  if (!canvas) return -1;

  // Paint the canvas with a gradient of colors
  for (int y = 0; y < canvas->height; y++) {
    for (int x = 0; x < canvas->width; x++) {
      canvas->pixels[y][x].red = (unsigned char)(x * 255 / canvas->width);
      canvas->pixels[y][x].green = (unsigned char)(y * 255 / canvas->height);
      canvas->pixels[y][x].blue = (unsigned char)(0);
    }
  }

  // Write the canvas to a file
  FILE *file = fopen("palette.ppm", "wb");
  if (!file) return -1;
  fprintf(file, "P3\n%d %d\n255\n", canvas->width, canvas->height);
  for (int y = 0; y < canvas->height; y++) {
    for (int x = 0; x < canvas->width; x++) {
      fprintf(file, "%d %d %d\n", canvas->pixels[y][x].red, canvas->pixels[y][x].green, canvas->pixels[y][x].blue);
    }
  }
  fclose(file);

  destroy_canvas(canvas);
  return 0;
}