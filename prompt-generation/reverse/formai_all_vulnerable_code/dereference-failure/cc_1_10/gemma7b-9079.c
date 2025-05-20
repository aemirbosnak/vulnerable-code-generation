//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter {
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
  int inputValue;
  char inputUnit;
  char outputUnit;
  int outputValue;
} HexadecimalConverter;

HexadecimalConverter* createHexadecimalConverter() {
  HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
  converter->bufferIndex = 0;
  converter->inputValue = 0;
  converter->inputUnit = '\0';
  converter->outputUnit = '\0';
  converter->outputValue = 0;
  return converter;
}

void destroyHexadecimalConverter(HexadecimalConverter* converter) {
  free(converter);
}

void convertHexadecimal(HexadecimalConverter* converter) {
  char* input = converter->buffer;
  int inputLength = converter->bufferIndex;
  int value = 0;
  int i = 0;

  for (i = 0; i < inputLength; i++) {
    char digit = input[i] - '0';
    value += digit * pow(16, inputLength - i - 1);
  }

  converter->outputValue = value;
}

int main() {
  HexadecimalConverter* converter = createHexadecimalConverter();

  printf("Enter hexadecimal number: ");
  scanf("%s", converter->buffer);
  converter->bufferIndex = scanf("%s", converter->buffer) - 1;

  convertHexadecimal(converter);

  printf("Converted value: %d %s\n", converter->outputValue, converter->outputUnit);

  destroyHexadecimalConverter(converter);

  return 0;
}