//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int ScanAndSync(const char *src, const char *dest) {
  DIR *dir;
  int err, newCount = 0;
  struct stat srcStat, destStat;
  char *srcFile, *destFile, *newDestPath;

  if ((dir = opendir(src)) == NULL) {
    printf("Could not open source directory %s\n", src);
    return 1;
  }

  while ((srcFile = readdir(dir)) != NULL) {
    if (srcFile[0] == '.') {
      continue;
    }
    newDestPath = malloc(strlen(dest) + strlen(srcFile) + 2);
    strcpy(newDestPath, dest);
    strcat(newDestPath, "/");
    strcat(newDestPath, srcFile);
    destFile = newDestPath;

    if (lstat(srcFile, &srcStat) < 0) {
      printf("Could not stat source file %s\n", srcFile);
      free(newDestPath);
      continue;
    }

    if (lstat(destFile, &destStat) < 0) {
      // File does not exist, or is unreachable
      if (S_ISREG(srcStat.st_mode)) {
        printf("Copying %s to %s\n", srcFile, destFile);
        if ((err = link(srcFile, destFile)) != 0) {
          printf("Could not link %s to %s\n", srcFile, destFile);
          free(newDestPath);
          continue;
        }
        newCount++;
      } else if (S_ISDIR(srcStat.st_mode)) {
        printf("Creating directory %s\n", destFile);
        if ((err = mkdir(destFile, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)) != 0) {
          printf("Could not create directory %s\n", destFile);
          free(newDestPath);
          continue;
        }
        newCount++;
      }
      free(newDestPath);
      continue;
    }

    // File exists
    if (S_ISREG(srcStat.st_mode) && (srcStat.st_mtime > destStat.st_mtime)) {
      printf("Updating %s in %s\n", srcFile, destFile);
      if ((err = link(srcFile, destFile)) != 0) {
        printf("Could not link %s to %s\n", srcFile, destFile);
      }
    } else if (S_ISDIR(srcStat.st_mode)) {
      ScanAndSync(srcFile, destFile);
    }
    free(newDestPath);
  }

  if (closedir(dir) != 0) {
    printf("Could not close source directory %s\n", src);
    return 1;
  }
  return newCount;
}

int main(int argc, char **argv) {
  int newCount;

  if (argc != 3) {
    printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
    return 1;
  }

  newCount = ScanAndSync(argv[1], argv[2]);
  if (newCount > 0) {
    printf("Synchronized %d files\n", newCount);
  } else {
    printf("No files to synchronize\n");
  }
  return 0;
}