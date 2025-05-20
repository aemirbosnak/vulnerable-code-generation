//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600

char *screen;

void init_screen() {
  screen = malloc(WIDTH * HEIGHT);
}

void clear_screen() {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    screen[i] = ' ';
  }
}

void draw_line(int x1, int y1, int x2, int y2) {
  float dx = x2 - x1;
  float dy = y2 - y1;
  float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  float x_inc = dx / steps;
  float y_inc = dy / steps;

  float x = x1;
  float y = y1;

  for (int i = 0; i < steps; i++) {
    screen[(int)x + (int)y * WIDTH] = '*';
    x += x_inc;
    y += y_inc;
  }
}

void draw_circle(int cx, int cy, int radius) {
  for (int x = -radius; x <= radius; x++) {
    for (int y = -radius; y <= radius; y++) {
      if (x * x + y * y <= radius * radius) {
        screen[(cx + x) + (cy + y) * WIDTH] = '*';
      }
    }
  }
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  draw_line(x1, y1, x2, y2);
  draw_line(x2, y2, x3, y3);
  draw_line(x3, y3, x1, y1);
}

void draw_text(int x, int y, char *text) {
  for (int i = 0; text[i] != '\0'; i++) {
    screen[x + i + (y * WIDTH)] = text[i];
  }
}

void save_screen(char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  fprintf(file, "P2\n%d %d\n255\n", WIDTH, HEIGHT);

  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    fprintf(file, "%d ", screen[i] == ' ' ? 255 : 0);
  }

  fclose(file);
}

int main() {
  init_screen();

  clear_screen();

  draw_line(0, 0, WIDTH, HEIGHT);
  draw_line(0, HEIGHT, WIDTH, 0);

  draw_circle(WIDTH / 2, HEIGHT / 2, 100);

  draw_triangle(WIDTH / 2 - 50, HEIGHT / 2 - 50, WIDTH / 2 + 50, HEIGHT / 2 - 50,
               WIDTH / 2, HEIGHT / 2 + 50);

  draw_text(10, 10, "Linus Torvalds");

  save_screen("pixel_art.pgm");

  free(screen);

  return 0;
}