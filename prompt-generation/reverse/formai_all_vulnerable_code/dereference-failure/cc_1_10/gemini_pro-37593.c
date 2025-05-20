//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_STR_LEN 64

typedef struct {
  char *color_str;
  unsigned int color_code;
} color_entry;

int main(int argc, char *argv[]) {
  color_entry colors[] = {
    {"black", 0x000000},
    {"white", 0xFFFFFF},
    {"red", 0xFF0000},
    {"green", 0x00FF00},
    {"blue", 0x0000FF},
    {"yellow", 0xFFFF00},
    {"magenta", 0xFF00FF},
    {"cyan", 0x00FFFF},
    {"darkgreen", 0x006400},
    {"darkblue", 0x00008B},
    {"darkcyan", 0x008B8B},
    {"darkmagenta", 0x8B008B},
    {"darkred", 0x8B0000},
    {"darkyellow", 0x8B8B00},
  };

  int num_colors = sizeof(colors) / sizeof(color_entry);

  char *color_str = NULL;
  unsigned int color_code = 0;

  if (argc == 2) {
    color_str = argv[1];
  } else {
    printf("Usage: %s <color>\n", argv[0]);
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_colors; i++) {
    if (strcmp(color_str, colors[i].color_str) == 0) {
      color_code = colors[i].color_code;
      break;
    }
  }

  if (color_code == 0) {
    printf("Invalid color: %s\n", color_str);
    return EXIT_FAILURE;
  }

  printf("Color code for %s: %06X\n", color_str, color_code);

  return EXIT_SUCCESS;
}