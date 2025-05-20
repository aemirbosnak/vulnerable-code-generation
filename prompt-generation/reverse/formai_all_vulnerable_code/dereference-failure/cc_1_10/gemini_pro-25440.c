//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the RGB color codes
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Define the reset color code
#define RESET "\x1B[0m"

// Print a color-coded string
void print_color(const char* color, const char* string) {
  printf("%s%s%s", color, string, RESET);
}

// Convert a hex color code to RGB
void hex_to_rgb(char* hex, int* r, int* g, int* b) {
  *r = strtol(hex + 1, NULL, 16);
  *g = strtol(hex + 3, NULL, 16);
  *b = strtol(hex + 5, NULL, 16);
}

// Convert an RGB color code to hex
char* rgb_to_hex(int r, int g, int b) {
  static char hex[7];
  sprintf(hex, "#%02X%02X%02X", r, g, b);
  return hex;
}

// Print a color palette
void print_palette() {
  printf("Color Palette:\n");
  print_color(BLACK, "Black\n");
  print_color(RED, "Red\n");
  print_color(GREEN, "Green\n");
  print_color(YELLOW, "Yellow\n");
  print_color(BLUE, "Blue\n");
  print_color(MAGENTA, "Magenta\n");
  print_color(CYAN, "Cyan\n");
  print_color(WHITE, "White\n");
}

int main() {
  // Get the input hex color code
  char hex[7];
  printf("Enter a hex color code (e.g., #FF0000): ");
  scanf("%s", hex);

  // Convert the hex color code to RGB
  int r, g, b;
  hex_to_rgb(hex, &r, &g, &b);

  // Print the RGB color code
  printf("RGB Color Code: %d, %d, %d\n", r, g, b);

  // Convert the RGB color code to hex
  char* new_hex = rgb_to_hex(r, g, b);

  // Print the hex color code
  printf("New Hex Color Code: %s\n", new_hex);

  // Print the color palette
  print_palette();

  return 0;
}