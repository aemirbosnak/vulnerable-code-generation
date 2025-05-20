//FormAI DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 4

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

typedef struct {
  Pixel *pixels;
  int w;
  int h;
} Image;

typedef struct {
  Image *image;
  int start;
  int end;
} ThreadArgs;

void *grayScale(void *arg) {
  ThreadArgs *args = (ThreadArgs*)arg;
  Image *image = args->image;
  int start = args->start;
  int end = args->end;
  for (int i = start; i < end; i++) {
    Pixel *p = &image->pixels[i];
    unsigned int average = (p->r + p->g + p->b) / 3;
    p->r = average;
    p->g = average;
    p->b = average;
  }
  pthread_exit(NULL);
}

void *flipHorizontal(void *arg) {
  ThreadArgs *args = (ThreadArgs*)arg;
  Image *image = args->image;
  int start = args->start;
  int end = args->end;
  int width = image->w;
  for (int i = start; i < end; i++) {
    int row = i / width;
    int col1 = i % width;
    int col2 = width - col1 - 1;
    if (col1 < col2) {
      Pixel tmp = image->pixels[row * width + col1];
      image->pixels[row * width + col1] = image->pixels[row * width + col2];
      image->pixels[row * width + col2] = tmp;
    }
  }
  pthread_exit(NULL);
}

void *flipVertical(void *arg) {
  ThreadArgs *args = (ThreadArgs*)arg;
  Image *image = args->image;
  int start = args->start;
  int end = args->end;
  int width = image->w;
  int height = image->h;
  for (int i = start; i < end; i++) {
    int row1 = i / width;
    int row2 = height - row1 - 1;
    int col = i % width;
    if (row1 < row2) {
      Pixel tmp = image->pixels[row1 * width + col];
      image->pixels[row1 * width + col] = image->pixels[row2 * width + col];
      image->pixels[row2 * width + col] = tmp;
    }
  }
  pthread_exit(NULL);
}

void *invertColors(void *arg) {
  ThreadArgs *args = (ThreadArgs*)arg;
  Image *image = args->image;
  int start = args->start;
  int end = args->end;
  for (int i = start; i < end; i++) {
    Pixel *p = &image->pixels[i];
    p->r = 255 - p->r;
    p->g = 255 - p->g;
    p->b = 255 - p->b;
  }
  pthread_exit(NULL);
}

void applyFilters(Image *image) {
  pthread_t threads[N_THREADS];
  int chunk = (image->w * image->h) / N_THREADS;
  int remainder = (image->w * image->h) % N_THREADS;
  ThreadArgs args[N_THREADS];
  int start = 0;
  int end = 0;
  for (int i = 0; i < N_THREADS; i++) {
    end = start + chunk;
    if (i < remainder) {
      end++;
    }
    args[i].image = image;
    args[i].start = start;
    args[i].end = end;
    if (i == 0) {
      pthread_create(&threads[i], NULL, grayScale, &args[i]);
    } else if (i == 1) {
      pthread_create(&threads[i], NULL, flipHorizontal, &args[i]);
    } else if (i == 2) {
      pthread_create(&threads[i], NULL, flipVertical, &args[i]);
    } else if (i == 3) {
      pthread_create(&threads[i], NULL, invertColors, &args[i]);
    }
    start = end;
  }
  for (int i = 0; i < N_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s input.ppm\n", argv[0]);
    return 1;
  }
  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }
  char magic[3];
  int width, height, maxval;
  fscanf(f, "%2s\n%d %d\n%d\n", magic, &width, &height, &maxval);
  if (magic[0] != 'P' || magic[1] != '6') {
    fprintf(stderr, "Invalid header format.\n");
    return 1;
  }
  Image image;
  image.w = width;
  image.h = height;
  image.pixels = malloc(sizeof(Pixel) * width * height);
  fread(image.pixels, sizeof(Pixel), width * height, f);
  fclose(f);
  applyFilters(&image);
  f = fopen("output.ppm", "wb");
  fprintf(f, "P6\n%d %d\n255\n", image.w, image.h);
  fwrite(image.pixels, sizeof(Pixel), image.w * image.h, f);
  fclose(f);
  free(image.pixels);
  return 0;
}