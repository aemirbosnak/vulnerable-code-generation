//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LINUX
#include <sys/mman.h>
#include <fcntl.h>
#endif

#define WIDTH 640
#define HEIGHT 480

typedef struct {
  unsigned char r, g, b;
} pixel_t;

pixel_t *pixels;

void load_image(const char *filename) {
#ifdef LINUX
  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    perror("open");
    exit(1);
  }

  pixels = mmap(NULL, WIDTH * HEIGHT * sizeof(pixel_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (pixels == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  close(fd);
#else
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  pixels = malloc(WIDTH * HEIGHT * sizeof(pixel_t));
  if (pixels == NULL) {
    perror("malloc");
    exit(1);
  }

  fread(pixels, sizeof(pixel_t), WIDTH * HEIGHT, fp);
  fclose(fp);
#endif
}

void save_image(const char *filename) {
#ifdef LINUX
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    perror("open");
    exit(1);
  }

  if (write(fd, pixels, WIDTH * HEIGHT * sizeof(pixel_t)) < 0) {
    perror("write");
    exit(1);
  }

  close(fd);
#else
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  fwrite(pixels, sizeof(pixel_t), WIDTH * HEIGHT, fp);
  fclose(fp);
#endif
}

void invert_image() {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    pixels[i].r = 255 - pixels[i].r;
    pixels[i].g = 255 - pixels[i].g;
    pixels[i].b = 255 - pixels[i].b;
  }
}

void grayscale_image() {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    unsigned char gray = (pixels[i].r + pixels[i].g + pixels[i].b) / 3;
    pixels[i].r = gray;
    pixels[i].g = gray;
    pixels[i].b = gray;
  }
}

void blur_image() {
  pixel_t *temp = malloc(WIDTH * HEIGHT * sizeof(pixel_t));
  if (temp == NULL) {
    perror("malloc");
    exit(1);
  }

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      int sumr = 0, sumg = 0, sumb = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          int x = i + k, y = j + l;
          if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            sumr += pixels[y * WIDTH + x].r;
            sumg += pixels[y * WIDTH + x].g;
            sumb += pixels[y * WIDTH + x].b;
          }
        }
      }
      temp[j * WIDTH + i].r = sumr / 9;
      temp[j * WIDTH + i].g = sumg / 9;
      temp[j * WIDTH + i].b = sumb / 9;
    }
  }

  memcpy(pixels, temp, WIDTH * HEIGHT * sizeof(pixel_t));
  free(temp);
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
    exit(1);
  }

  load_image(argv[1]);

  // TODO: Process the image here

  save_image(argv[2]);

  return 0;
}