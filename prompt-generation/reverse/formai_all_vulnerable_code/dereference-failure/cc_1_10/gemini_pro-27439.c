//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main() {
  // Get the current time as a string.
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char time_string[256];
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", tm);

  // Get the name of the file to be backed up.
  char *file_name = "file.txt";

  // Get the name of the backup file.
  char *backup_file_name = "backup.txt";

  // Open the file to be backed up.
  int fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Create the backup file.
  int fd2 = open(backup_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd2 == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Write the current time to the backup file.
  ssize_t n = write(fd2, time_string, strlen(time_string));
  if (n == -1) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Copy the contents of the file to be backed up to the backup file.
  char buffer[BUFFER_SIZE];
  while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
    if (write(fd2, buffer, n) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
  }

  if (n == -1) {
    perror("read");
    return EXIT_FAILURE;
  }

  // Close the files.
  close(fd);
  close(fd2);

  return EXIT_SUCCESS;
}