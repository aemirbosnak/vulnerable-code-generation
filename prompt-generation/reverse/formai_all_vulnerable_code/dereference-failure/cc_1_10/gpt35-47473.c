//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

// function prototypes
int synchronize_dirs(const char* src_dir, const char* dest_dir);
int copy_file(const char* src_file, const char* dest_file);
int is_regular_file(const char* path);

int main(int argc, char* argv[]) {

  // check for proper usage
  if (argc != 3) {
    printf("Usage: %s src_dir dest_dir\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // call synchronize_dirs function to copy files from src_dir to dest_dir
  if (synchronize_dirs(argv[1], argv[2]) == -1) {
    printf("Failed to synchronize directories\n");
    exit(EXIT_FAILURE);
  }

  printf("Directories synchronized successfully\n");
  return 0;
}

/**
 * This function synchronizes two directories by copying files from the source
 * directory to the destination directory if they do not already exist or if they
 * have been modified.
 */
int synchronize_dirs(const char* src_dir, const char* dest_dir) {

  DIR* src_dp, *dest_dp;
  struct dirent* src_ep, *dest_ep;
  char src_path[PATH_MAX], dest_path[PATH_MAX];
  struct stat src_sb, dest_sb;

  // open source and destination directories
  src_dp = opendir(src_dir);
  if (src_dp == NULL) {
    printf("Error opening source directory\n");
    return -1;
  }
  dest_dp = opendir(dest_dir);
  if (dest_dp == NULL) {
    printf("Error opening destination directory\n");
    closedir(src_dp);
    return -1;
  }

  // loop through source directory entries
  while ((src_ep = readdir(src_dp)) != NULL) {

    // skip current directory (.)
    if (strcmp(src_ep->d_name, ".") == 0) continue;

    // skip parent directory (..)
    if (strcmp(src_ep->d_name, "..") == 0) continue;

    // build source and destination file paths
    sprintf(src_path, "%s/%s", src_dir, src_ep->d_name);
    sprintf(dest_path, "%s/%s", dest_dir, src_ep->d_name);

    // get source file attributes
    if (stat(src_path, &src_sb) == -1) continue;

    // check if source file is a directory
    if (S_ISDIR(src_sb.st_mode)) {

      // create destination directory if it does not exist
      if (stat(dest_path, &dest_sb) != 0) {
        mkdir(dest_path, 0700);
      }

      // synchronize nested directories
      synchronize_dirs(src_path, dest_path);

    } else {

      // check if destination file exists and get its attributes
      if (stat(dest_path, &dest_sb) == -1) {

        // destination file does not exist, copy source file to destination
        if (copy_file(src_path, dest_path) == -1) continue;

      } else {

        // compare modification times to determine if file needs to be copied
        if (src_sb.st_mtime > dest_sb.st_mtime) {
          if (copy_file(src_path, dest_path) == -1) continue;
        }
      }
    }
  }

  // close directories
  closedir(src_dp);
  closedir(dest_dp);

  return 0;
}

/**
 * This function copies a file from the source path to the destination path.
 */
int copy_file(const char* src_file, const char* dest_file) {

  int src_fd, dest_fd, n;
  char buf[BUFSIZ];

  // open source file for reading
  src_fd = open(src_file, O_RDONLY);
  if (src_fd == -1) {
    printf("Error opening source file %s\n", src_file);
    return -1;
  }

  // create or truncate destination file for writing
  dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0700);
  if (dest_fd == -1) {
    printf("Error creating destination file %s\n", dest_file);
    close(src_fd);
    return -1;
  }

  // copy contents of source file to destination file
  while ((n = read(src_fd, buf, BUFSIZ)) > 0) {
    if (write(dest_fd, buf, n) != n) {
      printf("Error writing to destination file %s\n", dest_file);
      close(src_fd);
      close(dest_fd);
      return -1;
    }
  }

  // close files
  close(src_fd);
  close(dest_fd);

  return 0;
}

/**
 * This function checks if a file is a regular file.
 */
int is_regular_file(const char* path) {

  struct stat sb;

  if (stat(path, &sb) == 0) {
    if (S_ISREG(sb.st_mode)) {
      return 1;
    }
  }

  return 0;
}