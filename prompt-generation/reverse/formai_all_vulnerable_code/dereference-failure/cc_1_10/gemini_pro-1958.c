//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// Structure to store file information
typedef struct fileinfo {
  char *name;
  size_t size;
} fileinfo;

// Function to compare fileinfo structures by size
int compare_fileinfo(const void *a, const void *b) {
  const fileinfo *fa = (const fileinfo *)a;
  const fileinfo *fb = (const fileinfo *)b;
  return fa->size - fb->size;
}

// Function to get the size of a file
size_t get_file_size(const char *path) {
  struct stat st;
  if (stat(path, &st) == 0) {
    return st.st_size;
  }
  return 0;
}

// Function to get the files in a directory
fileinfo *get_files_in_dir(const char *path, size_t *num_files) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    return NULL;
  }

  *num_files = 0;
  fileinfo *files = NULL;

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *filepath = malloc(strlen(path) + strlen(entry->d_name) + 2);
    sprintf(filepath, "%s/%s", path, entry->d_name);

    fileinfo *file = malloc(sizeof(fileinfo));
    file->name = filepath;
    file->size = get_file_size(filepath);

    files = realloc(files, (*num_files + 1) * sizeof(fileinfo));
    files[*num_files] = *file;
    *num_files += 1;
  }

  closedir(dir);

  return files;
}

// Function to print the files in a directory
void print_files(const fileinfo *files, size_t num_files) {
  for (size_t i = 0; i < num_files; i++) {
    printf("%s: %lu\n", files[i].name, files[i].size);
  }
}

// Function to analyze the disk space usage
void analyze_disk_space(const char *path) {
  size_t num_files;
  fileinfo *files = get_files_in_dir(path, &num_files);

  if (files == NULL) {
    perror("Error getting files in directory");
    return;
  }

  qsort(files, num_files, sizeof(fileinfo), compare_fileinfo);

  printf("Files in directory %s:\n", path);
  print_files(files, num_files);

  size_t total_size = 0;
  for (size_t i = 0; i < num_files; i++) {
    total_size += files[i].size;
  }

  printf("Total size: %lu\n", total_size);

  for (size_t i = 0; i < num_files; i++) {
    free(files[i].name);
  }
  free(files);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return 1;
  }

  analyze_disk_space(argv[1]);

  return 0;
}