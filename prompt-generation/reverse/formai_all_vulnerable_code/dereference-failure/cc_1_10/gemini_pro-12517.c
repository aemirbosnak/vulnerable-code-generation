//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
  char name[256];
  char data[MAX_FILE_SIZE];
  size_t size;
  time_t timestamp;
} file;

file files[MAX_FILES];
int num_files = 0;

void backup_file(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    return;
  }
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  rewind(fp);
  char *data = malloc(size);
  if (data == NULL) {
    perror("malloc");
    fclose(fp);
    return;
  }
  fread(data, 1, size, fp);
  fclose(fp);
  strcpy(files[num_files].name, filename);
  memcpy(files[num_files].data, data, size);
  files[num_files].size = size;
  files[num_files].timestamp = time(NULL);
  num_files++;
  free(data);
}

void restore_file(char *filename) {
  int i;
  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, filename) == 0) {
      FILE *fp = fopen(filename, "wb");
      if (fp == NULL) {
        perror("fopen");
        return;
      }
      fwrite(files[i].data, 1, files[i].size, fp);
      fclose(fp);
      return;
    }
  }
  printf("File '%s' not found in backup.\n", filename);
}

void list_files() {
  int i;
  for (i = 0; i < num_files; i++) {
    printf("%s (%ld bytes, %s)\n", files[i].name, files[i].size, ctime(&files[i].timestamp));
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <command> <filename>\n", argv[0]);
    return 1;
  }
  if (strcmp(argv[1], "backup") == 0) {
    backup_file(argv[2]);
  } else if (strcmp(argv[1], "restore") == 0) {
    restore_file(argv[2]);
  } else if (strcmp(argv[1], "list") == 0) {
    list_files();
  } else {
    printf("Invalid command '%s'.\n", argv[1]);
    return 1;
  }
  return 0;
}