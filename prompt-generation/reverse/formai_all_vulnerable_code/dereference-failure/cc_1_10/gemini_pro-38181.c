//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Convert a hexadecimal color code to its RGB equivalent.
 *
 * @param hex The hexadecimal color code.
 * @param rgb The RGB equivalent of the hexadecimal color code.
 */
void hex_to_rgb(const char *hex, char *rgb) {
  int r, g, b;

  sscanf(hex, "%2x%2x%2x", &r, &g, &b);

  sprintf(rgb, "%d,%d,%d", r, g, b);
}

/*
 * Convert an RGB color code to its hexadecimal equivalent.
 *
 * @param rgb The RGB color code.
 * @param hex The hexadecimal equivalent of the RGB color code.
 */
void rgb_to_hex(const char *rgb, char *hex) {
  int r, g, b;

  sscanf(rgb, "%d,%d,%d", &r, &g, &b);

  sprintf(hex, "%02x%02x%02x", r, g, b);
}

/*
 * Main function.
 */
int main(int argc, char *argv[]) {
  char hex[7];
  char rgb[12];

  if (argc != 2) {
    printf("Usage: %s <hexadecimal color code>\n", argv[0]);
    exit(1);
  }

  strcpy(hex, argv[1]);

  if (strlen(hex) != 6) {
    printf("Invalid hexadecimal color code: %s\n", hex);
    exit(1);
  }

  hex_to_rgb(hex, rgb);

  printf("The RGB equivalent of %s is %s\n", hex, rgb);

  rgb_to_hex(rgb, hex);

  printf("The hexadecimal equivalent of %s is %s\n", rgb, hex);

  return 0;
}