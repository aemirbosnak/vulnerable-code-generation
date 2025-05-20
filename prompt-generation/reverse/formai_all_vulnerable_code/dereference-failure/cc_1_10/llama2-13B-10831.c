//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void recover_file(const char *filename) {
  int fd = open(filename, O_RDONLY | O_NONBLOCK, 0644);
  if (fd == -1) {
    perror("Error opening file");
    return;
  }

  struct stat filestat;
  if (fstat(fd, &filestat) == -1) {
    perror("Error stat'ing file");
    close(fd);
    return;
  }

  off_t filesize = filestat.st_size;
  off_t buffer_size = BUFFER_SIZE;
  char *buffer = malloc(buffer_size);
  off_t read_size = 0;

  while (read_size < filesize) {
    ssize_t read_ret = read(fd, buffer, buffer_size);
    if (read_ret == -1) {
      perror("Error reading from file");
      break;
    }

    if (read_ret == 0) {
      printf("Reached end of file\n");
      break;
    }

    read_size += read_ret;
    buffer += read_ret;
  }

  close(fd);

  // Recover data from the buffer
  char *data = buffer;
  off_t data_size = read_size;
  off_t offset = 0;

  while (offset < data_size) {
    char *current = data + offset;
    char *next = strchr(current, '\n');
    if (next != NULL) {
      *next = '\0';
      printf("%s\n", current);
      offset = next - data + 1;
    } else {
      printf("%s\n", current);
      offset += strlen(current) + 1;
    }
  }

  free(buffer);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file-name>\n", argv[0]);
    return 1;
  }

  recover_file(argv[1]);
  return 0;
}