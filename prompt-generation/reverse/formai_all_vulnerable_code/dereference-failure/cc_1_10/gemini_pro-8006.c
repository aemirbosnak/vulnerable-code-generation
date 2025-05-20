//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char *banner = "Apocalypse Now!";
char *chars = " .:-=+*#%@";

unsigned char *image;
char *ascii;

void load_image(char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    perror("Error opening image file");
    exit(1);
  }
  image = malloc(WIDTH * HEIGHT);
  fread(image, 1, WIDTH * HEIGHT, f);
  fclose(f);
}

void create_ascii() {
  ascii = malloc(WIDTH * HEIGHT);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int index = image[y * WIDTH + x];
      ascii[y * WIDTH + x] = chars[index % strlen(chars)];
    }
  }
}

void print_ascii() {
  printf("%s\n", banner);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", ascii[y * WIDTH + x]);
    }
    printf("\n");
  }
}

void free_resources() {
  free(image);
  free(ascii);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <image_filename>\n", argv[0]);
    exit(1);
  }

  load_image(argv[1]);
  create_ascii();
  print_ascii();
  free_resources();

  return 0;
}