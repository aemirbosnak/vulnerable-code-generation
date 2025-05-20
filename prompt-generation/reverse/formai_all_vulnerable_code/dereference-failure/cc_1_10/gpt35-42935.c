//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a file or directory exists
int exists(const char *path) {
  struct stat stats;
  return stat(path, &stats) == 0;
}

// Function to copy a file
void sync_file(const char *source, const char *destination) {
  FILE *f1, *f2;
  char buffer[1024];
  size_t read_size;

  f1 = fopen(source, "rb");
  f2 = fopen(destination, "wb");

  while ((read_size = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
    fwrite(buffer, 1, read_size, f2);
  }

  fclose(f1);
  fclose(f2);
}

// Function to synchronize two directories
void sync_directories(const char *source, const char *destination) {
  struct dirent *entry;
  DIR *dir;

  // Loop through all the files and directories in the source directory
  if ((dir = opendir(source)) != NULL) {
    while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
        char source_path[1024], destination_path[1024];

        sprintf(source_path, "%s/%s", source, entry->d_name);
        sprintf(destination_path, "%s/%s", destination, entry->d_name);

        if (exists(destination_path)) {
          // Check if the file in the source directory is newer
          struct stat source_stats, destination_stats;

          stat(source_path, &source_stats);
          stat(destination_path, &destination_stats);

          if (difftime(source_stats.st_mtime, destination_stats.st_mtime) > 0) {
            // The file in the source directory is newer, so sync it
            printf("Syncing %s to %s\n", source_path, destination_path);
            sync_file(source_path, destination_path);
          }
        } else {
          // The file doesn't exist in the destination directory, so copy it
          printf("Copying %s to %s\n", source_path, destination_path);
          sync_file(source_path, destination_path);
        }

        if (entry->d_type == DT_DIR) {
          // Recursively sync subdirectories
          sync_directories(source_path, destination_path);
        }
      }
    }

    closedir(dir);
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
    return 1;
  }

  sync_directories(argv[1], argv[2]);

  printf("Sync complete!\n");

  return 0;
}