//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

typedef struct {
  char name[32];
  int size;
  int blocks[MAX_BLOCKS];
} file;

typedef struct {
  file files[MAX_BLOCKS];
  int free_blocks[MAX_BLOCKS];
  int num_free_blocks;
} file_system;

file_system *fs;

void init_file_system() {
  fs = malloc(sizeof(file_system));
  for (int i = 0; i < MAX_BLOCKS; i++) {
    fs->free_blocks[i] = i;
  }
  fs->num_free_blocks = MAX_BLOCKS;
}

int allocate_blocks(int num_blocks) {
  if (num_blocks > fs->num_free_blocks) {
    return -1;
  }
  int blocks[num_blocks];
  for (int i = 0; i < num_blocks; i++) {
    blocks[i] = fs->free_blocks[i];
    fs->free_blocks[i] = -1;
  }
  fs->num_free_blocks -= num_blocks;
  return blocks;
}

void deallocate_blocks(int *blocks, int num_blocks) {
  for (int i = 0; i < num_blocks; i++) {
    fs->free_blocks[fs->num_free_blocks++] = blocks[i];
  }
}

int create_file(char *name, int size) {
  if (size <= 0) {
    return -1;
  }
  int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
  int *blocks = allocate_blocks(num_blocks);
  if (blocks == NULL) {
    return -1;
  }
  file *f = &fs->files[blocks[0]];
  strcpy(f->name, name);
  f->size = size;
  for (int i = 0; i < num_blocks; i++) {
    f->blocks[i] = blocks[i];
  }
  return 0;
}

int delete_file(char *name) {
  for (int i = 0; i < MAX_BLOCKS; i++) {
    file *f = &fs->files[i];
    if (strcmp(f->name, name) == 0) {
      deallocate_blocks(f->blocks, (f->size + BLOCK_SIZE - 1) / BLOCK_SIZE);
      memset(f, 0, sizeof(file));
      return 0;
    }
  }
  return -1;
}

int main() {
  init_file_system();
  create_file("test.txt", 1024);
  create_file("test2.txt", 512);
  delete_file("test2.txt");
  return 0;
}