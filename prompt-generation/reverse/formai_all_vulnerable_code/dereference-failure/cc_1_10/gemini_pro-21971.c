//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 256

typedef struct {
  int code;
  char *symbol;
} code_t;

typedef struct {
  code_t *codes;
  int code_len;
} codebook_t;

codebook_t *create_codebook(int code_len) {
  codebook_t *codebook = malloc(sizeof(codebook_t));
  codebook->codes = malloc(code_len * sizeof(code_t));
  codebook->code_len = code_len;
  return codebook;
}

void free_codebook(codebook_t *codebook) {
  free(codebook->codes);
  free(codebook);
}

void add_code_to_codebook(codebook_t *codebook, int code, char *symbol) {
  codebook->codes[codebook->code_len++] = (code_t){code, symbol};
}

void compress(codebook_t *codebook, char *input, int input_len, char **output, int *output_len) {
  int i, j;
  char *output_buffer = malloc(input_len * sizeof(char));
  int output_buffer_len = 0;
  for (i = 0; i < input_len; i++) {
    for (j = 0; j < codebook->code_len; j++) {
      if (strcmp(input + i, codebook->codes[j].symbol) == 0) {
        output_buffer[output_buffer_len++] = codebook->codes[j].code;
        break;
      }
    }
  }
  *output = output_buffer;
  *output_len = output_buffer_len;
}

void decompress(codebook_t *codebook, char *input, int input_len, char **output, int *output_len) {
  int i, j;
  char *output_buffer = malloc(input_len * sizeof(char));
  int output_buffer_len = 0;
  for (i = 0; i < input_len; i++) {
    for (j = 0; j < codebook->code_len; j++) {
      if (input[i] == codebook->codes[j].code) {
        strcat(output_buffer, codebook->codes[j].symbol);
        output_buffer_len += strlen(codebook->codes[j].symbol);
        break;
      }
    }
  }
  *output = output_buffer;
  *output_len = output_buffer_len;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s input_file\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", argv[1]);
    return 1;
  }

  fseek(input_file, 0, SEEK_END);
  int input_len = ftell(input_file);
  rewind(input_file);

  char *input = malloc(input_len * sizeof(char));
  fread(input, 1, input_len, input_file);

  codebook_t *codebook = create_codebook(MAX_CODE_LEN);

  // Add codes to the codebook
  add_code_to_codebook(codebook, 0, "a");
  add_code_to_codebook(codebook, 1, "b");
  add_code_to_codebook(codebook, 2, "c");
  add_code_to_codebook(codebook, 3, "d");
  add_code_to_codebook(codebook, 4, "e");

  char *compressed_data;
  int compressed_data_len;
  compress(codebook, input, input_len, &compressed_data, &compressed_data_len);

  char *decompressed_data;
  int decompressed_data_len;
  decompress(codebook, compressed_data, compressed_data_len, &decompressed_data, &decompressed_data_len);

  printf("Original data: %s\n", input);
  printf("Compressed data: ");
  for (int i = 0; i < compressed_data_len; i++) {
    printf("%d ", compressed_data[i]);
  }
  printf("\n");
  printf("Decompressed data: %s\n", decompressed_data);

  free(input);
  free(compressed_data);
  free(decompressed_data);
  free_codebook(codebook);
  fclose(input_file);

  return 0;
}