//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

typedef struct Pixel {
  int r, g, b;
  struct Pixel* next;
} Pixel;

Pixel* createPixel(int r, int g, int b) {
  Pixel* pixel = (Pixel*)malloc(sizeof(Pixel));
  pixel->r = r;
  pixel->g = g;
  pixel->b = b;
  pixel->next = NULL;
  return pixel;
}

void drawPixel(Pixel* pixel) {
  printf("(%d, %d, %d) ", pixel->r, pixel->g, pixel->b);
}

void convertImageToAscii(Pixel* pixel) {
  switch (pixel->r) {
    case 0:
      printf(" ");
      break;
    case 1:
      printf(".");
      break;
    case 2:
      printf("$");
      break;
    case 3:
      printf("%");
      break;
    case 4:
      printf("#");
      break;
    default:
      printf("?");
  }
  switch (pixel->g) {
    case 0:
      printf(" ");
      break;
    case 1:
      printf(".");
      break;
    case 2:
      printf("$");
      break;
    case 3:
      printf("%");
      break;
    case 4:
      printf("#");
      break;
    default:
      printf("?");
  }
  switch (pixel->b) {
    case 0:
      printf(" ");
      break;
    case 1:
      printf(".");
      break;
    case 2:
      printf("$");
      break;
    case 3:
      printf("%");
      break;
    case 4:
      printf("#");
      break;
    default:
      printf("?");
  }
  printf(" ");
}

int main() {
  Pixel* pixel = createPixel(255, 255, 255);
  drawPixel(pixel);
  printf("\n");

  pixel = createPixel(0, 0, 0);
  drawPixel(pixel);
  printf("\n");

  pixel = createPixel(255, 0, 0);
  drawPixel(pixel);
  printf("\n");

  convertImageToAscii(pixel);

  return 0;
}