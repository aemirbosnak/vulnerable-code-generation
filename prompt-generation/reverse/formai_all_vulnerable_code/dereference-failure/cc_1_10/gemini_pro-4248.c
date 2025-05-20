//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char *image[HEIGHT];
int histogram[256];

void read_image(FILE *fp) {
  for (int i = 0; i < HEIGHT; i++) {
    image[i] = malloc(WIDTH + 1);
    fread(image[i], 1, WIDTH, fp);
    image[i][WIDTH] = '\0';
  }
}

void write_image(FILE *fp) {
  for (int i = 0; i < HEIGHT; i++) {
    fwrite(image[i], 1, WIDTH, fp);
    fwrite("\n", 1, 1, fp);
  }
}

void create_histogram() {
  memset(histogram, 0, sizeof(histogram));
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      histogram[(unsigned char)image[i][j]]++;
    }
  }
}

void print_histogram() {
  for (int i = 0; i < 256; i++) {
    printf("%3d: %d\n", i, histogram[i]);
  }
}

void convert_to_ascii() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int brightness = (unsigned char)image[i][j];
      char *characters = " .:-=+*#%@";
      int index = brightness * (strlen(characters) - 1) / 255;
      image[i][j] = characters[index];
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
    return 1;
  }

  FILE *input_fp = fopen(argv[1], "rb");
  if (input_fp == NULL) {
    perror("fopen");
    return 1;
  }

  FILE *output_fp = fopen(argv[2], "wb");
  if (output_fp == NULL) {
    perror("fopen");
    return 1;
  }

  read_image(input_fp);
  create_histogram();
  convert_to_ascii();
  write_image(output_fp);

  fclose(input_fp);
  fclose(output_fp);

  return 0;
}