//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct file_info {
  char path[MAX_PATH_LENGTH];
  char name[MAX_FILE_NAME_LENGTH];
  size_t size;
  time_t mtime;
} file_info;

int compare_files(const void *a, const void *b) {
  const file_info *fa = (const file_info *)a;
  const file_info *fb = (const file_info *)b;

  return strcmp(fa->path, fb->path);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source directory> <target directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the source and target directories.
  char *source_dir = argv[1];
  char *target_dir = argv[2];

  // Open the source directory.
  DIR *source_dirp = opendir(source_dir);
  if (source_dirp == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Create an array to store the file information.
  file_info *files = malloc(sizeof(file_info) * 1024);
  if (files == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Get the file information for each file in the source directory.
  int num_files = 0;
  struct dirent *dent;
  while ((dent = readdir(source_dirp)) != NULL) {
    if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/%s", source_dir, dent->d_name);

    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
      perror("stat");
      continue;
    }

    files[num_files].size = statbuf.st_size;
    files[num_files].mtime = statbuf.st_mtime;
    strncpy(files[num_files].path, path, sizeof(files[num_files].path) - 1);
    strncpy(files[num_files].name, dent->d_name, sizeof(files[num_files].name) - 1);

    num_files++;
  }

  closedir(source_dirp);

  // Sort the files by path.
  qsort(files, num_files, sizeof(file_info), compare_files);

  // Open the target directory.
  DIR *target_dirp = opendir(target_dir);
  if (target_dirp == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Synchronize the files.
  for (int i = 0; i < num_files; i++) {
    // Get the path to the file in the target directory.
    char target_path[MAX_PATH_LENGTH];
    snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, files[i].name);

    // Check if the file exists in the target directory.
    struct stat statbuf;
    if (stat(target_path, &statbuf) != 0) {
      // The file does not exist in the target directory. Create it.
      FILE *target_file = fopen(target_path, "w");
      if (target_file == NULL) {
        perror("fopen");
        continue;
      }

      fclose(target_file);

      // Update the file information.
      files[i].size = 0;
      files[i].mtime = time(NULL);
    } else {
      // The file exists in the target directory. Check if it is up to date.
      if (files[i].size != statbuf.st_size || files[i].mtime != statbuf.st_mtime) {
        // The file is not up to date. Update it.
        FILE *source_file = fopen(files[i].path, "r");
        if (source_file == NULL) {
          perror("fopen");
          continue;
        }

        FILE *target_file = fopen(target_path, "w");
        if (target_file == NULL) {
          perror("fopen");
          fclose(source_file);
          continue;
        }

        char buffer[4096];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
          fwrite(buffer, 1, bytes_read, target_file);
        }

        fclose(source_file);
        fclose(target_file);

        // Update the file information.
        files[i].size = statbuf.st_size;
        files[i].mtime = statbuf.st_mtime;
      }
    }
  }

  closedir(target_dirp);

  // Free the memory allocated for the file information.
  free(files);

  return EXIT_SUCCESS;
}