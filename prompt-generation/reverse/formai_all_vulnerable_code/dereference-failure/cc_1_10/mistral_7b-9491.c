//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

// Inquisitive alien greeting 👽
void greet() {
  printf("\n🌌 Hey there, human! I see you're in a pickle.\n");
  printf("💻 You've lost track of all that precious data on your C: drive.\n");
  printf("🔎 Fear not, for I, the Space Cadet, am here to help you out!\n");
}

// Function to get file size
long long get_file_size(const char *filename) {
  struct stat file_stat;
  if (stat(filename, &file_stat) == -1) {
    perror("Error getting file size");
    return -1;
  }
  return file_stat.st_size;
}

// Function to print file size in a fun way
void print_size(long long size) {
  char units[10][3] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB", "BB"};
  int i = 0;
  while (size >= 1024) {
    size /= 1024;
    i++;
  }
  printf("%lld %s\n", size, units[i]);
}

// Function to print file details
void print_file(const char *filename, long long size) {
  struct stat file_stat;
  char *filename_last_slash;

  if (stat(filename, &file_stat) == -1) {
    perror("Error getting file details");
    return;
  }

  filename_last_slash = strrchr(filename, '/');

  if (filename_last_slash) {
    printf("%s/", filename_last_slash);
  }

  printf("%s - %lld bytes\n", filename, size);
}

// Function to list files in a directory
void list_files(const char *path) {
  DIR *dir;
  struct dirent *entry;
  int count = 0;

  if (!(dir = opendir(path))) {
    perror("Error opening directory");
    return;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      print_file(entry->d_name, get_file_size(entry->d_name));
      count++;
    }
  }

  closedir(dir);

  if (count == 0) {
    printf("%s: empty directory\n", path);
  }
}

// Main function
int main() {
  greet();
  list_files("./");
  return 0;
}