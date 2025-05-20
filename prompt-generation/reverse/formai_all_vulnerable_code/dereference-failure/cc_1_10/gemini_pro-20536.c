//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  // open the directory
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  // create a buffer for the directory entries
  struct dirent *entry;
  char buf[BUFSIZE];

  // loop through the directory entries
  while ((entry = readdir(dir)) != NULL) {
    // skip . and ..
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // get the file size
    struct stat statbuf;
    if (lstat(entry->d_name, &statbuf) == -1) {
      perror("lstat");
      continue;
    }

    // print the file size
    printf("%lld %s\n", (long long)statbuf.st_size, entry->d_name);
  }

  // close the directory
  closedir(dir);

  return 0;
}