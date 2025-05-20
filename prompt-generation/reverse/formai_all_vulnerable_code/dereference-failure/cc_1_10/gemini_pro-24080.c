//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_FILES 1000

// Define the file synchronization function
int sync_files(char *src_dir, char *dst_dir) {
  // Open the source and destination directories
  DIR *src_dirp = opendir(src_dir);
  if (src_dirp == NULL) {
    perror("opendir");
    return -1;
  }
  DIR *dst_dirp = opendir(dst_dir);
  if (dst_dirp == NULL) {
    perror("opendir");
    return -1;
  }

  // Get a list of files in the source directory
  struct dirent *src_files[MAX_FILES];
  int src_num_files = 0;
  while ((src_files[src_num_files] = readdir(src_dirp)) != NULL) {
    src_num_files++;
  }
  closedir(src_dirp);

  // Get a list of files in the destination directory
  struct dirent *dst_files[MAX_FILES];
  int dst_num_files = 0;
  while ((dst_files[dst_num_files] = readdir(dst_dirp)) != NULL) {
    dst_num_files++;
  }
  closedir(dst_dirp);

  // Compare the lists of files
  for (int i = 0; i < src_num_files; i++) {
    // Check if the file exists in the destination directory
    int found = 0;
    for (int j = 0; j < dst_num_files; j++) {
      if (strcmp(src_files[i]->d_name, dst_files[j]->d_name) == 0) {
        found = 1;
        break;
      }
    }

    // If the file does not exist in the destination directory, copy it
    if (!found) {
      char src_path[256];
      char dst_path[256];
      sprintf(src_path, "%s/%s", src_dir, src_files[i]->d_name);
      sprintf(dst_path, "%s/%s", dst_dir, src_files[i]->d_name);
      if (copy_file(src_path, dst_path) < 0) {
        perror("copy_file");
        return -1;
      }
    }
  }

  // Close the directories
  closedir(src_dirp);
  closedir(dst_dirp);

  return 0;
}

// Define the file copy function
int copy_file(char *src_path, char *dst_path) {
  // Open the source and destination files
  FILE *src_file = fopen(src_path, "rb");
  if (src_file == NULL) {
    perror("fopen");
    return -1;
  }
  FILE *dst_file = fopen(dst_path, "wb");
  if (dst_file == NULL) {
    perror("fopen");
    return -1;
  }

  // Copy the data from the source file to the destination file
  char buf[4096];
  size_t bytes_read;
  while ((bytes_read = fread(buf, 1, sizeof(buf), src_file)) > 0) {
    if (fwrite(buf, 1, bytes_read, dst_file) != bytes_read) {
      perror("fwrite");
      return -1;
    }
  }

  // Close the files
  fclose(src_file);
  fclose(dst_file);

  return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
    return 1;
  }

  // Synchronize the files
  if (sync_files(argv[1], argv[2]) < 0) {
    return 1;
  }

  return 0;
}