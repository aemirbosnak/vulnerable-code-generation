//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 4096

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int read_size, write_size, file_size, backup_size = 0, total_size = 0;
  FILE *file, *backup;
  struct stat file_stat;

  // Open file
  file = fopen("my_file.txt", "r");
  if (!file) {
    perror("Error opening file");
    exit(1);
  }

  // Get file size
  fstat(fileno(file), &file_stat);
  file_size = file_stat.st_size;

  // Allocate backup space
  backup = fopen("backup.bin", "w");
  if (!backup) {
    perror("Error opening backup file");
    exit(1);
  }

  // Read file in chunks
  while (read_size = read(file, buffer, MAX_BUFFER_SIZE)) {
    write_size = write(backup, buffer, read_size);
    if (write_size != read_size) {
      perror("Error writing to backup");
      exit(1);
    }

    backup_size += read_size;
  }

  // Calculate total size
  total_size = backup_size + file_size;

  // Close files
  fclose(file);
  fclose(backup);

  // Print total size
  printf("Total size of backup: %d bytes\n", total_size);

  return 0;
}