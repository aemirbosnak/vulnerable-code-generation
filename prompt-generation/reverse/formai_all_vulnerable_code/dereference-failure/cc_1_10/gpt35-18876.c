//FormAI DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Pixel {
  int r;
  int g;
  int b;
} Pixel;

typedef struct Fractal {
  Pixel** pixels;
  int width;
  int height;
} Fractal;

Pixel* createPixel(int r, int g, int b) {
  Pixel* pixel = malloc(sizeof(Pixel));
  pixel->r = r;
  pixel->g = g;
  pixel->b = b;
  return pixel;
}

void destroyPixel(Pixel* pixel) {
  free(pixel);
}

Fractal* createFractal(int width, int height) {
  Fractal* fractal = malloc(sizeof(Fractal));
  fractal->width = width;
  fractal->height = height;
  fractal->pixels = malloc(sizeof(Pixel*) * width);
  for (int i = 0; i < width; i++) {
    fractal->pixels[i] = malloc(sizeof(Pixel) * height);
    for (int j = 0; j < height; j++) {
      fractal->pixels[i][j] = *createPixel(0, 0, 0);
    }
  }
  return fractal;
}

void destroyFractal(Fractal* fractal) {
  for (int i = 0; i < fractal->width; i++) {
    free(fractal->pixels[i]);
  }
  free(fractal->pixels);
  free(fractal);
}

Pixel* getColor(double iter) {
  int r = iter * 255;
  int g = (1 - iter) * 255;
  int b = (iter - 0.5) * 255;
  return createPixel(r, g, b);
}

void fractalGeneration(Fractal* fractal, double zoom, double offsetX, double offsetY, int limit) {
  for (int x = 0; x < fractal->width; x++) {
    for (int y = 0; y < fractal->height; y++) {
      double zx = 1.5 * (x - fractal->width / 2) / (0.5 * zoom * fractal->width) + offsetX;
      double zy = 1.0 * (y - fractal->height / 2) / (0.5 * zoom * fractal->height) + offsetY;
      double i = limit;
      while (i > 0) {
        double r = zx * zx - zy * zy;
        double iNew = 2 * zx * zy;
        zx = r + -0.726895 * -0.8;
        zy = iNew + -0.188887 * -0.8;
        if ((zx * zx + zy * zy) > 4) break;
        i--;
      }
      Pixel* color = getColor(i / limit);
      fractal->pixels[x][y] = *color;
      destroyPixel(color);
    }
  }
}

void writeFractal(Fractal* fractal, char* filename) {
  FILE* file = fopen(filename, "wb");
  fprintf(file, "P6 %d %d 255\n", fractal->width, fractal->height);
  for (int i = 0; i < fractal->width * fractal->height; i++) {
    fwrite(&fractal->pixels[i / fractal->width][i % fractal->height].r, 1, 1, file);
    fwrite(&fractal->pixels[i / fractal->width][i % fractal->height].g, 1, 1, file);
    fwrite(&fractal->pixels[i / fractal->width][i % fractal->height].b, 1, 1, file);
  }
  fclose(file);
}

int main() {
  clock_t start = clock();
  Fractal* fractal = createFractal(1920, 1080);
  fractalGeneration(fractal, 1, 0, 0, 1000);
  writeFractal(fractal, "fractal.ppm");
  destroyFractal(fractal);
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Fractal generation took %f seconds.\n", time_spent);
  return 0;
}