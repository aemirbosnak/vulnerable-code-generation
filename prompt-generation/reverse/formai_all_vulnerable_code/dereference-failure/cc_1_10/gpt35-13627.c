//FormAI DATASET v1.0 Category: Image compression ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
  int width;
  int height;
  int **pixels;
} Image;

Image* create_image(int width, int height) {
  Image *img = (Image*)malloc(sizeof(Image));
  int i, j;
  img->width = width;
  img->height = height;
  img->pixels = (int**)malloc(height*sizeof(int*));
  for(i = 0; i < height; i++) {
    img->pixels[i] = (int*)malloc(width*sizeof(int));
    for(j = 0; j < width; j++) {
      img->pixels[i][j] = 0;
    }
  }
  return img;
}

void destroy_image(Image* img) {
  int i;
  for(i = 0; i < img->height; i++) {
    free(img->pixels[i]);
  }
  free(img->pixels);
  free(img);
}

void compress_image(Image* img, int threshold) {
  int i, j;
  for(i = 0; i < img->height; i++) {
    for(j = 0; j < img->width; j++) {
      if(img->pixels[i][j] <= threshold) {
        img->pixels[i][j] = MIN_PIXEL_VALUE;
      } else {
        img->pixels[i][j] = MAX_PIXEL_VALUE;
      }
    }
  }
}

int main() {
  int width = 4;
  int height = 4;
  int pixel_data[4][4] = {
    {100, 200, 150, 50},
    {250, 100, 50, 200},
    {100, 50, 80, 150},
    {120, 210, 100, 180}
  };
  int threshold = 150;

  Image *img = create_image(width, height);
  int i, j;
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      img->pixels[i][j] = pixel_data[i][j];
    }
  }

  compress_image(img, threshold);

  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      printf("%d ", img->pixels[i][j]);
    }
    printf("\n");
  }

  destroy_image(img);
  return 0;
}