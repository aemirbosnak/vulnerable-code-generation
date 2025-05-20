//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

char *text;
int width, height;
char *pixels;

void init(char *t, int w, int h) {
  text = t;
  width = w;
  height = h;
  pixels = malloc(width * height);
  memset(pixels, ' ', width * height);
}

void clear() {
  memset(pixels, ' ', width * height);
}

void setPixel(int x, int y, char c) {
  if (x >= 0 && x < width && y >= 0 && y < height) {
    pixels[y * width + x] = c;
  }
}

void drawText() {
  int x = 0, y = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '\n') {
      y++;
      x = 0;
    } else {
      setPixel(x, y, text[i]);
      x++;
    }
  }
}

void printArt() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", pixels[y * width + x]);
    }
    printf("\n");
  }
}

int main() {
  init("Hello, world!", 80, 24);
  drawText();
  printArt();
  clear();
  init("This is some ASCII art!", 80, 24);
  drawText();
  printArt();
  return 0;
}