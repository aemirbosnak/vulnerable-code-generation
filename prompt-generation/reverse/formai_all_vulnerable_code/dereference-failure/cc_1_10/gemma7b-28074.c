//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void color_converter(char **color_code);

int main() {
  char **color_code = malloc(10);
  color_converter(color_code);
  free(color_code);
  return 0;
}

void color_converter(char **color_code) {
  printf("Enter the color code: ");
  scanf("%s", color_code);

  if (strlen(*color_code) != 3) {
    printf("Error: Invalid color code.\n");
    return;
  }

  switch (*color_code[0]) {
    case 'R':
      printf("Red: %d.\n", atoi(*color_code[1]) * 2);
      break;
    case 'G':
      printf("Green: %d.\n", atoi(*color_code[1]) * 2);
      break;
    case 'B':
      printf("Blue: %d.\n", atoi(*color_code[1]) * 2);
      break;
    default:
      printf("Error: Invalid color code.\n");
      return;
  }

  switch (*color_code[1]) {
    case '0':
      printf("Shade: 0%.0f%%.\n", atoi(*color_code[2]) * 10);
      break;
    case '1':
      printf("Shade: 1%.0f%%.\n", atoi(*color_code[2]) * 10);
      break;
    case '2':
      printf("Shade: 2%.0f%%.\n", atoi(*color_code[2]) * 10);
      break;
    default:
      printf("Error: Invalid color code.\n");
      return;
  }
}