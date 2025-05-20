//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Excited C File Synchronizer Program!

int main() {
  char sourceDir[256], destDir[256];

  // Get the source and destination directories from the user.
  printf("Greetings fellow file adventurer! Let's synchronize some files!\n");
  printf("Enter the source directory: ");
  scanf("%s", sourceDir);
  printf("Enter the destination directory: ");
  scanf("%s", destDir);

  // Check if the directories exist.
  DIR *sourceDirPtr = opendir(sourceDir);
  if (sourceDirPtr == NULL) {
    printf("Oops! The source directory doesn't exist. Please check the path and try again!\n");
    return 1;
  }
  closedir(sourceDirPtr);

  DIR *destDirPtr = opendir(destDir);
  if (destDirPtr == NULL) {
    printf("Hmm... The destination directory doesn't exist either. Let's create it for you!\n");
    mkdir(destDir, 0755);
    destDirPtr = opendir(destDir);
  }
  closedir(destDirPtr);

  // Loop through the files in the source directory.
  struct dirent *direntPtr;
  sourceDirPtr = opendir(sourceDir);
  while ((direntPtr = readdir(sourceDirPtr)) != NULL) {
    // Skip hidden files.
    if (direntPtr->d_name[0] == '.') {
      continue;
    }

    // Get the file's path and check if it exists in the destination directory.
    char sourceFilePath[256];
    strcpy(sourceFilePath, sourceDir);
    strcat(sourceFilePath, "/");
    strcat(sourceFilePath, direntPtr->d_name);
    struct stat statBuf;
    if (stat(sourceFilePath, &statBuf) != 0) {
      printf("Oh no! The file %s doesn't exist in the source directory. Skipping...\n", sourceFilePath);
      continue;
    }

    char destFilePath[256];
    strcpy(destFilePath, destDir);
    strcat(destFilePath, "/");
    strcat(destFilePath, direntPtr->d_name);
    if (stat(destFilePath, &statBuf) == 0) {
      // The file already exists in the destination directory. Check if it's up to date.
      if (statBuf.st_mtime < statBuf.st_mtime) {
        // The file in the source directory is newer. Copy it to the destination directory.
        printf("Aha! The file %s is out of sync. Copying it now!\n", destFilePath);
        FILE *sourceFilePtr = fopen(sourceFilePath, "rb");
        FILE *destFilePtr = fopen(destFilePath, "wb");
        char buffer[4096];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFilePtr)) > 0) {
          fwrite(buffer, 1, bytesRead, destFilePtr);
        }
        fclose(sourceFilePtr);
        fclose(destFilePtr);
      } else {
        // The file in the destination directory is up to date. Skip it.
        printf("The file %s is already up to date. Moving on!\n", destFilePath);
      }
    } else {
      // The file doesn't exist in the destination directory. Copy it from the source directory.
      printf("Eureka! The file %s is missing in the destination directory. Adding it now!\n", destFilePath);
      FILE *sourceFilePtr = fopen(sourceFilePath, "rb");
      FILE *destFilePtr = fopen(destFilePath, "wb");
      char buffer[4096];
      size_t bytesRead;
      while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFilePtr)) > 0) {
        fwrite(buffer, 1, bytesRead, destFilePtr);
      }
      fclose(sourceFilePtr);
      fclose(destFilePtr);
    }
  }
  closedir(sourceDirPtr);

  // All done!
  printf("Woohoo! Your files have been synchronized. You're welcome!\n");

  return 0;
}