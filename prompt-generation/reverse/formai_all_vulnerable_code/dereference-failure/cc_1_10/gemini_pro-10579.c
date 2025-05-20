//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_NAMES_LENGTH 12
#define COLOR_CODES_LENGTH 3

typedef struct {
  char *name;
  int r, g, b;
} Color;

Color colors[] = {
  { "red", 255, 0, 0 },
  { "green", 0, 255, 0 },
  { "blue", 0, 0, 255 },
  { "white", 255, 255, 255 },
  { "black", 0, 0, 0 },
  { "yellow", 255, 255, 0 },
  { "magenta", 255, 0, 255 },
  { "cyan", 0, 255, 255 },
  { "gray", 128, 128, 128 },
  { "pink", 255, 192, 203 },
  { "orange", 255, 165, 0 },
  { "purple", 128, 0, 128 },
};

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
    exit(1);
  }

  char *colorName = argv[1];
  int colorIndex = -1;

  for (int i = 0; i < COLOR_NAMES_LENGTH; i++) {
    if (strcmp(colorName, colors[i].name) == 0) {
      colorIndex = i;
      break;
    }
  }

  if (colorIndex == -1) {
    fprintf(stderr, "Error: Invalid color name \"%s\"\n", colorName);
    exit(1);
  }

  printf("Color code: #%02x%02x%02x\n", colors[colorIndex].r, colors[colorIndex].g, colors[colorIndex].b);

  return 0;
}