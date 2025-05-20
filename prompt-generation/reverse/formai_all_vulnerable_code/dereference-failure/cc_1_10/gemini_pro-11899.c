//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
  int width;
  int height;
  char **pixels;
} Image;

Image *create_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    image->pixels[i] = malloc(width);
  }
  return image;
}

void destroy_image(Image *image) {
  for (int i = 0; i < image->height; i++) {
    free(image->pixels[i]);
  }
  free(image->pixels);
  free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->pixels[y][x] = c;
}

char get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return ' ';
  }
  return image->pixels[y][x];
}

void print_image(Image *image) {
  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      printf("%c", get_pixel(image, j, i));
    }
    printf("\n");
  }
}

int main() {
  Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);

  // Draw a triangle
  for (int i = 0; i < MAX_HEIGHT; i++) {
    for (int j = 0; j < i; j++) {
      set_pixel(image, j, i, '*');
    }
  }

  // Draw a circle
  for (int i = 0; i < MAX_HEIGHT; i++) {
    for (int j = 0; j < MAX_WIDTH; j++) {
      if ((j - MAX_WIDTH / 2) * (j - MAX_WIDTH / 2) + (i - MAX_HEIGHT / 2) * (i - MAX_HEIGHT / 2) <= MAX_WIDTH * MAX_HEIGHT / 4) {
        set_pixel(image, j, i, '*');
      }
    }
  }

  // Draw a spiral
  int x = MAX_WIDTH / 2;
  int y = MAX_HEIGHT / 2;
  int dx = 0;
  int dy = -1;
  for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
    set_pixel(image, x, y, '*');
    int nx = x + dx;
    int ny = y + dy;
    if (nx < 0 || nx >= MAX_WIDTH || ny < 0 || ny >= MAX_HEIGHT || get_pixel(image, nx, ny) != ' ') {
      int temp = dx;
      dx = -dy;
      dy = temp;
      nx = x + dx;
      ny = y + dy;
    }
    x = nx;
    y = ny;
  }

  // Print the image
  print_image(image);

  // Destroy the image
  destroy_image(image);

  return 0;
}