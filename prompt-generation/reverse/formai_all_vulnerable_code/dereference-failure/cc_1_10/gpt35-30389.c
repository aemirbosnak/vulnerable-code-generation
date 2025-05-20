//FormAI DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

char* hexToRgb(char* hexValue) {
  // convert hex to RGB
  int r, g, b;
  sscanf(hexValue, "#%02x%02x%02x", &r, &g, &b);
  // allocate memory for the rgb string
  char* rgbValue = (char*)malloc(16 * sizeof(char));
  // format the rgb string
  sprintf(rgbValue, "%d,%d,%d", r, g, b);
  return rgbValue;
}

char* rgbToHex(char* rgbValue) {
  // convert RGB to hex
  int r, g, b;
  sscanf(rgbValue, "%d,%d,%d", &r, &g, &b);
  // allocate memory for the hex string
  char* hexValue = (char*)malloc(8 * sizeof(char));
  // format the hex string
  sprintf(hexValue, "#%02x%02x%02x", r, g, b);
  return hexValue;
}

int main() {
  // initialize variables
  int choice;
  char* colorCode = (char*)malloc(8 * sizeof(char));
  char* convertedCode = (char*)malloc(16 * sizeof(char));
  // get user input
  printf("Enter a color code (Hex or RGB): ");
  scanf("%s", colorCode);
  // determine conversion type
  if(colorCode[0] == '#') {
    convertedCode = hexToRgb(colorCode);
    choice = 1;
  }
  else {
    convertedCode = rgbToHex(colorCode);
    choice = 2;
  }
  // output results
  if(choice == 1) {
    printf("Hex: %s\nRGB: %s\n", colorCode, convertedCode);
  }
  else {
    printf("RGB: %s\nHex: %s\n", colorCode, convertedCode);
  }
  // free memory
  free(colorCode);
  free(convertedCode);
  return 0;
}