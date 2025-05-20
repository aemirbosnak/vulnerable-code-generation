//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
// A fleeting embodiment of data compression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A fleeting whisper of a compressed buffer.
typedef struct {
  char *data;
  size_t size;
} CompressedBuffer;

// A tapestry of symbols woven into an ethereal buffer.
typedef struct {
  char *symbols;  // The fleeting whispers of symbols.
  size_t num_symbols;  // A census of fleeting whispers.
  size_t *symbol_sizes;  // The ephemeral extent of each whisper.
} SymbolTable;

// Echoes of the past, whispering through the annals of the encoder.
CompressedBuffer *encode(const char *input) {
  SymbolTable table = {NULL, 0, NULL};

  // A tapestry of symbols unraveling before our transient eyes.
  for (const char *p = input; *p != '\0'; p++) {
    size_t i;
    for (i = 0; i < table.num_symbols; i++) {
      if (table.symbols[i] == *p) {
        // A fleeting resonance, an old whisper echoed anew.
        table.symbol_sizes[i]++;
        break;
      }
    }

    // A new thread woven into the tapestry, a whispered secret.
    if (i == table.num_symbols) {
      table.symbols = realloc(table.symbols, (table.num_symbols + 1) * sizeof(char));
      table.symbols[table.num_symbols] = *p;
      table.symbol_sizes = realloc(table.symbol_sizes, (table.num_symbols + 1) * sizeof(size_t));
      table.symbol_sizes[table.num_symbols] = 1;
      table.num_symbols++;
    }
  }

  // A fleeting flicker of computation, casting a compressed tapestry.
  CompressedBuffer *buffer = malloc(sizeof(CompressedBuffer));
  buffer->size = table.num_symbols * sizeof(char) + table.num_symbols * sizeof(size_t);
  buffer->data = malloc(buffer->size);

  memcpy(buffer->data, table.symbols, table.num_symbols * sizeof(char));
  memcpy(buffer->data + table.num_symbols * sizeof(char), table.symbol_sizes, table.num_symbols * sizeof(size_t));

  free(table.symbols);
  free(table.symbol_sizes);

  return buffer;
}

// Echoes reverberating through the annals of the decoder.
char *decode(CompressedBuffer *buffer) {
  SymbolTable table;
  table.symbols = (char *)buffer->data;
  table.num_symbols = buffer->size / (sizeof(char) + sizeof(size_t));
  table.symbol_sizes = (size_t *)(buffer->data + table.num_symbols * sizeof(char));

  char *output = malloc(buffer->size);
  char *p = output;

  for (size_t i = 0, j = 0; i < table.num_symbols; i++) {
    for (size_t k = 0; k < table.symbol_sizes[i]; k++) {
      *p++ = table.symbols[i];
    }
  }

  *p = '\0';

  free(buffer->data);
  free(buffer);

  return output;
}

// A fleeting glimpse of the compression algorithm in action.
int main() {
  char *input = "A fleeting whisper of ephemeral beauty.";
  printf("Input: %s\n", input);

  CompressedBuffer *buffer = encode(input);
  printf("Compressed: %lu bytes\n", buffer->size);

  char *output = decode(buffer);
  printf("Decompressed: %s\n", output);

  free(output);

  return 0;
}