//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 25
#define HEIGHT 25

typedef struct Pixel {
  int r, g, b;
} Pixel;

Pixel **generateQRcode(char *data) {
  Pixel **qrcode = (Pixel **)malloc(WIDTH * HEIGHT * sizeof(Pixel));
  for (int y = 0; y < HEIGHT; y++) {
    qrcode[y] = (Pixel *)malloc(WIDTH * sizeof(Pixel));
    for (int x = 0; x < WIDTH; x++) {
      qrcode[y][x].r = 0;
      qrcode[y][x].g = 0;
      qrcode[y][x].b = 0;
    }
  }

  int i = 0;
  while (data[i] != '\0') {
    int module = data[i] % 2;
    int x = data[i] / 2 * WIDTH;
    int y = HEIGHT - 1 - module * HEIGHT / 2;
    qrcode[y][x].r = 255;
    qrcode[y][x].g = 255;
    qrcode[y][x].b = 255;
    i++;
  }

  return qrcode;
}

void printQRcode(Pixel **qrcode) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c ", qrcode[y][x].r);
    }
    printf("\n");
  }
}

int main() {
  char data[] = "HELLO WORLD!";
  Pixel **qrcode = generateQRcode(data);
  printQRcode(qrcode);
  free(qrcode);

  return 0;
}