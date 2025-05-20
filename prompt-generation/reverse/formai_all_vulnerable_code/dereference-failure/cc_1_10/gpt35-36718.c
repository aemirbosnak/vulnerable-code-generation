//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>

#define WIDTH 180
#define HEIGHT 60
#define CHARS_PER_PIXEL 2

char grayscale_to_char(int);

int main(int argc, char *argv[]) {
  FILE *image_file;
  char pixels[WIDTH][HEIGHT][CHARS_PER_PIXEL];
  int i, j, k;

  if (argc < 2) {
    printf("Usage: ./img2ascii [path to image]\n");
    return 1; 
  }

  if (!(image_file = fopen(argv[1], "r"))) {
    printf("Error: Invalid file path.\n");
    return 1;
  }

  fseek(image_file, 18, SEEK_SET);

  if (fread(pixels, 1, WIDTH * HEIGHT * CHARS_PER_PIXEL, image_file) !=
      WIDTH * HEIGHT * CHARS_PER_PIXEL) {
    printf("Error: Could not read image.\n");
    return 1;
  }

  fclose(image_file);

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%c", grayscale_to_char(pixels[j][i][0]));
    }
    printf("\n");
  }

  return 0;
}

char grayscale_to_char(int value) {
  char chars[] =
      "$@B%8&WM#*oahkbdpwmZO0QCJYXNHY>~;:-.^_,\"'` ";
  int num_chars = sizeof(chars) - 1;
  int char_index = value * num_chars / 256;
  return chars[char_index];
}