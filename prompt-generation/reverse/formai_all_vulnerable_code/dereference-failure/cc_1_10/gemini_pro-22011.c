//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  char *directory = argv[1];

  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
    sprintf(path, "%s/%s", directory, entry->d_name);

    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
      perror("stat");
      free(path);
      continue;
    }

    if (!S_ISREG(statbuf.st_mode)) {
      free(path);
      continue;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
      perror("open");
      free(path);
      continue;
    }

    char *buffer = malloc(BUFFER_SIZE);
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
      // Process the data in the buffer here.
    }

    free(buffer);
    close(fd);
    free(path);
  }

  closedir(dir);

  return 0;
}