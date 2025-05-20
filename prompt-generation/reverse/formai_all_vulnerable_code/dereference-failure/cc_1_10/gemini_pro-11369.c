//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

// A simple file synchronizer that uses a rolling hash to check for changes

// The hash function is a simple sum of the bytes in the file
// It is not a cryptographic hash function and is not secure
// But it is fast and good enough for our purposes

unsigned int hash(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  unsigned int h = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    h += c;
  }

  fclose(fp);

  return h;
}

// The main function takes two arguments: the source directory and the destination directory
// It synchronizes the files in the source directory to the destination directory

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
    exit(1);
  }

  DIR *dp = opendir(argv[1]);
  if (dp == NULL) {
    perror("opendir");
    exit(1);
  }

  struct dirent *dent;
  while ((dent = readdir(dp)) != NULL) {
    if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
      continue;
    }

    char source[PATH_MAX];
    char destination[PATH_MAX];
    snprintf(source, sizeof(source), "%s/%s", argv[1], dent->d_name);
    snprintf(destination, sizeof(destination), "%s/%s", argv[2], dent->d_name);

    struct stat statbuf;
    if (stat(source, &statbuf) == -1) {
      perror("stat");
      continue;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      // Recursively synchronize the directory
      mkdir(destination, statbuf.st_mode);
      main(source, destination);
      continue;
    }

    unsigned int source_hash = hash(source);
    unsigned int destination_hash = hash(destination);

    if (source_hash != destination_hash) {
      // The files are different, so copy the source file to the destination file
      int fd_source = open(source, O_RDONLY);
      if (fd_source == -1) {
        perror("open");
        continue;
      }

      int fd_destination = open(destination, O_WRONLY | O_CREAT | O_TRUNC, statbuf.st_mode);
      if (fd_destination == -1) {
        perror("open");
        close(fd_source);
        continue;
      }

      char buffer[4096];
      int n;
      while ((n = read(fd_source, buffer, sizeof(buffer))) > 0) {
        if (write(fd_destination, buffer, n) != n) {
          perror("write");
          close(fd_source);
          close(fd_destination);
          continue;
        }
      }

      if (n == -1) {
        perror("read");
        close(fd_source);
        close(fd_destination);
        continue;
      }

      close(fd_source);
      close(fd_destination);
    }
  }

  closedir(dp);

  return 0;
}