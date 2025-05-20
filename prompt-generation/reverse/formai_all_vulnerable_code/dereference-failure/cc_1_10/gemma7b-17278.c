//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Pixel Pixel;
struct Pixel {
  int r, g, b, a;
};

Pixel **image;

void initializeImage() {
  image = (Pixel **)malloc(MAX_IMAGE_SIZE * sizeof(Pixel *));
  for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
    image[i] = (Pixel *)malloc(MAX_IMAGE_SIZE * sizeof(Pixel));
    for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
      image[i][j].r = image[i][j].g = image[i][j].b = image[i][j].a = 0;
    }
  }
}

void setImagePixel(int x, int y, int r, int g, int b, int a) {
  if (x < 0 || x >= MAX_IMAGE_SIZE || y < 0 || y >= MAX_IMAGE_SIZE) {
    return;
  }
  image[x][y].r = r;
  image[x][y].g = g;
  image[x][y].b = b;
  image[x][y].a = a;
}

void displayImage() {
  for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
    for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
      printf("%c%c%c%c ", image[i][j].r, image[i][j].g, image[i][j].b, image[i][j].a);
    }
    printf("\n");
  }
}

int main() {
  initializeImage();
  setImagePixel(100, 100, 255, 0, 0, 255);
  setImagePixel(101, 100, 0, 255, 0, 255);
  setImagePixel(102, 100, 0, 0, 255, 255);
  displayImage();

  return 0;
}