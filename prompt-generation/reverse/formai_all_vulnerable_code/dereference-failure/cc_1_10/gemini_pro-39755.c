//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 50

char *image[HEIGHT];
char *ascii[HEIGHT];

void loadImage(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < HEIGHT; i++) {
    image[i] = malloc(WIDTH);
    if (image[i] == NULL) {
      perror("malloc");
      exit(EXIT_FAILURE);
    }

    fread(image[i], 1, WIDTH, fp);
  }

  fclose(fp);
}

void convertImageToAscii() {
  for (int i = 0; i < HEIGHT; i++) {
    ascii[i] = malloc(WIDTH + 1);
    if (ascii[i] == NULL) {
      perror("malloc");
      exit(EXIT_FAILURE);
    }

    for (int j = 0; j < WIDTH; j++) {
      double brightness = (double)image[i][j] / 255.0;
      char *symbol;

      if (brightness < 0.2) {
        symbol = "█";
      } else if (brightness < 0.4) {
        symbol = "▓";
      } else if (brightness < 0.6) {
        symbol = "▒";
      } else if (brightness < 0.8) {
        symbol = "░";
      } else {
        symbol = " ";
      }

      strcat(ascii[i], symbol);
    }

    ascii[i][WIDTH] = '\0';
  }
}

void printAsciiImage() {
  for (int i = 0; i < HEIGHT; i++) {
    printf("%s\n", ascii[i]);
  }
}

void freeMemory() {
  for (int i = 0; i < HEIGHT; i++) {
    free(image[i]);
    free(ascii[i]);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  loadImage(argv[1]);
  convertImageToAscii();
  printAsciiImage();
  freeMemory();

  return 0;
}