//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_FILES 100

char *files[MAX_FILES];
int num_files = 0;

void add_file(char *file) {
  if (num_files >= MAX_FILES) {
    fprintf(stderr, "Error: Too many files specified.\n");
    exit(EXIT_FAILURE);
  }

  files[num_files++] = strdup(file);
}

void backup_files() {
  for (int i = 0; i < num_files; i++) {
    char *file = files[i];

    FILE *input = fopen(file, "rb");
    if (input == NULL) {
      fprintf(stderr, "Error: Unable to open file %s for reading.\n", file);
      exit(EXIT_FAILURE);
    }

    char backup_file[strlen(file) + 5];
    sprintf(backup_file, "%s.bak", file);

    FILE *output = fopen(backup_file, "wb");
    if (output == NULL) {
      fprintf(stderr, "Error: Unable to open file %s for writing.\n", backup_file);
      exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, BUF_SIZE, input)) > 0) {
      fwrite(buf, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Error: No files specified.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    add_file(argv[i]);
  }

  backup_files();

  printf("Backup complete.\n");
  return EXIT_SUCCESS;
}