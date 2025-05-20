//FormAI DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

void syncFiles(char sourceDir[], char destinationDir[]) {
  DIR *dir;
  struct dirent *entry;
  struct stat sb;
  char srcPath[256], destPath[256];

  if ((dir = opendir(sourceDir)) == NULL) {
    perror("Error while opening source directory");
    exit(EXIT_FAILURE);
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    snprintf(srcPath, sizeof(srcPath), "%s/%s", sourceDir, entry->d_name);
    snprintf(destPath, sizeof(destPath), "%s/%s", destinationDir, entry->d_name);
    if (lstat(srcPath, &sb) == -1) {
      perror("lstat failed");
      exit(EXIT_FAILURE);
    }

    if (S_ISREG(sb.st_mode)) { // If it's a file
      int srcFd, destFd;
      if ((srcFd = open(srcPath, O_RDONLY)) == -1) {
        perror("Unable to open source file");
        continue; // Skip to next file
      }
      if ((destFd = open(destPath, O_CREAT|O_WRONLY|O_TRUNC, sb.st_mode)) == -1) {
        perror("Unable to open destination file");
        close(srcFd); // Close previously opened file
        continue; // Skip to next file
      }

      // Copying the contents of source file to destination file
      char buffer[4096];
      ssize_t bytesRead;
      while ((bytesRead = read(srcFd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytesWritten = write(destFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
          perror("Error while copying data");
          close(srcFd);
          close(destFd);
          continue;
        }
      }

      close(srcFd);
      close(destFd);
    }
    else if (S_ISDIR(sb.st_mode)) { // If it's a directory
      // Recursively copy the directory and it's contents
      syncFiles(srcPath, destPath);
    }
  }
  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  syncFiles(argv[1], argv[2]);
  printf("Files synchronized successfully!\n");

  return 0;
}