//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 1024
#define ITERATIONS 256

static inline uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  return (uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b;
}

struct fractal {
  int width;
  int height;
  int iterations;
  uint32_t *data;
};

static inline struct fractal *fractal_new(int width, int height, int iterations) {
  struct fractal *f = malloc(sizeof(struct fractal));
  f->width = width;
  f->height = height;
  f->iterations = iterations;
  f->data = malloc(sizeof(uint32_t) * width * height);
  return f;
}

static inline void fractal_free(struct fractal *f) {
  free(f->data);
  free(f);
}

static inline void fractal_render(struct fractal *f) {
  double cx = -0.7;
  double cy = 0.27015;
  double zx, zy, tx, ty;
  int x, y;
  uint32_t *p = f->data;
  for (y = 0; y < f->height; y++) {
    for (x = 0; x < f->width; x++) {
      zx = 1.5 * (x - f->width / 2) / (0.5 * f->width);
      zy = 1.0 * (y - f->height / 2) / (0.5 * f->height);
      int i;
      for (i = 0; i < f->iterations; i++) {
        tx = zx * zx - zy * zy + cx;
        ty = 2.0 * zx * zy + cy;
        zx = tx;
        zy = ty;
        if (zx * zx + zy * zy > 4.0) {
          break;
        }
      }
      *p++ = color(i * 255 / f->iterations, 0, 0);
    }
  }
}

int main(int argc, char **argv) {
  struct fractal *f = fractal_new(WIDTH, HEIGHT, ITERATIONS);
  fractal_render(f);
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P6\n%d %d\n255\n", f->width, f->height);
  fwrite(f->data, sizeof(uint32_t), f->width * f->height, fp);
  fclose(fp);
  fractal_free(f);
  return 0;
}