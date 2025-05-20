//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

typedef struct {
  char *name;
  long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
  FileInfo *fa = (FileInfo *)a;
  FileInfo *fb = (FileInfo *)b;
  return fb->size - fa->size;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *directory = argv[1];

  // Get the directory listing.
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Create an array to store the file information.
  FileInfo *files = NULL;
  int num_files = 0;

  // Iterate over the directory listing.
  struct dirent *dirent;
  while ((dirent = readdir(dir)) != NULL) {
    // Skip directories.
    if (dirent->d_type == DT_DIR) {
      continue;
    }

    // Get the file information.
    struct stat statbuf;
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "%s/%s", directory, dirent->d_name);
    if (stat(path, &statbuf) == -1) {
      perror("stat");
      continue;
    }

    // Add the file information to the array.
    files = realloc(files, (num_files + 1) * sizeof(FileInfo));
    files[num_files].name = strdup(dirent->d_name);
    files[num_files].size = statbuf.st_size;
    num_files++;
  }

  closedir(dir);

  // Sort the array by file size, in descending order.
  qsort(files, num_files, sizeof(FileInfo), compareFileInfo);

  // Print the file information.
  printf("File Size Analysis\n");
  printf("------------------\n");
  for (int i = 0; i < num_files; i++) {
    printf("%s: %ld bytes\n", files[i].name, files[i].size);
  }

  // Free the allocated memory.
  for (int i = 0; i < num_files; i++) {
    free(files[i].name);
  }
  free(files);

  return EXIT_SUCCESS;
}