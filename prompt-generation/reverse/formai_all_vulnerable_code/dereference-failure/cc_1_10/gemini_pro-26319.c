//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <limits.h>

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 1024

// Define the maximum number of files to track
#define MAX_FILES 1000

// Define the structure of a file
typedef struct file {
  char *path;
  size_t size;
  time_t mtime;
} file_t;

// Define the structure of a directory
typedef struct directory {
  char *path;
  size_t size;
  time_t mtime;
  file_t files[MAX_FILES];
  int num_files;
} directory_t;

// Define the structure of the disk space analyzer
typedef struct disk_space_analyzer {
  char *root_path;
  size_t total_size;
  time_t total_mtime;
  directory_t directories[MAX_FILES];
  int num_directories;
} disk_space_analyzer_t;

// Create a new disk space analyzer
disk_space_analyzer_t *disk_space_analyzer_new(const char *root_path) {
  disk_space_analyzer_t *analyzer = malloc(sizeof(disk_space_analyzer_t));
  if (analyzer == NULL) {
    return NULL;
  }

  analyzer->root_path = strdup(root_path);
  if (analyzer->root_path == NULL) {
    free(analyzer);
    return NULL;
  }

  analyzer->total_size = 0;
  analyzer->total_mtime = 0;
  analyzer->num_directories = 0;

  return analyzer;
}

// Free the memory used by a disk space analyzer
void disk_space_analyzer_free(disk_space_analyzer_t *analyzer) {
  if (analyzer == NULL) {
    return;
  }

  free(analyzer->root_path);
  for (int i = 0; i < analyzer->num_directories; i++) {
    directory_t *directory = &analyzer->directories[i];
    free(directory->path);
    for (int j = 0; j < directory->num_files; j++) {
      file_t *file = &directory->files[j];
      free(file->path);
    }
  }

  free(analyzer);
}

// Get the size of a file
size_t file_size(const char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) == -1) {
    return 0;
  }

  return statbuf.st_size;
}

// Get the modification time of a file
time_t file_mtime(const char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) == -1) {
    return 0;
  }

  return statbuf.st_mtime;
}

// Add a file to a directory
void directory_add_file(directory_t *directory, const char *path) {
  file_t *file = &directory->files[directory->num_files];
  file->path = strdup(path);
  file->size = file_size(path);
  file->mtime = file_mtime(path);

  directory->size += file->size;
  directory->mtime = directory->mtime > file->mtime ? directory->mtime : file->mtime;

  directory->num_files++;
}

// Add a directory to a disk space analyzer
void disk_space_analyzer_add_directory(disk_space_analyzer_t *analyzer, const char *path) {
  directory_t *directory = &analyzer->directories[analyzer->num_directories];
  directory->path = strdup(path);
  directory->size = 0;
  directory->mtime = 0;
  directory->num_files = 0;

  analyzer->total_size += directory->size;
  analyzer->total_mtime = analyzer->total_mtime > directory->mtime ? analyzer->total_mtime : directory->mtime;

  analyzer->num_directories++;

  DIR *dir = opendir(path);
  if (dir == NULL) {
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char subpath[MAX_PATH_LENGTH];
    snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);

    struct stat statbuf;
    if (stat(subpath, &statbuf) == -1) {
      continue;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      disk_space_analyzer_add_directory(analyzer, subpath);
    } else if (S_ISREG(statbuf.st_mode)) {
      directory_add_file(directory, subpath);
    }
  }

  closedir(dir);
}

// Print the disk space usage for a directory
void directory_print_usage(directory_t *directory, int depth) {
  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("%s (%lu bytes, mtime: %s)\n", directory->path, directory->size, ctime(&directory->mtime));

  for (int i = 0; i < directory->num_files; i++) {
    file_t *file = &directory->files[i];
    for (int j = 0; j < depth + 1; j++) {
      printf(" ");
    }
    printf("%s (%lu bytes, mtime: %s)\n", file->path, file->size, ctime(&file->mtime));
  }
}

// Print the disk space usage for a disk space analyzer
void disk_space_analyzer_print_usage(disk_space_analyzer_t *analyzer) {
  for (int i = 0; i < analyzer->num_directories; i++) {
    directory_print_usage(&analyzer->directories[i], 0);
  }

  printf("Total: %lu bytes, mtime: %s\n", analyzer->total_size, ctime(&analyzer->total_mtime));
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <root_path>\n", argv[0]);
    return 1;
  }

  const char *root_path = argv[1];

  disk_space_analyzer_t *analyzer = disk_space_analyzer_new(root_path);
  if (analyzer == NULL) {
    fprintf(stderr, "Error: Could not create disk space analyzer\n");
    return 1;
  }

  disk_space_analyzer_add_directory(analyzer, root_path);

  disk_space_analyzer_print_usage(analyzer);

  disk_space_analyzer_free(analyzer);

  return 0;
}