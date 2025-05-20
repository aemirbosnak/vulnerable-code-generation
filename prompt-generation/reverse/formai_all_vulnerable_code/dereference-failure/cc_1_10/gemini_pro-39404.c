//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Structure to represent a file
typedef struct file {
  char *name;
  int size;
} file;

// Function to compare two files by size
int compare_files(const void *a, const void *b) {
  file *fa = (file *)a;
  file *fb = (file *)b;
  return fb->size - fa->size;
}

// Function to print the files in a directory
void print_files(file *files, int num_files) {
  printf("Files sorted by size:\n");
  for (int i = 0; i < num_files; i++) {
    printf("%s: %d bytes\n", files[i].name, files[i].size);
  }
}

// Function to analyze the disk space usage
void analyze_disk_space(char *path) {
  DIR *dir;
  struct dirent *entry;
  file *files;
  int num_files = 0;

  // Open the directory
  dir = opendir(path);
  if (dir == NULL) {
    perror("Could not open directory");
    exit(1);
  }

  // Iterate over the files in the directory
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Allocate memory for the file
    files = realloc(files, (num_files + 1) * sizeof(file));
    if (files == NULL) {
      perror("Could not allocate memory");
      exit(1);
    }

    // Get the file size
    files[num_files].name = strdup(entry->d_name);
    files[num_files].size = get_file_size(path, entry->d_name);

    num_files++;
  }

  // Close the directory
  closedir(dir);

  // Sort the files by size
  qsort(files, num_files, sizeof(file), compare_files);

  // Print the files
  print_files(files, num_files);

  // Free the memory allocated for the files
  for (int i = 0; i < num_files; i++) {
    free(files[i].name);
  }
  free(files);
}

// Function to get the file size
int get_file_size(char *path, char *file) {
  char *full_path;
  FILE *fp;
  int size;

  // Allocate memory for the full path
  full_path = malloc(strlen(path) + strlen(file) + 1);
  if (full_path == NULL) {
    perror("Could not allocate memory");
    exit(1);
  }

  // Copy the path and file to the full path
  strcpy(full_path, path);
  strcat(full_path, "/");
  strcat(full_path, file);

  // Open the file
  fp = fopen(full_path, "rb");
  if (fp == NULL) {
    perror("Could not open file");
    exit(1);
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);

  // Close the file
  fclose(fp);

  // Free the memory allocated for the full path
  free(full_path);

  return size;
}

int main(int argc, char **argv) {
  // Check if a path was provided
  if (argc != 2) {
    printf("Usage: %s <path>\n", argv[0]);
    exit(1);
  }

  // Analyze the disk space usage
  analyze_disk_space(argv[1]);

  return 0;
}