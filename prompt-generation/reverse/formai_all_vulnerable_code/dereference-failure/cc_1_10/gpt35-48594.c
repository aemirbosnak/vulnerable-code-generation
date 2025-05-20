//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define W 1000
#define H 1000

// This function generates a random color for each iteration
int random_color() {
  return rand() % 255;
}

// This function sets the color of the pixel
void set_pixel(int x, int y, int r, int g, int b, unsigned char* image) {
  int index = (x + y * W) * 3;
  image[index] = r;
  image[index + 1] = g;
  image[index + 2] = b;
}

// This function generates the fractal
void generate_fractal(float x, float y, float size, float angle, int depth, unsigned char* image) {
  if (depth == 0) {
    // If we hit the bottom of the recursion, we color the pixel
    int r = random_color();
    int g = random_color();
    int b = random_color();
    set_pixel(x, y, r, g, b, image);
  } else {
    // Otherwise, we generate smaller fractals around the main one
    float new_size = size * 0.5;
    float new_angle = angle + (30 + rand() % 60) * (rand() % 2 == 0 ? -1 : 1);

    generate_fractal(x, y, new_size, angle, depth - 1, image);
    generate_fractal(x + size * cos(angle), y + size * sin(angle), new_size, new_angle, depth - 1, image);
    generate_fractal(x + size * cos(new_angle), y + size * sin(new_angle), new_size, new_angle, depth - 1, image);
    generate_fractal(x + size * cos(angle + M_PI), y + size * sin(angle + M_PI), new_size, angle, depth - 1, image);
  }
}

int main() {
  unsigned char* image = (unsigned char*)malloc(W * H * 3);

  // We clear the image to white
  memset(image, 255, W * H * 3);

  // We generate the fractal
  generate_fractal(W / 2, H / 2, 200, 0, 7, image);

  // We write the image to a file
  FILE* fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P6\n%d %d\n255\n", W, H);
  fwrite(image, 1, W * H * 3, fp);
  fclose(fp);

  free(image);
  return 0;
}