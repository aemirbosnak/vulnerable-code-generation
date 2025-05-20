//GEMINI-pro DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file
struct file {
  char *name;
  char *contents;
  size_t size;
};

// Create a new file
struct file *file_new(const char *name, const char *contents, size_t size) {
  struct file *file = malloc(sizeof(struct file));
  if (!file) {
    return NULL;
  }

  file->name = strdup(name);
  if (!file->name) {
    free(file);
    return NULL;
  }

  file->contents = malloc(size);
  if (!file->contents) {
    free(file->name);
    free(file);
    return NULL;
  }

  memcpy(file->contents, contents, size);
  file->size = size;

  return file;
}

// Open a file
struct file *file_open(const char *name) {
  FILE *fp = fopen(name, "rb");
  if (!fp) {
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  rewind(fp);

  char *contents = malloc(size);
  if (!contents) {
    fclose(fp);
    return NULL;
  }

  fread(contents, 1, size, fp);
  fclose(fp);

  return file_new(name, contents, size);
}

// Save a file
int file_save(struct file *file) {
  FILE *fp = fopen(file->name, "wb");
  if (!fp) {
    return -1;
  }

  fwrite(file->contents, 1, file->size, fp);
  fclose(fp);

  return 0;
}

// Close a file
void file_close(struct file *file) {
  free(file->name);
  free(file->contents);
  free(file);
}

// Print a file
void file_print(struct file *file) {
  printf("%s:\n", file->name);
  fwrite(file->contents, 1, file->size, stdout);
  printf("\n");
}

// Main function
int main() {
  // Create a new file
  struct file *file = file_new("test.txt", "Hello, world!\n", 13);
  if (!file) {
    fprintf(stderr, "Error creating file\n");
    return EXIT_FAILURE;
  }

  // Save the file
  if (file_save(file) != 0) {
    fprintf(stderr, "Error saving file\n");
    return EXIT_FAILURE;
  }

  // Open the file
  struct file *file2 = file_open("test.txt");
  if (!file2) {
    fprintf(stderr, "Error opening file\n");
    return EXIT_FAILURE;
  }

  // Print the file
  file_print(file2);

  // Close the files
  file_close(file);
  file_close(file2);

  return EXIT_SUCCESS;
}