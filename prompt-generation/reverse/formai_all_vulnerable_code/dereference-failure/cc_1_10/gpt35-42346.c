//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function to recursively traverse the directory and synchronize files
void syncDirectories(char* sourcePath, char* destinationPath) {
  DIR* sourceDir;
  DIR* destinationDir;
  struct dirent* sourceEntry;
  struct stat sourceStat, destinationStat;
  char sourceFilePath[1000], destinationFilePath[1000];

  // open source and destination directory
  sourceDir = opendir(sourcePath);
  destinationDir = opendir(destinationPath);

  // iterate over each file in the source directory
  while ((sourceEntry = readdir(sourceDir))) {
    // skip . and .. directories
    if (strcmp(sourceEntry->d_name, ".") == 0 || strcmp(sourceEntry->d_name, "..") == 0) {
      continue;
    }

    // get the file path for both source and destination directory
    sprintf(sourceFilePath, "%s/%s", sourcePath, sourceEntry->d_name);
    sprintf(destinationFilePath, "%s/%s", destinationPath, sourceEntry->d_name);

    // get file stats for both source and destination files
    stat(sourceFilePath, &sourceStat);
    stat(destinationFilePath, &destinationStat);

    // if the file does not exist in the destination directory, copy it over
    if (destinationStat.st_ino == 0) {
      printf("Copying %s to %s\n", sourceFilePath, destinationFilePath);
      FILE* sourceFile = fopen(sourceFilePath, "rb");
      FILE* destinationFile = fopen(destinationFilePath, "wb");
      int c;

      while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
      }

      fclose(sourceFile);
      fclose(destinationFile);
    } else if (S_ISDIR(sourceStat.st_mode)) { // handle subdirectories
      syncDirectories(sourceFilePath, destinationFilePath);
    } else if (sourceStat.st_mtime > destinationStat.st_mtime) { // handle file updates
      printf("Updating %s in %s\n", sourceFilePath, destinationPath);
      FILE* sourceFile = fopen(sourceFilePath, "rb");
      FILE* destinationFile = fopen(destinationFilePath, "wb");
      int c;

      while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
      }

      fclose(sourceFile);
      fclose(destinationFile);
    }
  }

  closedir(sourceDir);
  closedir(destinationDir);
}

// main function
int main(int argc, char** argv) {
  char* sourcePath;
  char* destinationPath;

  if (argc != 3) { // make sure we have two directories
    printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
    return -1;
  }

  sourcePath = argv[1];
  destinationPath = argv[2];

  syncDirectories(sourcePath, destinationPath);

  printf("Synchronization complete!\n");

  return 0;
}