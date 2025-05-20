//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexConverter {
  char buffer[MAX_BUFFER_SIZE];
  int position;
  int input_length;
  int converted_length;
} HexConverter;

HexConverter* hex_converter_init() {
  HexConverter* converter = (HexConverter*)malloc(sizeof(HexConverter));
  converter->position = 0;
  converter->input_length = 0;
  converter->converted_length = 0;
  return converter;
}

void hex_converter_add_input(HexConverter* converter, char input) {
  if (converter->position >= MAX_BUFFER_SIZE - 1) {
    return;
  }
  converter->buffer[converter->position++] = input;
  converter->input_length++;
}

int hex_converter_convert(HexConverter* converter) {
  int i, converted_value = 0, offset = 0;
  for (i = 0; i < converter->input_length; i++) {
    char input_char = converter->buffer[i];
    int digit = input_char - 'a' + 10;
    converted_value += digit * offset;
    offset *= 16;
  }
  converter->converted_length = i + 1;
  return converted_value;
}

int main() {
  HexConverter* converter = hex_converter_init();
  hex_converter_add_input(converter, 'a');
  hex_converter_add_input(converter, 'b');
  hex_converter_add_input(converter, 'c');
  int converted_value = hex_converter_convert(converter);
  printf("Converted value: %x\n", converted_value);
  printf("Converted length: %d\n", converter->converted_length);
  free(converter);
  return 0;
}