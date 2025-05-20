//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
  char *name;
  char *hex_code;
} color;

color colors[] = {
  { "black", "#000000" },
  { "white", "#ffffff" },
  { "red", "#ff0000" },
  { "green", "#00ff00" },
  { "blue", "#0000ff" },
  { "yellow", "#ffff00" },
  { "magenta", "#ff00ff" },
  { "cyan", "#00ffff" },
  { "orange", "#ffa500" },
  { "purple", "#800080" },
  { "brown", "#a52a2a" },
  { "gray", "#808080" },
  { "pink", "#ffc0cb" },
  { "gold", "#ffd700" },
  { "silver", "#c0c0c0" },
  { "bronze", "#cd7f32" },
  { "olive", "#808000" },
  { "teal", "#008080" },
  { "navy", "#000080" },
  { "maroon", "#800000" },
  { "lime", "#00ff00" },
  { "aqua", "#00ffff" },
  { "fuchsia", "#ff00ff" },
  { "wheat", "#f5deb3" },
  { "salmon", "#fa8072" },
  { "khaki", "#f0e68c" },
  { "lavender", "#e6e6fa" },
  { "beige", "#f5f5dc" },
  { "mint", "#00ff00" },
  { "coral", "#ff7256" },
  { "plum", "#dda0dd" },
  { "turquoise", "#00ffff" },
  { "indigo", "#4b0082" },
  { "violet", "#800080" },
  { "tan", "#d2b48c" },
  { "peach", "#ffe5b4" },
  { "azure", "#007fff" },
  { "jade", "#00ff00" },
  { "cerulean", "#007ba7" },
  { "lilac", "#c8a2c8" },
  { "sage", "#87ae73" },
  { "apricot", "#ff8366" },
  { "navy", "#000080" },
  { "teal", "#008080" },
  { "olive", "#808000" },
  { "khaki", "#f0e68c" },
  { "wheat", "#f5deb3" },
  { "tan", "#d2b48c" },
  { "peach", "#ffe5b4" },
  { "coral", "#ff7256" },
  { "salmon", "#fa8072" },
  { "beige", "#f5f5dc" },
  { "lavender", "#e6e6fa" },
  { "plum", "#dda0dd" },
  { "violet", "#800080" },
  { "lilac", "#c8a2c8" },
  { "indigo", "#4b0082" },
  { "cerulean", "#007ba7" },
  { "azure", "#007fff" },
  { "turquoise", "#00ffff" },
  { "aqua", "#00ffff" },
  { "lime", "#00ff00" },
  { "mint", "#00ff00" },
  { "jade", "#00ff00" },
  { "sage", "#87ae73" },
  { "bronze", "#cd7f32" },
  { "gold", "#ffd700" },
  { "silver", "#c0c0c0" },
  { "gray", "#808080" },
  { "black", "#000000" },
  { "white", "#ffffff" },
};

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
    return 1;
  }

  char *color_name = argv[1];

  for (int i = 0; i < sizeof(colors) / sizeof(color); i++) {
    if (strcmp(color_name, colors[i].name) == 0) {
      printf("%s\n", colors[i].hex_code);
      return 0;
    }
  }

  fprintf(stderr, "Error: color \"%s\" not found.\n", color_name);
  return 1;
}