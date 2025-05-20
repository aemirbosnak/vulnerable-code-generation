//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int **matrix;
} Image;

Image* create_image(int size) {
  Image *image = (Image*) malloc(sizeof(Image));
  image->size = size;
  image->matrix = malloc(sizeof(int*) * size);

  for (int i = 0; i < size; i++) {
    image->matrix[i] = malloc(sizeof(int) * size);
  }

  return image;
}

void destroy_image(Image *image) {
  for (int i = 0; i < image->size; i++) {
    free(image->matrix[i]);
  }

  free(image->matrix);
  free(image);
}

void print_image(Image *image) {
  for (int i = 0; i < image->size; i++) {
    for (int j = 0; j < image->size; j++) {
      printf("%3d ", image->matrix[i][j]);
    }
    printf("\n");
  }
}

void flip_image(Image *image) {
  for (int i = 0; i < image->size; i++) {
    for (int j = 0, k = image->size - 1; j < k; j++, k--) {
      int tmp = image->matrix[i][j];
      image->matrix[i][j] = image->matrix[i][k];
      image->matrix[i][k] = tmp;
    }
  }
}

void change_brightness(Image *image, int delta) {
  for (int i = 0; i < image->size; i++) {
    for (int j = 0; j < image->size; j++) {
      image->matrix[i][j] += delta;
      if (image->matrix[i][j] < 0) {
        image->matrix[i][j] = 0;
      } else if (image->matrix[i][j] > 255) {
        image->matrix[i][j] = 255;
      }
    }
  }
}

void change_contrast(Image *image, float factor) {
  for (int i = 0; i < image->size; i++) {
    for (int j = 0; j < image->size; j++) {
      image->matrix[i][j] = (int) (factor * image->matrix[i][j]);
      if (image->matrix[i][j] < 0) {
        image->matrix[i][j] = 0;
      } else if (image->matrix[i][j] > 255) {
        image->matrix[i][j] = 255;
      }
    }
  }
}

int main() {
  Image *image = create_image(4);
  image->matrix[0][0] = 10;
  image->matrix[0][1] = 50;
  image->matrix[0][2] = 90;
  image->matrix[0][3] = 130;
  image->matrix[1][0] = 30;
  image->matrix[1][1] = 70;
  image->matrix[1][2] = 110;
  image->matrix[1][3] = 150;
  image->matrix[2][0] = 50;
  image->matrix[2][1] = 90;
  image->matrix[2][2] = 130;
  image->matrix[2][3] = 170;
  image->matrix[3][0] = 70;
  image->matrix[3][1] = 110;
  image->matrix[3][2] = 150;
  image->matrix[3][3] = 190;

  printf("Original image:\n");
  print_image(image);

  printf("\nFlipped image:\n");
  flip_image(image);
  print_image(image);

  printf("\nBrighter image:\n");
  change_brightness(image, 50);
  print_image(image);

  printf("\nHigher contrast image:\n");
  change_contrast(image, 1.5);
  print_image(image);

  destroy_image(image);
  return 0;
}