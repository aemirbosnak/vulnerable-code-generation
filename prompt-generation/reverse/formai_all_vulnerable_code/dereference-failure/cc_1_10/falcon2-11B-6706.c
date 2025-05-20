//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_COLOR 256

typedef struct {
  int rows;
  int cols;
  int *data;
} Image;

void init_image(Image *image) {
  image->rows = MAX_ROWS;
  image->cols = MAX_COLS;
  image->data = (int *)malloc(image->rows * image->cols * sizeof(int));
}

void free_image(Image *image) {
  free(image->data);
}

void load_image(const char *filename, Image *image) {
  // TODO: load image from file
}

void save_image(const char *filename, Image *image) {
  // TODO: save image to file
}

void display_image(Image *image) {
  int i, j;
  for (i = 0; i < image->rows; i++) {
    for (j = 0; j < image->cols; j++) {
      printf("%d ", image->data[i * image->cols + j]);
    }
    printf("\n");
  }
}

void edit_image(Image *image, int row, int col, int color) {
  int i, j;
  for (i = row; i < image->rows; i++) {
    for (j = col; j < image->cols; j++) {
      if (i * image->cols + j == row * image->cols + col) {
        image->data[i * image->cols + j] = color;
      }
    }
  }
}

int main() {
  Image image;
  init_image(&image);

  load_image("image.jpg", &image);
  display_image(&image);

  edit_image(&image, 0, 0, 255);
  display_image(&image);

  save_image("edited_image.jpg", &image);

  free_image(&image);

  return 0;
}