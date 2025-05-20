//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int synchronizeFiles(char *dir1, char *dir2) {
  DIR *d1, *d2;
  struct dirent *dir;
  struct stat st;
  char path1[256], path2[256];
  int count = 0;

  // Open the directories
  d1 = opendir(dir1);
  d2 = opendir(dir2);

  // Make sure they opened successfully
  if (!d1 || !d2) {
    printf("Failed to open directories.\n");
    return 1;
  }

  // Iterate over the files in dir1
  while ((dir = readdir(d1)) != NULL) {
    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
      // Skip over "." and ".."
      continue;
    }

    strcpy(path1, dir1);
    strcat(path1, "/");
    strcat(path1, dir->d_name);

    strcpy(path2, dir2);
    strcat(path2, "/");
    strcat(path2, dir->d_name);

    // Check if the file exists in dir2
    if (stat(path2, &st) == -1) {
      // If it doesn't, copy it over
      printf("Copying %s to %s\n", path1, path2);
      FILE *f1 = fopen(path1, "rb");
      FILE *f2 = fopen(path2, "wb");

      if (!f1 || !f2) {
        printf("Error opening files.\n");
        return 2;
      }

      char buffer[1024];
      size_t n;

      while ((n = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
        fwrite(buffer, 1, n, f2);
      }

      fclose(f1);
      fclose(f2);

      count++;
    }
  }

  // Close dir1 and reset it
  closedir(d1);
  d1 = opendir(dir1);

  // Iterate over the files in dir2
  while ((dir = readdir(d2)) != NULL) {
    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
      // Skip over "." and ".."
      continue;
    }

    strcpy(path2, dir2);
    strcat(path2, "/");
    strcat(path2, dir->d_name);

    // Check if the file exists in dir1
    if (stat(path1, &st) == -1) {
      // If it doesn't, copy it over
      printf("Copying %s to %s\n", path2, path1);
      FILE *f1 = fopen(path1, "wb");
      FILE *f2 = fopen(path2, "rb");

      if (!f1 || !f2) {
        printf("Error opening files.\n");
        return 2;
      }

      char buffer[1024];
      size_t n;

      while ((n = fread(buffer, 1, sizeof(buffer), f2)) > 0) {
        fwrite(buffer, 1, n, f1);
      }

      fclose(f1);
      fclose(f2);

      count++;
    }
  }

  // Close the directories and print out how many files were synchronized
  closedir(d1);
  closedir(d2);
  printf("%d files synchronized.\n", count);

  return 0;
}

int main() {
  char *dir1 = "./dir1";
  char *dir2 = "./dir2";
  
  printf("Welcome to our cheerful file synchronizer!\n");
  printf("Let's make sure the directories are ready...\n");

  if (access(dir1, F_OK) == -1 || access(dir2, F_OK) == -1) {
    printf("One or both directories do not exist. Creating them now...\n");

    mkdir(dir1, 0777);
    mkdir(dir2, 0777);
  }

  printf("Directories are ready for syncing!\n");

  synchronizeFiles(dir1, dir2);

  printf("All done!\n");

  return 0;
}