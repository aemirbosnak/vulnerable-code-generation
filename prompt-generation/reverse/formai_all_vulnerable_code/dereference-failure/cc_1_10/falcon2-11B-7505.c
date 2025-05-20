//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char *argv[]) {
  char src_path[MAX_PATH_LENGTH];
  char dest_path[MAX_PATH_LENGTH];
  char file_name[MAX_PATH_LENGTH];
  DIR *src_dir;
  struct dirent *entry;
  int status;
  FILE *src_file, *dest_file;

  if (argc!= 3) {
    fprintf(stderr, "Usage: %s <source-path> <dest-path>\n", argv[0]);
    return 1;
  }

  strcpy(src_path, argv[1]);
  strcpy(dest_path, argv[2]);

  src_dir = opendir(src_path);
  if (src_dir == NULL) {
    fprintf(stderr, "Error opening source directory: %s\n", strerror(errno));
    return 1;
  }

  while ((entry = readdir(src_dir))!= NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    status = snprintf(file_name, MAX_PATH_LENGTH, "%s/%s", src_path, entry->d_name);
    if (status >= MAX_PATH_LENGTH) {
      fprintf(stderr, "Error: file name is too long\n");
      return 1;
    }

    src_file = fopen(file_name, "rb");
    if (src_file == NULL) {
      fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
      return 1;
    }

    dest_file = fopen(file_name, "wb");
    if (dest_file == NULL) {
      fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
      return 1;
    }

    while (fread(dest_file, 1, 4096, src_file)!= 0) {
      fflush(dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
  }

  closedir(src_dir);

  return 0;
}