//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HexConverter {
  char **buffer;
  int size;
  int index;
  int is_valid;
} HexConverter;

HexConverter *hex_converter_init(int size) {
  HexConverter *converter = malloc(sizeof(HexConverter));
  converter->buffer = malloc(size * sizeof(char *));
  converter->size = size;
  converter->index = 0;
  converter->is_valid = 0;
  return converter;
}

void hex_converter_add(HexConverter *converter, char data) {
  converter->buffer[converter->index] = data;
  converter->index++;
  if (converter->index >= converter->size) {
    converter->is_valid = 0;
  }
}

void hex_converter_flush(HexConverter *converter) {
  converter->index = 0;
  converter->is_valid = 0;
}

void hex_converter_print(HexConverter *converter) {
  if (converter->is_valid) {
    for (int i = 0; i < converter->index; i++) {
      printf("%x ", converter->buffer[i]);
    }
    printf("\n");
  } else {
    printf("Invalid conversion.\n");
  }
}

int main() {
  HexConverter *converter = hex_converter_init(10);
  hex_converter_add(converter, 0x12);
  hex_converter_add(converter, 0x34);
  hex_converter_add(converter, 0x56);
  hex_converter_flush(converter);
  hex_converter_print(converter);
  return 0;
}