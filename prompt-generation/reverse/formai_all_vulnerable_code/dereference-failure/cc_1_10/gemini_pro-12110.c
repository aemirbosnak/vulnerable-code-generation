//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  size_t size;
  void *data;
} File;

File *open_file(const char *path) {
  FILE *fp = fopen(path, "rb");
  if (!fp) {
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  rewind(fp);
  void *data = malloc(size);
  if (!data) {
    fclose(fp);
    return NULL;
  }
  fread(data, size, 1, fp);
  fclose(fp);
  File *file = malloc(sizeof(File));
  if (!file) {
    free(data);
    return NULL;
  }
  file->name = strdup(path);
  if (!file->name) {
    free(file);
    free(data);
    return NULL;
  }
  file->size = size;
  file->data = data;
  return file;
}

void close_file(File *file) {
  free(file->name);
  free(file->data);
  free(file);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }
  File *file = open_file(argv[1]);
  if (!file) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  printf("File: %s\n", file->name);
  printf("Size: %zu\n", file->size);
  printf("Data:\n");
  fwrite(file->data, file->size, 1, stdout);
  close_file(file);
  return EXIT_SUCCESS;
}