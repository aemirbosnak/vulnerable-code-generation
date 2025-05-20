//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#define _CRYPTIC_ASCII_CONV_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 31
#define HEIGHT 11

typedef struct { char symbol; int r, g, b; } pixel;

const char art[HEIGHT][WIDTH] = {
  "#######################################",
  "##                                   ##",
  "##      ______          ______       ##",
  "##     |    |        |    |         ##",
  "##     |____|        |____|         ##",
  "##               ______               ##",
  "##              |   _   |              ##",
  "##              |  |_|  |              ##",
  "##              |  | _ | |              ##",
  "##              | _|___| |____________ ##",
  "##              |________|             ##",
  "##                                   ##",
  "#######################################"
};

void rgb2ascii(int r, int g, int b) {
  const char *ascii_map =
    "   !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  int i;

  for (i = 0; r > 0; i++) {
    if (r < 33) r += 33;
    r -= 33;
    r /= 8;
    g += r;
    r = g % 33;
    g /= 8;
    b += g;
    g = b % 33;
    b /= 8;
  }

  putchar(ascii_map[g]);
  putchar(ascii_map[r]);
  putchar(ascii_map[b]);
}

int main() {
  int i, j;
  int width, height;
  pixel *image;

  height = HEIGHT;
  width = WIDTH;

  image = malloc(width * height * sizeof(pixel));

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++) {
      image[i * width + j].symbol = art[i][j];
      image[i * width + j].r = i * 16 + j / 2;
      image[i * width + j].g = i * 11 + j;
      image[i * width + j].b = j * 11 + i;
    }

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      rgb2ascii(image[i * width + j].r, image[i * width + j].g, image[i * width + j].b);

  free(image);

  return 0;
}