//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_FILES 100

// Structure to store file information
typedef struct {
  char path[MAX_PATH];
  time_t last_modified;
  int size;
} FileInfo;

// Function to compare two files
int compare_files(const void *a, const void *b) {
  FileInfo *file1 = (FileInfo *)a;
  FileInfo *file2 = (FileInfo *)b;

  return strcmp(file1->path, file2->path);
}

// Function to get file information
int get_file_info(const char *path, FileInfo *file_info) {
  struct stat stat_buf;

  if (stat(path, &stat_buf) != 0) {
    return -1;
  }

  file_info->last_modified = stat_buf.st_mtime;
  file_info->size = stat_buf.st_size;
  strcpy(file_info->path, path);

  return 0;
}

// Function to create a backup of a file
int backup_file(const char *src_path, const char *dst_path) {
  int src_fd, dst_fd;
  char buffer[4096];
  ssize_t bytes_read, bytes_written;

  // Open the source file
  src_fd = open(src_path, O_RDONLY);
  if (src_fd == -1) {
    return -1;
  }

  // Open the destination file
  dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (dst_fd == -1) {
    close(src_fd);
    return -1;
  }

  // Copy the contents of the source file to the destination file
  while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
    bytes_written = write(dst_fd, buffer, bytes_read);
    if (bytes_written != bytes_read) {
      close(src_fd);
      close(dst_fd);
      return -1;
    }
  }

  // Close the files
  close(src_fd);
  close(dst_fd);

  return 0;
}

int main(int argc, char *argv[]) {
  FileInfo file_infos[MAX_FILES];
  int num_files = 0;
  int i;
  char dst_path[MAX_PATH];

  // Check the arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s src_dir dst_dir\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the files in the source directory
  for (i = 0; i < MAX_FILES; i++) {
    if (get_file_info(argv[1], &file_infos[i]) != 0) {
      break;
    }
    num_files++;
  }

  // Sort the files by name
  qsort(file_infos, num_files, sizeof(FileInfo), compare_files);

  // Create the destination directory
  sprintf(dst_path, "%s/backup", argv[2]);
  if (mkdir(dst_path, 0755) != 0) {
    perror("mkdir");
    return EXIT_FAILURE;
  }

  // Backup the files
  for (i = 0; i < num_files; i++) {
    sprintf(dst_path, "%s/%s", dst_path, file_infos[i].path);
    if (backup_file(file_infos[i].path, dst_path) != 0) {
      perror("backup_file");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}