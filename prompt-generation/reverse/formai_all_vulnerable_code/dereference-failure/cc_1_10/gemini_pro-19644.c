//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: innovative
// File Synchronizer: A Dyad's Delight

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// File Comparison Function
int file_compare(const void *a, const void *b) {
  return strcmp((*(struct stat *)a).st_mtime, (*(struct stat *)b).st_mtime);
}

// File Synchronizer Function
void file_sync(char *src, char *dest) {
  // Gather File Information
  struct stat src_stat, dest_stat;
  stat(src, &src_stat);
  stat(dest, &dest_stat);

  // Compare File Timestamps
  int cmp = file_compare(&src_stat, &dest_stat);

  // Synchronize Files if Necessary
  if (cmp > 0) {
    // Source File is Newer, Copy to Destination
    int src_fd = open(src, O_RDONLY);
    int dest_fd = open(dest, O_WRONLY | O_TRUNC | O_CREAT, src_stat.st_mode);
    char buf[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buf, sizeof(buf))) > 0) {
      write(dest_fd, buf, bytes_read);
    }
    close(src_fd);
    close(dest_fd);
  } else if (cmp < 0) {
    // Destination File is Newer, Copy to Source
    int src_fd = open(src, O_WRONLY | O_TRUNC | O_CREAT, dest_stat.st_mode);
    int dest_fd = open(dest, O_RDONLY);
    char buf[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(dest_fd, buf, sizeof(buf))) > 0) {
      write(src_fd, buf, bytes_read);
    }
    close(src_fd);
    close(dest_fd);
  }
}

// Main Function
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s [source file] [destination file]\n", argv[0]);
    return 1;
  }

  file_sync(argv[1], argv[2]);

  printf("Files successfully synchronized.\n");
  return 0;
}