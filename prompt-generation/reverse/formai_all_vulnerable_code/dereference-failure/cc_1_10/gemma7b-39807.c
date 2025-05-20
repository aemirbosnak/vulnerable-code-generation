//Gemma-7B DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct Pixel Pixel;
struct Pixel {
  int r, g, b, a;
  Pixel *next;
};

Pixel *createPixel(int r, int g, int b, int a) {
  Pixel *pixel = malloc(sizeof(Pixel));
  pixel->r = r;
  pixel->g = g;
  pixel->b = b;
  pixel->a = a;
  pixel->next = NULL;
  return pixel;
}

void drawPixel(Pixel *pixel) {
  printf("\033[48;2;%d;%d;%dm", pixel->r, pixel->g, pixel->b);
  printf("%c", pixel->a);
}

void drawLine(Pixel *start, Pixel *end) {
  Pixel *pixel = start;
  while (pixel != end) {
    drawPixel(pixel);
    pixel = pixel->next;
  }
}

int main() {
  Pixel *pixelList = createPixel(0, 0, 0, 255);
  Pixel *head = pixelList;

  // Draw a horizontal line
  drawLine(head, createPixel(255, 0, 0, 255));

  // Draw a vertical line
  drawLine(head, createPixel(0, 255, 0, 255));

  // Draw a diagonal line
  drawLine(head, createPixel(255, 255, 0, 255));

  return 0;
}