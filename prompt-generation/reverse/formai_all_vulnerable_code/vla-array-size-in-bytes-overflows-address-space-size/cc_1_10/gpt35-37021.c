//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate and print pixel art */
void generate_pixel_art(int width, int height) {
  char pixel_art[height][width];
  int i, j;

  /* Initialize random seed */
  srand(time(NULL));

  /* Generate random pixel art */
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      /* Randomly generate shape shifting style */
      int shape_shift = rand() % 4;

      switch (shape_shift) {
        case 0:
          pixel_art[i][j] = '-';
          break;
        case 1:
          pixel_art[i][j] = '|';
          break;
        case 2:
          pixel_art[i][j] = '/';
          break;
        case 3:
          pixel_art[i][j] = '\\';
          break;
        default:
          pixel_art[i][j] = ' ';
      }
    }
  }

  /* Print pixel art */
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%c ", pixel_art[i][j]);
    }
    printf("\n");
  }
}

/* Main function */
int main() {
  int width, height;

  /* Prompt user for input dimensions */
  printf("Enter width and height of pixel art:\n");
  scanf("%d %d", &width, &height);

  /* Generate and print pixel art */
  generate_pixel_art(width, height);

  return 0;
}