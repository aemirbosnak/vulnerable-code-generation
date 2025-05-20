//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
char* syncdir(char*);
int main(int argc, char** argv) {
  int i;
  if (argc < 2) {
    printf("Usage: %s <srcdir>\n", argv[0]);
    return 1;
  }
  for (i = 1; i < argc; i++) {
    char* srcdir = argv[i];
    syncdir(srcdir);
  }
  return 0;
}

char* syncdir(char* srcdir) {
  DIR* srcdirp = opendir(srcdir);
  if (srcdirp == NULL) {
    perror("opendir");
    return NULL;
  }
  struct dirent* srcdirent;
  while ((srcdirent = readdir(srcdirp)) != NULL) {
    struct stat srcstat;
    char* srcpath = malloc(strlen(srcdir) + strlen(srcdirent->d_name) + 2);
    strcpy(srcpath, srcdir);
    strcat(srcpath, "/");
    strcat(srcpath, srcdirent->d_name);
    if (lstat(srcpath, &srcstat) == -1) {
      perror("lstat");
      free(srcpath);
      continue;
    }
    if (S_ISDIR(srcstat.st_mode)) {
      if (strcmp(srcdirent->d_name, ".") == 0 || strcmp(srcdirent->d_name, "..") == 0)
        continue;
      syncdir(srcpath);
    } else {
      char* dstpath = malloc(strlen(srcdir) + strlen(srcdirent->d_name) + 2);
      strcpy(dstpath, srcdir);
      strcat(dstpath, "/");
      strcat(dstpath, srcdirent->d_name);
      struct stat dststat;
      if (lstat(dstpath, &dststat) == -1) {
        // file does not exist
        if (link(srcpath, dstpath) == -1) {
          perror("link");
          free(srcpath);
          free(dstpath);
          continue;
        }
      } else {
        if (srcstat.st_mtime > dststat.st_mtime) {
          // src file is newer
          if (unlink(dstpath) == -1) {
            perror("unlink");
            free(srcpath);
            free(dstpath);
            continue;
          }
          if (link(srcpath, dstpath) == -1) {
            perror("link");
            free(srcpath);
            free(dstpath);
            continue;
          }
        }
      }
      free(srcpath);
      free(dstpath);
    }
  }
  closedir(srcdirp);
  return NULL;
}