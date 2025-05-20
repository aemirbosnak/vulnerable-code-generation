//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SURPRISED_COMPRESSION_MAGIC 0xA5E7E5

void surprised_compress(char* input, int input_len, char** output, int* output_len) {
  int i, j, k, l;
  int byte_count = 0;
  int symbol_count = 0;
  int last_symbol = -1;
  int last_byte = -1;
  int compression_count = 0;

  // Step 1: Count the number of unique symbols in the input string
  for (i = 0; i < input_len; i++) {
    if (input[i] == last_symbol) {
      symbol_count++;
    } else {
      last_symbol = input[i];
      symbol_count = 1;
    }
    last_byte = i;
  }

  // Step 2: Create a lookup table for each symbol and its frequency
  int* lookup_table = calloc(symbol_count, sizeof(int));
  for (i = 0; i < input_len; i++) {
    lookup_table[input[i] - 'a'] = (lookup_table[input[i] - 'a'] + 1) % 2;
  }

  // Step 3: Compress the input string
  for (i = 0; i < input_len; i++) {
    if (lookup_table[input[i] - 'a'] == 1) {
      // If the symbol is the first occurrence of its type, encode it as a single byte
      if (compression_count == 0) {
        output[byte_count++] = SURPRISED_COMPRESSION_MAGIC | (input[i] - 'a');
      } else {
        // Otherwise, encode it as a variable-length encoded byte
        int delta = input[i] - 'a';
        output[byte_count++] = SURPRISED_COMPRESSION_MAGIC | (delta - last_byte);
        last_byte = i;
        last_symbol = input[i];
      }
      compression_count++;
    } else {
      // If the symbol is not the first occurrence of its type, encode it as a delta
      int delta = input[i] - last_symbol;
      output[byte_count++] = SURPRISED_COMPRESSION_MAGIC | (delta - last_byte);
      last_byte = i;
      last_symbol = input[i];
    }
  }

  // Step 4: Write the compressed data to the output buffer
  *output_len = byte_count;
  return;
}

int main() {
  char input[] = "Hello, world!";
  int input_len = strlen(input);
  char* output = calloc(1, 10);
  int output_len = 0;

  surprised_compress(input, input_len, &output, &output_len);

  printf("Compressed string: %s\n", output);
  free(output);
  return 0;
}