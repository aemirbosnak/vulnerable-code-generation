//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <string.h>

// Function to get the file size
long long get_file_size(const char *filename) {
  struct stat st;
  if (stat(filename, &st) == 0) {
    return st.st_size;
  }
  return -1;
}

// Function to get the file modification time
time_t get_file_modification_time(const char *filename) {
  struct stat st;
  if (stat(filename, &st) == 0) {
    return st.st_mtime;
  }
  return -1;
}

// Function to compare two file modification times
int compare_file_modification_times(const char *filename1, const char *filename2) {
  time_t time1 = get_file_modification_time(filename1);
  time_t time2 = get_file_modification_time(filename2);
  if (time1 == -1 || time2 == -1) {
    return -1;
  }
  return time1 - time2;
}

// Function to print the file information
void print_file_info(const char *filename) {
  long long size = get_file_size(filename);
  time_t time = get_file_modification_time(filename);
  if (size == -1 || time == -1) {
    printf("Error getting file information for %s\n", filename);
    return;
  }
  char time_string[26];
  ctime_r(&time, time_string);
  time_string[24] = '\0';
  printf("%-20s %10lld %s\n", filename, size, time_string);
}

// Function to walk the directory tree and print the file information
void walk_directory(const char *directory_name) {
  DIR *dir = opendir(directory_name);
  if (dir == NULL) {
    printf("Error opening directory %s\n", directory_name);
    return;
  }
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    char filename[strlen(directory_name) + strlen(entry->d_name) + 2];
    sprintf(filename, "%s/%s", directory_name, entry->d_name);
    print_file_info(filename);
  }
  closedir(dir);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <directory_name>\n", argv[0]);
    return 1;
  }
  walk_directory(argv[1]);
  return 0;
}