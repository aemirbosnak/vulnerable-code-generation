//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// A structure for a file or directory
typedef struct _File {
  char *name;
  long size;
  time_t timestamp;
  int is_directory;
} File;

// A comparison function for sorting files by size
int compare_files(const void *a, const void *b) {
  const File *fa = (const File *)a;
  const File *fb = (const File *)b;
  return fa->size - fb->size;
}

// A function to print the file or directory information
void print_file(const File *file) {
  printf("%s: %ld bytes (%s)", file->name, file->size, ctime(&file->timestamp));
}

// A function to get the size of a directory and its subdirectories
long get_directory_size(char *path) {
  long size = 0;
  DIR *dir = opendir(path);
  if (!dir) {
    perror("opendir");
    return -1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir))) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
    strcpy(full_path, path);
    strcat(full_path, "/");
    strcat(full_path, entry->d_name);

    struct stat statbuf;
    if (stat(full_path, &statbuf) == -1) {
      perror("stat");
      free(full_path);
      closedir(dir);
      return -1;
    }

    if (S_ISREG(statbuf.st_mode)) {
      size += statbuf.st_size;
    } else if (S_ISDIR(statbuf.st_mode)) {
      size += get_directory_size(full_path);
    }

    free(full_path);
  }

  closedir(dir);

  return size;
}

int main(int argc, char *argv[]) {
  // Get the list of files and directories in the current directory
  DIR *dir = opendir(".");
  if (!dir) {
    perror("opendir");
    return 1;
  }

  // Create an array to store the files and directories
  File *files = malloc(sizeof(File) * 100);
  int num_files = 0;

  struct dirent *entry;
  while ((entry = readdir(dir))) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *full_path = malloc(strlen(".") + strlen(entry->d_name) + 2);
    strcpy(full_path, ".");
    strcat(full_path, "/");
    strcat(full_path, entry->d_name);

    struct stat statbuf;
    if (stat(full_path, &statbuf) == -1) {
      perror("stat");
      free(full_path);
      closedir(dir);
      free(files);
      return 1;
    }

    File *file = &files[num_files++];
    file->name = malloc(strlen(entry->d_name) + 1);
    strcpy(file->name, entry->d_name);
    file->size = statbuf.st_size;
    file->timestamp = statbuf.st_mtime;
    file->is_directory = S_ISDIR(statbuf.st_mode);

    free(full_path);
  }

  closedir(dir);

  // Sort the files and directories by size
  qsort(files, num_files, sizeof(File), compare_files);

  // Print the list of files and directories
  for (int i = 0; i < num_files; i++) {
    print_file(&files[i]);
  }

  // Free the memory allocated for the files and directories
  for (int i = 0; i < num_files; i++) {
    free(files[i].name);
  }
  free(files);

  return 0;
}