//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 1024 // 1GB
#define MAX_BLOCK_SIZE 1024 * 1024 // 1MB

typedef struct {
  char *data;
  size_t size;
} block_t;

typedef struct {
  char *data;
  size_t size;
  size_t capacity;
} file_t;

void *xmalloc(size_t size) {
  void *p = malloc(size);
  if (p == NULL) {
    fprintf(stderr, "Error: could not allocate memory\n");
    exit(EXIT_FAILURE);
  }
  return p;
}

void *xrealloc(void *ptr, size_t size) {
  void *p = realloc(ptr, size);
  if (p == NULL) {
    fprintf(stderr, "Error: could not reallocate memory\n");
    exit(EXIT_FAILURE);
  }
  return p;
}

block_t *new_block(size_t size) {
  block_t *block = xmalloc(sizeof(block_t));
  block->data = xmalloc(size);
  block->size = size;
  return block;
}

void free_block(block_t *block) {
  free(block->data);
  free(block);
}

file_t *new_file() {
  file_t *file = xmalloc(sizeof(file_t));
  file->data = NULL;
  file->size = 0;
  file->capacity = 0;
  return file;
}

void free_file(file_t *file) {
  free(file->data);
  free(file);
}

void append_block(file_t *file, block_t *block) {
  if (file->size + block->size > file->capacity) {
    file->capacity = (file->capacity == 0) ? MAX_BLOCK_SIZE : file->capacity * 2;
    file->data = xrealloc(file->data, file->capacity);
  }
  memcpy(file->data + file->size, block->data, block->size);
  file->size += block->size;
}

void write_file(file_t *file, char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file for writing\n");
    exit(EXIT_FAILURE);
  }
  fwrite(file->data, 1, file->size, fp);
  fclose(fp);
}

block_t *read_block(FILE *fp, size_t size) {
  block_t *block = xmalloc(sizeof(block_t));
  block->data = xmalloc(size);
  block->size = fread(block->data, 1, size, fp);
  return block;
}

file_t *read_file(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file for reading\n");
    exit(EXIT_FAILURE);
  }
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  file_t *file = new_file();
  while (size > 0) {
    size_t block_size = (size > MAX_BLOCK_SIZE) ? MAX_BLOCK_SIZE : size;
    block_t *block = read_block(fp, block_size);
    append_block(file, block);
    free_block(block);
    size -= block_size;
  }
  fclose(fp);
  return file;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input-file> <output-file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  file_t *file = read_file(argv[1]);
  write_file(file, argv[2]);
  free_file(file);
  return EXIT_SUCCESS;
}