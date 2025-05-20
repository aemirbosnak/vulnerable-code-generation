//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  int size;
} buffer;

buffer *create_buffer(int size) {
  buffer *b = malloc(sizeof(buffer));
  b->data = malloc(size);
  b->size = size;
  return b;
}

void free_buffer(buffer *b) {
  free(b->data);
  free(b);
}

int recover_data(buffer *b, const char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    return -1;
  }
  fread(b->data, b->size, 1, f);
  fclose(f);
  return 0;
}

int write_data(buffer *b, const char *filename) {
  FILE *f = fopen(filename, "wb");
  if (!f) {
    return -1;
  }
  fwrite(b->data, b->size, 1, f);
  fclose(f);
  return 0;
}

int main(int argc, char **argv) {
  if (argc == 4 && strcmp(argv[1], "-r") == 0) {
    buffer *b = create_buffer(atoi(argv[2]));
    if (recover_data(b, argv[3]) == -1) {
      printf("Error recovering data from file %s\n", argv[3]);
      free_buffer(b);
      return 1;
    }
    printf("Data recovered from file %s\n", argv[3]);
    free_buffer(b);
    return 0;
  } else if (argc == 4 && strcmp(argv[1], "-w") == 0) {
    buffer *b = create_buffer(atoi(argv[2]));
    if (write_data(b, argv[3]) == -1) {
      printf("Error writing data to file %s\n", argv[3]);
      free_buffer(b);
      return 1;
    }
    printf("Data written to file %s\n", argv[3]);
    free_buffer(b);
    return 0;
  } else {
    printf("Usage: %s [-r | -w] <size> <filename>\n", argv[0]);
    return 1;
  }
}