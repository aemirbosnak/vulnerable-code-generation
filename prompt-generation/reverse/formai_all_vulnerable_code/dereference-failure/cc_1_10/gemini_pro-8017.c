//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function to calculate the size of a directory and its subdirectories
int get_directory_size(const char *path) {
  int size = 0;
  DIR *dir = opendir(path);
  struct dirent *dirent;

  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  while ((dirent = readdir(dir)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    char full_path[256];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, dirent->d_name);

    struct stat statbuf;
    if (stat(full_path, &statbuf) == 0) {
      if (S_ISDIR(statbuf.st_mode)) {
        size += get_directory_size(full_path);
      } else {
        size += statbuf.st_size;
      }
    }
  }

  closedir(dir);

  return size;
}

int main() {
  // Get the size of the home directory
  int size = get_directory_size("/home");

  // Convert the size to megabytes
  float size_mb = size / (1024.0f * 1024.0f);

  // Print the size of the home directory in a romantic style
  printf("Oh, my darling, my heart's desire,\n");
  printf("Your home directory is a vast expanse,\n");
  printf("A treasure trove of memory and romance.\n");
  printf("Its size, a testament to our love's embrace,\n");
  printf("Measures %0.2f megabytes, a breathtaking space.\n", size_mb);

  return 0;
}