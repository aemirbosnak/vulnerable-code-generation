//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
  char *name;
  char *hex_code;
} color_code;

color_code color_codes[] = {
  { "Black", "#000000" },
  { "White", "#FFFFFF" },
  { "Red", "#FF0000" },
  { "Green", "#00FF00" },
  { "Blue", "#0000FF" },
  { "Yellow", "#FFFF00" },
  { "Magenta", "#FF00FF" },
  { "Cyan", "#00FFFF" },
  { "Orange", "#FFA500" },
  { "Purple", "#800080" },
  { "Brown", "#A52A2A" },
  { "Gray", "#808080" },
  { "Silver", "#C0C0C0" },
  { "Gold", "#FFD700" },
  { "Bronze", "#CD7F32" },
  { "Copper", "#B87333" },
  { "Brass", "#B5A642" },
  { "Aluminum", "#A9ACB0" },
  { "Steel", "#404040" },
  { "Iron", "#804040" },
  { "Cobalt", "#0047AB" },
  { "Nickel", "#72747D" },
  { "Copper", "#B87333" }
};

const int num_color_codes = sizeof(color_codes) / sizeof(color_codes[0]);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <color code>\n", argv[0]);
    return 1;
  }

  char *color_code = argv[1];

  if (strlen(color_code) != MAX_COLOR_CODE_LENGTH) {
    printf("Invalid color code: %s\n", color_code);
    return 1;
  }

  for (int i = 0; i < num_color_codes; i++) {
    if (strcmp(color_code, color_codes[i].hex_code) == 0) {
      printf("%s: %s\n", color_code, color_codes[i].name);
      return 0;
    }
  }

  printf("Unknown color code: %s\n", color_code);
  return 1;
}