//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LEN 256
#define MAX_FILE_NAME_LEN 128
#define MAX_LINE_LEN 512

// Function to compare two file paths
int compare_paths(const char *path1, const char *path2) {
  return strcmp(path1, path2);
}

// Function to copy a file from one path to another
int copy_file(const char *src_path, const char *dst_path) {
  FILE *src_file = fopen(src_path, "rb");
  if (src_file == NULL) {
    perror("Error opening source file");
    return -1;
  }

  FILE *dst_file = fopen(dst_path, "wb");
  if (dst_file == NULL) {
    perror("Error opening destination file");
    fclose(src_file);
    return -1;
  }

  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
    fwrite(buffer, 1, bytes_read, dst_file);
  }

  fclose(src_file);
  fclose(dst_file);
  return 0;
}

// Function to synchronize the files between two directories
int sync_directories(const char *src_dir_path, const char *dst_dir_path) {
  DIR *src_dir = opendir(src_dir_path);
  if (src_dir == NULL) {
    perror("Error opening source directory");
    return -1;
  }

  DIR *dst_dir = opendir(dst_dir_path);
  if (dst_dir == NULL) {
    perror("Error opening destination directory");
    closedir(src_dir);
    return -1;
  }

  struct dirent *src_entry;
  while ((src_entry = readdir(src_dir)) != NULL) {
    if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
      continue;
    }

    char src_path[MAX_PATH_LEN];
    strcpy(src_path, src_dir_path);
    strcat(src_path, "/");
    strcat(src_path, src_entry->d_name);

    struct stat src_stat;
    if (stat(src_path, &src_stat) == -1) {
      perror("Error getting source file stat");
      continue;
    }

    char dst_path[MAX_PATH_LEN];
    strcpy(dst_path, dst_dir_path);
    strcat(dst_path, "/");
    strcat(dst_path, src_entry->d_name);

    if (S_ISREG(src_stat.st_mode)) {
      struct stat dst_stat;
      if (stat(dst_path, &dst_stat) == -1) {
        // Destination file does not exist, so copy it from the source
        if (copy_file(src_path, dst_path) == -1) {
          perror("Error copying file");
          continue;
        }
      } else if (src_stat.st_mtime > dst_stat.st_mtime) {
        // Source file is newer than the destination file, so replace it
        if (remove(dst_path) == -1) {
          perror("Error removing destination file");
          continue;
        }

        if (copy_file(src_path, dst_path) == -1) {
          perror("Error copying file");
          continue;
        }
      }
    } else if (S_ISDIR(src_stat.st_mode)) {
      // Source file is a directory, so create the corresponding directory in the destination
      if (mkdir(dst_path, src_stat.st_mode) == -1) {
        perror("Error creating destination directory");
        continue;
      }

      // Recursively synchronize the subdirectories
      if (sync_directories(src_path, dst_path) == -1) {
        perror("Error synchronizing subdirectories");
        continue;
      }
    }
  }

  closedir(src_dir);
  closedir(dst_dir);
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <src_dir> <dst_dir>\n", argv[0]);
    return -1;
  }

  const char *src_dir_path = argv[1];
  const char *dst_dir_path = argv[2];

  if (sync_directories(src_dir_path, dst_dir_path) == -1) {
    perror("Error synchronizing directories");
    return -1;
  }

  printf("Directories synchronized successfully!\n");
  return 0;
}