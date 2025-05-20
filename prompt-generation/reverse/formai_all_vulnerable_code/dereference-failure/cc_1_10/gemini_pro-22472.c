//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program converts a color code from one format to another.

// The following function converts a color code from RGB to hex.
char *rgb_to_hex(char *rgb) {
  char *hex = malloc(7);
  sscanf(rgb, "%d,%d,%d", &hex[1], &hex[3], &hex[5]);
  hex[0] = '#';
  hex[2] = hex[1] > 9 ? '0' + hex[1] / 10 : hex[1] + '0';
  hex[4] = hex[3] > 9 ? '0' + hex[3] / 10 : hex[3] + '0';
  hex[6] = hex[5] > 9 ? '0' + hex[5] / 10 : hex[5] + '0';
  return hex;
}

// The following function converts a color code from hex to RGB.
char *hex_to_rgb(char *hex) {
  char *rgb = malloc(12);
  sscanf(hex + 1, "%2x%2x%2x", &rgb[0], &rgb[2], &rgb[4]);
  sprintf(rgb, "%d,%d,%d", rgb[0], rgb[2], rgb[4]);
  return rgb;
}

// The following function converts a color code from one format to another.
char *convert_color_code(char *color_code, char *from, char *to) {
  if (strcmp(from, "rgb") == 0 && strcmp(to, "hex") == 0) {
    return rgb_to_hex(color_code);
  } else if (strcmp(from, "hex") == 0 && strcmp(to, "rgb") == 0) {
    return hex_to_rgb(color_code);
  } else {
    printf("Error: Invalid color code format conversion.\n");
    return NULL;
  }
}

// The following function prints the usage of the program.
void print_usage() {
  printf("Usage: color_code_converter <color_code> <from> <to>\n");
  printf("Where:\n");
  printf("  <color_code> is the color code to convert.\n");
  printf("  <from> is the original format of the color code.\n");
  printf("  <to> is the desired format of the color code.\n");
}

// The following function is the main function of the program.
int main(int argc, char **argv) {
  if (argc != 4) {
    print_usage();
    return 1;
  }

  char *color_code = argv[1];
  char *from = argv[2];
  char *to = argv[3];

  char *converted_color_code = convert_color_code(color_code, from, to);
  if (converted_color_code == NULL) {
    return 1;
  }

  printf("%s\n", converted_color_code);

  free(converted_color_code);

  return 0;
}