//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  HEX,
  DEC,
  OCT,
  BIN
} NumberBase;

void printUsage(void) {
  printf("Usage: hexconvert <number> <base>\n");
  printf("  where <number> is the number to convert\n");
  printf("  and <base> is the base to convert to (hex, dec, oct, bin)\n");
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printUsage();
    return 1;
  }

  NumberBase base;
  if (strcmp(argv[2], "hex") == 0) {
    base = HEX;
  } else if (strcmp(argv[2], "dec") == 0) {
    base = DEC;
  } else if (strcmp(argv[2], "oct") == 0) {
    base = OCT;
  } else if (strcmp(argv[2], "bin") == 0) {
    base = BIN;
  } else {
    printf("Invalid base: %s\n", argv[2]);
    printUsage();
    return 1;
  }

  char *endptr;
  long long number = strtoll(argv[1], &endptr, 0);
  if (*endptr != '\0') {
    printf("Invalid number: %s\n", argv[1]);
    printUsage();
    return 1;
  }

  switch (base) {
  case HEX:
    printf("%llx\n", number);
    break;
  case DEC:
    printf("%lld\n", number);
    break;
  case OCT:
    printf("%llo\n", number);
    break;
  case BIN:
    printf("%llb\n", number);
    break;
  }

  return 0;
}