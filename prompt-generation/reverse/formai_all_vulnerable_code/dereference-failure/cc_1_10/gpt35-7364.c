//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

void handleError(const char* format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  exit(1);
}

void copyFile(const char* src, const char* dest) {
  
  FILE *srcFile = fopen(src, "rb");
  FILE *destFile = fopen(dest, "wb");
  char buffer[BUFFER_SIZE];
  
  if (!srcFile) {
    handleError("Error opening source file: %s\n", src);
  }
  
  if (!destFile) {
    handleError("Error opening destination file: %s\n", dest);
  }
  
  while (!feof(srcFile)) {
    int bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile);
    fwrite(buffer, 1, bytesRead, destFile);
  }
  
  fclose(srcFile);
  fclose(destFile);
}

void syncDirectory(const char* srcDir, const char* destDir) {
  
  DIR *src, *dest;
  struct dirent *entry;
  struct stat srcStat, destStat;
  char srcPath[BUFFER_SIZE], destPath[BUFFER_SIZE];
  
  if ((src = opendir(srcDir)) == NULL) {
    handleError("Cannot open source directory: %s\n", srcDir);
  }
  
  if ((dest = opendir(destDir)) == NULL) {
    handleError("Cannot open destination directory: %s\n", destDir);
  }
  
  while ((entry = readdir(src)) != NULL) {
    snprintf(srcPath, BUFFER_SIZE, "%s/%s", srcDir, entry->d_name);
    snprintf(destPath, BUFFER_SIZE, "%s/%s", destDir, entry->d_name);
    
    if (entry->d_type == DT_DIR) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        continue;
      }
      
      if (stat(srcPath, &srcStat) == -1) {
        handleError("Error getting status of source directory: %s\n", srcPath);
      }
      
      if (stat(destPath, &destStat) == -1) {
        if (mkdir(destPath, srcStat.st_mode) == -1) {
          handleError("Error creating destination directory: %s\n", destPath);
        } else {
          printf("Created destination directory: %s\n", destPath);
        }
      }
      
      syncDirectory(srcPath, destPath);
    } else if (entry->d_type == DT_REG) {
      if (stat(srcPath, &srcStat) == -1) {
        handleError("Error getting status of source file: %s\n", srcPath);
      }
      
      if (stat(destPath, &destStat) == -1) {
        copyFile(srcPath, destPath);
        printf("Copied file from %s to %s\n", srcPath, destPath);
      } else {
        if (srcStat.st_mtime > destStat.st_mtime) {
          copyFile(srcPath, destPath);
          printf("Updated file at %s\n", destPath);
        }
      }
    }
  }
  
  closedir(dest);
  closedir(src);
}


int main(int argc, char* argv[]) {
  
  if (argc < 3) {
    printf("File Synchronizer requires two arguments: source and destination directories.\n");
    return 0;
  }
  
  syncDirectory(argv[1], argv[2]);
  
  return 0;
}