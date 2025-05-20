//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  HEX_CONVERTER,
  DEC_CONVERTER
} CONVERTER_MODE;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input> <output> [-h | -d]\n", argv[0]);
    printf("  -h: convert hexadecimal to decimal\n");
    printf("  -d: convert decimal to hexadecimal\n");
    return 1;
  }

  CONVERTER_MODE mode = HEX_CONVERTER;
  if (strcmp(argv[3], "-h") == 0) {
    mode = HEX_CONVERTER;
  } else if (strcmp(argv[3], "-d") == 0) {
    mode = DEC_CONVERTER;
  } else {
    printf("Invalid conversion mode. Please specify either -h or -d.\n");
    return 1;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    printf("Error opening input file: %s\n", argv[1]);
    return 1;
  }

  FILE *output = fopen(argv[2], "w");
  if (output == NULL) {
    printf("Error opening output file: %s\n", argv[2]);
    fclose(input);
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), input) != NULL) {
    if (mode == HEX_CONVERTER) {
      int dec = strtol(line, NULL, 16);
      fprintf(output, "%d\n", dec);
    } else if (mode == DEC_CONVERTER) {
      char hex[128];
      sprintf(hex, "%x\n", strtol(line, NULL, 10));
      fprintf(output, "%s", hex);
    }
  }

  fclose(input);
  fclose(output);
  return 0;
}