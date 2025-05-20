//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
    return 1;
  }

  // Get the source and destination file paths.
  char *source_file = argv[1];
  char *destination_file = argv[2];

  // Check if the source file exists.
  if (access(source_file, F_OK) == -1) {
    fprintf(stderr, "Error: Source file '%s' not found.\n", source_file);
    return 1;
  }

  // Check if the destination file exists and is writable.
  if (access(destination_file, F_OK) == 0) {
    if (access(destination_file, W_OK) == -1) {
      fprintf(stderr, "Error: Destination file '%s' is not writable.\n", destination_file);
      return 1;
    }
  } else {
    // Create the destination file.
    int fd = open(destination_file, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
      fprintf(stderr, "Error: Could not create destination file '%s'.\n", destination_file);
      return 1;
    }
    close(fd);
  }

  // Open the source and destination files.
  FILE *source_fp = fopen(source_file, "rb");
  if (source_fp == NULL) {
    fprintf(stderr, "Error: Could not open source file '%s'.\n", source_file);
    return 1;
  }
  FILE *destination_fp = fopen(destination_file, "wb");
  if (destination_fp == NULL) {
    fprintf(stderr, "Error: Could not open destination file '%s'.\n", destination_file);
    return 1;
  }

  // Get the current time.
  time_t current_time;
  time(&current_time);

  // Write the current time to the destination file.
  fwrite(&current_time, sizeof(time_t), 1, destination_fp);

  // Copy the contents of the source file to the destination file.
  char buf[BUF_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buf, 1, BUF_SIZE, source_fp)) > 0) {
    fwrite(buf, 1, bytes_read, destination_fp);
  }

  // Close the files.
  fclose(source_fp);
  fclose(destination_fp);

  return 0;
}