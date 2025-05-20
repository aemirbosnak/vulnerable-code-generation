//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Free the memory allocated for the directory entries
void free_dir_entries(struct dirent **entries, int count) {
  for (int i = 0; i < count; i++) {
    free(entries[i]);
  }
  free(entries);
}

// Get the size of a file in bytes
long long get_file_size(const char *path) {
  struct stat file_stat;
  if (stat(path, &file_stat) != 0) {
    perror("stat");
    return -1;
  }
  return file_stat.st_size;
}

// Get the directory entries for a directory
struct dirent **get_dir_entries(const char *path, int *count) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return NULL;
  }

  struct dirent **entries = NULL;
  *count = 0;

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    entries = realloc(entries, (*count + 1) * sizeof(struct dirent *));
    entries[*count] = entry;
    (*count)++;
  }

  closedir(dir);
  return entries;
}

// Analyze the disk space usage for a directory
long long analyze_dir(const char *path) {
  long long total_size = 0;

  int dir_entry_count;
  struct dirent **dir_entries = get_dir_entries(path, &dir_entry_count);
  if (dir_entries == NULL) {
    return -1;
  }

  for (int i = 0; i < dir_entry_count; i++) {
    struct dirent *dir_entry = dir_entries[i];

    // Skip "." and ".."
    if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
      continue;
    }

    char full_path[strlen(path) + strlen(dir_entry->d_name) + 2];
    sprintf(full_path, "%s/%s", path, dir_entry->d_name);

    struct stat file_stat;
    if (stat(full_path, &file_stat) != 0) {
      perror("stat");
      continue;
    }

    if (S_ISDIR(file_stat.st_mode)) {
      // Recursively analyze the subdirectory
      long long subdir_size = analyze_dir(full_path);
      if (subdir_size == -1) {
        continue;
      }
      total_size += subdir_size;
    } else {
      // Add the size of the file to the total
      total_size += file_stat.st_size;
    }
  }

  free_dir_entries(dir_entries, dir_entry_count);
  return total_size;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  long long total_size = analyze_dir(argv[1]);
  if (total_size == -1) {
    perror("analyze_dir");
    return 1;
  }

  printf("Total size: %lld bytes\n", total_size);
  return 0;
}