//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter {
  char input[MAX_BUFFER_SIZE];
  char output[MAX_BUFFER_SIZE];
  int input_position;
  int output_position;
  int conversion_state;
  char conversion_table[16];
} HexadecimalConverter;

HexadecimalConverter* create_hexadecimal_converter(void) {
  HexadecimalConverter* converter = (HexadecimalConverter*)malloc(sizeof(HexadecimalConverter));

  converter->input_position = 0;
  converter->output_position = 0;
  converter->conversion_state = 0;

  converter->conversion_table[0] = '0';
  converter->conversion_table[1] = '1';
  converter->conversion_table[2] = '2';
  converter->conversion_table[3] = '3';
  converter->conversion_table[4] = '4';
  converter->conversion_table[5] = '5';
  converter->conversion_table[6] = '6';
  converter->conversion_table[7] = '7';
  converter->conversion_table[8] = '8';
  converter->conversion_table[9] = '9';
  converter->conversion_table[10] = 'A';
  converter->conversion_table[11] = 'B';
  converter->conversion_table[12] = 'C';
  converter->conversion_table[13] = 'D';
  converter->conversion_table[14] = 'E';
  converter->conversion_table[15] = 'F';

  return converter;
}

int convert_hexadecimal(HexadecimalConverter* converter) {
  int input_hex_value = converter->input[converter->input_position] - '0';

  switch (converter->conversion_state) {
    case 0:
      converter->output[converter->output_position++] = converter->conversion_table[input_hex_value / 16];
      converter->output[converter->output_position++] = converter->conversion_table[input_hex_value % 16];
      converter->conversion_state = 1;
      break;
    case 1:
      converter->output[converter->output_position++] = converter->conversion_table[input_hex_value];
      break;
  }

  converter->input_position++;

  return 0;
}

int main() {
  HexadecimalConverter* converter = create_hexadecimal_converter();

  printf("Enter hexadecimal number: ");
  fgets(converter->input, MAX_BUFFER_SIZE, stdin);

  while (!feof(stdin)) {
    convert_hexadecimal(converter);
  }

  printf("Converted hexadecimal number: ");
  puts(converter->output);

  return 0;
}