//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void printUsage() {
  printf("Usage: analyze [directory path]\n\n");
  printf("This program will analyze the disk space usage of the specified directory and its contents.");
}

void analyzeDirectory(char* path) {
  DIR* dir = opendir(path);
  if (!dir) {
    printf("Error analyzing directory %s\n", path);
    exit(EXIT_FAILURE);
  }
  
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Ignore . and .. directories
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    
    // Create the full path for the current entry
    char* entryPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
    sprintf(entryPath, "%s/%s", path, entry->d_name);
    
    // Get information about the entry
    struct stat info;
    if (lstat(entryPath, &info) < 0) {
      printf("Could not get information for %s\n", entryPath);
      free(entryPath);
      continue;
    }
    
    if (S_ISDIR(info.st_mode)) {
      // Recursively process directories
      analyzeDirectory(entryPath);
    } else {
      // Print information for files
      printf("%-50s %10lld bytes\n", entryPath, info.st_size);
    }
    
    free(entryPath);
  }
  
  closedir(dir);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printUsage();
    return EXIT_FAILURE;
  }
  
  char* path = argv[1];
  analyzeDirectory(path);
  
  return EXIT_SUCCESS;
}